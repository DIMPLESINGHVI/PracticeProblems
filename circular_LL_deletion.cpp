#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
     
    }
    ~Node()
    {
        int val = data;
        if(this->next!=NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertnode(Node* &tail,int ele,int val)
{
    if(tail==NULL)  //empty list
    {
        Node* temp = new Node(val);
        tail = temp;
        temp->next = temp; //apne aap ko point krwao
    }
    else
    {
        Node* curr = tail;
        while(curr->data != ele)
        {
            curr= curr->next;
        }
        Node* temp = new Node(val);
        temp->next = curr->next;
        curr->next = temp;
    }
    
} 

void deletion(Node* &tail, int ele)
{
    if(tail==NULL)
    {
        cout<<"List is empty";
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data!=ele)
        {
            prev = curr;
            curr=curr->next;
        }
        
        prev->next = curr->next;
        
        if(curr==prev) //if only one node present in the list
        {
            tail = NULL;
        }
        else if(tail==curr) //more than 2 nodes in the list
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;

    }
}
void display(Node* &tail)
{
    
    Node* temp = tail;
    if(tail==NULL)
    {   
        cout<<"\nList is empty";
        return;
    }
    do
    {
        cout<<tail->data<<"->";
        tail = tail->next;
    }while(tail!=temp); //sara element print krne ke liye
    cout<<endl;
}

int main()
{
    
    Node* tail = NULL;
    insertnode(tail,5,3); //konse element ke baad print krana 
    display(tail);
    
    insertnode(tail,3,5);
    display(tail);
    
    insertnode(tail,5,7);
    display(tail);
    
    insertnode(tail,7,8);
    display(tail);
    
    insertnode(tail,5,6);
    display(tail);

    insertnode(tail,3,4);
    display(tail);
    
    cout<<"\nDeletion: \n";
    deletion(tail,3);
    display(tail);
    
    return 0;
}
