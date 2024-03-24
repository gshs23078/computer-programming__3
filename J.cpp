#include <bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
using namespace std;
ll h(ll n){
// 근본 
	if(!n) return 0;
	return h(n-1)*2+1;
}
ll g(ll n){
// 삼각 
	if(n==0) return 0;
	if(n==1) return 2;
	ll k=g(n-2)+1+2*h(n-2)+1+2*h(n-1)+1;
	for(int i=n-2; i>=0; i--){
		k+=2*h(i)+2;
	}
	return k;
}
ll four(ll n){
	ll ans, min=(1<<30);
	if(n==0) return 0;
	for(int i=0; i<n; i++){
		ans=four(i)*2+h(n-i);
		if(ans<min) min=ans;
	}
	return min;
}
ll f(ll n){
// 사각 
	ll ans, min=(1<<30);
//	cout << "min: " << min << endl;
	if(n==0) return 0;
	for(int i=0; i<n; i++){
		ans=0;
		ans+=f(i);
		ans+=g(n-i);
		ans+=2*four(i);
		if(ans<min) min=ans;
	}
	return min;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	cout << f(n);
}
// no dp, only recursion
