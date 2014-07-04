/**
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
		void DispatchSetBackgroundImage(const char *img);
		void DispatchDrawBackgroundImage();
		void DispatchUpdateWindow();
		void DispatchSetMainWindow(int x, int y, int bpp, Uint32 flags);
		void DispatchSetMainWindowCaption(const char* title, const char* icon);
		bool GetUserInteractionStatus();
		void SetUserInteractionStatus(bool status);

	private:
		Model::GameWindowModel *gameWindowModel;
		View::GameWindowView *gameWindowView;
	};
}


#endif /* GAMEWINDOWCONTROLLER_H_ */
