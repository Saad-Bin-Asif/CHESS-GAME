#include<iostream>
#include"Board.h"
using namespace std;
int main() {
	Board b;
	bool isWhiteTurn = true;
	int startRow, startColumn, endRow, endColumn;
	while (true) {
		b.print();
		
		cout << "Enter Start Row - Column : ";
		cin >> startRow >> startColumn;
		if (isWhiteTurn == true && b.check_isWhite(startRow, startColumn) == true) {
			cout << "Enter End Row - Column : ";
			cin >> endRow >> endColumn;
			
			if (b.movePiece(startRow, startColumn, endRow, endColumn) == false) {
				cout << " Invalid Move!\n";
				system("pause");
				system("CLS");
				continue;
			}
			if (b.isCheck(true) == true) {
				b.undo(startRow, startColumn, endRow, endColumn);
				cout << " Check \n";
				system("pause");
				system("CLS");
				continue;
			}
			if (b.isCheck(false) == true)
			{
				cout << "Check!" << endl;
				if (b.isCheckMate(false) == true) {
					cout << " Check Mate! \n";
					cout << " white Wins! \n";
					system("pause");
					break;
				}
				system("pause");
				b.undo(startRow, startColumn, endRow, endColumn);
				system("CLS");
				continue;
			}
			system("CLS");
			isWhiteTurn=false;
			continue;
		}
		else if(isWhiteTurn ==true && b.check_isWhite(startRow,startColumn)==false){
			cout << " Whites Move! \n";
			system("pause");
			system("CLS");
			continue;
		}
		if (isWhiteTurn == false && b.check_isWhite(startRow, startColumn) == false) {
			cout << "Enter End Row - Column : ";
			cin >> endRow >> endColumn;
			if (b.movePiece(startRow, startColumn, endRow, endColumn) == false) {
				cout << " Invalid Move!\n";
				system("pause");
				system("CLS");
				continue;
			}
			if (b.isCheck(false) == true) {
				b.undo(startRow, startColumn, endRow, endColumn);
				cout << " Check \n";
				system("pause");
				system("CLS");
				continue;
			}
			if (b.isCheck(true) == true)
			{
				cout << "Check!" << endl;
				if (b.isCheckMate(true) == true) {
					cout << " Check Mate! \n";
					cout << " White  Wins! \n";
					system("pause");
					break;
				}
				system("pause");
				b.undo(startRow, startColumn, endRow, endColumn);
				system("CLS");
				continue;
				
			}
			system("CLS");
			isWhiteTurn = true;
			continue;
		}
		else if(isWhiteTurn ==false && b.check_isWhite(startRow,startColumn)==true) {
			cout << " Blacks Move! \n";
			system("pause");
			system("CLS");
			continue;

		}
	
			
	}
}

