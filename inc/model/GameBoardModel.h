/*
 * GameBoardModel.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMEBOARDMODEL_H_
#define GAMEBOARDMODEL_H_

#include "../Common.h"
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

	class GameBoard
	{
	public:
		GameBoard();
		~GameBoard();
	};
}


#endif /* GAMEBOARDMODEL_H_ */
