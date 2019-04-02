#include <iostream>
#include <SDL.h>
#include "rule.h"
#include <SDL_ttf.h>
using namespace std;


void gameOver(SDL_Renderer* renderer,SDL_Event event,int m)
{
    SDL_Color Red = { 255, 0, 0 };
	SDL_Color White = { 255, 255, 255 };
	SDL_Color Black = { 0, 0, 0 };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

	TTF_Font* font = TTF_OpenFont((char*)"lightitalic.ttf", 30);
	if (font == NULL) {

		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* gameover = TTF_RenderText_Solid(font, "Game Over", Red);
    SDL_Surface* retry = TTF_RenderText_Solid(font, "Press enter to retry", Black);
    SDL_Surface* point = TTF_RenderText_Solid(font, ( to_string(m*1000)).c_str(), Black);

	SDL_Texture* gameoverMessage = SDL_CreateTextureFromSurface(renderer, gameover);
    SDL_Texture* retryMessage = SDL_CreateTextureFromSurface(renderer, retry);
	SDL_Texture* pointMessage = SDL_CreateTextureFromSurface(renderer, point);

	SDL_Rect gameoverRect;

	gameoverRect.w = 200;
	gameoverRect.h = 100;
	gameoverRect.x = 200;
	gameoverRect.y = 100;

	SDL_Rect retryRect;

	retryRect.w = 425;
	retryRect.h = 100;
	retryRect.x = 87;
	retryRect.y = 200;

    int a;
	if(m < 1){
        a= 1;
	} else {
        a= 4;
	}
	SDL_Rect pointRect;

	pointRect.w = 25*a;
	pointRect.h = 40;
	pointRect.x = 250;
	pointRect.y = 330;

	SDL_RenderCopy(renderer, gameoverMessage, NULL, &gameoverRect);
    SDL_RenderCopy(renderer, retryMessage, NULL, &retryRect);
    SDL_RenderCopy(renderer, pointMessage, NULL, &pointRect);
	TTF_CloseFont(font);


	while (true) {
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit(0);
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}
		}
	}

}

void mybegin(SDL_Renderer* renderer,SDL_Event event)
{
    SDL_Color Red = { 255, 0, 0 };
	SDL_Color White = { 255, 255, 255 };
	SDL_Color Black = { 0, 0, 0 };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

	TTF_Font* font = TTF_OpenFont((char*)"lamba.ttf", 30);
	if (font == NULL) {

		cout << "Font loading error" << endl;
		return;
	}

	SDL_Surface* mybegin1 = TTF_RenderText_Solid(font, "aaa", Black);
    SDL_Surface* mybegin2 = TTF_RenderText_Solid(font, "press enter to start", Black);
	SDL_Texture* beginMessage = SDL_CreateTextureFromSurface(renderer, mybegin1);
    SDL_Texture* beginMessage2 = SDL_CreateTextureFromSurface(renderer, mybegin2);
	SDL_Rect beginRect;
	beginRect.w = 200;
	beginRect.h = 100;
	beginRect.x = 200;
	beginRect.y = 100;

	SDL_Rect beginRect2;
	beginRect2.w = 400;
	beginRect2.h = 100;
	beginRect2.x = 100;
	beginRect2.y = 400;

	SDL_RenderCopy(renderer, beginMessage, NULL, &beginRect);
	SDL_RenderCopy(renderer, beginMessage2, NULL, &beginRect2);
	TTF_CloseFont(font);


	while (true) {
		SDL_RenderPresent(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				exit(0);
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				return;
			}
		}
	}

}


