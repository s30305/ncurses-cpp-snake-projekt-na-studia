#pragma once
#include <ncursesw/curses.h>
#include "Draw.hpp"


class Empty : public Draw
{
public:
	Empty(int y, int x){
		this->y = y;
		this->x = x;
		this->sign = ' ';
	}
};