#include <bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<ll,ll> p;

ll n,k,x,y;

struct node{
	ll finish;
	ll start;
	ll cost;
};

node a[25];
ll dp[25];

bool acompare(node lhs, node rhs) { return lhs.finish < rhs.finish; }

int main(){
    cin>>n>>k;
    for(ll i=0;i<k;i++)
    	cin>>a[i].cost;
    for(ll i=0;i<k;i++)
    	cin>>a[i].start>>a[i].finish;
    sort(a,a+k,acompare);
    for(int i=0;i<k;i++)
    	dp[i]=a[i].cost;
    for(ll i=1;i<k;i++)
    	for(ll j=0;j<i;j++)
    		if(a[j].finish<a[i].start)
    			dp[i]=max(dp[i],dp[j]+a[i].cost);
    			
    ll ans=dp[0];
    for(ll i=1;i<k;i++)
    	ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
