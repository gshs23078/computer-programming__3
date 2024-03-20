#include <iostream>
typedef long long int ll;
using namespace std;
ll pow(ll n){
	if(!n) return 1;
	ll p=pow(n/2);
	if(n&1) return p*p*2;
	return p*p;
}
ll f(ll n){
	if(!n) return 0;
	if(n==1) return 2;
	if(n&1) return 2+5*(pow(n+1)-4)/3-3*(n/2);
	return 5*2*(pow(n)-1)/3-3*(n/2);
}
int main(){
	ll n;
	cin >> n;
	cout << f(n);
}
