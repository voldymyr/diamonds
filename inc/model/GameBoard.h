/*
 * GameBoard.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include "../inc/Common.h"
#include <map>
#include <vector>

namespace Model
{
	struct BoardElement
	{
		int id;
		ElementType type;
		int value;
		float x;
		float y;
	};
}


#endif /* GAMEBOARD_H_ */
