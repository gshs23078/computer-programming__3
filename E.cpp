#include <iostream>
#include <math.h>
#include <limits>
using namespace std;
typedef long long int ll;
ll hanoi4[1000]={0};
ll f(ll n){
	if(hanoi4[n]) return hanoi4[n];
	if(n==1) return hanoi4[n]=1;
	ll min=numeric_limits<ll>::max();
	for(ll i=1; i<n; i++){
		ll k=2*f(i)+pow(2, n-i)-1;
		if(k<0) continue;
		if(k<min) min=k;
	}
	return hanoi4[n]=min;
}
int main(){
	ll n;
	cin >> n;
	cout << f(n);
}
