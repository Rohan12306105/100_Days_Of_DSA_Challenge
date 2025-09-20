/*
https://leetcode.com/problems/valid-sudoku/submissions/1777126464/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9], cols[9], boxes[9];
        for(int i = 0; i<9; i++){
            for(int j = 0;j<9; j++){
                char c = board[i][j];
                if(c=='.')continue;
                int boxidx = (i/3)*3 + (j/3);
                if(row[i].count(c) || cols[j].count(c) || boxes[boxidx].count(c)) return false;
                row[i].insert(c);
                cols[j].insert(c);
                boxes[boxidx].insert(c);
            }
        } 
        return true;
    }
};


/*
cb explaination - kartik mathur



#include<bits/stdc++.h>
#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;


bool safeHai(int matrix[][9], int i, int j, int n, int no) {
	//  row mei and column mei no present nhi hona chahiyee
	for (int k = 0; k < n; ++k){
		if (matrix[i][k] == no || matrix[k][j] == no) {
			return false;
		}
	}
	// Chote wale box mei number nhi hona chahiye
	n = sqrt(n);

	int x = (i / n) * n;
	int y = (j / n) * n;

	for (int i = x; i < x + n; ++i){
		for (int j = y; j < y + n; ++j){
			if (matrix[i][j] == no) {
				return false;
			}
		}
	}

	return true;// Safe hai
}









bool sudokuSolver(int matrix[][9], int i, int j, int n) {
	// base case
	if (i == n) { // Matlab poora sudoku solve ho gaya n-1th index tak

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}
	// Jab j matrix ke size se bahar ho jaaye
	if (j == n) {
		return sudokuSolver(matrix, i + 1, 0, n);
	}

	//  Agar cell already filled hai, toh recursion ko bolo aage jaa
	if (matrix[i][j] != 0) {
		return sudokuSolver(matrix, i, j + 1, n);
	}





	// recursive case
	// 1 se n tak, empty cell par ek number rakh kar dekhenge
	for (int no = 1; no <= n; ++no){
		if (safeHai(matrix, i, j, n, no) == true) {
			// Agar no rakhna safe hai toh rakho
			matrix[i][j] = no;

			// Ab baaki ka recursion ko bolo solve krne ko
			bool kyaBaakiSolveHua = sudokuSolver(matrix, i, j + 1, n);
			if (kyaBaakiSolveHua == true) { // Agar ho gaya baaki solve,
				//toh baat ban gai
				return true;
			}

			// If nhi hua solve, toh jo number rakha hai vo sahi nhi hai
			matrix[i][j] = 0; // Backtracking
		}
	}

	// Agar 1 se n tak koi bhi number nhi rakh paaye toh, yeh solve nhi hoga
	return false;
}








int main() {

	int matrix[9][9] =
	{	{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	sudokuSolver(matrix, 0, 0, 9);


	return 0;
}

*/