

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    if(head == nullptr){
        head = newNode;
        return head;
    }
    DoublyLinkedListNode *temp = head;

     while(temp){ // if the temp is not null
        if(temp->data > data){
            newNode->next = temp;
            newNode->prev = temp->prev;
            if(temp->prev) temp->prev->next = newNode; // if condition to handel first node
            else head = newNode; // this will be in first node
            temp->prev = newNode;
            
            break;
        }else if(temp->next == nullptr){ // handle last item
            temp->next = newNode;
            newNode->prev = temp;
            break;
        }
        temp = temp->next;
     }
     return head;

      


}

