#pragma once
#include"Piece.h"
class Pawn:public Piece
{
public:
	Pawn(char name, bool isWhite, int row, int column) :Piece(isWhite, row, column,name) {}
	bool isValidMove(int endRow, int endColumn) override {
		if (isWhite == true) {
			
				if (endRow == position.row + 1 && (endColumn == position.column + 1 || endColumn == position.column - 1)) {
					return true;
				
			}
			if (isFirstMove == true) {
				
				if( (endRow - position.row == 1 || endRow - position.row == 2)&&(endColumn==position.column)) {
					
					return true;

				}
			}
			else if (isFirstMove==false){
				if ((endRow - position.row == 1) && (endColumn == position.column))
					return true;

			}
		}
		if (isWhite == false) {
			
				if (endRow == position.row - 1 && (endColumn == position.column + 1 || endColumn == position.column - 1)) {
					return true;
				
			}
			if (isFirstMove == true) {
				
				if ((endRow - position.row == -1 || endRow - position.row == -2) && (endColumn == position.column)) {
					
					return true;

				}
			}
			else if (isFirstMove == false) {
				if ((endRow - position.row == -1) && (endColumn == position.column))
					return true;

			}
		}
		return false;
		
	}

};

