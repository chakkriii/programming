// stock span problem: https://practice.geeksforgeeks.org/problems/stock-span-problem/0
#include <iostream>
#include<stack>

using namespace std;
int arr[201];
int stockSpan[201];

void printStockSpan(int n){
	stack<int> s;
	stockSpan[0] = 1;

	for(int i=0; i<n; i++){
		while(!s.empty() && arr[i]>arr[s.top()]){
			s.pop();				
		}
		if(!s.empty()){
			stockSpan[i] = i - s.top(); 		
		}else{
			stockSpan[i] = i + 1;
		}
		s.push(i);
	}

	for(int i=0;i<n;i++){
		cout << stockSpan[i] << " ";	
	}
}


int main()
{
	int t, n;
	//freopen("Testcase.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> t;
	while (t-- > 0) {

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		printStockSpan(n);
		cout << "\n";
	}
	return 0;
}
//complexity O(n);
