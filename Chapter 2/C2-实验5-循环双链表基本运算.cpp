#include <iostream>
using namespace std;
typedef char Elem;
typedef struct LinkNode{
	Elem data;
	LinkNode *prior;
	LinkNode *next;
}DNode;
void InitList(DNode *&L){
	L=(DNode*)malloc(sizeof(DNode));
	L->next=L;
	L->prior=L;
}
void CreatListH(DNode *&L,Elem a[],int n){
	DNode *s;
	for(int i=0;i<n;++i){
		s =(DNode*)malloc(sizeof(DNode));
		s->data = a[i];
		s->next=L->next;
		L->next->prior=s;
		L->next=s;
		s->prior=L;
	}
}
void CreatListT(DNode *&L,Elem a[],int n){
	DNode *s,*p=L;
	for(int i=0;i<n;++i){
		s=(DNode*)malloc(sizeof(DNode));
		s->data = a[i];
		s->next = p->next;
		p->next->prior=s;
		s->prior=p;
		p->next=s;
		p=s;
	}
}
void DispList(DNode *&L){
	DNode *p=L->next;
	while(p!=L){
		cout << p->data << " ";
		p=p->next;
	}
	cout << endl;
}
bool LsitEmpty(DNode *&L){
	return L->next == L ;
}
int ListLength(DNode *&L){
	DNode *p=L->next;
	int i=0;
	while(p!=L){
		++i;
		p=p->next;
	}
	return i;
}
void DestroyList(DNode *&L){
	DNode *p=L->next,*q;
	while(p!=L){
		q=p->next;
		free(p);
		p=p->next;
	}
	free(q);
}
bool GetElem(DNode *&L,int i,Elem &e){
	if(i<=0) return false;
	DNode *p=L->next;
	int j=1;
	while(j<i&&p!=L){
		++j;
		p=p->next;
	}
	if(p==L) return false;
	else{
		e = p->data;
		return true;
	}
}
int LocateElem(DNode *&L,Elem e){
	int j=1;
	DNode *p=L->next;
	while(p!=L&&p->data!=e){
		++j;
		p=p->next;
	}
	if(p==L) return 0;
	else return j;
}
bool ListInsert(DNode *&L,int i,Elem e){
	if(i<=0) return false;
	DNode *p=L->next,*q=L,*s;
	int j=1;
	while(j<i&&p!=L){
		++j;
		q=p;
		p=p->next;
	}
	if(p==L) return false;
	else{
		s = (DNode*)malloc(sizeof(DNode));
		s->data = e;
		q->next->prior=s;
		s->next=q->next;
		s->prior=q;
		q->next=s;
	}
	return true;
}
bool ListDelete(DNode *&L,int i,Elem &e){
	if(i<=0) return false;
	DNode *p=L->next,*q=L;
	int j=1;
	while(j<i&&p!=L){
		++j;
		q=p;
		p=p->next;
	}
	if(p!=L){
		e = q->data;
		q->next=p->next;
		p->next->prior=p;
		free(p);
		return true;
	}else return false;
}
void test(){
	DNode *h;
	InitList(h);
	char a[5]={'a','b','c','d','e'};
	CreatListT(h,a,5);
	DispList(h);
	cout << "The Length : "<<ListLength(h)<<endl;
	if(LsitEmpty(h)) cout<<"The list is empty!"<<endl;
	else cout << "The List is't empty!" <<endl;
	char t;
	GetElem(h,3,t);
	cout << "t: "<<t <<endl;
	cout << LocateElem(h,'a')<<endl;
	ListInsert(h,4,'f');
	DispList(h);
	ListDelete(h,3,t);
	DispList(h);
	DestroyList(h);
}
int main(){
	test();
	return 0;
}
