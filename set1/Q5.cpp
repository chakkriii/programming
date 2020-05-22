//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
#include <iostream>
#include<deque>
using namespace std;
int arr[10000001];

void printMax(int n, int k){
	deque<int> dq;
	for(int i=0;i<k;i++){
		while((!dq.empty()) && arr[dq.back()] < arr[i]){
			dq.pop_back();		
		}
		dq.push_back(i);
	}
	cout << arr[dq.front()] << " ";

	for(int i=k; i<n; i++){
		while((!dq.empty()) && i - dq.front() >= k){dq.pop_front();}
		while((!dq.empty()) && arr[dq.back()] < arr[i]){
			dq.pop_back();		
		}
		dq.push_back(i);
		cout << arr[dq.front()] << " ";
	}
}


int main()
{
	int t, n, k;
	//freopen("Testcase.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> t;
	while (t-- > 0) {

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		printMax(n,k);
		cout << "\n";
	}
	return 0;
}
// Time Complexity O(n)

