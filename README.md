Puzzle game where player needs to match elements of the same type

How To Install, Compile and Run on Linux

The game is based on SDL library and its additions, such as SDL_image, SDL_mixer, SDL_ttf

1. In order to compile the game you need to install above mentioned libraries. On Ubuntu based linux you can type the following in the terminal: sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev

2. Eclipse has been used to create the game, so you can install it too by typing the following command into the terminal:
sudo apt-get install eclipse.

3. Next step would be to clone this repository, which can be donw with the following command:
git clone https://github.com/vovabendiuga/diamonds

4. Now open this project in Eclipse (in Eclipse you do this by creating a new project with the same name, and since the project already exists, it will just open it)

5. Navigate to Project->Properties->C/C++ General->Paths And Symbols. In the Library Paths tab add new entries such as: /usr/lib, /usr/local/lib or other path if you installed libraries somewhere else.

6. In the Libraries tab add libraries one by one: SDL, SDL_image, SDL_mixer, SDL_ttf

7. Now compile and run the game
