#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> >& matrix, int rowSize, int colSize) {
	for(int i = 0; i < rowSize; i++) {
		for(int j = 0; j < colSize; j++) {
			cout << matrix[i][j] << " ";
		}
		cout<<endl;
	}
}

void setRowColToZero(vector<vector<int> >& matrix, int row, int col) {
	vector<int> rowVec(row, 0);
	vector<int> colVec(col, 0);

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(matrix[i][j] == 0) {
				rowVec[i] = 1;
				colVec[j] = 1;
			}
		}
	}	

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(rowVec[i] == 1 || colVec[j] == 1)
				matrix[i][j] = 0;
		}
	}
}

int main() {
	int rowSize = 3, colSize = 4;
	int num = 0;
	vector<vector<int> > matrix(rowSize, vector<int>(colSize));
	for(int i = 0;  i < rowSize; i++) {
		for(int j = 0; j < colSize; j++) {
			matrix[i][j] = num++;
		}
	}
	cout<<"Image before rotation"<<endl;
	printMatrix(matrix, rowSize, colSize);
	setRowColToZero(matrix, rowSize, colSize);
	cout<<"Image after rotation"<<endl;
	printMatrix(matrix, rowSize, colSize);
	return 0;
}
