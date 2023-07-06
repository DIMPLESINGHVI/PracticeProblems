
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d)
    {
        this->data=d;
        this->next = NULL;
    }
    
};

void insertatbeg(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
    
}

void insertattail(Node* &tail, int d)
{
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}


void display(Node* &head)
{   
    cout<<"Control is here\n";
    
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    
}
int main()
{
    //int d;  
    Node* node1 = new Node(10);
    Node* head = node1;
    insertatbeg(head,20);
    insertatbeg(head,30);
    display(head);
    cout<<endl;
    
    Node* tail = node1;
    insertattail(tail,40);
    insertattail(tail,50);
    insertattail(tail,60);
    
    display(head);
    
    

}    


