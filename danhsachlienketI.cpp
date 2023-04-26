#include <bits/stdc++.h>
struct Node{
	int data;
	Node* next;
};
Node *newnode(int x){
	Node *temp = new Node;
	temp->data=x;
	temp->next=NULL;
	return temp;
}
int count(Node *head){
	int dem=0;
	while(head != NULL){
		dem++;
		head=head->next;
	}
	return dem;
}
void InsertLast(Node *&head,int x){
	Node *temp = newnode(x);
	if(head == NULL){
		head = temp;
	}else{
		Node *p=head;
		while(p->next != NULL){
			p=p->next;
		}
		p->next = temp;
	}
}
void Delete(Node *&head,int del){
	int n = count(head);
	Node *after = NULL, *before = head;
	if(del <= 0 || del >n){
		return ;
	}
	for(int i=1;i<del;i++){
		after = before;
		before = before->next;
	}
	if(after==NULL){
		head = head->next;
	}else{
		after->next=before->next;
	}
}
long long Sum(Node *head){
	int s=0;
	Node* tmp = head;
	while(tmp !=NULL){
		s+=tmp->data;
		tmp=tmp->next;
	}
	return s;
}
int main(){
	Node* head=NULL;
	int n,x,p;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		InsertLast(head,x);
	}
	char Kitu;
	while(scanf("%s",&Kitu)){
		switch(Kitu){
			case 'i':
				scanf("%d",&x);
				InsertLast(head,x);
				break;
			case 'd':
				scanf("%d",&p);
				Delete(head,p);	
				break;
			case 's':
				printf("%ld",Sum(head));
				printf("\n");
			break;
			case '0':
				return 0;	
		}
	}
	return 0;
}
