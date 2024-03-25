#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
using namespace std;
ll H[101]={0}, G[101]={0};
ll Four[101]={0}, F[101]={0};
ll h(ll n){
// 근본 
	if(H[n]) return H[n];
	if(!n) return H[n]=0;
	ll k=h(n-1)*2+1;
	if(k>(1LL<<60) || k<0) return H[n]=-1;
	return H[n]=k;
}
ll g(ll n){
// 삼각 
	if(G[n]) return G[n];
	if(n==0) return G[n]=0;
	if(n==1) return G[n]=2;
	if(h(n-1)<0) return G[n]=-1;
	ll k=g(n-2)+2*h(n-2)+4*h(n-1)+3;
	if(k>(1LL<<60)) return G[n]=-1;
	return G[n]=k;
}
ll four(ll n){
// 기둥 4개 
	if(Four[n]) return Four[n];
	ll ans, min=(1LL<<60);
	if(n==0) return Four[n]=0;
	for(ll i=0; i<n; i++){
		if(four(i)<0 || h(n-i)<0)
			continue;
		ans=four(i)*2+h(n-i);
		if(ans>(1LL<<60)) continue;
		if(ans<min) min=ans;
	}
	if(min==(1LL<<60)) min=-1;
	return Four[n]=min;
}
ll f(ll n){
// 사각 
	if(F[n]) return F[n];
	ll ans, min=(1LL<<60);
	if(n==0) return F[n]=0;
	for(ll i=0; i<n; i++){
		ans=0;
		if(f(i)<0) continue;
		if(g(n-i)<0) continue;
		if(four(i)<0) continue;
		ans+=f(i);
		ans+=g(n-i);
		ans+=2*four(i);
		if(ans>(1LL<<60)) continue;
		if(ans<min) min=ans;
	}
	if(min==(1LL<<60)) return F[n]=-1;
	return F[n]=min;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	cout << f(n);
}
// dp (memoization)
