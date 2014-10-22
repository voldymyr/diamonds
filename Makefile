os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/view/GameBoardView.d -MT src/view/GameBoardView.d -o src/view/GameBoardView.o src/view/GameBoardView.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/view/GameWindowView.d -MT src/view/GameWindowView.d -o src/view/GameWindowView.o src/view/GameWindowView.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/model/GameBoardModel.d -MT src/model/GameBoardModel.d -o src/model/GameBoardModel.o src/model/GameBoardModel.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/model/GameWindowModel.d -MT src/model/GameWindowModel.d -o src/model/GameWindowModel.o src/model/GameWindowModel.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/engine/GameEngine.d -MT src/engine/GameEngine.d -o src/engine/GameEngine.o src/engine/GameEngine.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/controller/GameWindowController.d -MT src/controller/GameWindowController.d -o src/controller/GameWindowController.o src/controller/GameWindowController.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/controller/LogicsController.d -MT src/controller/LogicsController.d -o src/controller/LogicsController.o src/controller/LogicsController.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/Driver.d -MT src/Driver.d -o src/Driver.o src/Driver.cpp")
os.system("g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF src/Game.d -MT src/Game.d -o src/Game.o src/Game.cpp")

print "\n\t\t***** DONE *****\n"
print "\n\t\t***** LINKING *****\n"
os.system("g++ -o Release/diamonds ./src/view/GameBoardView.o ./src/view/GameWindowView.o  ./src/model/GameBoardModel.o ./src/model/GameWindowModel.o ./src/engine/GameEngine.o  ./src/controller/GameWindowController.o ./src/controller/LogicsController.o ./src/Driver.o ./src/Game.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf")
