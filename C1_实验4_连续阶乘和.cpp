#include <iostream>
using namespace std;
int SumFactorial(int n){
	int sum=0;
	int t=1;
	for(int i=1;i<=n;++i){
		t*=i;
		//cout << t << endl;
		sum+=t;
	}
	return sum;
}
int main(){
	int t;
	cout << "Please input t: ";
	cin >> t ;
	cout << SumFactorial(t);
	return 0;
}
