#pragma once

class Scoreboard {
	WINDOW *scorewin;
	
public:
	Scoreboard(){
		
	}
	
	Scoreboard(int width, int y, int x){
		scorewin = newwin(1, width, y, x);
	}
	
	void initialize(int initialscore, int highscore){
		clear();
		mvwprintw(scorewin, 0, 0, "Score:");
		mvwprintw(scorewin, 0, 15, "HighScore:");
		updatescore(initialscore);
		hs(highscore);
		refresh();
	}
	
	void updatescore(int score){
		mvwprintw(scorewin, 0, 6, "%i", score); 
	}
	void hs(int highscore){
		mvwprintw(scorewin, 0, 25, "%i", highscore); 
	}
	
	void clear(){
		wclear(scorewin);
	}
	
	void refresh(){
		wrefresh(scorewin);
	}
};