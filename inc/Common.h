/*
 * Common.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>

using namespace std;

/* Types of elements on the game board */
enum ElementType {Yellow = 10, Green = 20, Blue = 30, Purple = 40, Red = 50, None = 60};

/* Common structure representing position of objects on the 2D game board */
struct Position
{
	float x;
	float y;
};

#endif /* COMMON_H_ */
