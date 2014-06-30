/*
 * Driver.cpp
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#include <cstdlib>
#include <cstdio>

#include "../inc/GameController.h"

int main(int argc, char** argv)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Could not init SDL library.");
		exit(-1);
	}

	printf("Hello World!");
	return 0;
}

