#include<iostream>

using namespace std;


class circular_queue{
private:
    class node{
        public:
            int data;
            node*next;
            node*prev;
        
            node():next(NULL),prev(NULL){}
        
    };
    node*head;
    node*tail;

public:
    circular_queue():head(NULL),tail(NULL){}

    void push(int x){
        node*newNode=new node;
        newNode->data=x;

        if(head==NULL){
            head=tail=newNode;
        } else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            tail->next=head;
            head->prev=tail;
        }
    }

    void pop(){
        if(head!=NULL){
            node*temp=head;
            head=head->next;
            head->prev=tail;
            tail->next=head;

            delete temp;
        }
    }

    void show(){
        node*cur=head;
        do{
            cout<<cur->data<<" ";
            cur=cur->next;
        }while(cur!=head);
        cout<<"\n\n\n\n"<<endl;
    }

    void showReverse(){
        node*cur=tail;
        do{
            cout<<cur->data<<" ";
            cur=cur->prev;
        }while(cur!=tail);
        cout<<"\n\n\n\n"<<endl;
    }


};

int main(){
    circular_queue Q;

    Q.push(34);
    Q.push(25);
    Q.push(6);
    Q.push(25);
    Q.push(56);
    Q.push(7);
    Q.push(8);
    Q.push(1);

    Q.show();

    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();


    Q.show();

    return 0;
}
