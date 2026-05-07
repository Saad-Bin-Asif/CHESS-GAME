#pragma once
#include"piece.h"
class King:public Piece
{
public:
	King(char name,bool isWhite,int row,int column):Piece(isWhite,row,column,name){}
	bool isValidMove(int endRow, int endColumn) override {
		if (position.row == endRow && position.column != endColumn) {
			if (abs(endColumn - position.column) == 1)
				return true;
		}
		else if (position.row != endRow && position.column == endColumn) {
			if (abs(endRow - position.row) == 1) {
				return true;
			}
		}
		if (position.row != endRow && position.column != endColumn) {
			if ((abs(position.row - endRow) == 1) && abs(position.column - endColumn) == 1) {
				return true;
			}
		}
		return false;
	}
};

