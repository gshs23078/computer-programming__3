#include <iostream>
using namespace std;
typedef long long int ll;
ll f(ll n){
	if(!n) return 0;
	if(n==1) return 1;
	ll min=1e15;
	for(ll i=1; i<n; i++){
		ll k=2*f(i)+(1<<n-i)-1;
		if(k<min) min=k;
	}
	return min;
}
int main(){
	ll n;
	cin >> n;
	cout << f(n);
}
