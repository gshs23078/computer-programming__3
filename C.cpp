#include <iostream>
using namespace std;
void f(int n, char x, char y, char z){
	if(n<=0){
		return;
	}
	f(n-1, x, z, y);
	cout << "move disk " << n << " " << x << "->" << z << "\n";
	f(n-1, y, x, z);
}
int main(){
	int n;
	cin >> n;
	cout << (1<<n)-1 << "\n";
	f(n, 'A', 'B', 'C');
}
