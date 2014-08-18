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

void View::GameWindowView::UpdateWindow(SDL_Surface*& window)
{
	SDL_Flip(window);
}

void View::GameWindowView::DrawImage(SDL_Surface*& img, SDL_Surface*& window)
{
	SDL_BlitSurface(img, NULL, window, NULL);
}

void View::GameWindowView::DrawImage(SDL_Surface*& img, SDL_Rect* rect, SDL_Surface*& window)
{
	SDL_BlitSurface(img, NULL, window, rect);
}

