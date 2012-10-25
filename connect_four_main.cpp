/*
*Author :Tharindra Galahena
*Project:Connect - Four A.I. Agent
*Date   :25/10/2012
*License:
* 
*     Copyright 2012 Tharindra Galahena
*
* This program is free software: you can redistribute it and/or modifood_y it under the 
* terms of the GNU General Public License as published by the Free Software Foundation, 
* either version 3 of the License, or (at your option) any later version. This program is 
* distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even 
* the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with This program. 
* If not, see http://www.gnu.org/licenses/.
*
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <fstream>

#include "connect_four.cpp"

using namespace std;

state current_state;
bool finish = false;

void frame(int step){
	current_state.update(step, '0');
	if(current_state.get_minimax() == -20){
		cout << " Human Win !!! " << endl;
		finish = true;
		return;
	}	
	if(current_state.get_minimax() == 0){
		cout << " No Winners !!! " << endl;
		finish = true;
		return;
	}	
	current_state.steps = 0;
	current_state = get_value(0, current_state, 0);
	if(current_state.get_minimax() == 20){
		cout << " A. I. Win !!! " << endl;
		finish = true;
		return;
	}
	if(current_state.get_minimax() == -20){
		cout << " Human Win !!! " << endl;
		finish = true;
		return;
	}
	if(current_state.get_minimax() == 0){
		cout << " No Winners !!! " << endl;
		finish = true;
		return;
	}
}
void par(float x1, float x2, float y1, float y2, float r, float b, float g){
	glColor3f(r, b, g);
	glBegin(GL_QUADS);
	
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x1, y2, 0.0);

	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity ();

	glTranslatef(0.0, 0.0, -22.0);
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			if(current_state.bord[i][j] == '0')
				par(-7.5 + 2.2 * j + 0.1,
				-7.5 + 2.2 * (j + 1) - 0.1,
				4.5 - 2.2 * i + 0.1,
				4.5 - 2.2 * (i - 1) - 0.1, 0.0, 0.0, 1.0);
			else if(current_state.bord[i][j] == '#')
				par(-7.5 + 2.2 * j + 0.1,
				-7.5 + 2.2 * (j + 1) - 0.1,
				4.5 - 2.2 * i + 0.1,
				4.5 - 2.2 * (i - 1) - 0.1, 1.0, 0.0, 0.0);
		}
	}
	par(-7.5,
		-7.5 + 2.2 * 7,
		4.5 + 2.4 + 0.1,
		4.5 + 2.4, 1.0, 0.0, 0.0);
	par(-7.5,
		-7.5 + 2.2 * 7,
		4.5 - 2.2*5 ,
		4.5 - 2.2*5 - 0.1, 1.0, 0.0, 0.0);
	par(-7.5 - 0.1,
		-7.5 ,
		4.5 + 2.5,
		4.5 - 2.2*5 - 0.1 , 1.0, 0.0, 0.0);
	par(-7.5 + 2.2 * 7,
		-7.5 + 2.2 * 7 + 0.1,
		4.5 + 2.5,
		4.5 - 2.2*5 - 0.1, 1.0, 0.0, 0.0);
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y){
	
	if(key == 27) {		
		exit(0);	
	}else if((char)key == 'a'){
		if(!finish) frame(0);
	}else if((char)key == 's'){
		if(!finish) frame(1);
	}else if((char)key == 'd'){
		if(!finish) frame(2);
	}else if((char)key == 'f'){
		if(!finish) frame(3);
	}else if((char)key == 'g'){
		if(!finish) frame(4);
	}else if((char)key == 'h'){
		if(!finish) frame(5);
	}else if((char)key == 'j'){
		if(!finish) frame(6);
	}else if((char)key == 'r'){
		current_state.reset();
		finish = false;
	}
	glutPostRedisplay();
}
void init(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);	
	glLoadIdentity ();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLfloat acolor[] = {1.4, 1.4, 1.4, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, acolor);
}

void Reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(45.0, (float)w/(float)h, 0.1, 200.0);
}
int main(int argc, char** argv){
	srand(time(NULL));
	
	cout << "-----------------------------------------------" << endl;
	cout << endl;
	cout << "          --- CONNECT - FOUR A.I. ---          " << endl;
	cout << endl;
	cout << "created by : tharindra galahena (inf0_warri0r) " << endl;
	cout << "blog       : www.inf0warri0r.blogspot.com      " << endl;
	cout << endl;
	cout << "-----------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	
	glutInit(&argc,argv);
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(500,0);
	glutCreateWindow("A.I.");
	
	init();
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}
