#ifndef SDL_H
#define SDL_H

#include <iostream>
#include <SDL.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char WINDOW_TITLE[] = "MYGAME";
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
	int screenWidth, int screenHeight, const char* windowTitle) ;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();
#endif // SDL_H

