#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int val)
    {
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
    
    ~Node()
    {
        int val = this->data;
        if(this->next!=NULL && this->prev!=NULL)
        {
            delete next;
            delete prev;
            this->next = NULL;
            this->prev = NULL;
        }
    }
};

void InsertAthead(Node* &head,Node* &tail,int val)
{
    if(head==NULL)   //if list is empty
    {
        Node* temp = new Node(val);
        head = temp;
        tail = temp;
    }
    else
    {   Node* temp = new Node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}    

void InsertAtTail(Node* &head,Node* &tail,int val)
{
    if(tail==NULL)   //if list is empty
    {
        Node* temp = new Node(val);
        tail=temp;
        head=temp;
    }
    else
    {
        Node* temp = new Node(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp; 
    }
 
}


void Insertatpos(Node* &head,Node* &tail,int pos,int val)
{
    if(pos==1)
    {
        InsertAthead(head,tail,val);
        return;
    }
    
    int cnt=1;
    Node* temp=head;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }
    
    if(temp->next ==NULL)
    {
        InsertAtTail(head,tail,val);
        return;
    }
    
    Node* node2ins = new Node(val);
    node2ins->next = temp->next;
    temp->next->prev = node2ins;
    temp->next = node2ins;
    node2ins->prev = temp;

}


void display(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}



int getlen(Node* &head)
{
    int cnt=0;
    Node* temp = head;
    while(temp!=NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    //Node* node1  = new Node(10);  //when list is not empty
    //Node* head = node1;
    //Node* tail = node1;
    
    Node* head = NULL; //when list is empty
    Node* tail = NULL;
    cout<<"\nInsert at head:\n";
    InsertAthead(head,tail,20);
    InsertAthead(head,tail,30);
    display(head);
    
    cout<<"\nInsert at tail:\n";
    InsertAtTail(head,tail,40);
    InsertAtTail(head,tail,50);
    display(head);

    cout<<"\nInsert at position 2:\n";
    Insertatpos(head,tail,2,60);
    display(head);
    cout<<"\nInsert at position 1:\n";
    Insertatpos(head,tail,1,70);
    display(head);
    cout<<"\nInsert at position 7:\n";
    Insertatpos(head,tail,7,80);
    display(head);
    cout<<"\nLength of doubly linked list:"<<getlen(head)<<endl;
   
    return 0;
}
