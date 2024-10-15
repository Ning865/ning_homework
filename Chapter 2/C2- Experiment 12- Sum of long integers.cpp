#include <iostream>
#include <string>
using namespace std;
struct Node{
	int val;
	Node *next;
};
void Creat(Node *&L,string a){
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	Node *s;
	for(int i=0 ;i<(int)a.size();++i){
		s=(Node*)malloc(sizeof(Node));
		s->val = (a[i]-'0');
		s->next=L->next;
		L->next = s;
	}
}
int Length(Node *L){
	Node *p=L->next;
	int i=0;
	while(p!=NULL){
		++i;
		p=p->next;
	}
	return i;
}
void Disp(Node *&L){
	Node *p=L->next;
	while(p!=NULL){
		cout << p->val ;
		p=p->next;
	}
}
void Add(Node *&L1,Node *&L2,Node *&L3){
	Node *p=L1->next,*p2=L2->next;
	L3 = (Node*)malloc(sizeof(Node));
	L3->next=NULL;
	Node *s,*p3=L3;
	while(p!=NULL && p2!=NULL){
		s=(Node*)malloc(sizeof(Node));
		s->val = p->val + p2->val;
		s->next = NULL;
		p3->next=s;
		p3=s;
		p=p->next;
		p2=p2->next;
	}
	while(p!=NULL){
		s=(Node*)malloc(sizeof(Node));
		s->val=p->val;
		s->next = NULL ;
		p3->next = s;
		p3=s;
		p=p->next;
	}
	while(p2!=NULL){
		s=(Node*)malloc(sizeof(Node));
		s->val=p2->val;
		s->next = NULL ;
		p3->next = s;
		p3=s;
		p2=p2->next;
	}
}
void Dest(Node *&L){
	Node *p=L->next,*q=L;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
}
void Simpty(Node *&L){
	Node *p=L->next,*s;
	while(p!=NULL){
		if(p->val>=10){
			if(p->next == NULL ){
				p->val-=10;
				s=(Node*)malloc(sizeof(Node));
				s->val  = 1;
				p->next=s;
				s->next=NULL;
			}else{
				p->val %= 10;
				p->next->val++;
			}
		}
		p=p->next;
	}
	Node *h=L->next,*q;
	L->next= NULL;
	while(h!=NULL){
		q=h->next;
		h->next=L->next;
		L->next = h;
		h=q;
	}
}
void test(){
	string t1,t2;
	cout << "请输入操作数1：";
	cin >> t1;
	cout<<"请输入操作数2：";
	cin >> t2;
	Node *h1,*h2,*h3;
	Creat(h1,t1);
	Creat(h2,t2);
	Add(h1,h2,h3);
	Simpty(h3);
	cout << "相加结果为：";
	Disp(h3);
	Dest(h1);
	Dest(h2);
	Dest(h3);
}
int main(){ 
	test();
	return 0;
}
