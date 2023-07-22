// approach 2: take 2 pointers fast and slow, fast moves 2 times faster than slow. Means if fast reached n then slow will reach n/2.

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

    // int len = getlen(head);
    // int mid = (len/2) ;
    // Node* temp = head;
    // int cnt=0;
    // while(cnt<mid)
    // {
    //     temp = temp->next;
    //     cnt++;
    // }

    // return temp;
    if(head == NULL || head->next == NULL) // if one or no node present
    {
        return head;
    }

    if(head->next->next == NULL) //if two node are there
    {
        return head->next;
    }

    Node* slow = head;
    Node* fast =  head->next;
    while(fast!=NULL)
    {
        fast = fast->next;  //ek baar aage bada
        if(fast!=NULL) 
        {
            fast = fast->next; //do baaar aage badh gya
        }
        slow = slow->next;
    }

    return slow;

}

