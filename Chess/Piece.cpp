#include "Piece.h"
//----------Piece----------//
Piece::Piece(bool isWhite = NULL, int row = NULL, int column = NULL,char name=' ') : isWhite(isWhite), isAlive(true), name(name) {
	this->position.row = row;
	this->position.column = column;
	this->isFirstMove = true;
}
bool Piece::is_White() {
	if (this->isWhite == true)
		return true;
	return false;
}
bool Piece::is_Captured() {
	if (this->isAlive == true)
		return true;
	return false;
}
void Piece:: update_Position(int row,int column) {
	this->position.row = row;
	this->position.column = column;
	return;
}
void Piece::captured() {
	this->isAlive = false;
	return;
}
char Piece::getName() { return name; }
void Piece::firstMoveFalse() { isFirstMove = false; }
void Piece::firstMoveTrue() { isFirstMove = true; }
 

