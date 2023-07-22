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

bool isCircular(Node* &tail)
{
    if(tail==NULL) //if no element return true for is circular
    {
        return true;
    }
    Node* temp = tail->next;   //starting with element just after the head/tail node. 
    while(temp!=NULL && temp!=tail) //if the list is circular then temp comes back and points head(tail) and comes out of the loop, if the temp points null it comes out of the loop.
    {
        temp = temp->next;
    }
    if(temp==tail)  //if the temp points head(tail) then it is a circular
    return true;
    
    return false;
}

int main()
{
    
    Node* tail = NULL;
    insertnode(tail,5,3); //konse element ke baad print krana 
    insertnode(tail,3,5);
    insertnode(tail,5,7);
    insertnode(tail,7,8);
    insertnode(tail,5,6);
    insertnode(tail,3,4);
    
    display(tail);
    
  
    if(isCircular(tail))
    {
        cout<<"Is a circular list";
    }
    else
    {
        cout<<"Not a circular list";
    }

    
    return 0;
}
