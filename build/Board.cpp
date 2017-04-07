#include <iostream>
#include <vector>
#include <cassert>
#include "Board.h"
#include "Tile.h"

namespace reversi {

Board::Board(int size) : board(size) {

	assert(size > 1);

	for (int i = 0; i < board.size(); i++) {
		board[i] = std::vector<Tile>(size, Tile::none);
	}

	board[3][3] = Tile::white;
	board[4][4] = Tile::white;
	board[3][4] = Tile::black;
	board[4][3] = Tile::black;

}

int Board::size() const {
	return board.size();
}

bool Board::in_board(int row, int col) const {
	return (0 <= row && row < size()) && (0 <= col && col < size());
}

void Board::set(int row, int col, const Tile& t) {
	assert(in_board(row, col));
	board[row][col] = t;
}

Tile Board::get(int row, int col) const {
	assert(in_board(row, col));
	return board[row][col];
}

void Board::print() const {
	
	std::cout << "    a   b   c   d   e   f   g   h\n\n";

	for (int i = 0; i < size(); i++) {
		std::cout << i + 1 << "   ";

		for (int j = 0; j < size(); j++) {
			std::cout << char(board[i][j]) << "   ";
		}
	
		std::cout << "\n\n";
	}
}

std::vector<Board::direction> Board::search_base(int row, int col, const Tile& t) {
	std::vector<Board::direction> base_case;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (get(row + i, col + j) == t) {
				base_case.push_back(Board::direction());
				base_case[base_case.size()-1].row = i;
				base_case[base_case.size()-1].col = j;
				base_case[base_case.size()-1].valid = 1;
			}
		}
	}

	return base_case;
}

void Board::search_recur(Board::direction& dir, int start_row, int start_col, const Tile& t) {
	if (get(start_row, start_col) != t && get(start_row, start_col) != Tile::none) {
		std::cout << "found endpoint\n";
		dir.valid = 0;
	} else if (get(start_row, start_col) == t) {
		std::cout << "found t\n";
		dir.score += 1;
		search_recur(dir, start_row + dir.row, start_col + dir.col, t);
	}

}

void Board::replace(Board::direction dir, int start_row, int start_col, const Tile& main, const Tile& target) {
	if (get(start_row, start_col) == target) {
		set(start_row, start_col, main);
		replace(dir, start_row + dir.row, start_col + dir.col, main, target);
	}
}
}
