#pragma once
#include <string>
using namespace std;
struct Position{
	int row;
	int column;
};
class Piece
{
protected:
	bool isFirstMove;
	char name;
	bool isWhite;
	bool isAlive;
	Position position;
public:

	bool is_White();
	bool is_Captured();
	void update_Position(int row, int column);
	void captured();
	virtual bool isValidMove(int endRow, int endColumn) =0;
	char getName();
	void firstMoveFalse();
	void firstMoveTrue();
	Piece(bool isWhite, int row, int column, char name);
};

