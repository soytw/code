#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arr[100000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,k;
	cin>>N>>k;
	for (int i=0; i<N; i++) cin>>arr[i];
	int ans = -1;
	for (int i=0; i<=N-k; i++) {
		int first=-1, second=-1;
		for (int j=i; j<i+k; j++) {
			if (arr[j] > first) {
				second = first;
				first = arr[j];
			}
			else if (arr[j] < first && arr[j] > second) second = arr[j];
		}
		ans = max(ans, second);
	}
	cout<<ans<<endl;
	return 0;
}