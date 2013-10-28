#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> >& matrix) {
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout<<endl;
	}
}

void rotateImage(vector<vector<int> >& img) {
	int N = img.size();

	for(int layer = 0; layer < N/2; ++layer) {
		int first = layer;
		int last = N - layer - 1;
		for(int i = first; i < last; i++) {
			int tmp = img[layer][i];
			img[layer][i] = img[last-(i-first)][layer];

			img[last-(i-first)][layer] = img[last][last-(i-first)];

			img[last][last-(i-first)] = img[i][last];

			img[i][last] = tmp;
			//cout<<"intermitent matrix"<<endl;
			//printMatrix(img);
		}
	}
}

int main() {
	int N = 5;
	int num = 1;
	vector<vector<int> > img(N, vector<int>(N));
	for(int i = 0;  i < img.size(); i++) {
		for(int j = 0; j < img[i].size(); j++) {
			img[i][j] = num++;
		}
	}
	cout<<"Image before rotation"<<endl;
	printMatrix(img);
	rotateImage(img);
	cout<<"Image after rotation"<<endl;
	printMatrix(img);
	return 0;
}
