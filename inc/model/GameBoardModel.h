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

	class GameBoardModel
	{
	public:
		GameBoardModel();
		~GameBoardModel();

		vector<BoardElement> GetLevelModel() const;
		vector<BoardElement> GetBoardElements() const;
		BoardElement GetLevelModelElementByID(int id) const;
		BoardElement GetBoardElementByID(int id) const;

	private:
		vector<BoardElement> levelModel;
		vector<BoardElement> elements;

	};
}


#endif /* GAMEBOARDMODEL_H_ */
