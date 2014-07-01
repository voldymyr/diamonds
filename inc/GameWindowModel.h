/*
 * GameWindowModel.h
 *
 * Currently this class is dependent on the SDL library
 * It should be abstracted from SDL by GraphicsEngine
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
		void SetBackGroundIMG(SDL_Surface **img);
		SDL_Surface* GetBackGroundIMG(void);
		void SetBackGroundRect(SDL_Rect *rect);
		SDL_Rect GetBackGroundRect(void);
		void SetTextFont(TTF_Font **font);
		TTF_Font* GetTextFont(void);
		void SetTextColor(SDL_Color *color);
		SDL_Color GetTextColor(void);
		void SetGameOverStr(SDL_Surface ** surfaceStr);
		SDL_Surface* GetGameOverStr(void);
		void SetGameOverRect(SDL_Rect *rect);
		SDL_Rect GetGameOverRect(void);

	protected:
		SDL_Surface* mainWindow;
		SDL_Surface* backGroundIMG;
		SDL_Rect backGroundRect;
		TTF_Font* textFont;
		SDL_Color textColor;
		SDL_Surface* gameOverStr;
		SDL_Rect gameOverRect;
	};
}

#endif /* GAMEWINDOWMODEL_H_ */
