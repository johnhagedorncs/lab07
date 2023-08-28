#include "linkedListFuncs.h"
#include <stddef.h>

using namespace std;


int recursiveSum(Node* head) {
    if ( head != NULL ) {
        return head->data + recursiveSum(head->next);
    } else {
        return 0;
    }
}


int recursiveLargestValue(Node* head) {
    int current = head->data;
    int next;
    if (head->next == NULL) {
        return current;
    } else {
        next = recursiveLargestValue(head->next); 
    }
    if (current > next) {
        return current;
    } else {
        return next;
    }
}


Node* recursiveFindKthNode(Node *head, int k){
    if (head == nullptr) {
        return nullptr;
    }
    if (k == 1) {
        return head;
    }
    return recursiveFindKthNode(head->next, k - 1);
}


Node* recursiveDeleteKthNode(Node *head, int k) {
    if (head == nullptr) {
        return nullptr; // Base case: empty list
    }

    if (k == 1) {
        Node* temp = head->next;
        delete head;
        return temp; // Delete the first node
    }

    head->next = recursiveDeleteKthNode(head->next, k - 1);
    return head;
}


Node* recursiveRemoveKFromFront(Node *head, int k) {
    if (head == nullptr || k <= 0) {
        return head; // Base case: no more nodes to remove
    }

    Node* newHead = head->next; // Move to the next node
    delete head; // Delete the current node

    // Recursively remove the remaining k-1 nodes from the new head
    return recursiveRemoveKFromFront(newHead, k - 1);
}


/*Given two linked lists, return a NEW linked-list where each element is the sum of the corresponding elements of the input
 * If a linked list has a longer length than the other, treat the corresponding NULL element as a node with value 0
 * 
 * Example: List 1: 1 -> 2 -> 3 -> 12
 * 	    List 2: 4 -> 5 -> 6
 * Return &head of the linked list 5 -> 7 -> 9 -> 12
 */
Node* recursiveElementwiseSum(Node *head1, Node *head2) {
    return NULL;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}


/*BONUS: Given the heads of two linked lists, splice the second linked list into the first, alternating elements from each list
 * 
 * The first element of the newly arranged linked list will always be head1, unless head1 is NULL (in which case just return head2)
 *
 * You MUST modify the linked lists themselves and DO NOT create another list or any new nodes
 *
 * Example: List 1: 1->2->3, List 2: 4 -> 5 -> 6
 * Return &head of 1 -> 4 -> 2 -> 5 -> 3 -> 6
 */
Node* recursiveSplice(Node *head1, Node *head2) {
    return NULL;
    //STUB: edit with the correct output, according to the lab instructions, using recursion
}
