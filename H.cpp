#include <iostream>
typedef long long int ll;
using namespace std;
ll mod=1e9+7;
ll pow(ll n){
	if(!n) return 1;
	ll p=pow(n/2);
	if(n&1) return p*p*2%mod;
	return p*p%mod;
}
ll f(ll n){
	if(!n) return 0;
	if(n==1) return 2;
	if(n&1) return (2+5*((pow(n+1)-4+mod)%mod*(mod+1)/3%mod)%mod-3*(n/2)+mod)%mod;
	return (5*2*(pow(n)-1)%mod*(mod+1)/3%mod-3*n/2+mod)%mod;
}
int main(){
	ll n;
	cin >> n;
	cout << f(n);
}
//이 코드로 G도 풀리긴 하지만... mod가 너무 난무하는 관계로...
