//approach 1: finding the length of the linked list and then finding the mid element. (for position we do (len/2) + 1.

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int getlen(Node* head)
{
    int len=0;
    while(head!=NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

Node *findMiddle(Node *head) {
    // Write your code here

    int len = getlen(head);
    int mid = (len/2) ;
    Node* temp = head;
    int cnt=0;
    while(cnt<mid)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;

}

