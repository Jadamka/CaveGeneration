#ifndef CAVE_H
#define CAVE_H

#define MAP_WIDTH 100
#define MAP_HEIGHT 60

void genCave();
int nearCell(int x, int y);
void cellularAutomata();
void displayCave();

#endif