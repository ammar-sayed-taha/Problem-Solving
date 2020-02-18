

// Complete the reverse function below.

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
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {

    if(!head) return head; // if linked list is empty

    DoublyLinkedListNode*node, *tail = nullptr;

    while(head){
        node = head;
        head = head->next;
        node->next = tail;
        if(tail) tail->prev= node;
        node->prev = nullptr;
        tail = node;
    }

    return tail;



}

