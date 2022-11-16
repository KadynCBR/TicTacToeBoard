/**
 * Unit Tests for TicTacToeBoard
 **/

#include <gtest/gtest.h>

#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test {
 protected:
  TicTacToeBoardTest() {}
  virtual ~TicTacToeBoardTest() {}
  virtual void SetUp() {}     // sets up before each test (after constructor)
  virtual void TearDown() {}  // clean up after each test, (before destructor)
};

TEST(TicTacToeBoardTest, test_toggle_X) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece new_turn = t.toggleTurn();
  ASSERT_EQ(new_turn, O);
}

TEST(TicTacToeBoardTest, test_toggle_O) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece new_turn = t.toggleTurn();
  new_turn = t.toggleTurn();
  ASSERT_EQ(new_turn, X);
}

TEST(TicTacToeBoardTest, test_place_inside) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(1, 1);
  ASSERT_EQ(placed, X);
}

TEST(TicTacToeBoardTest, test_place_outside_row) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(5, 1);
  ASSERT_EQ(placed, Invalid);
}

TEST(TicTacToeBoardTest, test_place_outside_col) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(1, 5);
  ASSERT_EQ(placed, Invalid);
}

TEST(TicTacToeBoardTest, test_place_outside_both) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(5, 5);
  ASSERT_EQ(placed, Invalid);
}

TEST(TicTacToeBoardTest, test_place_same_piece) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(1, 1);
  placed = t.placePiece(1, 1);
  ASSERT_EQ(placed, X);
}

TEST(TicTacToeBoardTest, test_place_opponent_piece) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(1, 1);
  t.toggleTurn();
  placed = t.placePiece(1, 1);
  ASSERT_EQ(placed, X);
}

TEST(TicTacToeBoardTest, test_get_piece_outside) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece p = t.getPiece(-1, 0);
  ASSERT_EQ(p, Invalid);
}
TEST(TicTacToeBoardTest, test_get_piece_blank) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece p = t.getPiece(0, 0);
  ASSERT_EQ(p, Invalid);
}
TEST(TicTacToeBoardTest, test_get_piece_piece_present) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece placed = t.placePiece(1, 1);
  Piece p = t.getPiece(1, 1);
  ASSERT_EQ(p, X);
}

TEST(TicTacToeBoardTest, test_winner_true_vertical) {
  TicTacToeBoard t = TicTacToeBoard();
  t.placePiece(0, 0);
  t.placePiece(1, 0);
  t.placePiece(2, 0);
  Piece winner = t.getWinner();
  ASSERT_EQ(winner, X);
}

TEST(TicTacToeBoardTest, test_winner_true_horizontal) {
  TicTacToeBoard t = TicTacToeBoard();
  t.placePiece(0, 0);
  t.placePiece(1, 0);
  t.placePiece(2, 0);
  Piece winner = t.getWinner();
  ASSERT_EQ(winner, X);
}

TEST(TicTacToeBoardTest, test_winner_true_diagonal_tl_br) {
  TicTacToeBoard t = TicTacToeBoard();
  t.placePiece(0, 0);
  t.placePiece(1, 1);
  t.placePiece(2, 2);
  Piece winner = t.getWinner();
  ASSERT_EQ(winner, X);
}

TEST(TicTacToeBoardTest, test_winner_true_diagonal_tr_bl) {
  TicTacToeBoard t = TicTacToeBoard();
  t.placePiece(0, 2);
  t.placePiece(1, 1);
  t.placePiece(2, 0);
  Piece winner = t.getWinner();
  ASSERT_EQ(winner, X);
}

TEST(TicTacToeBoardTest, test_winner_false) {
  TicTacToeBoard t = TicTacToeBoard();
  Piece winner = t.getWinner();
  ASSERT_EQ(winner, false);
}
