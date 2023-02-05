#include <iostream>
using namespace std;
char matrex[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';
void printmatrex() {
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrex[i][j] << "	";
		}
		cout << endl;
	}
}
void play() {
	char pos;
	cout << "chose your position - player ( " << player << ")  : ";
	cin >> pos;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrex[i][j] == pos) {
				matrex[i][j] = player;
			}
		}

	}
	if (player == 'X')
		player = 'O';
	else
		player = 'X';

}

char whowin() {
	int xc = 0, Oc = 0;
	int counter = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrex[i][j] != 'x' || matrex[i][j] != 'O') {
				counter++;
			}
				
				
			if (matrex[i][j] == 'X')xc++;
			else if (matrex[i][j] == 'X')Oc++;
			if (xc == 3 || Oc == 3) {
				return xc > Oc ? 'x' : 'O';
			}
		}
		xc = 0;
		Oc = 0;

	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrex[j][i] == 'X')xc++;
			else if (matrex[j][i] == 'X')Oc++;
			if (xc == 3 || Oc == 3) {
				return xc > Oc ? 'x' : 'O';
			}
		}
		xc = 0;
		Oc = 0;

	}
	if (matrex[0][0] == 'x' && matrex[1][1] == 'x' && matrex[2][2] == 'x')return'x';
	else if (matrex[0][0] == 'O' && matrex[1][1] == 'O' && matrex[2][2] == 'O')return'O';
	else if (matrex[0][2] == 'x' && matrex[1][1] == 'x' && matrex[2][0] == 'x')return'x';
	else if (matrex[0][2] == 'O' && matrex[1][1] == 'O' && matrex[2][0] == 'O')return'O';

	if (counter == 0)return 'Z';
	return '.';
}

int main() {
	while (whowin() == '.') {
		printmatrex();
		play();
	}
	printmatrex();
	if (whowin() == 'z')
		cout << "\nNo winneer !! \n\n" << endl;
	else
		cout << "\nthe  winner is player (" << whowin() << ")  , mbrooooooook ! ! ! \n\n";
	system("pause");


	return 0;
}