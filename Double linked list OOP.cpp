#include <iostream>

using namespace std;

class doubleLinkedList{
    private:
    class node{
        public:
        int data;
        node*prev;
        node*next;
    
        node() : prev(NULL), next(NULL) {}
    
    };
    node*head;
    node*tail;

    public:
    doubleLinkedList():head(NULL),tail(NULL){
        cout<<"Linked list\n"<<endl;
    }

    void createNode(int x){
        node*newNode=new node;
        newNode->data=x;
    
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void showList(){
        node*cur=head;
    
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur=cur->next;
        }

        cout<<"\n\n"<<endl;
    }

    void showListReverse(){
        node*cur=tail;

        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur=cur->prev;
        }

        cout<<"\n\n"<<endl;
    }
    

};

int main(){

    doubleLinkedList DLL;

    DLL.createNode(12);
    DLL.createNode(6);
    DLL.createNode(79);
    DLL.createNode(65);
    DLL.createNode(87);
    DLL.createNode(4);
    DLL.createNode(0);

    DLL.showList();
    DLL.showListReverse();

    cout<<"\n\n"<<endl;
    return 0;
}



