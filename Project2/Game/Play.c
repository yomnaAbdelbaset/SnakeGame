#include"Headers.h"

/*
name : Play,
parameters : void,
return : void,
This functions have all the functions that required to build everything and start the game
*/

void Play(void) {

	glutInit(&argc, argv); //Initialize glut
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //Initialize the color display mode, I chose RGBA mode
	glutInitWindowSize(500, 500);//Intialize the window size 
	glutCreateWindow("SNAKE GAME"); //Create the title of the window
	glutDisplayFunc(display_callback); //sets the display callback for the current window
	glutReshapeFunc(reshape_callback); //sets the reshape callback for the current window
	glutTimerFunc(0, timer_callback, 0); //registers a timer callback to be triggered in a specified number of milliseconds
	glutSpecialFunc(keyboard_callback); //sets the special keyboard callback for the current window
	init(); //sets the color and shape for the game window
	glutMainLoop(); //Display the window
}