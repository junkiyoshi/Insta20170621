#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");
	ofEnableDepthTest();
		
	this->icoSphere.setRadius(300);	
	this->icoSphere.setResolution(6);

	this->triangles = icoSphere.getMesh().getUniqueFaces();

	//this->light.setAreaLight(2048, 2048);
	//this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	//this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	//this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));

}

//--------------------------------------------------------------
void ofApp::update(){
	//this->light.setPosition(this->cam.getPosition().normalize() * 2048);
}

//--------------------------------------------------------------
void ofApp::draw() {

	//ofEnableLighting();
	//this->light.enable();

	cam.begin();

	ofRotateY(ofGetFrameNum() % 360);

	float noise_value;
	vector<ofMeshFace> tmp_triangles = this->triangles;

	ofVec3f faceNormal;
	ofColor c;
	for (int i = 0; i < triangles.size(); i++) {
		faceNormal = triangles[i].getFaceNormal();
		noise_value = ofNoise(triangles[i].getVertex(0).x * 0.0005, triangles[i].getVertex(0).y * 0.0005 - ofGetFrameNum() * 0.015, triangles[i].getVertex(0).z * 0.005);

		c.setHsb(255 * noise_value, 255, 255);
		tmp_triangles[i].setColor(0, c);
		tmp_triangles[i].setColor(1, c);
		tmp_triangles[i].setColor(2, c);
	}

	this->icoSphere.getMesh().setFromTriangles(tmp_triangles);

	this->icoSphere.draw();
	//this->icoSphere.drawWireframe();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
