/*
 * GameWindowModel.h
 *
 *
 *  Created on: Jun 30, 2014
 *      Author: khrystynka
 */

#ifndef GAMEWINDOWMODEL_H_
#define GAMEWINDOWMODEL_H_

#include "../Common.h"
#include "../engine/GameEngine.h"

namespace Model
{
	class GameWindowModel
	{
	public:
		GameWindowModel(void);
		~GameWindowModel(void);
		void SetWindowWidth(int width);
		int GetWindowWidth(void);
		void SetWindowHeight(int height);
		int GetWindowHeight(void);
		void SetMainWindow(int x, int y, int bpp, Uint32 flags);
		SDL_Surface* GetMainWindow(void);
		void SetMainWindowCaption(const char* title, const char* img);
		void SetBackGroundIMG(const char* img);
		SDL_Surface* GetBackGroundIMG(void);
		void SetBackGroundRect(SDL_Rect *rect);
		SDL_Rect GetBackGroundRect(void);
		void SetTextFont(TTF_Font *&font);
		TTF_Font* GetTextFont(void);
		void SetTextColor(SDL_Color *color);
		SDL_Color GetTextColor(void);
		void SetGameOverStr(SDL_Surface ** surfaceStr);
		SDL_Surface* GetGameOverStr(void);
		void SetGameOverRect(SDL_Rect *rect);
		SDL_Rect GetGameOverRect(void);
		void SetNoMoreMovesStr(SDL_Surface** surfaceStr);
		SDL_Surface* GetNoMoreMovesStr(void);
		void SetNoMoreMovesRect(SDL_Rect *rect);
		SDL_Rect GetNoMoreMovesRect(void);
		void SetTimeSurface(SDL_Surface** surf);
		SDL_Surface* GetTimeSurface();
		void SetScoreSurface(SDL_Surface** surf);
		SDL_Surface* GetScoreSurface();

		bool GetUserInteraction();
		void SetUserInteraction(bool inter);

	private:
		int windowWidth;
		int windowHeight;
		SDL_Surface* mainWindow;
		SDL_Surface* backGroundIMG;
		SDL_Rect backGroundRect;
		TTF_Font* textFont;
		SDL_Color textColor;
		SDL_Surface* gameOverStr;
		SDL_Rect gameOverRect;
		SDL_Surface* noMoreMovesStr;
		SDL_Rect noMoreMovesRect;
		SDL_Surface* timeSurface;
		SDL_Surface* scoreSurface;
		bool userInteractionAllowed;
	};
}

#endif /* GAMEWINDOWMODEL_H_ */
