#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

void addNode(int data){
    node* n = new node;
    node* temp = head;
    if (head == NULL){
        head = n;
        n->data = data;
        n->next = NULL;
    }
    else{
        while(temp != NULL){
            if (temp->next == NULL) {
                temp->next = n;
                n->next = NULL;
                n->data = data;
                temp = NULL;
            } 
            else  temp = temp->next;
        }
    }
}

void deleteNode(int n, int position){
    if (position == 0){
        node* temp = head;
        head = head->next;
        delete(temp);
    }
    else if (position == n){
        node* temp = head;
        while (temp->next->next != NULL){
		    temp = temp->next;
	    }
	    delete(temp->next);
    	temp->next = NULL;
    }
    else
    {   
        node* p = head;
        for (int i = 0; i < position - 1; i++){
            p = p->next;
        }
        node *temp = p->next;
	    p->next = p->next->next;
	    delete(temp);
    }
}    

void print(){
	node *temp = head;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main(){
    int n, index, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> index;
        addNode(index);
    }
    short position;
    cin >> position;
    deleteNode(n,position);
    print();
    return 0;
}
