#include <iostream>
#include <ncursesw/curses.h>
#include "Square.hpp"
#include "Game.hpp"
#include "Draw.hpp"
#include <fstream>
#include <string>

//boję się wkładać polskie znaczki w kod, a polski bez znaczków to herezja thus wszystko po angielsku
int loadhs(){
	std::ifstream fin("highscore.txt");
	int x;
	fin >> x;
	fin.close();
	return x;
}
void updatehs(int newhs){
	std::ofstream fin("highscore.txt");
	fin << newhs;
	fin.close();
}
int main(int argc, char **argv){
	int height = 16;
	int width = height*2;
	skok:;
	int score, x;
	int hs = loadhs();
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
	
	Game game(height, width, hs, plus, vase);
	while(!game.isover()){
		game.useinput();
		
		game.update();
		
		game.redraw();
		
	}
	
	score = game.getscore();
	if(hs < game.getscore()){
		updatehs(game.getscore());
	}
	if (!game.isexit())
		endwin();
		k:;
		std::cout << "Game Over" << std::endl << "Score: " << score << std::endl << "HighScore: " << hs << std::endl << "Do you want to continue playing? y/n" << std::endl;
		char y;
		std::cin >> y;
		if(y == 'y')
			goto skok;
		else if(y != 'y' && y != 'n'){
			std::cout << "invalid input" << std::endl;
			goto k;}
		
	
	getch();
	endwin();
	return 0;
}