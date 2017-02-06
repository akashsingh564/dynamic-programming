#include <bits/stdc++.h>
using namespace std;

int dp[10005][10005];
int a[10005], b[10005];
int n,m;

int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];

	for(int i=1;i<=n;i++)
		for(int j=i;j<=m;j++)
			dp[i][j]=max(dp[i][j-1], (dp[i-1][j-1]+b[i-1]*a[j-1]));
	cout<<dp[n][m]<<endl;
}