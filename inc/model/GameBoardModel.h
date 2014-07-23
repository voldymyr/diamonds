/*
 * GameBoardModel.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef GAMEBOARDMODEL_H_
#define GAMEBOARDMODEL_H_

#include "../Common.h"
#include "../engine/GameEngine.h"
#include <map>
#include <vector>

namespace Model
{
	struct BoardElement
	{
		int id;
		ElementType type;
		int value;
		SDL_Rect pos;
	};

	class GameBoardModel
	{
	public:
		GameBoardModel();
		~GameBoardModel();

		void InitLevelModel(vector<BoardElement>& lm);
		vector<BoardElement> GetLevelModel() const;

		void InitBoardElements(vector<BoardElement>& be);
		vector<BoardElement> GetBoardElements() const;

		BoardElement GetLevelModelElementByID(int id) const;
		BoardElement GetBoardElementByID(int id) const;
		void SetBoardElementByID(int id, BoardElement el);

		void SetElementWidth(int w);
		int GetElementWidth() const;
		void SetElementHeight(int h);
		int GetElementHeight() const;
		void SetBoardWidth(int w);
		int GetBoardWidth() const;
		void SetBoardHeight(int h);
		int GetBoardHeight() const;

		void LoadElementImages(map<ElementType, string>& imgs);
		void UnloadElementImages();

	private:
		vector<BoardElement> levelModel;
		vector<BoardElement> elements;

		int elementWidth;
		int elementHeight;

		int boardWidth;
		int boardHeight;

		// All different element images
		map<ElementType, SDL_Surface*> elementImages;

	};
}


#endif /* GAMEBOARDMODEL_H_ */
