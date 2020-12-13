#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* createNode(int data){
    node* temp = new node;
    temp->next = NULL;
    temp->data = data; 
    return temp;
}

node *addElement(node* p, int data){
	node* temp = createNode(data);
	p->next = temp;
	return temp;
}

node *addHead(node *l, int x){
	node *temp = new node;
	temp->data = x;
	temp->next = l;
	l = temp;
	return l;
}

node *addTail(node *l, int x){
	node *p = l;
	while (p->next != NULL){
		p = p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	p->next = temp;
	return l;
}

node *addAt(node *l, int position, int value){
	node *p = l;
	node *temp = new node;
	for (int i = 0; i < position-1; i++){
		p = p->next;
	}
	temp->data = value;
	temp->next = p->next;
	p->next = temp;
	
	return l;
}

void printList(node* p){
	node *temp = p;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main(){
	int n, x, position;
	cin >> n;
	cin >> x;
	node *l = createNode(x);
	node *p = l;
	for (int i = 1; i < n; i++){
		cin >> x;
		p = addElement(p, x);
	}
	cin >> position >> x;
	
	if (position == 0)
		l = addHead(l, x);	
	else if (position == n)
		l = addTail(l, x);
	else
		l = addAt(l, position, x);
		
	printList(l);
	return 0;
}
