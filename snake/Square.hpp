#pragma once // program znajdzię się tylko w jednej kompilacji
#include <ncursesw/curses.h>
#include "Draw.hpp"

class Square{
public:
	Square(){
		parameters(0, 0);  //default
	}
	
	Square(int height, int width){
		parameters(height, width);
	}

	void drawsquare(){
		clear();
		refresh();    //automatyzacja goes brrrr
	}

	void addbox(){
		box(win, 0, 0);
	}
	
	void add(Draw draw){
		addsign(draw.gety(), draw.getx(), draw.getsign());
	}
	
	void addsign(int y, int x, chtype ch){
		mvwaddch(win, y, x, ch);
	}
	
	chtype getinput(){
		return wgetch(win);  //nazwy mówią same za siebie, więc zwrócę w komentarzu uwagę na brzydotę tej biblioteki. Kto uznał, że wgetch brzmi dobrze?
	}
	
	void getcoordinates(int &y, int &x){
		while((mvwinch(win, y = rand() % height, x = rand() % width)) != ' '); //losowe puste miejsce dla jabłka
	}
	
	chtype getchar(int y, int x){
		return mvwinch(win, y, x);
	}
	
	void clear(){
		wclear(win);
		addbox();
	}
	
	void refresh(){
		wrefresh(win);
	}
	
	void settimeout(int timeout){
		wtimeout(win, timeout);
	}
	
	int getstartrow(){
		return startrow;
	}
	
	int getstartcol(){
		return startcol;
	}
	
private:
	WINDOW *win;
	int height, width, startrow, startcol;
	
	void parameters(int height, int width){
		int xres, yres;
		getmaxyx(stdscr, yres, xres);
		this->height = height;  
		this->width = width;
		
		startrow = (yres / 2) - (height / 2);
		startcol = (xres / 2) - (width / 2);
		
		win = newwin(height, width, startrow, startcol);
		// automatyczne odświeżanie się ekranu / prędkość gry
		wtimeout(win, 300);
		// strzałki są wyłączone by default
		keypad(win, true);
	}
};