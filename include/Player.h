//Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Tile.h"
#include "Board.h"

namespace reversi {

class Player {
	public:

		virtual ~Player() { }

		virtual int score(Board b) const = 0;
		
		virtual Tile color() const = 0;
}; //Player
}

#endif //PLAYER_H_
