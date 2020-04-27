//https://practice.geeksforgeeks.org/problems/path-in-matrix/0
#include <iostream>
using namespace std;
int arr[21][21];

int maximum(int a, int b, int c){
	return max(a,max(b,c));	
}

int maxPath(int n){
	int dp[21][21];
	int left, right, _max = -1;
	for(int i=0; i<n; i++){
		dp[0][i] = arr[0][i];	
	}
	for(int i=1;i<n;i++){
		for(int j=0; j<n; j++){
			if(j-1<0){
				left = 0;
			}
			else{
				left = dp[i-1][j-1];
			} 	

			if(j+1>=n){
				right = 0;
			}
			else{
				right = dp[i-1][j+1];
			} 
	
			dp[i][j] = arr[i][j] + maximum(left, dp[i-1][j], right);
		}	
	}

	for(int i=0;i<n;i++){
		if(dp[n-1][i] > _max){
			_max = dp[n-1][i];		
		}	
	}
	return _max;
}

int main()
{
	int t,n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t ;
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> arr[i][j];			
			}	
		}
		cout << maxPath(n) << endl;
	}
	return 0;
}
// Time and space complexity O(N*N)
