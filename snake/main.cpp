#include <iostream>
#include <ncursesw/curses.h>
#include "Square.hpp"
#include "Game.hpp"
#include "Draw.hpp"

//boję się wkładać polskie znaczki w kod, a polski bez znaczków to herezja thus wszystko po angielsku
int main(int argc, char **argv){
	int height = 16;
	int width = height*2;
	int hs = 0;
	int x;
	bool plus = false;
	bool vase = false;
	a:;
	std::cout << "Press 1 to select plain gamemode" << std::endl << "Press 2 to select + gamemode" << std::endl << "Press 3 to select vase gamemode" << std::endl;
	std::cin >> x; 
	switch(x){
		case 1:
			break;
		case 2:
			plus = true;
			break;
		case 3:
			vase = true;
			break;
		default:
			std::cout << "Invalid input, retry" << std::endl;
			goto a;
	}
	
	
	initscr();
	refresh();
	noecho();
	curs_set(0);
	
	skok:;
	Game game(height, width, hs, plus, vase);
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