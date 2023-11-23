#pragma once // program znajdzię się tylko w jednej kompilacji
#include <ncursesw/curses.h>
#include "Draw.hpp"
#include "Ticks.hpp"

class Square{
public:
	Square(){
		parameters(0, 0, 300);  //default
	}
	
	Square(int height, int width, int speed){
		parameters(height, width, speed);
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
		time_t time_last_input = Time::milliseconds();
		
		chtype input = wgetch(win);
		chtype new_input = ERR;
		
		settimeout(0);
		while(time_last_input + timeout >= Time::milliseconds()){
			new_input = wgetch(win);
		}
		settimeout(timeout);
		if(new_input != ERR)
			input = new_input;
			
		return input;
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
	
	void settimeout(int speed){
		wtimeout(win, speed);   // automatyczne odświeżanie się ekranu / prędkość gry
	}
	
	int getstartrow(){
		return startrow;
	}
	
	int getstartcol(){
		return startcol;
	}
	
	int gettimeout(){
		return timeout;
	}
	
	void changetimeout(int speed){
		timeout = speed;
	}
	
private:
	WINDOW *win;
	int height, width, startrow, startcol;
	int timeout;
	
	void parameters(int height, int width, int speed){
		int xres, yres;
		getmaxyx(stdscr, yres, xres);
		this->height = height;  
		this->width = width;
		
		startrow = (yres / 2) - (height / 2);
		startcol = (xres / 2) - (width / 2);
		
		win = newwin(height, width, startrow, startcol);
		
		timeout = speed;
		settimeout(speed);
		// strzałki są wyłączone by default
		keypad(win, true);
	}
};