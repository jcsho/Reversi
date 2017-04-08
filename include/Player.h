//Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Tile.h"

namespace reversi {

class Player {
	public:

		virtual ~Player() { }

		virtual int current_score() const = 0;

		virtual int num_pieces() const = 0;
		
		virtual Tile color() const = 0;
}; //Player

#endif //PLAYER_H_
