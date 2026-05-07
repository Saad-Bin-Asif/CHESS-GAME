#pragma once
#include<windows.h>
#include<iostream>
#include"Piece.h"
#include"Rock.h"
#include"Knight.h"
#include"King.h"
#include"Queen.h"
#include"Bishop.h"
#include"Pawn.h"
class Board
{
	int row;
	int column;
	Piece* temp;
	Piece* board[8][8];
public:
	
	Board() {
		//White
		board[0][0] = new Rook('R', true, 0, 0);
		board[0][1] = new Knight('N', true, 0, 1);
		board[0][2] = new Bishop('B', true, 0, 2);
		board[0][3] = new King('K', true, 0, 3);
		board[0][4] = new Queen('Q', true, 0, 4);
		board[0][5] = new Bishop('B', true, 0, 5);
		board[0][6] = new Knight('N', true, 0, 6);
		board[0][7] = new Rook('R', true, 0, 7);
		board[1][0] = new Pawn('P', true, 1, 0);
		board[1][1] = new Pawn('P', true, 1, 1);
		board[1][2] = new Pawn('P', true, 1, 2);
		board[1][3] = new Pawn('P', true, 1, 3);
		board[1][4] = new Pawn('P', true, 1, 4);
		board[1][5] = new Pawn('P', true, 1, 5);
		board[1][6] = new Pawn('P', true, 1, 6);
		board[1][7] = new Pawn('P', true, 1, 7);
		//Black
		board[7][0] = new Rook('r', false, 7, 0);
		board[7][1] = new Knight('n', false, 7, 1);
		board[7][2] = new Bishop('b', false, 7, 2);
		board[7][3] = new King('k', false, 7, 3);
		board[7][4] = new Queen('q', false, 7, 4);
		board[7][5] = new Bishop('b', false, 7, 5);
		board[7][6] = new Knight('n', false, 7, 6);
		board[7][7] = new Rook('r', false, 7, 7);
		board[6][0] = new Pawn('p', false, 6, 0);
		board[6][1] = new Pawn('p', false, 6, 1);
		board[6][2] = new Pawn('p', false, 6, 2);
		board[6][3] = new Pawn('p', false, 6, 3);
		board[6][4] = new Pawn('p', false, 6, 4);
		board[6][5] = new Pawn('p', false, 6, 5);
		board[6][6] = new Pawn('p', false, 6, 6);
		board[6][7] = new Pawn('p', false, 6, 7);
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = nullptr;
			}
		}
		temp = nullptr;
	}
	bool movePiece(int startRow, int startColumn, int endRow, int endColumn) {
		if (board[startRow][startColumn] == nullptr)
			return false;
		if (board[endRow][endColumn] != nullptr && board[endRow][endColumn]->is_White() == board[startRow][startColumn]->is_White())
			return false;

		if (board[startRow][startColumn]->isValidMove(endRow, endColumn) == false)
			return false;
		if( isPathClear(startRow, startColumn, endRow, endColumn)==false)
			return false;
		if (temp != nullptr) {
			delete temp;
			temp = nullptr;
		}
		
		if (board[endRow][endColumn] != nullptr &&( (board[startRow][startColumn]->is_White()) != (board[endRow][endColumn]->is_White()))) {
			temp = board[endRow][endColumn];
			temp->update_Position(endRow, endColumn);
			
		}
		
		board[endRow][endColumn] = board[startRow][startColumn];
		board[endRow][endColumn]->update_Position(endRow, endColumn);
		if (board[endRow][endColumn]->getName() == 'P' || board[endRow][endColumn]->getName() == 'p') {
			board[endRow][endColumn]->firstMoveFalse();
		}
		
		board[startRow][startColumn] = nullptr;
		
		return true;
	}
	bool isPathClear(int startRow, int startColumn, int endRow, int endColumn) {
		// ----ROOK----
		if (board[startRow][startColumn]->getName() == 'R' || board[startRow][startColumn]->getName() == 'r') {
			// COLUMN MOVEMENT
			if (startRow == endRow) {
				// RIGHT TO LEFT
				if (endColumn > startColumn) {
					for (int j = startColumn + 1; j < endColumn; j++) {
						if (board[startRow][j] != nullptr)
							return false;

					}
					return true;
				}
				// LEFT TO RIGHT 
				else {
					for (int j = endColumn + 1; j < startColumn; j++) {
						if (board[startRow][j] != nullptr)
							return false;
					}
					return true;
				}
			}
			// ROW MOVEMENT
			else {
				// UP TO DOWN
				if (endRow > startRow) {
					for (int i = startRow + 1; i < endRow; i++) {
						if (board[i][startColumn] != nullptr)
							return false;
					}
					return true;
				}
				// DOWN TO UP
				else {
					for (int i = endRow + 1; i < startRow; i++) {
						if (board[i][startColumn] != nullptr)
							return false;

					}
					return true;
				}
			}
		}
		// ----BISHOP----
		if (board[startRow][startColumn]->getName() == 'B' || board[startRow][startColumn]->getName() == 'b') {
			// DIGONAL UP TO DOWN
			if (startRow < endRow&& startColumn < endColumn) {
				for (int i = startRow + 1, j = startColumn + 1; i < endRow; i++, j++) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}
			// DIGONAL DOWN TO UP
			else if (startRow > endRow && startColumn > endColumn) {
				for (int i = startRow - 1, j = startColumn - 1; i > endRow; i--, j--) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}
			// SECONDARY DIGONAL DOWN TO UP
			else if (startRow > endRow && startColumn < endColumn) {
				for (int i = startRow - 1, j = startColumn + 1; i > endRow; i--, j++) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}
			// SECONDARY DIGONAL UP TO DOWN 
			else if (startRow<endRow && startColumn>endColumn) {
				for (int i = startRow + 1, j = startColumn - 1; i < endRow; i++, j--) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}

		}
		// ----KNIGHT----
		if (board[startRow][startColumn]->getName() == 'N' || board[startRow][startColumn]->getName() == 'n')
			return true;
		// ----QUEEN----
		if (board[startRow][startColumn]->getName() == 'Q' || board[startRow][startColumn]->getName() == 'q') {
			// COLUMN MOVEMENT
			if (startRow == endRow) {
				// RIGHT TO LEFT
				if (endColumn > startColumn) {
					for (int j = startColumn + 1; j < endColumn; j++) {
						if (board[startRow][j] != nullptr)
							return false;

					}
					return true;
				}
				// LEFT TO RIGHT 
				else {
					for (int j = endColumn + 1; j < startColumn; j++) {
						if (board[startRow][j] != nullptr)
							return false;
					}
					return true;
				}
			}
			// ROW MOVEMENT
			else if(startColumn==endColumn){
				// UP TO DOWN
				if (endRow > startRow) {
					for (int i = startRow + 1; i < endRow; i++) {
						if (board[i][startColumn] != nullptr)
							return false;
					}
					return true;
				}
				// DOWN TO UP
				else {
					for (int i = endRow + 1; i < startRow; i++) {
						if (board[i][startColumn] != nullptr)
							return false;

					}
					return true;
				}
			}
			// DIGONAL UP TO DOWN
			if (startRow < endRow&& startColumn < endColumn) {
				for (int i = startRow + 1, j = startColumn + 1; i < endRow; i++, j++) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}
			// DIGONAL DOWN TO UP
			else if (startRow > endRow && startColumn > endColumn) {
				for (int i = startRow - 1, j = startColumn - 1; i > endRow; i--, j--) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}
			// SECONDARY DIGONAL DOWN TO UP
			else if (startRow > endRow && startColumn < endColumn) {
				for (int i = startRow - 1, j = startColumn + 1; i > endRow; i--, j++) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}
			// SECONDARY DIGONAL UP TO DOWN 
			else if (startRow<endRow && startColumn>endColumn) {
				for (int i = startRow + 1, j = startColumn - 1; i < endRow; i++, j--) {
					if (board[i][j] != nullptr)
						return false;
				}
				return true;
			}

		}
		// ----PAWN----
		if (board[startRow][startColumn]->getName() == 'P' || board[startRow][startColumn]->getName() == 'p') {
			// DIGONAL CHECK 
			if (startColumn != endColumn) {
				if (board[endRow][endColumn]!=nullptr)
					return true;
				return false;
			}
			// FRONT CHECK
			if (startRow < endRow) {
				if (board[startRow + 1][startColumn] != nullptr)
					return false;
				return true;
			}
			else
				if (board[startRow - 1][startColumn] != nullptr)
					return false;
			return true;
		}
		if (board[startRow][startColumn]->getName() == 'K' || board[startRow][startColumn]->getName() == 'k') {
			return true;
		}
		return true;

	}
	// print
	void print()const {
		cout << endl;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		cout << "      ";
		for (int k = 0; k < 8; k++) {
			cout << k <<"    ";
		}
		cout << "\n------------------------------------------";
		cout << endl ;
		for (int i = 0; i < 8; i++) {
			SetConsoleTextAttribute(hConsole, 12);
			cout <<" " << i << "    ";
			for (int j = 0; j < 8; j++) {



				if (board[i][j] != nullptr) {
					SetConsoleTextAttribute(hConsole, 7);
					cout << board[i][j]->getName() << "    ";
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 11);
					cout << "." << "    ";
				}
			}
			cout << endl<<endl;
			SetConsoleTextAttribute(hConsole, 12);
		}
		cout << "------------------------------------------\n";
		cout << "      ";
		for (int k = 0; k < 8; k++) {
			cout << k << "    ";
		}
		cout << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}

	bool check_isWhite(int startRow, int startColumn) {
		if (board[startRow][startColumn] == nullptr)
			return false;
		return (board[startRow][startColumn]->is_White());
	}
	~Board() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				delete board[i][j];
			}
		}
	}
	bool isCheck(bool isWhiteTurn) {
		row = -1;
		column = -1;
		if (isWhiteTurn == true) {
		
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[i][j] != nullptr) {
						if (board[i][j]->is_White() == true && (board[i][j]->getName() == 'K' || board[i][j]->getName() == 'k')) {
							row = i;
							column = j;
							break;
						}
					}
				}
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[i][j] != nullptr && board[i][j]->is_White() ==false) {
						if (board[i][j]->isValidMove(row, column) == true) {
							if (isPathClear(i, j, row, column) == true) {
								return true;
							}
						}

					}
				}
			
			}
			return false;
		}
		else if (isWhiteTurn == false) {
		
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[i][j] != nullptr) {
						if (board[i][j]->is_White() == false && (board[i][j]->getName() == 'K' || board[i][j]->getName() == 'k')) {
							row = i;
							column = j;
						}
					}
				}
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (board[i][j] != nullptr && board[i][j]->is_White() == true){
						if (board[i][j]->isValidMove(row, column) == true) {
							if (isPathClear(i, j, row, column) == true) {
								return true;
							}
						}
					}
				}
			}
			return false;
		}
	}
	void undo(int startRow, int startColumn, int endRow, int endColumn) {
		board[startRow][startColumn] = board[endRow][endColumn];
		board[startRow][startColumn]->update_Position(startRow, startColumn);
		board[endRow][endColumn] = temp;
		temp = nullptr;
		if (board[startRow][startColumn]->getName() == 'P' || board[startRow][startColumn]->getName() == 'p') {
			if (startRow == 1 || startRow == 6) {
				board[startRow][startColumn]->firstMoveTrue();
			}
		}

	}
	bool isCheckMate(bool isWhiteTurn) {
		for (int startRow = 0; startRow < 8; startRow++) {
			for (int startColumn = 0; startColumn < 8; startColumn++) {
				if (board[startRow][startColumn] != nullptr && (board[startRow][startColumn]->is_White() == isWhiteTurn)) {
					for (int endRow = 0; endRow < 8; endRow++) {
						for (int endColumn = 0; endColumn < 8; endColumn++) {
							if (movePiece(startRow, startColumn, endRow, endColumn) == true) {
								if (isCheck(isWhiteTurn) == false) {
									undo(startRow, startColumn, endRow, endColumn);
									return false;
								}
								undo(startRow, startColumn, endRow, endColumn);
							}
						}
					}
				}
			}
		}

		return true;
	}


};

