#include <iostream>
#include <cstdlib>
#define MAX_SIZE 50
using namespace std;
typedef char Elem;
typedef struct{
	Elem val[MAX_SIZE];
	int length;
}SqL;
//创建顺序表
void CreatList(SqL *&L,Elem a[],int n){
	for(int i=0;i<n;++i){
		L->val[i]=a[i];
	}
	L->length=n;
}
//初始化顺序表
void InitList(SqL *&L){
	L = (SqL*)malloc(sizeof(SqL));
	L -> length = 0 ;
}
//销毁线性表
void DestroyList(SqL *&L){
	free(L);
}
//判断线性表是否为空
bool ListEmpty(SqL &L){
	return L.length == 0 ;
}
//求线性表的长度
int ListLength(SqL &L){
	return L.length;
}
//输出线性表
void DispList(SqL &L){
	for(int i=0;i<L.length;++i){
		cout << L.val[i]<< " " ;
	}
	cout << endl ;
}
//按序号求线性表中的元素
bool GetElem(SqL &L,int i,Elem &e){
	if(i>0&&i<=L.length){
		e = L.val[i-1];
		return true;
	}else return false;
}
//按元素查找,查找元素e的位置
int LocateELem(SqL &L,Elem e){
	int i=0;
	while(i<L.length){
		if(L.val[i] == e){
			break;
		}
		++i;
	}
	if(i == L.length) return 0;
	else return i+1 ;
}
//再第i个位置插入元素e
bool ListInsert(SqL &L,int i,Elem e){
	if(i<1||i>L.length+1||L.length==MAX_SIZE)
		return false;
	for(int j=L.length;j>=i;--j){
		L.val[j]=L.val[j-1];
	}
	L.val[i-1] = e;
	++L.length;
	return true;
}
//删除第i个位置的元素，使用e返回该位置的元素值
bool ListDelete(SqL &L,int i,Elem &e){
	if(i<1||i>L.length){
		return false;
	}
	else{
		e = L.val[i-1];
		for(int j=i-1;j<L.length;++j){
			L.val[j]=L.val[j+1];
		}
		--L.length; 
		return true;
	}
}
void request(){
	SqL *L;
	InitList(L);
	char a[5]={'a','b','c','d','e'};
	CreatList(L,a,5);
	DispList(*L);
	cout << "The Length of the list : "<<ListLength(*L)<<endl;
	cout <<"The List is Empty ? " << ListEmpty(*L)<<endl;
	char temp;
	GetElem(*L,3,temp);
	cout << temp <<endl;
	cout << "The a is on the "<<LocateELem(*L,'a')<<endl;
	ListInsert(*L,4,'f');
	DispList(*L);
	ListDelete(*L,3,temp);
	DispList(*L);
	DestroyList(L);
}
int main(){
	request();
	return 0;
}
