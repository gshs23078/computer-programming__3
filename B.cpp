#include <iostream>
using namespace std;
int ans=0;
void f(int n){
	if(!n) return;
	f(n-1);
	for(int i=0; i<n; i++){
		cout << "*";
		ans++;
	}
	cout << "\n";
	f(n-1);
}
int main(){
	int n;
	cin >> n;
	f(n);
	cout << ans;
}
