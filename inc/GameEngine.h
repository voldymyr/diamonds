/*
 * GameEngine.h
 *
 * GameEngine is an engine of the game which incorporates graphics engine
 * GameEngine has control over all Models and operations with them as well as
 * View of the game.
 *
 * GameEngine consists of different controllers, such as EventController for processing
 * user events, Logics Controller for processing all game logics, GameWindowController
 * to control how game window is drawn and updated.
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "../inc/Common.h"
#include "../inc/EventController.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
};

#endif /* GAMEENGINE_H_ */
