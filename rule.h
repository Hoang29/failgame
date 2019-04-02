#ifndef RULE_H
#define RULE_H

#include <iostream>
#include <SDL.h>

bool lose(int x,int y);
bool eat(int x,int y,int xf, int yf);
bool death(SDL_Rect a,SDL_Rect b);

void gameOver(SDL_Renderer* renderer,SDL_Event event,int m);

void mybegin(SDL_Renderer* renderer,SDL_Event event);

void rendergame(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect1, const SDL_Rect& filled_rect2,SDL_Rect& filled_rect3,SDL_Event event, int m,int time);


#endif // RULE_H
