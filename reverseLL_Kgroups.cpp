// approach : first check for the base case (list empty or not). Then keep the length of the remaining nodes in the LL. Check if this len is less than the K value,
// in that case return the current head alone. Then reverse the LL upto K, then call a recursive function to take care of the rest of the list. Finally return the new
// head of the reversed LL AKA prev.


/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    // Write your code here.
    int len = 0;
    Node* temp =head;
    while(temp!=NULL)  //counting the length of list
    {
        temp=temp->next;
        len++;
    }
    if (len < k) // Check if the value of k is not larger than the length of the remaining list
    {
      return head;
    }
    //base case
    if(head == NULL)  //if no item in the list return NULL
    {
        return NULL;
    }
    //step1: reverse the first part
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd  = NULL;
    int cnt=0;
    while(curr!=NULL && cnt<k)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        cnt++;
    }

    //step2: recursion takes cares of the rest part
    if(fwd!=NULL)
    {
        head->next = kReverse(fwd, k);
    }

    //step3: return the head of the reversed list -- prev
    return prev;


}
