#pragma once
#include <ncursesw/curses.h>

class Draw{
	public:
		Draw(){
			y = x = 0;
			sign = ' ';      //kolejny default
		}
		
		Draw(int y, int x, chtype ch){
			this->y = y;
			this->x = x;
			this->sign = ch;
		}
		
		int getx(){
			return x;
		}
		
		int gety(){
			return y;
		}
		
		chtype getsign(){
			return sign;
		}
		
	protected:
		int y, x;
		chtype sign;
};