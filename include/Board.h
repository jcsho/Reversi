//Board.h

#ifndef BOARD_H_
#define BOARD_H_

#include "Tile.h"
#include <vector>

namespace reversi {

class Board {
	private:
		std::vector<std::vector<Tile>> board; //stores the reversi game board

	public:
		Board(int size); //constructor

		//~Board(); //destructor

		struct direction {
			int row;
			int col;
			int valid;
			int score;
		}; //dir

		std::vector<direction> test;

		int size() const; //length of board

		bool in_board(int row, int col) const; //test if tile is within board

		void set(int row, int col, const Tile& t); //sets the tile (row, col) to be t

		Tile get(int row, int col) const; //return the type of tile at (row, col)

		void print() const; //prints board to terminal

		std::vector<direction> search_base(int row, int col, const Tile& t); //searches the adjacent 8 spaces around (row, col)

		void search_recur(direction& dir, int start_row, int start_col, const Tile& t); //searchs for t

		void replace(direction dir, int start_row, int start_col, const Tile& t); //replace all tiles in 1 direction with t

}; //Board

} //reversi

#endif //BOARD_H_
