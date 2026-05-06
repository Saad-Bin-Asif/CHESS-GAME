#pragma once
#include"Piece.h"
class Knight:public Piece
{
public:
	Knight(char name, bool isWhite, int row, int column) :Piece(isWhite, row, column,name) {}
	bool isValidMove(int endRow, int endColumn) override{
		if ((abs(position.row - endRow) == 2 && abs(position.column - endColumn) == 1) || (abs(position.row - endRow) == 1 && abs(position.column - endColumn) == 2)) 
			return true;
		return false;
		
	}
};
