#pragma once
#include"Piece.h"
class Bishop :public Piece
{

public:
	Bishop(char name, bool isWhite, int row, int column) : Piece(isWhite, row, column, name) {}
	bool isValidMove(int endRow, int endColumn)override {
		if ((position.row != endRow && position.column != endColumn) && (abs(endRow - position.row) == abs(endColumn - position.column)))
			return true;
		return false;
	}
};

