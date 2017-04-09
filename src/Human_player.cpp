//Human_player.cpp
#include <iostream>
#include <vector>

#include "Board.h"
#include "Tile.h"
#include "Direction.h"
#include "Human_player.h"

namespace reversi {

Human_player::Human_player(const Tile& t) {
	p_color = t;
	moved = false;
} 

void Human_player::invalid_move() {
	std::cout << "Invalid move. Try again.\n";
}

void Human_player::move(Board& b, int row, int col, const Tile& target) {
	moved = false;

	int score_amt = 0;

	avail_move = b.search_base(row, col, target);

	if (avail_move.size() > 0) {
		for (Direction& dir : avail_move) {
			b.search_recur(dir, row + dir.row, col + dir.col, p_color);
			score_amt += dir.temp_score;
		}

		if (score_amt > 0) {
			for (Direction& dir : avail_move) {
				if (dir.valid == 0) {
					b.set(row, col, p_color);
					b.replace(dir, row + dir.row, col + dir.col, p_color, target);
					moved = true;
					std::cout << "Human moved\n";
				}
			}
		} else {
			invalid_move();
		}
	} else {
		invalid_move();
	}
		
}

int Human_player::score(Board b) const {
	return b.score(p_color);
}

Tile Human_player::color() const {
	return p_color;
}

bool Human_player::turn_taken() const {
	return moved;
}
} //reversi
