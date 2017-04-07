//Computer_player.h

#ifndef COMPUTER_PLAYER_H_
#define COMPUTER_PLAYER_H_

#include <vector>

#include "Player.h"
#include "Board.h"
#include "Tile.h"

namespace reversi {

class Computer_player : public Player {
	private:
		int pieces;
		int score;
		Tile color;
		bool can_move;

		std::vector<Board::direction> avail_move;

	public:
		Computer_player(const Tile& t);

		~Computer_player() { }

		void move(Board& b, Human_player p);

		virtual int current_score() const;

		virtual int num_pieces() const;
		
		virtual Tile color() const;
		
}
}

#endif //COMPUTER_PLAYER_H_
