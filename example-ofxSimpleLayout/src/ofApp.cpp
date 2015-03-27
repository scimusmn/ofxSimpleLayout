#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //View 1
    layout.image("background_1");
    layout.button("button_1", 520, 540, "go to view_2");
    layout.saveView("view_1");
    
    //View 2
    layout.image("background_2");
    layout.video("vid_1", 680, 500);
    layout.video("vid_2", 50, 560);
    layout.button("button_2", 520, 560, "go to view_3");
    layout.saveView("view_2");
    
    //View 3
    layout.image("background_3");
    layout.stateObject("stateObj", 50, 330);
    layout.button("button_3", 520, 580, "go to view_1");
    layout.saveView("view_3");
    
    layout.setView("view_1");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    layout.update(); //Only neccessary if using videos.
}

//--------------------------------------------------------------
void ofApp::draw(){
    layout.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '0') layout.setState("stateObj", "0");
    if (key == '1') layout.setState("stateObj", "1");
    if (key == '2') layout.setState("stateObj", "2");
    if (key == '3') layout.setState("stateObj", "3");
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    string btnMsg = layout.getSelected(x,y);
    if (btnMsg.substr(0,5) == "go to") {
        layout.setView( btnMsg.substr(6) );
    }
    
}
