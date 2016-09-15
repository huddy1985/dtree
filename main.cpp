#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "draw.h"
#include "config.h"

int main()
{
	int i;
	Node* root = 0;
	srand(time(0));
	int data;

	for(i=0; i<MAX_NODE; ++i)
	{
		root = Create(root, random()%100);	
	}

	Walk(root);
	printf("\n");

	draw(root);
}
