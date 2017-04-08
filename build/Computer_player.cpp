//Computer_player.cpp
#include <iostream>
#include <vector>

#include "Board.h"
#include "Tile.h"
#include "Direction.h"
#include "Computer_player.h"

namespace reversi {

Computer_player::Computer_player(const Tile& t) {
	pieces = 32;
	score = 0;
	cp_color = t;
	can_move = true;
}

void Computer_player::move(Board& b, const Tile& target) {

	std::vector<Direction> best_move;
	int move_row = -1;
	int move_col = -1;
	int current_score = 0;
	int total_score = 0;
	can_move = true;

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			total_score = 0;

			if (b.get(i, j) == Tile::none) {
				avail_move = b.search_base(i, j, target);
				
				if (avail_move.size() > 0) {
					for (Direction& dir : avail_move) {
						b.search_recur(dir, i + dir.row, j + dir.col, target);
						total_score += dir.temp_score;
					}

					if (total_score > current_score) {
						current_score = total_score;
						best_move = avail_move;
						move_row = i;
						move_col = j;
					}
				}
			}
		}
	}

	if (move_row > -1 && move_col > -1) {
		for (const Direction dir : best_move) {
			if (dir.valid == 0) {
				b.set(move_row, move_col, cp_color);
				b.replace(dir, move_row + dir.row, move_col + dir.col, cp_color, target);
				score += dir.score;
				pieces -= dir.score;			
			}
		}
	} else {
		can_move = false;
	}


	avail_move.clear();
}

int Computer_player::current_score() const {
	return score;
}

int Computer_player::num_pieces() const {
	return pieces;
}

Tile Computer_player::color() const {
	return cp_color;
}
} //reversi
