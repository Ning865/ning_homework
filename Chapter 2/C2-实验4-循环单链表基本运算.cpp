#include <iostream>
using namespace std;
typedef char Elemtype;
typedef struct LinkNode{
	Elemtype data;
	LinkNode *next;
}Node;
void InitList(Node *&L){
	L=(Node*)malloc(sizeof(Node));
	L->next=L;
}
void CreatListH(Node *&L,Elemtype a[],int n){
	Node *s;
	for(int i=0;i<n;++i){
		s=(Node*)malloc(sizeof(Node));
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}
void CreatListT(Node *&L,Elemtype a[],int n){
	Node *p=L,*s;
	for(int i=0;i<n;++i){
		s=(Node*)malloc(sizeof(Node));
		s->data=a[i];
		s->next=p->next;
		p->next=s;
		p=s;
	}
}
void DispList(Node *&L){
	Node *p=L->next;
	while(p!=L){
		cout << p->data << " ";
		p=p->next;
	}
	cout << endl;
}
void DestroyList(Node *&L){
	Node *p=L->next,*q;
	while(p!=L){
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
}
int ListLength(Node *&L){
	Node *p=L->next;
	int i=0;
	while(p!=L){
		++i;
		p=p->next;
	}
	return i;
}
bool ListEmpty(Node *&L){
	return L->next==L ;
}
bool GetElem(Node *&L,int i,Elemtype &e){
	if(i<=0) return false;
	int j=1;
	Node *p=L->next;
	while(j<i && p!=L){
		++j;
		p=p->next;
	}
	if(p==L) return false;
	e = p->data;
	return true;
}
int LocateElem(Node *&L,Elemtype e){
	Node *p=L->next;
	int j=1;
	while(p->data!=e &&p!=L){
		++j;
		p=p->next;
	}
	if(p==L) return 0;
	else return j;
}
bool ListInsert(Node *&L,int i,Elemtype e){
	if(i<=0) return false;
	Node *p=L->next,*q=L,*s;
	s = (Node*)malloc(sizeof(Node));
	s->data = e;
	int j=1;
	while(j<i && p!=L){
		++j;
		q=p;
		p=p->next;
	}
	if(p==L) return false;
	s->next = q->next;
	q->next=s;
	return true;
}
bool ListDelete(Node *&L,int i,Elemtype &e){
	if(i<=0) return false;
	Node *p=L->next,*q=L;
	int j=1;
	while(j<i&&p!=L){
		++j;
		q=p;
		p=p->next;
	}
	if(p==L) return false;
	else{
		e=p->data;
		q->next=p->next;
		free(p);
		return true;
	}
}
void test(){
	Node *L;
	InitList(L);
	char a[5]={'a','b','c','d','e'};
	CreatListT(L,a,5);
	DispList(L);
	cout << "The length : " <<ListLength(L)<<endl;
	if(ListEmpty(L)) cout<<"The list is empty!"<<endl;
	else cout << "The List is't empty!" <<endl;
	char t;
	GetElem(L,3,t);
	cout << "t: "<<t <<endl;
	cout << LocateElem(L,'a')<<endl;
	ListInsert(L,4,'f');
	DispList(L);
	ListDelete(L,3,t);
	DispList(L);
	DestroyList(L);
}
int main(){
	test();
	return 0;
}
