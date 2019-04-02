#include <iostream>
#include <SDL.h>
#include "rule.h"
#include <SDL_ttf.h>
using namespace std;
void rendergame(SDL_Window* window, SDL_Renderer* renderer, const SDL_Rect& filled_rect1, const SDL_Rect& filled_rect2,SDL_Rect& filled_rect3,SDL_Event event, int m,int time){
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderFillRect(renderer, &filled_rect1);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &filled_rect2);



    SDL_SetRenderDrawColor(renderer, 225, 0, 0, 255);
    SDL_Rect mill;
    mill.x = 0;
    mill.y = 0;
    mill.w = 400;
    mill.h = 400;
    SDL_RenderDrawRect(renderer,& mill);

    SDL_Rect nill;
    nill.x = 400;
    nill.y = 0;
    nill.w = 200;
    nill.h = 600;
    SDL_SetRenderDrawColor(renderer, 0, 250, 200, 255);
    SDL_RenderFillRect(renderer,& nill);



    SDL_Rect qill;
    qill.x = 0;
    qill.y = 400;
    qill.w = 600;
    qill.h = 200;
    SDL_SetRenderDrawColor(renderer, 0, 250, 200, 255);
    SDL_RenderFillRect(renderer,& qill);

    SDL_Rect aill;
    aill.x = 450;
    aill.y = 20;
    aill.w = 100;
    aill.h = 30;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer,& aill);

    SDL_Rect bill;
    bill.x = 450;
    bill.y = 80;
    bill.w = 100;
    bill.h = 30;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer,& bill);

    /*SDL_Rect enemy;
    enemy.y = 370;
    enemy.w = 20;
    enemy.h = 20;
    enemy.x = 30;*/
    if(((time/1000)/10)%2== 0){
        filled_rect3.x = 30 + ((time/1000)%10)*10 ;
    } else {
        filled_rect3.x = 110 - ((time/1000)%10)*10;
    }
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer,& filled_rect3);

    SDL_SetRenderDrawColor(renderer, 220, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer, 220, 0, 0, 255);

    SDL_RenderDrawLine(renderer,30,30,30,80);
    SDL_RenderDrawLine(renderer,30,80,70,80);
    SDL_RenderDrawLine(renderer,70,80,70,160);
    SDL_RenderDrawLine(renderer,0,120,30,120);
    SDL_RenderDrawLine(renderer,0,160,190,160);
    SDL_RenderDrawLine(renderer,70,30,70,0);
    SDL_RenderDrawLine(renderer,70,30,110,30);
    SDL_RenderDrawLine(renderer,110,30,110,120);
    SDL_RenderDrawLine(renderer,110,120,150,120);
    SDL_RenderDrawLine(renderer,150,120,150,80);
    SDL_RenderDrawLine(renderer,150,80,230,80);
    SDL_RenderDrawLine(renderer,150,30,230,30);
    SDL_RenderDrawLine(renderer,190,160,190,120);
    SDL_RenderDrawLine(renderer,230,30,230,0);
    SDL_RenderDrawLine(renderer,230,80,230,160);
    SDL_RenderDrawLine(renderer,230,160,350,160);
    SDL_RenderDrawLine(renderer,270,30,270,120);
    SDL_RenderDrawLine(renderer,270,120,400,120);
    SDL_RenderDrawLine(renderer,310,0,310,80);
    SDL_RenderDrawLine(renderer,350,30,350,120);
    SDL_RenderDrawLine(renderer,190,160,190,200);
    SDL_RenderDrawLine(renderer,350,160,350,180);
    SDL_RenderDrawLine(renderer,110,200,190,200);
    SDL_RenderDrawLine(renderer,270,200,310,200);
    SDL_RenderDrawLine(renderer,230,160,230,240);
    SDL_RenderDrawLine(renderer,310,200,310,220);
    SDL_RenderDrawLine(renderer,310,220,400,220);
    SDL_RenderDrawLine(renderer,30,200,30,320);
    SDL_RenderDrawLine(renderer,70,200,70,280);
    SDL_RenderDrawLine(renderer,110,200,110,280);
    SDL_RenderDrawLine(renderer,150,240,270,240);
    SDL_RenderDrawLine(renderer,270,260,370,260);
    SDL_RenderDrawLine(renderer,270,240,270,260);
    SDL_RenderDrawLine(renderer,70,280,230,280);
    SDL_RenderDrawLine(renderer,230,280,230,300);
    SDL_RenderDrawLine(renderer,230,300,330,300);
    SDL_RenderDrawLine(renderer,370,260,370,300);
    SDL_RenderDrawLine(renderer,330,300,330,370);
    SDL_RenderDrawLine(renderer,330,340,370,340);
    SDL_RenderDrawLine(renderer,30,320,190,320);
    SDL_RenderDrawLine(renderer,190,320,190,360);
    SDL_RenderDrawLine(renderer,190,360,0,360);
    SDL_RenderDrawLine(renderer,190,340,290,340);
    SDL_RenderDrawLine(renderer,270,340,270,370);
    SDL_RenderDrawLine(renderer,230,380,230,400);

    SDL_Color Black = { 0, 0, 0 };

	TTF_Font* font = TTF_OpenFont((char*)"lightitalic.ttf", 30);
	if (font == NULL) {
		cout << "Font loading error" << endl;
		return;
	}


    SDL_Surface* score = TTF_RenderText_Solid(font, ( to_string(m*1000)).c_str(), Black);
	SDL_Texture* scoreMessage = SDL_CreateTextureFromSurface(renderer, score);
	int a;
	if(m < 1){
        a= 1;
	}
	else if(m >= 1 && m < 10){
        a= 4;
	}
	else if(m >= 10){
        a = 5;
	}


	SDL_Rect scoreRect;
	scoreRect.w = 15*a;
	scoreRect.h = 30;
	scoreRect.y = 20;
	if(m >= 1){
        scoreRect.x = 485;
	} else {
        scoreRect.x = 530;
	}
	SDL_RenderCopy(renderer, scoreMessage, NULL, &scoreRect);

    int aa = 180 - time/1000;
	int minute = aa/60;
    int second = aa - (minute*60);
    SDL_Surface* Mytime;
    if(second >= 10){
    Mytime = TTF_RenderText_Solid(font, ( to_string(minute) +":"+ to_string(second)).c_str(), Black);
    } else {
    Mytime = TTF_RenderText_Solid(font, ( to_string(minute) +":0"+ to_string(second)).c_str(), Black);
    }
    SDL_Texture* timeMessage = SDL_CreateTextureFromSurface(renderer, Mytime);
	SDL_Rect timeRect;
	timeRect.w = 50;
	timeRect.h = 30;
	timeRect.x = 480;
	timeRect.y = 80;
	SDL_RenderCopy(renderer, timeMessage, NULL, &timeRect);
    SDL_RenderPresent(renderer);
    TTF_CloseFont(font);
    SDL_DestroyTexture(timeMessage);

}
