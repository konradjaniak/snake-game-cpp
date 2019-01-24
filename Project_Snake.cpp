#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

bool bGameOver;
const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup();
void Draw();
void Input();
void Logic();

/* ----------------------------- */
int main()
{
	srand(time(NULL));
	Setup();
	while(!bGameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(100);
	}

	return 0;
}

/* ----------------------------- */ 
void Setup()
{
	bGameOver = false;
	dir = STOP;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	score = 0;
}

/* ----------------------------- */
void Draw()
{
	system("cls");

	// print top row
	for(int i = 0; i < WIDTH + 1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	// print side walls
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if(j == 0)
				std::cout << "#";

			if(i == y && j == x)
				std::cout << "0";
			else if(i == fruitY && j == fruitX)
				std::cout << "F";
			else
				std::cout << " ";
			if(j == WIDTH - 1)
				std::cout << "#";
		}
		std::cout << std::endl;
	}

	// print bottom row
	for(int i = 0; i < WIDTH + 1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	// print score
	std::cout << "Score: " << score << std::endl;
}

/* ----------------------------- */
void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			bGameOver = true;
			break;
		}
	}
}

/* ----------------------------- */
void Logic()
{
	// change movement direction
	switch(dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	// finish game when snake hit the wall
	if(x > WIDTH || x < 0 || y > HEIGHT || y < 0)
	{
		bGameOver = true;
	}

	// increase the score when snake eats the fruit and set new location of the fruit
	if(x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
	}
}
