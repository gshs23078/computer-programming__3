#include <iostream>
using namespace std;
typedef long long int ll;
ll cnt=0;
ll mod=1e9+7;
void f(ll n, char x, char y, char z){
	if(!n) return;
	if(cnt>=100) return;
	f(n-1, x, y, z);
	if(cnt<100) cout << n << " : " << x << "->" << y << "\n";
	else return;
	cnt++;
	if(cnt>=100) return;
	f(n-1, z, y, x);
	if(cnt<100) cout << n << " : " << y << "->" << z << "\n";
	else return;
	cnt++;
	if(cnt>=100) return;
	f(n-1, x, y, z);
	if(cnt>=100) return;
	return;
}
ll pow(ll n){
	if(!n) return 1;
	ll p=pow(n/2)*pow(n/2)%mod;
	if(n&1) return p*3%mod;
	return p%mod;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	f(n<100?n:100, 'A', 'C', 'B');
	cout << pow(n)-1;
}
