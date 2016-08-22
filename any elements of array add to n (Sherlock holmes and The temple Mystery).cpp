#include <bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int a[105];

int main(){
    int t,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	int sum=0;
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    		sum+=a[i];
    	}
    	if(sum%2!=0){
   			cout<<"NO"<<endl;
    	}
   		else{
   			for(int j=0;j<(sum/2)+1;j++)
   				dp[0][j]=0;
   			dp[0][0]=dp[0][a[0]]=1;
   			
   			for(int i=1;i<n;i++){
   				for(int j=0;j<(sum/2)+1;j++){
   					if(j==0)
   						dp[i][j]=1;
   					else if(dp[i-1][j]==1)
   						dp[i][j]=1;
   					else if (dp[i-1][j-a[i]]==1)
   						dp[i][j]=1;
   					else
   						dp[i][j]=0;
   				}
   			}
   			
   			if(dp[n-1][sum/2]==1)
	   			cout<<"YES"<<endl;
	   		else
	   			cout<<"NO"<<endl;
   		}
    }
    return 0;
}
