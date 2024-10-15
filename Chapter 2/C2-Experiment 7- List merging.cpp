#include <iostream>
#include "link_list.cpp"
using namespace std;
void Merging(LinkNode *h1,LinkNode *h2,LinkNode *&h3){
    LinkNode *p1=h1->next,*p2=h2->next,*p3;
	h3=h1;
    p3=h3;
    free(h2);
    while(p1!=NULL && p2!=NULL){
        p3->next=p1;
        p3=p1;
        p1=p1->next;
        p3->next=p2;
        p3=p2;
        p2=p2->next;
    }
    p3->next=NULL;
	if(p2!=NULL) p3->next=p2;
	else p3->next= p1;
}
void test(){
    LinkNode *L1,*L2,*L3;
    int a[5]={1,3,5,7,9};
    int b[5]={2,4,6,8,10};
    CreatListR(L1,a,5);
    CreatListR(L2,b,5);
    Merging(L1,L2,L3);
    DispList(L3);
    DestoryList(L3);
}
int main(){
    test();
    return 1;
}
