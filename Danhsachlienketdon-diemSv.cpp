#include <bits/stdc++.h>
using namespace std;
struct Node{
	string name;
	int marks;
	Node* next;
};
void InsertFirst(Node*& head, string vname, int vmarks){
	Node *newnode = new Node;
	newnode->name= vname;
	newnode->marks=vmarks;
	newnode->next=head;
	head = newnode;
}
void DeleteFirst(Node*& head){
	if(head==NULL){
		return;
	}
	Node *temp=head;
	head=temp->next;
	delete temp;
}
int Count(Node* head, int vmarks){
    int count = 0;
    while (head != NULL) {
        if (head->marks != vmarks) {
            count++;
        }
        head = head->next;
    }
    return count;
}
int main(){
	Node *head=NULL;
	string kt;
	while(true){
		cin >> kt;
		if(kt == "ins"){
			string name;
			int marks;
			cin >> name >> marks;
			InsertFirst(head,name,marks);
		}else if(kt =="del"){
			DeleteFirst(head);
		}else if(kt =="count"){
			int marks;
			cin >> marks;
			int count = Count(head,marks);
			cout << count <<endl;
		}else if(kt =="fin"){
			break;
		}
	}
	return 0;
}

