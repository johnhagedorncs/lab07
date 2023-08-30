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
        Node* newHead = head->next;
        delete head;
        return newHead; // Delete the first node
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


Node* recursiveElementwiseSum(Node *head1, Node *head2) {
    if (head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }

    Node* NewNode = new Node;
    int Sum = 0;

    if (head1 != nullptr) {
        Sum += head1->data;
        head1 = head1->next;
    }

    if (head2 != nullptr) {
        Sum += head2->data;
        head2 = head2->next;
    }

    NewNode->data = Sum;
    NewNode->next = recursiveElementwiseSum(head1, head2);

    return NewNode;
}


Node* recursiveSplice(Node *head1, Node *head2) {
    if (head2 == nullptr) {
        return head1;
    }
    if (head1 == nullptr) {
        return head2;
    }

    Node* tempVal1 = head1->next;
    Node* tempVal2 = head2->next;

    head1->next = head2;
    head2->next = recursiveSplice(tempVal1, tempVal2);

    return head1;
}
