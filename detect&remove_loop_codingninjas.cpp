/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node* detectloop(Node *head)
{
    if(head==NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        slow = slow->next;
        if(slow==fast)
            return slow;
    }
    return NULL;
}

Node* startofloop(Node* head)
{
    if(head==NULL)
        return NULL;

    Node* intersect = detectloop(head);
    if(intersect==NULL)
        return NULL;
    
    Node* slow = head;

    while(slow!=intersect)
    {
        slow = slow->next;
        intersect=intersect->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL)
        return NULL;
    Node* start = startofloop(head);
    
    if(startofloop(head)==NULL)
        return head;
    
    Node* temp = startofloop(head);

    while(temp->next!=start)
    {
        temp=temp->next;
    }
    temp->next = NULL;

    return head;
}
