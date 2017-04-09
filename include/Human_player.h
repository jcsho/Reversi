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
		Tile p_color;
		bool moved;

		Direction dir;
		std::vector<Direction> avail_move;

	public:
		Human_player(const Tile& t); //makes human player of color t

		void invalid_move(); //prints out invalid move

		void move(Board& b, int row, int col, const Tile& target); //makes a move from user input

		int score(Board b) const override;

		Tile color() const override; //returns tile color of player

		bool turn_taken() const; //checks if player made a valid turn
}; //Human_player
} //reversi

#endif //HUMAN_PLAYER_H_
