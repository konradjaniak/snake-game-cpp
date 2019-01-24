#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

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
		//Sleep(10);
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
	/* Print top row */
	for(int i = 0; i < WIDTH + 1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	/* Print side walls */
	for(int i = 0; i < HEIGHT; i++)
	{
		for(int j = 0; j < WIDTH; j++)
		{
			if(j == 0)
				std::cout << "#";
			else
				std::cout << " ";
			if(j == WIDTH - 1)
				std::cout << "#";
		}
		std::cout << std::endl;
	}
	/* Print bottom row */
	for(int i = 0; i < WIDTH + 1; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
}

/* ----------------------------- */
void Input()
{

}

/* ----------------------------- */
void Logic()
{

}
