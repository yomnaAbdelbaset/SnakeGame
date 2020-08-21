#include"Headers.h"

int gridX, gridY;
int foodX, foodY;
int snake_length = 1;
int snake_index;
int snake_posX[40] = { 10,10,10,10,10 }, snake_posY[40] = { 10,9,8,7,6 };
int food = 1;



extern int score;
extern short snake_direction;
extern int gameOver;
extern int Winner;

/*
name : init,
parameters : void,
return : void,
sets the color and shape for the game window
*/

void init(void)
{
	glClearColor(0.93, 0.93, 0.91, 1.0); //change the window color
	initGrid(COLUMNS, ROWS); //initialize the game grid with specified number of columns and rows already defined 
}

/*
name : initGrid,
parameters : x, y,
return : void,
sets the number of rows and columns to use in init
*/


void initGrid(int x, int y) { 
	gridX = x;
	gridY = y;
}

/*
name : drawGrid,
parameters : void ,
return : void,
draw the game grid using unit function 
*/


void unit(int, int); 
void drawGrid() { 
    
	//drawing the grid to move snake in
	for (int x = 0; x < gridX; x++) {   
		for (int y = 0; y < gridY; y++) {
			unit(x, y); //draw a single square gridX*gridY times which equals to ROWS*COLUMNS 
		}
	}
}

/*
name : unit,
parameters : x, y,
return : void,
draws a single square in the draw grid function to make the whole grid
*/

void unit(int x, int y) { 

	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) { // the dangerous edges that the snake mustn't touch
		glLineWidth(3.0);
		glColor3f(0.86, 0.08, 0.24);
	}
	else {
		glLineWidth(1.0);
		glColor3f(0.76, 0.75, 0.7);
	}

	glBegin(GL_LINE_LOOP); //start drawing square area
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();//end of drawing square area
}

/*
name : drawSnake,
parameters : void,
return : void,
draws the snake and increase it every time it eats food
*/


void drawSnake(void)
{
	for (int i = snake_length - 1; i > 0; i--) {
		snake_posX[i] = snake_posX[i - 1];
		snake_posY[i] = snake_posY[i - 1];
	} 

	// Drawing the snake due to the key pressed
	if (snake_direction == UP) {
		snake_posY[0]++;
	}
	else if (snake_direction == DOWN) {

		snake_posY[0]--;
	}
	else if (snake_direction == RIGHT) {
		snake_posX[0]++;
	}
	else if (snake_direction == LEFT) {
		snake_posX[0]--;
	}
	
	//different color for snake head but same for others
	for (int i = 0; i < snake_length; i++) {
		if (i == 0) {
			glColor3f(1, 0.89, 0.17);
		}
		else {
			glColor3f(0.55, 0.54, 0.49);
		}
		glRectd(snake_posX[i], snake_posY[i], snake_posX[i] + 1, snake_posY[i] + 1); 
		//drawing a singrectangle (in this case it's square) which makes the snake taller every time it eats the food  
	}

	//if the snake touches any dangerous edges then Game Over
	if (snake_posX[0] == 0 || snake_posX[0] == gridX - 1 || snake_posY[0] == 0 || snake_posY[0] == gridY - 1) {
		gameOver = 1;
	}

	// if the snake eats food increase the score and snake length
	if (snake_posX[0] == foodX && snake_posY[0] == foodY) {

		score++;
		snake_length++;
		if (snake_length > MAX) //When reached more than 19 the player wins and game ends
		{
			snake_length = MAX;
			Winner = 1;
		}
		food = 1; // flag to detect whether the snake eats the food or not
	}
}

/*
name : drawFood,
parameters : void,
return : void,
draws the  food for the snakein random places
*/

void drawFood(void)
{
	if (food) { // if the snake eats the food then generate another one in another random place
		random(&foodX, &foodY);
	}
	food = 0; // food flag off  
	glColor3f(0.36, 0, 0.49); //food color
	glRectf(foodX, foodY, foodX + 1, foodY + 1); //draw the food as square 
}


/*
name : random,
parameters : *x, *y,
return : void,
generates a random values to draw food inside the grid area
*/

void random(int* x, int* y) {
	int max_X = gridX - 2, max_Y = gridY - 2, minn = 1;
	srand(time(NULL));
	*x = minn + rand() % (max_X - minn + 1);
	*y = minn + rand() % (max_Y - minn + 1);
}