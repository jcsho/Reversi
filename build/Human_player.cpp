//Human_player.cpp
#include <iostream>
#include <vector>

#include "Board.h"
#include "Tile.h"
#include "Direction.h"
#include "Human_player.h"

namespace reversi {

Human_player::Human_player(const Tile& t) {
	pieces = 32;
	score = 0;
	p_color = t;
}

void Human_player::invalid_move() {
	std::cout << "Invalid move. Try again.\n";
}

void Human_player::move(Board& b, int row, int col, const Tile& target) {

	int score_amt = 0;

	avail_move = b.search_base(row, col, target);

	if (avail_move.size() > 0) {
		for (Direction& dir : avail_move) {
			b.search_recur(dir, row + dir.row, col + dir.col, target);
			score_amt += dir.temp_score;
		}
	} else {
		invalid_move();
	}

	if (score_amt > 0) {
		for (const Direction dir : avail_move) {
			if (dir.valid == 0) {
				b.set(row, col, p_color);
				b.replace(dir, row + dir.row, col + dir.col, p_color, target);
				score += dir.score;
				pieces -= dir.score;
			}
		}
	} else {
		invalid_move();
	}
		
}

int Human_player::current_score() const {
	return score;
}

int Human_player::num_pieces() const {
	return pieces;
}

Tile Human_player::color() const {
	return p_color;
}
} //reversi
