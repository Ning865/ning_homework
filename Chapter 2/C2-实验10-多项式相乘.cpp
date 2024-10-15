#include <iostream>
using namespace std;
struct poly{
	double coef;
	int exp;
};
typedef struct polynode{
	double coef;
	int exp;
	polynode *next;
}Node;
void Initploy(Node *&L){
	L = (Node*)malloc(sizeof(Node));
	L -> next =NULL;
}
void CreatT(Node *&L,poly a[],int n){
	Node *s;
	Node *p=L;
	for(int i=0;i<n;++i){
		s =(Node*)malloc(sizeof(Node));
		s ->coef = a[i].coef;
		s->exp=a[i].exp;
		p->next = s;
		p=s;
	}
	p->next = NULL;
}
void Destroy(Node *&L){
	Node *p=L->next,*q;
	while(p!=NULL){
		q=p->next;
		free(p);
		p=q;
	}
	free(p);
}
void Sort(Node *&L){
/*	Node *p=L->next->next;
	Node *w=L->next;
	w->next=NULL;
	Node *q=p,*mvp=L,*qn,*mv;
	while(q!=NULL){
		qn=q->next;
		mv=L->next;
		mvp=L;
		while(mv->exp > q->exp && mv!=NULL){
			mvp=mv;
			mv=mv->next;
		}
		
		mvp->next=q;
		q->next=mv;
		q=qn;
	}
	*/
	Node *p=L->next,*pre,*q;
	q=p->next;
	p->next=NULL;
	p=q;
	while(p!=NULL){
		q=p->next;
		pre=L;
		while(pre->next!=NULL&&pre->next->exp > p->exp)
			pre=pre->next;
		p->next=pre->next;
		pre->next=p;
		p=q;
	}
}
void Disp(Node *&L){
	Node *p=L->next;
	while(p!=NULL){
		cout << p->coef ;
		if(p->exp!=0) cout << "x^" << p->exp;
		if(p->next!=NULL) cout << " + ";
		p=p->next;
	}
	cout << endl;
}
void Mult(Node *L1,Node *L2,Node *&h){
	Node *p=L1->next,*s,*hp=h;
	while(p!=NULL){
		Node *q=L2->next;
		while(q!=NULL){
			s=(Node*)malloc(sizeof(Node));
			s->coef= p->coef * q->coef;
			s->exp=p->exp + q->exp;
			hp->next=s;
			hp=s;
			q=q->next;
		}
		p=p->next;
	}
}
void Comb(Node *&L){
	Sort(L);
	Node *pre=L->next,*p;
	p=pre->next;
	while(p!=NULL){
		while(p->exp == pre->exp){
			pre -> coef += p->coef;
			pre->next = p->next;
			free(p);
			p=pre->next;
		}
		pre=p;
		p=p->next;
	}
	
}
void test(){
	Node *h1,*h2,*h3;
	Initploy(h1);
	Initploy(h2);
	Initploy(h3);
	poly a[2]={{1,2},{1,0}};
	poly b[2]={{1,4},{1,0}};
	CreatT(h1,a,2);
	CreatT(h2,b,2);
	Mult(h1,h2,h3);
	Comb(h3);
	Disp(h3);
	Destroy(h1);
	Destroy(h2);
	Destroy(h3);
}
int main(){
	test();
	return 0;
}
