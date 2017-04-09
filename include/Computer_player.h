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
		Tile cp_color;
		bool can_move;

		Direction dir;
		std::vector<Direction> avail_move;

	public:
		Computer_player(const Tile& t); //makes computer of tile color t

		void move(Board& b, const Tile& target); //makes move at position which takes the most pieces

		int score(Board b) const override;

		Tile color() const override; //returns computer tile color
		
}; //Computer_player
} //reversi

#endif //COMPUTER_PLAYER_H_
