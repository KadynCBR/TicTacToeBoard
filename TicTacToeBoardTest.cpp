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

TEST(TicTacToeBoardTest, test_get_piece_outside) {}
TEST(TicTacToeBoardTest, test_get_piece_blank) {}
TEST(TicTacToeBoardTest, test_get_piece_piece_present) {}

TEST(TicTacToeBoardTest, test_winner_true) {
  TicTacToeBoard t = TicTacToeBoard();
  ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, test_winner_false) {}
