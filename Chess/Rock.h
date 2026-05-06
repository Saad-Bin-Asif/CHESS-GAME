#pragma once
#include"Piece.h"
class Rook :public Piece
{

public:
	
	Rook(char name, int isWhite, int row, int column) :Piece(isWhite, row, column, name) {}
	// moves only in rows and columns
	bool isValidMove(int endRow, int endColumn) override {
		if (((position.row == endRow) && (position.column != endColumn)) || ((position.row != endRow) && (position.column == endColumn))) {


			return true;
		}

		return false;
	}
	char getName() {
		return name;
	}
};

