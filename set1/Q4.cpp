//https://practice.geeksforgeeks.org/problems/edit-distance/0
#include<iostream>
#include<algorithm>
using namespace std;
char str1[101], str2[101];
int dp[101][101];

int minimum(int a, int b, int c){
	return min(min(a,b),c);
}
	
int getMinDistance(int p, int q){
	// insert p,q-1 , remove p-1,q ,  replace p-1, q-1
	for(int i=0; i<p; i++){
		dp[i][0] = i;	
	}
	
	for(int j=0; j<q; j++){
		dp[0][j] = j;	
	}

	for(int i=0; i<p; i++){
		for(int j=0; j<q; j++){
			if(str1[i]==str2[j]){
				dp[i][j] = dp[i-1][j-1];			
			}else{
				dp[i][j] = 1 + minimum(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
			}
		}
	}	
	return dp[p-1][q-1];
}	

int main(){
	int t, p, q;
	freopen("Testcase.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	while(t--){
		cin >> p >> q;
		cin >> str1 >> str2;
		cout << getMinDistance(p,q) << "\n";
	}

	return 0;
}
//time & space complexity O(m*n);
