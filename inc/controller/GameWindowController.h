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
		SDL_Surface* GetMainWindow() const;
		void LoadFont(TTF_Font*& font);
		void LoadColor(SDL_Color* color);
		void LoadNoMoreMoves(const char* str, int w, int h, int x, int y);
		void DispatchDrawNoMoreMoves();
		void LoadGameOver(const char* str, int w, int h, int x, int y);
		void DispatchDrawGameOver();
		void LoadTime(const char* timeStr);
		void DispatchDrawTime();
		void LoadScore(const char* scoreStr);
		void DispatchDrawScore();

	private:
		Model::GameWindowModel *gameWindowModel;
		View::GameWindowView *gameWindowView;
	};
}


#endif /* GAMEWINDOWCONTROLLER_H_ */
