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
        
        ~Node()
        {
            int val = this->data;
            if(this->next!=NULL)
            {
                delete next;
                this->next = NULL;
            }
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

void deleteatpos(int pos,Node* &head,Node* &tail)
{
    Node* prev=NULL;
    Node* curr=head;
    if(pos==1)
    {
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;        
    }
    else
    {
        int cnt=1;
        while(cnt<pos)
        {
            prev = curr;
            curr=curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        
        if(prev->next == NULL) //to change the value of tail if last node deleted
        tail = prev;
    }
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
    
    cout<<"\nDeleting at position:";
    deleteatpos(4,head,tail);
    display(head);
    
    cout<<tail->data;
    return 0;
}
