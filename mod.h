#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;	
	Node(int item){
		this->data=item;
		this->next=NULL;
	}
};
class LinkedList
{

	Node *head,*tail;
	int size;

public:
	LinkedList(){
		this->head=NULL;
		this->tail=NULL;
		this->size=0;
	}
	void addFirst(int item){
		Node *nn=new Node(item);
		if(this->head==NULL){
			this->tail=nn;
			this->head=nn;
		}else{
			nn->next=this->head;
			this->head=nn;
		}
		this->size++;
	}


	void addLast(int item){
		Node *nn=new Node(item);
		if(this->head==NULL){
			this->tail=nn;
			this->head=nn;

		}else{
			this->tail->next=nn;
			this->tail=nn;
		}
		this->size++;
	}

	void display(){
		Node *temp=this->head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<"\n-----------------"<<endl;
	}

	int Size(){
		return this->size;
	}

	Node* getFirstNode(){
		return this->head;
	}

	Node* getLastNode(){
		return this->tail;
	}

	Node* getNodeAt(int idx){
		if(idx<0 || idx>=this->size){
			throw idx;
		}else{
			Node* temp=this->head;
			for (int i = 0; i < idx; ++i)
			{
				temp=temp->next;
			}
			return temp;
		}
	}
	void addAt(int idx,int item){
		if(idx<0 || idx>this->size){
			throw idx;
		}else{
			if(idx==0){
				this->addFirst(item);
			}else if(idx==this->size){
				this->addLast(item);
			}else{
				Node* mnm=getNodeAt(idx-1);
				Node* nn=new Node(item);
				nn->next=mnm->next;
				mnm->next=nn;
				this->size++;

			}

		}
	}

	int removeFirst(){
		if(this->head==NULL){
			cout<<"LinkedList is Empty";
			throw 1;

		}else{
			Node* res=this->head;
			this->head=this->head->next;
			this->size--;
			return res->data;
		}
	}
	int removeLast(){
		if(this->head==NULL){
			cout<<"LinkedList is Empty";
			throw 1;

		}else{
			int mr=this->tail->data;
			this->tail=getNodeAt(this->size-2);
			this->size--;
			return mr;
		}
	}

	int removeAt( int idx){
		if(this->head==NULL || idx<0 || idx>=this->size){
			throw 2;
		}

		if(idx==0){
			return this->removeFirst();
		}else if(idx==this->size-1){
			return this->removeLast();
		}else{
			Node* nn=getNodeAt(idx-1);
			Node* mr=nn->next;
			nn->next=nn->next->next;
			this->size++;
			return mr->data;
		}

	}
	void reverseDI(){
		for (int i = 0; i < this->size/2; ++i)
		{
			Node* first=getNodeAt(i);
			Node* last=getNodeAt(this->size-1-i);
			int data=first->data;
			first->data=last->data;
			last->data=data;

			
		}
	}

	void reversePI(){
		Node *curr,*next,*prev;
		curr=this->head;
		next=NULL;
		prev=NULL;
		while(curr!=NULL){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		next=this->head;
		this->head=this->tail;
		this->tail=next;
	}


	void reverseDR(){
		reverseDR(this->head,this->head,0);
	}
private:
	Node* reverseDR(Node* left,Node* right,int count){
		if(right==NULL){
			return left;
		}

		Node* nn=reverseDR(left,right->next,count+1);
		if(count>=this->size/2){
			int data=nn->data;
			nn->data=right->data;
			right->data=data;
		}
		return nn->next;
	}
public:

	
};
