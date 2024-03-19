#include <iostream>
#include <math.h>
using namespace std;
int ans=0;
void f(int n, char x, char y, char z){
	if(n<=0) return;
	int p, q, r;
	p=x;q=y;r=z;
	if(abs(p-r)==1){
		f(n-1, x, z, y);
		cout << n << " : " << x << "->" << z << "\n";
		ans++;
		f(n-1, y, x, z);
	}
	if(abs(p-r)==2){
		f(n, x, z, y);
		f(n, y, x, z);
	}
	return;
}
int main(){
	int n;
	cin >> n;
	f(n, 'A', 'B', 'C');
	cout << ans;
}
