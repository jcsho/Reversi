//Human_player.h

#ifndef HUMAN_PLAYER_H_
#define HUMAN_PLAYER_H_

#include <vector>

#include "Player.h"
#include "Board.h"
#include "Tile.h"

namespace reversi {

class Human_player : public Player {
	private:
		int pieces;
		int score;
		Tile color;

		std::vector<Board::direction> avail_move;

	public:
		Human_player(const Tile& t);

		~Human_player() { }

		void invalid_move();

		void move(Board& b, int row, int col, Computer_player cp);

		virtual int current_score() const;

		virtual int num_pieces() const;

		virtual Tile color() const;
};
}

#endif //HUMAN_PLAYER_H_
