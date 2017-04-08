//Human_player.h

#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include <vector>

#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include "Direction.h"

namespace reversi {

class Human_player : public Player {
	private:
		int pieces;
		int score;
		Tile p_color;

		Direction dir;
		std::vector<Direction> avail_move;

	public:
		Human_player(const Tile& t);

		void invalid_move();

		void move(Board& b, int row, int col, const Tile& target);

		int current_score() const override;

		int num_pieces() const override;

		Tile color() const override;
}; //Human_player
} //reversi

#endif //HUMAN_PLAYER_H_
