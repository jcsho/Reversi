//Reversi.cpp

#include <vector>
#include <iostream>
#include "Board.h"
#include "Tile.h"
#include "Human_player.h"
#include "Computer_player.h"

void output(reversi::Board& b, reversi::Human_player& p, reversi::Computer_player& cp) {
	b.print();
	std::cout <<"\nScore:\nHuman: " << p.score(b) << "\nComputer: " << cp.score(b) <<"\n\n";

}

void input(reversi::Board& b, reversi::Human_player& p, reversi::Computer_player& cp) {

	std::vector<char> column = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

	int input_row = -1, output_row = -1, output_col = -1;
	char input_col;

	std::cout << "Enter your move (row, col) ex. 6e\n";
	std::cin >> input_row >> input_col;

	if (input_row == -7) {
		std::exit(EXIT_SUCCESS);
	}

	if (input_row >= 0 && input_row <= b.size()) {
	
		output_row = input_row - 1;	

		for (int i = 0; i < (int)column.size(); i ++) {
			if (input_col == column[i]) {
				output_col = i;
			}
		}
		
		if (output_col == -1) {
			p.invalid_move();
		} else {

			//std::cout << "\nInput: " << input_row << input_col << "\n";
			//std::cout << "\nOutput: " << output_row << output_col << "\n";
		
			if (b.get(output_row, output_col) != Tile::none) {
				p.invalid_move();
			} else {
				p.move(b, output_row, output_col, cp.color());

				if (p.turn_taken()) {
					output(b, p, cp);
					cp.move(b, p.color());
					output(b, p, cp);
				}
			}
		}

	} else {
		p.invalid_move();
	}
}

void gameOver(reversi::Board& b, reversi::Human_player& p, reversi::Computer_player& cp) {
	if (p.score(b) > cp.score(b)) {
		std::cout << "\nYou Won!!!\n";
	} else if (p.score(b) < cp.score(b)) {
		std::cout << "\nYou Lost\n";
	} else {
		std::cout << "\nDraw\n";
	}
}

void startGame() {
	int num;

	while (num != 1) {

		std::cout << "\nStart game? Enter 0 to begin, 1 to exit\n\n";

		std::cin >> num;

		if (num == 1) {
			std::exit(EXIT_SUCCESS);
		} else if (num != 0 ) {
			std::cout << "Invalid command. Try again.\n\n";
		} else if(num == 0) { 
			reversi::Board b(8);
			reversi::Human_player p(Tile::black);
			reversi::Computer_player cp(Tile::white);
	
			int turn = 1;

			output(b, p, cp);

			while (b.check_avail_move(p.color(), cp.color()) && b.check_avail_move(cp.color(), p.color())) {
				std::cout << "\n----------Turn: " << turn <<"----------\n";
				input(b, p, cp);

				if (p.turn_taken()) {
					turn++;
				}
			}
			
			gameOver(b, p, cp);
		}
	}
}


int main() {

	startGame();

	return 0;
}


