CFLAGS = -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF

diamonds: src/view/GameBoardView.o src/view/GameWindowView.o  src/model/GameBoardModel.o src/model/GameWindowModel.o src/engine/GameEngine.o  src/controller/GameWindowController.o src/controller/LogicsController.o src/Driver.o src/Game.o
	g++ -o Release/diamonds src/view/GameBoardView.o src/view/GameWindowView.o src/model/GameBoardModel.o src/model/GameWindowModel.o src/engine/GameEngine.o src/controller/GameWindowController.o src/controller/LogicsController.o src/Driver.o src/Game.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

Game.o: src/Game.d -MT src/Game.d src/Game.cpp
	g++ -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/Game.d -MT src/Game.d src/Game.cpp

Driver.o: src/Driver.d -MT src/Driver.d src/Driver.cpp
	g++ -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/Driver.d -MT src/Driver.d -o src/Driver.o src/Driver.cpp

LogicsController.o: src/controller/LogicsController.d -MT src/controller/LogicsController.d src/controller/LogicsController.cpp
	g++ $(CFLAGS) src/controller/LogicsController.d -MT src/controller/LogicsController.d -o src/controller/LogicsController.o src/controller/LogicsController.cpp

GameWindowController.o: src/controller/GameWindowController.d -MT src/controller/GameWindowController.d src/controller/GameWindowController.cpp
	g++ $(CFLAGS) src/controller/GameWindowController.d -MT src/controller/GameWindowController.d -o src/controller/GameWindowController.o src/controller/GameWindowController.cpp

GameEngine.o: src/engine/GameEngine.d -MT src/engine/GameEngine.d src/engine/GameEngine.cpp
	g++ $(CFLAGS) src/engine/GameEngine.d -MT src/engine/GameEngine.d -o src/engine/GameEngine.o src/engine/GameEngine.cpp

GameWindowModel.o: src/model/GameWindowModel.d -MT src/model/GameWindowModel.d src/model/GameWindowModel.cpp
	g++ $(CFLAGS) src/model/GameWindowModel.d -MT src/model/GameWindowModel.d -o src/model/GameWindowModel.o src/model/GameWindowModel.cpp

GameBoardModel.o: src/model/GameBoardModel.d -MT src/model/GameBoardModel.d src/model/GameBoardModel.cpp
	g++ $(CFLAGS) src/model/GameBoardModel.d -MT src/model/GameBoardModel.d -o src/model/GameBoardModel.o src/model/GameBoardModel.cpp

GameWindowView.o: src/view/GameWindowView.d -MT src/view/GameWindowView.d src/view/GameWindowView.cpp
	g++ $(CFLAGS) src/view/GameWindowView.d -MT src/view/GameWindowView.d -o src/view/GameWindowView.o src/view/GameWindowView.cpp

GameBoardView.o: src/view/GameBoardView.d -MT src/view/GameBoardView.d src/view/GameBoardView.cpp
	g++ $(CFLAGS) src/view/GameBoardView.d -MT src/view/GameBoardView.d -o src/view/GameBoardView.o src/view/GameBoardView.cpp

clean:
	rm -f Release/diamonds 
	rm -f src/*.o 
	rm -f src/controller/*.o 
	rm -f src/engine/*.o 
	rm -f src/model/*.o 
	rm -f src/view/*.o