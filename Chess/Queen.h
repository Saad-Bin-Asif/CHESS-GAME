#pragma once
#include"Piece.h"
class Queen:public Piece
{
	char name;
public:
Queen(char name,bool isWhite,int row,int column):Piece(isWhite,row,column,name){}
bool isValidMove(int endRow, int endColumn) override {
	if ((position.row == endRow && position.column != endColumn) || (position.row != endRow && position.column == endColumn)) 
		return true;
		if ((position.row != endRow && position.column != endColumn) && (abs(position.row - endRow) == abs(position.column - endColumn)))
			return true;
		return false;
	
}
};

