#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Bot{
public:
	int posx = 0;
	int posy = 0;

	Bot(int n, int m){
		maxx = m;
		maxy = n;
	}

	void move(char dir, int step, char* arr){
		arr[maxx*posy + posx] = '+';
		switch (dir){
			case 'U':
				posy -= step;
				for(int i = 0; i < step; i ++) arr[maxx*(posy-i) + posx] = '+';
				break;
			case 'D':
				for(int i = 0; i < step; i ++) arr[maxx*(posy+i) + posx] = '+';
				posy += step;
				break;
			case 'L':
				for(int i = 0; i < step; i ++) arr[maxx*posy + posx - i] = '+';
				posx -= step;
				break;
			case 'R':
				for(int i = 0; i < step; i ++) arr[maxx*posy + posx + i] = '+';
				posx += step;
				break;
		}
		//cout << dir << ", " << posx << ", " << posy << endl;
	}
private:
	int maxx, maxy;
};

int probe(char dir, char* arr, int n, int m, int x, int y){
	if (arr[m*y + x] == '#') return 0;
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
	
	while(arr[m*(y+i) + x + j] != '#' && x+j >= 0 && x+j < m && y+i >= 0 && y+i < n){
		step ++;
		x += j;
		y += i;
	}

	return step;
}

int main(){
	int n = 3;
	int m = 7;
	char matrix[n][m] = {
		{'.','.','.','#','.','.','.'}, 
		{'#','#','.','.','.','.','.'}, 
		{'.','.','.','.','.','.','.'}
	};
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cout << matrix[i][j];
		}
		cout << endl;
	}

	Bot bot(n, m);
	//string cmd = "UDD(RRD(R)*D)3";
	string cmd = "(RDRUL)5";
	cout << cmd << endl;

	stack<int> s;
	int lind, rind, iteration;

	for(int i = 0; i < cmd.length(); i ++){
		if(cmd[i] == '(') s.push(i);
		if(cmd[i] == ')' && cmd[i+1] != '*'){
			lind = s.top();
			s.pop();
			rind = i;
			string itsub = cmd.substr(rind+1, 1);
			int iteration = stoi(itsub);
			string sub = cmd.substr(lind+1, rind-lind-1);
			cout << sub << endl;
			string rep;
			for(int j = 0; j < iteration; j ++){
				rep += sub;
			}
			cmd.replace(lind, rind-lind+2, rep);
			cout << cmd << endl;
		}
	}
	while (cmd.length() > 0){
		int num = 1;
		if (cmd[0] != '('){
			while (cmd[num] == cmd[0]){
				num ++;
			}
			int step_probe = probe(cmd[0], &matrix[0][0], n, m, bot.posx, bot.posy);
			bot.move(cmd[0], step_probe > num ? num : step_probe, &matrix[0][0]);
			cmd.erase(0, num);
		}
		else{
			bot.move(cmd[1], probe(cmd[1], &matrix[0][0], n, m, bot.posx, bot.posy), &matrix[0][0]);
			cmd.erase(0, 4);
		}
	}
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
