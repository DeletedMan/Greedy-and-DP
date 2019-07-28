#include <bits/stdc++.h> 
using namespace std; 
int longestSubsequence(int a[], int n) 
{ 
	unordered_map<int, int> mp;  
	int dp[n]; 
	memset(dp, 0, sizeof(dp)); 
	int maximum = INT_MIN; 
	for (int i = 0; i < n; i++) {  
		if (mp.find(a[i] - 1) != mp.end()) { 
			int lastIndex = mp[a[i] - 1] - 1; 
			dp[i] = 1 + dp[lastIndex]; 
		} 
		else
			dp[i] = 1; 
		mp[a[i]] = i + 1; 
		maximum = max(maximum, dp[i]); 
	} 

	return maximum; 
} 

int main() 
{ 
	int a[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	cout << longestSubsequence(a, n); 
	return 0; 
} 
