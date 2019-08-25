#include <iostream>

using namespace std;

float sqrt(int n,int p){
	float ans = 1;

	float inc = 1;

	for(int i = 0;i<=p;i++){

		while(ans*ans<=n){
			ans = ans + inc;
			cout<<ans<<endl;
		}

		ans = ans - inc;
		inc = inc/10;

		cout<<ans<<endl;
	}

	return ans;	
}

int main(){

	cout<<sqrt(9,7)<<endl;

	return 0;
}