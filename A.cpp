#include <iostream>
using namespace std;
int f(int n, int k){
	if(k==1 || n==k) return 1;
	return f(n-1, k-1)+f(n-1, k);
}
int main(){
	int n, k;
	cin >> n >> k;
	cout << f(n, k);
}
