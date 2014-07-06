/*
 * LogicsController.h
 *
 *  Created on: Jun 29, 2014
 *      Author: voldymyr
 */

#ifndef LOGICSCONTROLLER_H_
#define LOGICSCONTROLLER_H_

#include "../model/GameBoardModel.h"
//#include "../view/GameBoardView.h"

namespace Controller
{
	class LogicsController
	{
	public:
		LogicsController();
		~LogicsController();

	private:
		bool allowSwap;
		bool allowSwapBack;
		bool allowMoveDown;
		bool allowDropNew;
	};
}


#endif /* LOGICSCONTROLLER_H_ */
