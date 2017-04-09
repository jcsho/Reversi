# Reversi

## Project recreating a custom command line version of Reversi/Othello in C++

### Criteria:

  - It allows a human to play against the computer as black.

  - It starts a game using the “Othello” board configuration, i.e. four pieces in the center alternating white and black. See the “starting position” picture on the Reversi page.

  - It displays the board in beautiful ASCII text on cout. The exact representation of the board is up to you, but make it easy to read and understand. In addition to showing the current state of the board, it should show how many pieces each player has, which pieces are the player ‘s and which are the computer’s, and any other information that the player needs to understand and enjoy the game.

  - It reads input from cin, and never crashes on invalid input. If the user enters an illegal or nonsensical move, then the program should politely point out the problem and ask them to re-enter a valid move.

  - A good way to get use input is to use coordinates, e.g. label each row with a number and each column with a letter, so a move would be a 2-character string like “5a” or “3e”.
  - When the game is over, it displays the piece-count for each player and says who won the game (or if it was a tie).

  - It should then asks the player if they want to play again when the game is over. If they choose to play again, then a brand new game is started. Otherwise, the program ends.

  - It correctly recognizes the end of the game, and whose move it is. In Reversi, players normally alternate moves. However, if a player has no possible moves then they must skip their turn (they are not allowed to skip their turn if they can make a move). It’s possible that one player could thus end up playing multiple moves in a row.

  - The game is over when neither player can make a move. Usually, this occurs when there are no more empty spaces on the board, but it’s possible that the game could end with one or more empty spaces left.
