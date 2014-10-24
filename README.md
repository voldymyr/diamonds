Puzzle game where player needs to match elements of the same type

How To Install, Compile and Run on Linux

The game is based on SDL library and its additions, such as SDL_image, SDL_mixer, SDL_ttf

1. In order to compile the game you need to install above mentioned libraries. Use provided python script to install them. Type this into terminal: python sdl2Install.py

2. g++ compiler has to be intalled prior to compilation. Type the following into terminal: sudo apt-get install g++

3. Now compile the code using provided Makefile. Type this into terminal: make

4. After successful compilation, game executable file will be located in Release folder. To run the game, type this into terminal: ./diamonds