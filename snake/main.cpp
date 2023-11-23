#include <iostream>
#include <ncursesw/curses.h>
#include "Square.hpp"
#include "Game.hpp"
#include "Draw.hpp"

//boję się wkładać polskie znaczki w kod, a polski bez znaczków to herezja thus wszystko po angielsku
#define squaresize 16
#define height squaresize
#define width squaresize * 2

int main(int argc, char **argv){
	int hs = 0;
	initscr();
	refresh();
	
	noecho();
	curs_set(0);
	skok:;
	Game game(height, width, hs);
	
	while(!game.isover()){
		game.useinput();
		
		game.update();
		
		game.redraw();
		
	}
	
	if(hs < game.getscore())
		hs = game.getscore();
	if (!game.isexit())
		goto skok;
	
	getch();
	endwin();
	return 0;
}