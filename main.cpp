#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Bot{
public:
	int posx = 3;
	int posy = 1;

	Bot(){
	}

private:
};

int probe(char dir, int* arr, int n, int m, int x, int y){
	if (arr[m*y + x] != 0) return 0;
	int i = 0;
	int j = 0; 
	int step = 0;

	switch (dir){
		case 'U':
			i = -1;
			break;
		case 'D':
			i = 1;
			break;
		case 'L':
			j = -1;
			break;
		case 'R':
			j = 1;
			break;
	}
	
	while(arr[m*(y+i) + x + j] == 0 && x+j >= 0 && x+j < m && y+i >= 0 && y+i < n){
		step ++;
		x += j;
		y += i;
	}

	return step;
}

string cmd2mov(string inp){
	stack<int> st;
}

int main(){
	int n = 3;
	int m = 7;
	int matrix[n][m] = {
		{0,0,0,1,0,0,0}, 
		{0,0,0,1,0,0,0}, 
		{0,0,0,0,0,0,0}
	};
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 7; j ++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;

	Bot bot;
	/*
	cout << "U:" << probe('U', &matrix[0][0], n, m, bot.posx, bot.posy);
	cout << ", D:" << probe('D', &matrix[0][0], n, m, bot.posx, bot.posy);
	cout << ", L:" << probe('L', &matrix[0][0], n, m, bot.posx, bot.posy);
	cout << ", R:" << probe('R', &matrix[0][0], n, m, bot.posx, bot.posy);
	cout << endl;
	*/
	string cmd;
	cin >> cmd;
	cout << cmd << endl;
}
