#include <ncurses.h>
#include "drawNode.h"
#include "config.h"

static int getHeight(int level)
{
	if(level == 1)
		return 0;

	if(level == 2)
		return 3;

	if(level == 3)
		return 6;

	if(level == 4)
		return 9;

	if(level == 5)
		return 12;

	if(level == 6)
		return 15;
}

static int getLevel(int index)
{
	if(index == 1)
		return 1;

	if(index >= 2 && index <= 3)
		return 2;

	if(index >= 4 && index <= 7)
		return 3;

	if(index >= 8 && index <= 15)
		return 4;

	if(index >= 16 && index <= 31)
		return 5;

	if(index >= 32 && index <= 61)
		return 6;
}


static float simple_pow(float e, int n)
{
	int flag = 0;

	if(n < 0)
	{
		n *= -1;
		flag = 1;
	}

	float result = 1.0f;
	while(n>0)
	{
		result *= e;
		--n;
	}

	if(flag)
	{
		result = 1 / result;
	}

	return result;
}


static bool isOnLeft(int index)
{
	int level = getLevel(index);
	float value = 3 * simple_pow(2, level-2);
	if(index < value)
	{
		return true;
	}
	else
	{
		return false;		
	}
}

int getBaseIndex(int index)
{
	int level = getLevel(index);
	return simple_pow(2, level-1);
}

float getBaseCoord(int index)
{
	int level = getLevel(index);

	/*
	   bool isLeft = isOnLeft(index);
	   float length = 1 / simple_pow(2, level-2) * LEAF_MARGIN;
	 */

	switch(level)
	{
		case 1:
			return 0;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 3.5;
		case 5:
			return 3.75;

		case 6:
			return 3.875;
	}

}

void drawNode(int index, int data)
{
	if(index <= 0 || index >= 32)
		//	if(index <= 0 || index >= 64)
		return;


	int i;
	int level = getLevel(index);
	int height = getHeight(level);
	int offset = index - getBaseIndex(index);	
	float coord = getBaseCoord(index) * LEAF_MARGIN;
	coord = COLS/2 - coord;

	float length = 1 / simple_pow(2, level-2) * LEAF_MARGIN;
	float center = 0.0f;
	while(offset--)
	{
		center += length * 4;
	}

	center += coord;

	int left = center - length;
	int right = center + length;

	move(height, (int)center);
	printw("%d", data);
	move(height+1, left);

	if(index <= MAX_NODE)
	{
		i = length;
		while(i--)
			printw("%c", '_');		

		printw("%c", '|');

		i = length;
		while(i--)
			printw("%c", '_');		

		move(height+2, left);
		printw("%c", '|');

		move(height+2, right);
		printw("%c", '|');
	}

}
