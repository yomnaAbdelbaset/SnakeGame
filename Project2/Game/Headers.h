#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>


#define UP 1 
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define MAX 19
#define COLUMNS 20
#define ROWS 20
#define FPS 7 //7 frames per second

int argc;
char** argv;

void initGrid(int, int);
void drawGrid(void);
void drawSnake(void);
void drawFood(void);
void random(int*, int*);

//main declarations

void init(void);
void display_callback(void);
void reshape_callback(int, int);
void timer_callback(void);
void keyboard_callback(int);
void Play(void);
