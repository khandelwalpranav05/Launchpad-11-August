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


}


int main(){

    // char ch = '1';
    // int ch_int = '1' - '0';


    // // ch = ch - '0' + 64;
    // ch = ch + 'A' - '1';
    // cout<<ch<<endl;

    mappedString("123","");

	return 0;
}