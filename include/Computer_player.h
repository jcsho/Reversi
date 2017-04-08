//Computer_player.h

#ifndef COMPUTER_PLAYER_H_
#define COMPUTER_PLAYER_H_

#include <vector>

#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include "Direction.h"

namespace reversi {

class Computer_player : public Player {
	private:
		int pieces;
		int score;
		Tile cp_color;
		bool can_move;

		Direction dir;
		std::vector<Direction> avail_move;

	public:
		Computer_player(const Tile& t);

		void move(Board& b, const Tile& target);

		int current_score() const override;

		int num_pieces() const override;

		Tile color() const override;
		
}; //Computer_player
} //reversi

#endif //COMPUTER_PLAYER_H_
