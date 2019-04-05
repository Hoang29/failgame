#include <iostream>
#include <SDL.h>
#include "SDL_utils.h"
#include <cstdlib>
#include <SDL_ttf.h>
#include "rule.h"
#include <thread>
#include <chrono>

using namespace std;


int main(int argc, char* argv[])
{

    while(true){
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SDL_Event e;
    mybegin(renderer,e);

    SDL_Rect filled_rect;
    filled_rect.x = 0;
    filled_rect.y = 0;
    filled_rect.w = 20;
    filled_rect.h = 20;

    SDL_Rect food;
    food.x = 80;
    food.y = 90;
    food.w = 10;
    food.h = 10;

    SDL_Rect enemy;
    enemy.y = 330;
    enemy.w = 20;
    enemy.h = 20;
    enemy.x = 5;

    SDL_Rect enemy2;
    enemy2.y = 130;
    enemy2.w = 20;
    enemy2.h = 20;
    enemy2.x = 240;

    SDL_Rect enemy3;
    enemy3.y = 230;
    enemy3.w = 20;
    enemy3.h = 20;
    enemy3.x = 380;

    int step = 5;
    int m = 0;

    if(e.type == SDL_QUIT) break;

    while (true) {
        SDL_Delay(10);

        while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT) exit(0);
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        break;
                    case SDLK_LEFT: filled_rect.x = (filled_rect.x + SCREEN_WIDTH - step) % SCREEN_WIDTH;
                        break;
                    case SDLK_RIGHT: filled_rect.x = (filled_rect.x + step) % SCREEN_WIDTH;
                        break;
                    case SDLK_DOWN: filled_rect.y = (filled_rect.y + step) % SCREEN_HEIGHT;
                        break;
                    case SDLK_UP: filled_rect.y = (filled_rect.y + SCREEN_HEIGHT - step) % SCREEN_HEIGHT;
                        break;
                    default: break;
                }


            }
            if(eat(filled_rect.x, filled_rect.y, food.x, food.y)){
                   food.x = rand() % (400 - food.x) + 40;
                   food.y = rand() % (400 - food.y) + 40 ;
                    m++;
            }


        }

        if(lose(filled_rect.x, filled_rect.y)){
            gameOver(renderer, e,m);
            break;
        }

        if(death(filled_rect,enemy) || death(filled_rect,enemy2) || death(filled_rect,enemy3)){
            gameOver(renderer, e,m);
            break;
        }
        int current = SDL_GetTicks();

        if(current >= 180000){
            gameOver(renderer,e,m);
            break;
        }
        rendergame(window, renderer, filled_rect,food,enemy,enemy2,enemy3,e,m,current);
    }

    quitSDL(window, renderer);
    }
    return 0;
}




