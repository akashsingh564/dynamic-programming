#include <bits/stdc++.h>
using namespace std;

long long power[1000001]={1};
long long hashed[1000001];
unordered_set <long long> s;
string a;
int len;



/*#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power[100];
ll hashed[100];
string p,t;

int main(){
    cin>>p>>t;
    ll pl=p.size();
    ll tl=t.size();
    ll ph=0;
    for(ll i=0;i<=tl;i++)
        power[i]=pow(3,i);
    for(ll i=0;i<pl;i++)
        ph+=(p[i]*power[i+1]);
    for(ll i=1;i<=tl;i++)
        hashed[i]=hashed[i-1]+(t[i-1]*power[i]);
    for(ll i=pl;i<=tl;i++){
        ll hashval=(hashed[i]-hashed[i-pl])/pow(3,(i-pl));
        if(hashval==ph){
            cout<<i-pl+1<<endl;
            break;
        }
    }
    return 0;
}*/




int match(int l){
	s.clear();
	for(int i=0;i+l<=len;i++){
		long long q=hashed[i+l]-hashed[i];
		q*=power[1000000-i];
		if(s.find(q)!=s.end())
			return 1;
		s.insert(q);
	}
	return 0;
}

int main(){
	cin>>a;
	len=a.size();
    for(int i=1;i<=1000000;i++)   /**** chain hashing****/
    	power[i]=power[i-1]*173;
    for(int i=1;i<=len;i++)
    	hashed[i]=hashed[i-1]+(a[i-1]*power[i-1]);
    
    /*while(l<r){    /**** BS for maching substring of len k ****/
    	int mid=(l+r+1)/2;
    	if(match(mid))
    		l=mid;
    	else
    		r=mid-1;
    }
    cout<<l<<endl;*/
    
    int l=0,r=len,found=0;
    for(int i=len-1;i>=0;i--){
    	if(match(i)){
    		found=i;
    		break;
    	}
    }
    if(found) cout<<found<<endl;
    else cout<<"0"<<endl;
    
    return 0;
}
