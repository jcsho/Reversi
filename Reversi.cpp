//Reversi.cpp

#include <vector>
#include <iostream>
#include "Board.h"
#include "Tile.h"

std::vector<char> column = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

void input(reversi::Board b, const Tile& t) {

	int input_row, output_row, output_col;
	char input_col;

	std::cout << "Enter your move (row, col) ex. 6e\n";
	std::cin >> input_row >> input_col;

	output_row = input_row - 1;	

	for (int i = 0; i < column.size(); i ++) {
		if (input_col == column[i]) {
			output_col = i;
		}
	}

	std::cout << "\nInput: " << input_row << input_col << "\n";
	std::cout << "\nOutput: " << output_row << output_col << "\n";

	b.test = b.search_base(output_row, output_col, t);

	if (b.test.size() > 0) {
		for (reversi::Board::direction& dir : b.test) {
			std::cout << dir.row << dir.col <<"\n";
			b.search_recur(dir, output_row + dir.row, output_col + dir.col, t);
		}

		for (reversi::Board::direction dir : b.test) {
			std::cout << dir.valid <<"\n" << dir.score << "\n";
		}
	}

}

int main() {

	reversi::Board b(8);

	b.print();

	input(b, Tile::black);

	return 0;
}


