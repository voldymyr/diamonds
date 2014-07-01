/*
 * GameWindowView.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: khrystynka
 */


#include "../../inc/view/GameWindowView.h"

View::GameWindowView::GameWindowView()
{

}

View::GameWindowView::~GameWindowView()
{

}

void View::GameWindowView::UpdateWindow(SDL_Surface **window)
{
	SDL_Flip(*window);
}

void View::GameWindowView::DrawBackground(SDL_Surface **img, SDL_Surface **window, int x, int y)
{
	SDL_Rect tmpRect;
	tmpRect.x = x;
	tmpRect.y = y;

	SDL_BlitSurface(*img, NULL, *window, &tmpRect);
}

