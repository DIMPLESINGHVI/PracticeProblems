#include <iostream>

using namespace std;

class Node
{
    public:
            int data;
            Node* next;
            Node* prev;
        Node(int val)
        {
            this->data = val;
            this->next = NULL;
            this->prev = NULL;
        }

};

void insertAttail(Node* &head,Node* &tail,int val)
{
    if(tail == NULL)
    {
        Node* temp = new Node(val);
        tail = temp;
        head = temp;
    }
    else
   {
        Node* temp = new Node(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
   }
}

void display(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* fwd = NULL;
    while(curr!=NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        curr->prev = fwd;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

int main()
{
    //cout<<"Hello World";
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAttail(head,tail,10);
    insertAttail(head,tail,20);
    insertAttail(head,tail,30);
    insertAttail(head,tail,40);
    insertAttail(head,tail,50);
    
   // reverse()
    display(head);
    Node* newhead = reverse(head);
    display(newhead);
    return 0;
}
