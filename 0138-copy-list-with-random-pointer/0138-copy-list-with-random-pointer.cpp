/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void inserttail(Node* &head , Node* &tail , int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }    
public:
    Node* copyRandomList(Node* head) {

        // step 1 - create clone list
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;
        while(temp != NULL){
            inserttail(clonehead , clonetail , temp->val);
            temp = temp->next;
        }

        //step 2 - adding clone nodes in original list;
        Node* originalnode = head;
        Node* clonenode = clonehead;

        while(originalnode != NULL && clonenode != NULL){
            Node* originalnext = originalnode->next; 
            originalnode->next = clonenode;
            originalnode = originalnext;

            Node* clonenext = clonenode->next;
            clonenode->next = originalnode;
            clonenode = clonenext;
        }


        //step 3 - marking random pointers
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL ){
                temp->next->random = temp->random ? temp->random->next : temp->random;
                // this =          condition check     if true             if false
            } 
            temp = temp->next->next;    
        }

        // step 4 - making both list normal
        originalnode = head;
        clonenode = clonehead;

        while(originalnode && clonenode){

            originalnode->next = clonenode->next;
            originalnode = originalnode->next;

            if(originalnode != NULL){
                clonenode->next = originalnode->next;
            }
            clonenode = clonenode->next;
        }

        //step 5 - returning head
        return clonehead;
    }
};