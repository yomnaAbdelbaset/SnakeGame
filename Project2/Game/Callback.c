#include"Headers.h"

int score = 0;
short snake_direction = RIGHT;
int gameOver;
int Winner;

/*
name : display_callback,
parameters : void ,
return : void,
used in glutDisplayFunc that sets the display callback for the current window.
( responsible for displaying the game window with all things in it like (grid - snake - food) )
*/
void display_callback(void) {  
	glClear(GL_COLOR_BUFFER_BIT); //clearing the color buffer
	drawGrid(); // drawing the grid that the snake plays inside
	drawSnake(); //drawing the snake 
	drawFood(); //drawing the food

	glutSwapBuffers(); //(promotes the contents of the back buffer of the layer in use of the current window to become the contents of the front buffer)
	
	if (gameOver) //in case if you hit the red area then you lose and your score will be displayed
	{
		char _score[10];
		_itoa(score, _score, 10); // convert the score (int) to (string) in order to display the score without problems
		char text[50] = "Your Score: ";
		strcat(text, _score); // concatenating the score with the text to be displayed
		MessageBox(NULL, text, "GAME OVER!", 0); 
		exit(0); //exit the window
	}

	if (Winner) // if your score is 19 (I specified it to be more easy to see the end of the game to check everything is working good)
	{
		char _score[10];
		_itoa(score, _score, 10); // convert the score (int) to (string) in order to display the score without problems
		char text[50] = "Congratulations!\nYour Score: ";
		strcat(text, _score); // concatenating the score with the text to be displayed
		MessageBox(NULL, text, "WINNER!", 0);
		exit(0);  //exit the window
	}
}


/*
name : reshape_callback,
parameters : width, height,
return : void,
used in glutReshapeFunc that sets the reshape callback for the current window.
( used in specifiying the width and height of the game window )
*/
void reshape_callback(int width, int height) { 

	glViewport(0, 0, (GLsizei)width, (GLsizei)height); //sets the viewport, takes the width & height parameters 
	glMatrixMode(GL_PROJECTION); //specify which matrix is the current matrix
	glLoadIdentity(); //replace the current matrix with the identity matrix 
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0); // multiply the current matrix with an orthographic matrix
	glMatrixMode(GL_MODELVIEW);

}

/*
name : timer_callback,
parameters : void,
return : void,
used in glutTimerFunc that registers a timer callback to be triggered in a specified number of milliseconds.
*/ 
void timer_callback(void) {
	glutPostRedisplay(); //marks the current window as needing to be redisplayed.
	glutTimerFunc(1000 / FPS, timer_callback, 0);
}


/*
name : keyboard_callback,
parameters : key,
return : void,
used in glutSpecialFunc that sets the special keyboard callback for the current window.
( used to detect which key is pressed to move the snake )
*/
void keyboard_callback(int key) {
	switch (key) {
	case GLUT_KEY_UP:
		if (snake_direction != DOWN) {
			snake_direction = UP;
		}
		break;
	case GLUT_KEY_DOWN:
		if (snake_direction != UP) {
			snake_direction = DOWN;
		}
		break;
	case GLUT_KEY_LEFT:
		if (snake_direction != RIGHT) {
			snake_direction = LEFT;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (snake_direction != LEFT) {
			snake_direction = RIGHT;
		}
		break;
	}

}





