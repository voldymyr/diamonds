/*
 * GameBoardView.h
 *
 *  Created on: Jul 7, 2014
 *      Author: khrystynka
 */

#ifndef GAMEBOARDVIEW_H_
#define GAMEBOARDVIEW_H_

#include "../Common.h"
#include "../engine/GameEngine.h"
#include "../model/GameBoardModel.h"

namespace View
{
	class GameBoardView
	{
	public:
		GameBoardView();
		~GameBoardView();

		void DrawElements(SDL_Surface*& window, map<ElementType, SDL_Surface*>& imgs, vector<Model::BoardElement>& elements);
	};
}


#endif /* GAMEBOARDVIEW_H_ */
