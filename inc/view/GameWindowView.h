/*
 * GameView.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMEWINDOWVIEW_H_
#define GAMEWINDOWVIEW_H_

#include "../engine/GameEngine.h"

namespace View
{
	class GameWindowView
	{
	public:
		GameWindowView();
		~GameWindowView();
		void UpdateWindow(SDL_Surface*& window);
		void DrawImage(SDL_Surface*& img, SDL_Surface*& window);
	};
}


#endif /* GAMEWINDOWVIEW_H_ */
