/*
 * GameBoardView.cpp
 *
 *  Created on: Jul 7, 2014
 *      Author: khrystynka
 */

#include "../../inc/view/GameBoardView.h"


View::GameBoardView::GameBoardView()
{
}

View::GameBoardView::~GameBoardView()
{
}

void View::GameBoardView::DrawElements(SDL_Surface*& window, map<ElementType, SDL_Surface*>& imgs, vector<Model::BoardElement>& elements)
{
	for(unsigned int i = 0; i < elements.size(); i++)
	{
		if(elements[i].type == None)
			continue;
		else
		{
			if(SDL_BlitSurface(imgs[elements[i].type], NULL, window, &elements[i].pos) < 0)
				cout << "Could not blitSurface!" << endl;
		}
	}
}
