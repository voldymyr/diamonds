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
		GameWindowModel();
		~GameWindowModel();
		void SetMainWindow();

	protected:
		SDL_Surface *mainWindow;
	};
}

#endif /* GAMEWINDOWMODEL_H_ */
