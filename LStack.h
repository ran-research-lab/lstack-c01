//
// Created by Rafael Arce Nazario on 9/30/20.
//

#ifndef LSTACK_H
#define LSTACK_H
#include <string>
#include <stdexcept>
#include "Stack.h"
using namespace std;


class Node {         // Singly linked list node class
    public:
        stackElementType data;    // Value for this node
        Node *next;      // Point to next node in list

        // Constructor
        Node(stackElementType d = 0, Node *n = NULL) { data = d; next = n; }
    };

    // Linked stack implementation
    class LStack : public Stack {
    private:
        Node* top;               // Pointer to first element
        int size;               // Number of elements

    public:

    // The only reason we receive a parameter is to be consistent
    // with the other implementations
    LStack(int size = 0) { top = NULL; size = 0; }


    // Reinitialize stack
    void clear() { while (top != NULL) pop(); }

    // Put "it" on stack
    bool push(const stackElementType& it) {
        top = new Node(it, top);
        size++;
        return true;
    }

    // Remove "it" from stack
    stackElementType pop() {
        if (top == NULL)
            throw std::out_of_range("trying to pop() from an empty LStack");
        stackElementType it = top->data;
        top = top->next;
        size--;
        return it;
    }

    stackElementType topValue() const{      // Return top value
        if (top == NULL)
            throw std::out_of_range("trying to get topValue() from an empty LStack");
        return top->data;
    }

    // Return stack length
    int length() const { return size; }

    // Check if the stack is empty
    bool isEmpty() const { return size == 0; }

    string toString() const {
        string outputString;
        Node *tmp = top;
        while(tmp != NULL) {
            outputString += to_string(tmp->data);
            outputString += " ";
            tmp = tmp->next;
        }
        return outputString;
    }
};


#endif //LSTACK_H
