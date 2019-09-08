#include<iostream>

using namespace std;

int main(){

		int arr[6][6]= {{1, 2, 3, 4, 5, 6},
						{7, 8, 9, 10,11,12},
						{13,14,15,16,17,18},
						{19,20,21,22,23,24},
						{25,26,27,28,29,30},
						{31,32,33,34,35,36}};


	int maxRow = 5;
	int maxCol = 5;
	int minCol = 0;
	int minRow = 0;
	int num_of_elements = 0;

	while(num_of_elements<36){

		for(int i=minRow;i<=maxRow;i++){
			cout<<arr[i][minCol]<<" ";
			num_of_elements++;
		}
		minCol++;

		for(int i=minCol;i<=maxCol;i++){
			cout<<arr[maxRow][i]<<" ";
			num_of_elements++;
		}
		maxRow--;

		for(int i=maxRow;i>=minRow;i--){
			cout<<arr[i][maxCol]<<" ";
			num_of_elements++;
		}
		maxCol--;

		for(int i=maxCol;i>=minCol;i--){
			cout<<arr[minRow][i]<<" ";
			num_of_elements++;
		}
		minRow++;

	}


	return 0;
}