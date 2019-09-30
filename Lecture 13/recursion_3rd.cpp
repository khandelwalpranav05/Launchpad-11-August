#include <iostream>

using namespace std;

void mappedString(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch1 = str[0];
	string ros1 = str.substr(1);

	int ch1_int = ch1 - '0';
	ch1 = ch1_int + 'A' - 1;

	mappedString(ros1,ans+ch1);

	if(str.length()>1){

		char ch2 = str[1];

		int ch2_int = ch2 - '0';
		ch2 = ch2_int + 'A' - 1;

		if(ch1_int*10 + ch2_int <= 26){
			char second_char = ch1_int*10 + ch2_int + 'A' - 1;
			string ros2 = str.substr(2);
			mappedString(ros2,ans+second_char);
		}
	}

}

string code[] = {" ",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 

void keypad(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string key = code[ch-'0'];

	// keypad(ros,ans+key[0]); //Wrong Way
	// keypad(ros,ans+key[1]);
	// keypad(ros,ans+key[2]);
	// keypad(ros,ans+key[3]);

	for(int i=0;i<key.length();i++){
		keypad(ros,ans+key[i]);
	}
}

void printPermutations(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<str.length();i++){
		char ch = str[i];
		string ros = str.substr(0,i) + str.substr(i+1);
		printPermutations(ros,ans+ch);
	}
}

int counter = 0;

int countBoardPath(int start,int end){
	if(start==end){
		counter++;
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int i=1;i<=6;i++){
		count += countBoardPath(start+i,end);
	}

	return count;
}

int countMazePath(int startRow,int startCol,int endRow,int endCol){

	if(startRow==endRow and startCol==endCol){
		return 1;
	}

	if(startRow>endRow or startCol >endCol){
		return 0;
	}

	int count = 0;

	int veritcal = countMazePath(startRow+1,startCol,endRow,endCol);
	int horizontal = countMazePath(startRow,startCol+1,endRow,endCol);

	count = veritcal + horizontal;
	return count;
}

void printMazePath(int startRow,int startCol,int endRow,int endCol,string path){
	if(startRow==endRow and startCol==endCol){
		cout<<path<<endl;
		return;
	}

	if(startRow>endRow or startCol >endCol){
		//
		return;
	}

	printMazePath(startRow+1,startCol,endRow,endCol,path+"vertical -> ");
	printMazePath(startRow,startCol+1,endRow,endCol,path+"horizontal -> ");
}

void printBoardPath(int start,int end,string path){
	if(start==end){
		cout<<path<<endl;
		return;
	}

	if(start>end){
		return;
	}

	for(int i=1;i<=6;i++){
		char ch = i + '0';
		printBoardPath(start+i,end,path + "->" + ch);
	}
}


int main(){

    // char ch = '1';
    // int ch_int = '1' - '0';


    // // ch = ch - '0' + 64;
    // ch = ch + 'A' - '1';
    // cout<<ch<<endl;

    // mappedString("123","");

    // keypad("37","");

    // printPermutations("abc","");

    // cout<<countBoardPath(0,4)<<endl;
    // cout<<counter<<endl;

    // cout<<countMazePath(0,0,2,2)<<endl;
    // printMazePath(0,0,2,2,"");

	// printBoardPath(0,4,"");

	return 0;
}