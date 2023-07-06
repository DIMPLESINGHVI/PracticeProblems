#include <iostream>

using namespace std;

class Node
{
    public:
            int data;
            Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

void insertathead(Node* &head,int item)
{
    Node* temp = new Node(item);
    temp->next = head;
    head = temp;
    
}

void insertatend(Node* &tail, int item)
{
    Node* temp = new Node(item);
    tail->next = temp;
    tail = temp;
}

void insertAtpos(Node* &head,Node* &tail,int pos,int item)
{
    if(pos==1)
    {
        insertathead(head,item);
        return;
    }
    
    Node* temp = head;
    int curr = 1;
    while(curr<pos-1)
    {
        temp = temp->next;
        curr++;
    }

    if(temp->next==NULL)
    {
        insertatend(tail,item);
        return;
    }   
    Node* node2 = new Node(item);
    node2->next = temp->next;
    temp->next = node2;
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

int main()
{
    //cout<<"Hello World";
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    cout<<"Head insertion:";
    insertathead(head,12);
    display(head);
    cout<<"\nEnd insertion:";
    insertatend(tail,15);
    display(head);
    
    cout<<"\nAt a position insert:";
    insertAtpos(head,tail,3,20);
    display(head);
    
    return 0;
}
