/*
 * GameWindowModel.h
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#ifndef GAMEWINDOWMODEL_H_
#define GAMEWINDOWMODEL_H_

#include "../inc/GraphicsEngine.h"
#include "../inc/Common.h"

namespace Model
{
	class GameWindowModel
	{
	public:
		GameWindowModel(void);
		~GameWindowModel(void);
		void SetMainWindow(SDL_Surface **window);
		SDL_Surface* GetMainWIndow(void);

	protected:
		SDL_Surface *mainWindow;
	};
}

#endif /* GAMEWINDOWMODEL_H_ */
