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
	int x;
	bool obstacle = false;
	a:;
	std::cout << "Press 1 to select plain gamemode" << std::endl << "Press 2 to select obstacle gamemode" << std::endl;
	std::cin >> x; 
	if (x==1)
		obstacle = false;
	else if (x==2)
		obstacle = true;
	else{
		std::cout << "Invalid input, retry" << std::endl;
		goto a;
	}
	
	
	initscr();
	refresh();
	noecho();
	curs_set(0);
	
	skok:;
	Game game(height, width, hs, obstacle);
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