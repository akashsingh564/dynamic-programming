#include <bits/stdc++.h>
using namespace std;

int primes[]={1,2,3,5,7,11,13,17,19,23,29};
int visited[10]={0};

long long dp[2005][2005]={0};

int n,tw;
long long p[2005];
int w[2005];
vector <long long> v;


int main(){
    cin>>n>>tw;
    for(int i=1;i<=n;i++)
    	cin>>p[i]>>w[i];
    	
   	for(int i=0;i<=n;i++){
   		for(int j=0;j<=tw;j++){
   			if(i==0 || j==0)
   				dp[i][j]=0;
   			else if(j<w[i])
   				dp[i][j]=dp[i-1][j];
   			else
   				dp[i][j]=max(dp[i-1][j],(p[i]+dp[i-1][j-w[i]]));
   		}
   	}
   	
   	/*for(int i=0;i<=n;i++){
   		for(int j=0;j<=tw;j++)
   			cout<<dp[i][j]<<" ";
   		cout<<endl;
   	}*/
   	
   	int x=n,y=tw;
   	while(x>0 && y>0){
   		if(dp[x][y]!=dp[x-1][y]){
   			//cout<<"found item "<<x<<" wt "<<y<<endl;
   			v.push_back(p[x]);
   			y=y-w[x];
   			x=x-1;
   			//cout<<"changed "<<x<<" "<<y<<endl;
   		}
   		else{
   			//cout<<"coundnt load item "<<x<<" wt "<<y<<endl;
   			x=x-1;
   		}
   	}
   	
   	int j=10;
   	sort(v.begin(),v.end());
   	long long ans=0;
   	for(int i=v.size()-1;i>=0;i--){
   		ans+=(v[i]*primes[j--]);
   		if(j<0) j=0;
   	}
   	cout<<ans<<endl;
   	
   	
   	
    return 0;
}
