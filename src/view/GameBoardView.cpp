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
		SDL_BlitSurface(imgs[elements[i].type], &elements[i].pos, window, NULL);
	}
}
