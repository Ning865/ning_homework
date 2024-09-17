#include <iostream>
#include <ctime>
#include <math.h>
#include <windows.h>
using namespace std;
bool IsPrime01(int e){
	if(e<=1) return false;
	for(int i=2;i<=e/2;++i){
		if(e%i == 0) return false;
	}
	return true;
}
bool IsPrime02(int e){
	if(e<=1) return false;	
	for(int i=2;i<=sqrt(e);++i){
		if(e%i == 0) return false;
	}
	return true;
}
int CntPrime01(int a[],int n){
	int cnt=0;
	for(int i=0;i<n;++i){
		if(IsPrime01(a[i])) ++cnt;
	}
	return cnt;
}
int CntPrime02(int a[],int n){
	int cnt=0;
	for(int i=0;i<n;++i){
		if(IsPrime02(a[i])) ++cnt;
	}
	return cnt;
}
int main(){
	int a[100];
	for(int i=1;i<=100;++i){
		a[i]=i;
	}
	cout << CntPrime01(a,100)<<endl;
	cout << CntPrime02(a,100)<<endl;
	return 0;
}
