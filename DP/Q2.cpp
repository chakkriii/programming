// Question link : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include <iostream>
using namespace std;
int arr[101], sum;

bool findSubsetExist(int n){
	int sumByTwo = sum/2;
	bool dp[n+1][sumByTwo+1];
	
	for(int i=0; i<=n; i++){
 		dp[i][0] = true;	
	}
	for(int i=1; i<=sumByTwo; i++){
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
	return dp[n][sumByTwo];
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
		
		if(sum%2==0 && findSubsetExist(n) == true){
			cout << "YES" << endl;
			continue;
		}
			
		cout << "NO" << endl;
	}
	return 0;
}

// Time and space complexity O(N*(sum of N elements))
