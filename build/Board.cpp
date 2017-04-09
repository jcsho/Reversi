//Board.cpp
#include <iostream>
#include <vector>
#include <cassert>
#include "Board.h"
#include "Tile.h"
#include "Direction.h"

namespace reversi {

Board::Board(int size) : board(size) {

	assert(size > 1);

	for (int i = 0; i < (int)board.size(); i ++) {
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
	
	std::cout << "\n    a   b   c   d   e   f   g   h\n\n";

	for (int i = 0; i < size(); i++) {
		std::cout << i + 1 << "   ";

		for (int j = 0; j < size(); j++) {
			std::cout << char(board[i][j]) << "   ";
		}
	
		std::cout << "\n\n";
	}
}

std::vector<Direction> Board::search_base(int row, int col, const Tile& target) {
	std::vector<Direction> base_case;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((row + i) >= 0 && (row + i) < size() && (col + j) >= 0 && (col + j) < size()) {
				if (get(row + i, col + j) == target) {
					base_case.push_back(Direction());
					base_case[base_case.size()-1].row = i;
					base_case[base_case.size()-1].col = j;
					base_case[base_case.size()-1].valid = 1;
					base_case[base_case.size()-1].temp_score = 0;
					base_case[base_case.size()-1].score = 0;
				}
			}
		}
	}

	return base_case;
}

void Board::search_recur(Direction& dir, int start_row, int start_col, const Tile& target) {
	if (get(start_row, start_col) == target) {
		dir.valid = 0;
	} else if (get(start_row, start_col) == Tile::none || (start_row + dir.row) < 0 || (start_row + dir.row) >= size() || (start_col + dir.col) < 0 || (start_col + dir.col) >= size()) {
		dir.temp_score = 0;
	} else if ((start_row + dir.row) >= 0 && (start_row + dir.row) < size() && (start_col + dir.col) >= 0 && (start_col + dir.col) < size()) {
		dir.temp_score++;
		search_recur(dir, start_row + dir.row, start_col + dir.col, target);
	}
}

void Board::replace(Direction& dir, int start_row, int start_col, const Tile& main, const Tile& target) {
	if (get(start_row, start_col) == target) {
		set(start_row, start_col, main);
		dir.score ++;
		replace(dir, start_row + dir.row, start_col + dir.col, main, target);
	}
}

int Board::score(const Tile& color) const {
	int amt = 0;

	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < size(); j++) {
			if (get(i, j) == color) {
				amt++;
			}
		}
	}

	return amt;

}

bool Board::check_avail_move(const Tile& main, const Tile& target) {
	std::vector<Direction> check;
	
	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < size(); j++) {
			if (get(i, j) == Tile::none) {
				check = search_base(i, j, target);
				
				if (check.size() > 0) {
					for (Direction& dir : check) {
						search_recur(dir, i + dir.row, j + dir.col, main);
						if (dir.valid == 0) {
							return true;
						}
					}		
				}
			}
		}
	}

	return false;
}

} //reversi
