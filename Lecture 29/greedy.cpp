#include <iostream>
#include <algorithm>

using namespace std;

class ActivityTime{
public:
	int start;
	int end;

	ActivityTime(int start,int end){
		this->start = start;
		this->end = end;
	}

	ActivityTime(){}
};

int compare(ActivityTime a,ActivityTime b){
	return a.end<b.end;
}

int maxActivity(int startTime[],int endTime[],int n){

	ActivityTime arr[6];

	for(int i=0;i<n;i++){
		ActivityTime obj(startTime[i],endTime[i]);
		arr[i] = obj;
	}

	sort(arr,arr+n,compare);

	for(int i=0;i<n;i++){
		cout<<"start "<<arr[i].start<<" end "<<arr[i].end<<endl;
	}

	int numActivity = 1;

	int check = arr[0].end;

	for(int i=1;i<n;i++){

		if(check<=arr[i].start){
			numActivity++;
			check = arr[i].end;
		}
	}

	return numActivity;
}

// int maxCircles(){

// }

int deepakAndJourney(int cost[],int dist[],int n){

	int minCost = cost[0];

	int ans = cost[0]*dist[0];

	for(int i=1;i<n;i++){

		if(cost[i]<minCost){
			minCost = cost[i];
		}

		ans += minCost*dist[i];
	}

	return ans;
}

int main(){

	int startTime[] = {7,0,4,8,4,5};
	int endTime[] = {9,10,5,9,10,7};

	cout<<maxActivity(startTime,endTime,6)<<endl;

	return 0;
}