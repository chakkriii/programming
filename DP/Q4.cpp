//https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
#include <iostream>
using namespace std;

int countSteps(int n){
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
	}	
	return dp[n];
}

int main()
{
	int t,n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t ;
	while(t--){
		cin >> n;
		cout << countSteps(n) << endl;
	}
	return 0;
}
// Time and space complexity O(n)
