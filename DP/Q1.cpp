// Question link : https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
#include <iostream>
using namespace std;
char str1[101], str2[101];

int maximum(int a, int b){
	if(a>b){
		return a;	
	}else{
		return b;	
	}
}

int LCS(int a, int b){
	int dp[a+1][b+1];

	for(int i=0; i<=a; i++){
		dp[i][0] = 0;
	}
	for(int j=1; j<=b; j++){
		dp[0][j] = 0;	
	}

	for(int i=1; i<=a; i++){
		for(int j=1; j<=b; j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];			
			}else{
				dp[i][j] = maximum(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[a][b];
}

int main()
{
	int t, a, b;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t ;
	while(t--){
		cin >> a >> b;
		cin >> str1 >> str2;
		cout << LCS(a,b) << endl;
	}
	return 0;
}

// Time Complexity O(axb)
// Space complexity O(axb)
