#pragma once
#include <ncursesw/curses.h>
#include "Draw.hpp"
#include <queue>

enum Direction{
	up = -1,
	down = 1,
	left = -2,
	right = 2
};

class SnakePiece : public Draw{
public:
	SnakePiece(){
		this->x = this->y = 0;
		this->sign = '#';
	}
	SnakePiece(int y, int x){
		this->x = x;
		this->y = y;
		this->sign = '#';
	}
};

class Snake{
	std::queue<SnakePiece> prev_pieces;
	Direction cur_direction;
	
public:
	Snake(){
		cur_direction = down;
	}
	
	void addpiece(SnakePiece piece){
		prev_pieces.push(piece);
	}
	
	void removepiece(){
		prev_pieces.pop();
	}
	
	SnakePiece tail(){
		return prev_pieces.front();
	}
	
	SnakePiece head(){
		return prev_pieces.back();
	}
	
	Direction getdirection(){
		return cur_direction;
	}
	
	void setdirection(Direction d){
		if (cur_direction + d != 0)
			cur_direction = d;
	}
	
	SnakePiece nexthead(){
		int row = head().gety();
		int col = head().getx();
		
		switch(cur_direction){
			case down:
				row++;
				break;
			case up:
				row--;
				break;
			case left:
				col--;
				break;
			case right:
				col++;
				break;
		}
		return SnakePiece(row, col);
	}
};