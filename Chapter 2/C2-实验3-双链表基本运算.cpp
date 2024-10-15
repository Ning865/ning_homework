#include <iostream>
using namespace std;
typedef char Elemtype;
typedef struct DLinkNode{
	Elemtype data;
	DLinkNode *next;
	DLinkNode *prior;
}Dnode;
//建立双链表
//头插法
void CreatListH(Dnode *&L,Elemtype e[],int n){
	Dnode *s;
	L = (Dnode*)malloc(sizeof(Dnode));
	L->prior=NULL;
	L->next = NULL;
	for(int i=0;i<n;++i){
		s = (Dnode*)malloc(sizeof(Dnode));
		s -> data = e[i];
		if(L->next!=NULL)
			L->next->prior=s;
		s->next=L->next;
		s->prior=L;
		L->next=s;
	}
}
//尾插法
void CreatListT(Dnode *&L,Elemtype e[],int n){
	Dnode *s,*p;
	L=(Dnode*)malloc(sizeof(Dnode));
	L->prior=L->next=NULL;
	p=L;
	for(int i=0;i<n;++i){
		s = (Dnode*)malloc(sizeof(Dnode));
		s ->data = e[i];
		p->next=s;
		s->prior=p;
		s->next=NULL;
		p=s;
	}
	p->next = NULL;
}
//初始化线性表
void InitList(Dnode *&L){
	L = (Dnode*)malloc(sizeof(Dnode));
	L->next=L->prior=NULL;
}
//销毁线性表
void DestoryList(Dnode *&L){
	Dnode *p,*q;
	p=L;
	q=L;
	while(p!=NULL){
		p=p->next;
		free(q);
		q=p;
	}
	free(q);
}
//判断顺序表是否为空
bool ListEmpty(Dnode *L){
	return L->next==NULL;
}
//求线性表的长度
int ListLength(Dnode *L){
	int cnt=0;
	Dnode *p=L->next;
	while(p!=NULL){
		++cnt;
		p=p->next;
	}
	return cnt;
}
//输出线性表
void DispList(Dnode *L){
	Dnode *p=L->next;
	while(p!=NULL){
		cout << p->data << " ";
		p=p->next;
	}
	cout << endl;
}
//按序号求第i个元素，使用e存储返回
bool GetELem(Dnode *L,int i,Elemtype &e){
	if(i<=0) return false;
	int j=0;
	Dnode *p=L;
	while(j<i&&p!=NULL){
		++j;
		p=p->next;
	}
	if(p==NULL) return false;
	else{
		e=p->data;
		return true;
	}
}
//按元素查找元素e所在的位置
int LocateElem(Dnode *L,Elemtype e){
	int i=0;
	Dnode *p=L;
	while(p!=NULL&&p->data!=e){
		++i;
		p=p->next;
	}
	if(p==NULL) return 0;
	else return i;
}
//插入元素
bool ListInsert(Dnode *&L,int i,Elemtype e){
	if(i<=0) return false;
	Dnode *s,*p=L;
	int j=0;
	s = (Dnode*)malloc(sizeof(Dnode));
	s->data = e ;
	while(j<i&&p!=NULL){
		++j;
		p=p->next;
	}
	if(p==NULL) return false;
	p->prior->next=s;
	s->prior=p->prior;
	s->next=p;
	return true;
}
//删除指定元素
bool ListDelete(Dnode *&L,int i,Elemtype &e){
	if(i<=0) return false;
	Dnode *p=L;
	int j=0;
	while(j<i && p!=NULL){
		++j;
		p=p->next;
	}
	if(p==NULL) return false;
	e=p->data;
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
	return true;
}
void test(){
	Dnode *L;
	InitList(L);
	char a[5]={'a','b','c','d','e'};
	CreatListT(L,a,5);
	DispList(L);
	cout << ListLength(L)<<endl;
	if(ListEmpty(L)) cout <<"Empty!" <<endl;
	else cout <<"Not empty!" <<endl;
	char t;
	GetELem(L,3,t);
	cout << t <<endl;
	cout << LocateElem(L,'a')<<endl;
	ListInsert(L,4,'f');
	DispList(L);
	ListDelete(L,3,t);
	DispList(L);
	DestoryList(L);
}
int main(){
	test();
	return 0;
}

