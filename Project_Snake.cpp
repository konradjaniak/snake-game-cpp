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
int tailX[100], tailY[100];
int nTail;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup();
void Draw();
void Input();
void Logic();

int main()
{
	srand(time(NULL));
	Setup();
	while(!bGameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(150);
	}

	system("cls");
	std::cout << "Game Over!" << std::endl;
	std::cout << "Score: " << score << std::endl;

	return 0;
}

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

void Draw()
{
	system("cls");

	// print top row
	for(int i = 0; i < WIDTH + 1; i++)
		std::cout << "#";
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
			{
				bool bPrint = false;
				for(int k = 0; k < nTail; k++)
				{
					if(tailX[k] == j && tailY[k] == i)
					{
						std::cout << "o";
						bPrint = true;
					}
				}
				if(!bPrint)
					std::cout << " ";
			}
			if(j == WIDTH - 1)
				std::cout << "#";
		}
		std::cout << std::endl;
	}

	// print bottom row
	for(int i = 0; i < WIDTH + 1; i++)
		std::cout << "#";
	std::cout << std::endl;

	// print score
	std::cout << "Score: " << score << std::endl;
}

void Input()
{
	if(_kbhit()) // if user press the key
	{
		switch(_getch()) // check which key was pressed
		{
		case 'a':
			if(dir != RIGHT)
				dir = LEFT;
			break;
		case 'd':
			if(dir != LEFT)
				dir = RIGHT;
			break;
		case 'w':
			if(dir != DOWN)
				dir = UP;
			break;
		case 's':
			if(dir != UP)
				dir = DOWN;
			break;
		case 'x':
			bGameOver = true;
			break;
		}
	}
}

void Logic()
{
	// update coordinates of elements of the tail
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

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

	if(x >= WIDTH)
		x = 0;
	else if(x < 0)
		x = WIDTH;
	if(y >= HEIGHT)
		y = 0;
	else if(y < 0)
		y = HEIGHT;

	// finish game when snake eats his own tail
	for(int i = 0; i < nTail; i++)
		if(tailX[i] == x && tailY[i] == y)
			bGameOver = true;

	// increase the score when snake eats the fruit and set new location of the fruit
	if(x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		nTail++;
	}
}