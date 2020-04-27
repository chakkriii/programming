//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include <iostream>
using namespace std;
int arr[51], sum;

int findMin(int n){
	int sumByTwo = sum/2;
	int _max = 0;
	bool dp[n+1][sumByTwo+1];
	
	for(int i=0; i<n; i++){
 		dp[i][0] = true;	
	}
	for(int i=1; i<sumByTwo; i++){
		dp[0][i] = false;	
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sumByTwo; j++){
					
			if(j<arr[i-1]){
				dp[i][j] = dp[i-1][j];		
			}else{
				dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i-1]];		
			}
		}	
	}
	
	for(int j=sumByTwo; j>=0; j--){
		if(dp[n][j] == true){
			_max = j;	
			break;	
		}	
	}
	return sum - 2*_max;
}

int main()
{
	int t, n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t ;
	while(t--){
		cin >> n;
		sum = 0;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			sum += arr[i];
		}
		cout << findMin(n) << endl;
	}
	return 0;
}
