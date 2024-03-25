#include <bits/stdc++.h>
#define endl "\n"
#define MAX 2147483647
using namespace std;
int h(int n){
// 근본 
	if(!n) return 0;
	return h(n-1)*2+1;
}
int g(int n){
// 삼각 
	if(n==0) return 0;
	if(n==1) return 2;
	return g(n-2)+2*h(n-2)+4*h(n-1)+3;
}
int four(int n){
// 기둥 4개
	int ans, min=MAX;
	if(n==0) return 0;
	for(int i=0; i<n; i++){
		ans=four(i)*2+h(n-i);
		if(ans<min) min=ans;
	}
	return min;
}
int f(int n){
// 사각 
	int ans, min=MAX;
	if(n==0) return 0;
	for(int i=0; i<n; i++){
		ans=f(i)+g(n-i)+2*four(i);
		if(ans<min) min=ans;
	}
	return min;
}
int main(){
	int n;
	cin >> n;
	cout << f(n);
}
// no dp, only recursion
