// Question link : https://practice.geeksforgeeks.org/problems/k-largest-elements/0
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printKMax(int k,vector<int> arr){
	make_heap(arr.begin(), arr.end());
	for (int i = 0; i < k; i++) {
		cout << arr[0] << " ";
		pop_heap(arr.begin(), arr.end());
	}
	cout << "\n";
}

int main()
{
	int t, n, k, input;
	freopen("Testcase.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	while (t-- > 0) {
		vector<int> arr;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> input;
			arr.push_back(input);
		}
		printKMax(k,arr);
	}
	return 0;
}

/*;
max-heap,
complexity of build = O(n);
complexity of removing k max = log(n) + log(n-1) +... log(n-k)
overall complexity = O(n) + k*Olog(n)
*/
