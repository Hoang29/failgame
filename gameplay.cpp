#include <iostream>
#include <SDL.h>
#include "rule.h"
#include <SDL_ttf.h>
using namespace std;
bool eat(int x, int y, int xf, int yf){

  if((x == xf && y == yf)||
     ((x <= xf && x + 20 >= xf)&& (y + 20 >= yf)&&(yf >= y))||
     ((x >= xf && x <= xf + 10)&& (y + 20 >= yf)&&(yf >= y))||
     ((x <= xf && x + 20 >= xf)&& (y <= yf + 10)&&(yf <= y))||
     ((x >= xf && x <= xf + 10)&& (y <= yf + 10)&&(yf <= y))){

        return true;
    }
  else return false;
}

bool death(SDL_Rect a,SDL_Rect b){
    if((a.x == b.x && a.y == b.y)||
     ((a.x <= b.x && a.x + 20 >= b.x)&& (a.y + 20 >= b.y)&&(b.y >= a.y))||
     ((a.x >= b.x && a.x <= b.x+ 20)&& (a.y + 20 >= b.y)&&(b.y >= a.y))||
     ((a.x <= b.x && a.x + 20 >= b.x)&& (a.y <= b.y + 20)&&(b.y <= a.y))||
     ((a.x >= b.x && a.x <= b.x + 20)&& (a.y <= b.y + 20)&&(b.y <= a.y))){

        return true;
    }
  else return false;
}

bool lose(int x,int y){
  if((x <= 30 && x >= 10)&&((y >= 10)&&(y <= 80))) return true;
  else if ((x > 380)||(y > 380)) return true;
  else if ((x >= 30 && x <= 70)&&((y <= 80 && y >= 60))) return true;
  else if (((x <= 70)&&(x >= 50))&&(y >= 80 && y <= 140)) return true;
  else if ((x >= 0 && x <= 170)&&(y <= 160&&y >= 140)) return true;
  else if ((x >= 0 && x <= 30)&&(y >= 100 && y <= 120)) return true;
  else if ((x >= 50 && x <= 70)&&(y <= 30)) return true;
  else if ((x >= 50 && x <= 110)&&(y <= 30 && y >= 10 )) return true;
  else if ((x >= 90 && x <= 110)&&(y >= 10 && y <= 120)) return true;
  else if ((x >= 90 && x <= 150)&&(y <= 120 && y >= 100)) return true;
  else if ((x >= 170 && x <= 190)&&(y >= 100 && y <= 200)) return true;
  else if ((x >= 130 && x <= 150)&&(y >= 60 && y <= 120)) return true;
  else if ((x >= 130 && x <= 230)&&(y >= 60 && y <= 80)) return true;
  else if ((x >= 130 && x <= 230)&&(y >= 10 && y <= 30)) return true;
  else if ((x >= 210 && x <= 230)&&(y >= 0 && y <= 30)) return true;
  else if ((x >= 250 && x <= 270)&&(y >= 10 && y <= 120)) return true;
  else if ((x >= 250 && x <= 380)&&(y >= 100 && y <= 120)) return true;
  else if ((x >= 290 && x <= 310)&&(y >= 0 && y <= 80)) return true;
  else if ((x >= 330 && x <= 350)&&(y >= 10 && y <= 100)) return true;
  else if ((x >= 210 && x <= 230)&&(y >= 60 && y <= 240)) return true;
  else if ((x >= 210 && x <= 350)&&(y >= 140 && y <= 160)) return true;
  else if ((x >= 330 && x <= 350)&&(y >= 140 && y <= 180)) return true;
  else if ((x >= 90 && x <= 190)&&(y >= 180 && y <= 200)) return true;
  else if ((x >= 90 && x <= 110)&&(y >= 180 && y <= 280)) return true;
  else if ((x >= 50 && x <= 70)&&(y >= 180 && y <= 280)) return true;
  else if ((x >= 10 && x <= 30)&&(y >= 180 && y <= 320)) return true;
  else if ((x >= 130 && x <= 270)&&(y >= 220 && y <= 240)) return true;
  else if ((x >= 50 && x <= 230)&&(y >= 260 && y <= 280)) return true;
  else if ((x >= 10 && x <= 190)&&(y >= 300 && y <= 320)) return true;
  else if ((x >= 250 && x <= 310)&&(y >= 180 && y <= 200)) return true;
  else if ((x >= 170 && x <= 190)&&(y >= 300 && y <= 360)) return true;
  else if ((x >= 210 && x <= 230)&&(y >= 260 && y <= 300)) return true;
  else if ((x >= 250 && x <= 270)&&(y >= 220 && y <= 260)) return true;
  else if ((x >= 290 && x <= 310)&&(y >= 180 && y <= 220)) return true;
  else if ((x >= 0 && x <= 190)&&(y >= 340 && y <= 360)) return true;
  else if ((x >= 170 && x <= 290)&&(y >= 320 && y <= 340)) return true;
  else if ((x >= 210 && x <= 230)&&(y >= 360 && y <= 380)) return true;
  else if ((x >= 250 && x <= 270)&&(y >= 320 && y <= 370)) return true;
  else if ((x >= 290 && x <= 380)&&(y >= 200 && y <= 220)) return true;
  else if ((x >= 250 && x <= 370)&&(y >= 240 && y <= 260)) return true;
  else if ((x >= 210 && x <= 330)&&(y >= 280 && y <= 300)) return true;
  else if ((x >= 310 && x <= 370)&&(y >= 320 && y <= 340)) return true;
  else if ((x >= 310 && x <= 330)&&(y >= 280 && y <= 370)) return true;
  else if ((x >= 350 && x <= 370)&&(y >= 240 && y <= 300)) return true;
  else return false;
}
