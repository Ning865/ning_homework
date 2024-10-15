#include <iostream>
#define MAX_SIZE 50
using namespace std;
class ASet{
public:
	int val[MAX_SIZE];
	int length;
	ASet(){}
	ASet(int a[],int n){
		for(int i=0;i<n;++i){
			this->val[i]=a[i];
		}
		this->length = n;
	};
	~ASet(){}
	void CreatAset(int a[],int n);
	void DispAset();
	bool IsElem(int e);
	ASet Intersection(ASet &rhs);//交集
	ASet Difference(ASet &rhs);//差集
	ASet Union(ASet &rhs);//并集
};
void ASet::CreatAset(int a[],int n){
	for(int i=0;i<n;++i){
		this->val[i] = a[i];
	}
	this->length = n ;
}
void ASet::DispAset(){
	for(int i=0;i<this->length;++i){
		cout << val[i] << " ";
	}
	cout << endl;
}
bool ASet::IsElem(int e){
	for(int i=0;i<this->length;++i){
		if(this->val[i]==e){
			return true;
		}
	}
	return false;
}
ASet ASet::Union(ASet &rhs){
	ASet res;
	for(int i=0;i<this->length;++i){
		res.val[i]=this->val[i];
	}
	res.length = this->length ;
	for(int i=0,j=this->length;i<rhs.length;++i){
		if(!res.IsElem(rhs.val[i])){
			res.val[j]=rhs.val[i];
			++j;
			++res.length;
		}
	}
	return res;
}
ASet ASet::Difference(ASet &rhs){
	ASet res;
	res.length=0;
	if(this->length >= rhs.length){
		for(int i=0,j=0;i<this->length;++i){
			if(!rhs.IsElem(this->val[i])){
				res.val[j]=this->val[i];
				++j;
				++res.length;
			}
		}
	}else{
		for(int i=0,j=0;i<rhs.length;++i){
			if(!this->IsElem(rhs.val[i])){
				res.val[j]=rhs.val[i];
				++j;
				++res.length;
			}
		}
	}
	return res;
}
ASet ASet::Intersection(ASet &rhs){
	ASet res;
	res.length = 0 ;
	if(this->length>=rhs.length){
		for(int i=0,j=0;i<this->length;++i){
			if(rhs.IsElem(this->val[i])){
				res.val[j]=this->val[i];
				++j;
				++res.length;
			}
		}
	}else{
		for(int i=0,j=0;i<rhs.length;++i){
			if(this->IsElem(rhs.val[i])){
				res.val[j]=rhs.val[i];
				++j;
				++res.length;
			}
		}
	}
	return res;
}
void test(){
	int a[5]={1,2,3,4,8};
	int b[6]={1,2,3,4,5,6};
	ASet T1(a,5);
	ASet T2;
	T2.CreatAset(b,6);
	T1.DispAset();
	T2.DispAset();
	cout << T1.length << " " << T2.length << endl ;
	cout << T1.IsElem(5)<< " "<<T2.IsElem(5)<<endl;
	ASet T3;
	T3 = T1.Union(T2);
	T3.DispAset();
	cout << T3.length << endl;
	T3 = T2.Intersection(T1);
	T3.DispAset();
	cout << T3.length << endl;
	T3 = T1.Difference(T2);
	T3.DispAset();
	cout << T3.length ;
}
int main(){
	test();
	return 0;
}

