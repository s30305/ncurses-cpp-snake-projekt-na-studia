#pragma once
#include <ncursesw/curses.h>
#include "Draw.hpp"


class Apple : public Draw
{
public:
	Apple(int y, int x){
		this->y = y;
		this->x = x;
		this->sign = '@';
	}
};