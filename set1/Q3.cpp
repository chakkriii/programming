//https://practice.geeksforgeeks.org/problems/next-larger-element/0
#include <iostream>
#include<stack>

using namespace std;
long long int arr[10000001];

void printNGE(int n){
	stack<long long int> s;
	for(int i=0; i<n; i++){

		while(!s.empty() && arr[i] > arr[s.top()]){			
			cout << arr[i] << " ";
			s.pop(); 
		}

		s.push(i);
	}
	
	while(!s.empty()){
		 cout << -1 << " ";	
		s.pop();
	}
}


int main()
{
	int t, n;
	freopen("Testcase.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	while (t-- > 0) {

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		printNGE(n);
		cout << "\n";
	}
	return 0;
}
// Time complexity O(n);
