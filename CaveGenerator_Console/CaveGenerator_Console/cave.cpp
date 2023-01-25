#include <iostream>

#include "cave.h"

bool alive = true;
bool map[MAP_HEIGHT][MAP_WIDTH];

int seed = time(NULL);
int aliveProb = 58;
int generations = 10;

void genCave()
{
	srand(seed);

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			map[y][x] = alive;
			if (rand() % 100 > aliveProb) 
				map[y][x] = !alive;
		}
	}
}

int nearCell(int x, int y)
{
	int count = 0;

	for (int h = y-1; h < 2+y; h++)
	{
		for (int w = x-1; w < 2+x; w++)
		{
			if (!(w == x && h == y))
				count += (int)map[h][w];
		}
	}

	return count;
}

void cellularAutomata()
{
	for (int gen = 0; gen < generations; gen++)
	{
		for (int y = 1; y < MAP_HEIGHT - 1; y++)
		{
			for (int x = 1; x < MAP_WIDTH - 1; x++)
			{
				int count = nearCell(x, y);
				if (map[y][x] == !alive && count >= 6) map[y][x] = alive;
				if (map[y][x] == alive && count <= 3) map[y][x] = !alive;
			}
		}
	}
}

void displayCave()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (map[y][x])
				std::cout << '.';
			else
				std::cout << '#';
		}
		std::cout << '\n';
	}
}