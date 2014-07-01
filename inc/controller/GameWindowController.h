/*
 * GameWindowController.h
 *
 *  Created on: Jul 1, 2014
 *      Author: khrystynka
 */

#ifndef GAMEWINDOWCONTROLLER_H_
#define GAMEWINDOWCONTROLLER_H_

#include "../model/GameWindowModel.h"
#include "../view/GameWindowView.h"

namespace Controller
{
	class GameWindowController
	{
	public:
		GameWindowController();
		~GameWindowController();
		void LoadBackgroundImage(const char *img);
		void DrawBackgroundImage();

	private:
		Model::GameWindowModel *gameWindowModel;
		View::GameWindowView *gameWindowView;
	};
}


#endif /* GAMEWINDOWCONTROLLER_H_ */
