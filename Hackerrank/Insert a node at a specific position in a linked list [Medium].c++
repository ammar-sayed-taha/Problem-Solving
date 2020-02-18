

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    int pos = 0;
    SinglyLinkedListNode * temp = head;

    if(position == 0){
        newNode->next = temp;
        head = newNode;
        return head;
    }

    while(pos < position-1 && temp->next != nullptr) {
        temp = temp->next;
        pos++;
    }

    if(pos == position-1){
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
  


}

