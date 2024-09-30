#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node { //node class
    public: // public attributes 
        int data;
        Node* next;

        Node(int data) { //constructor
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
        
        }
        void setNext(Node* next) { //functions
            this->next = next;
        }
        Node* getNext() {
            return this->next;
        }
        int getData() {
            return this->data;
        }
        void setData(int data) {
            this->data = data;
        }
};
class Stack { //stack class
    private:
        Node* top;
        int Size;
    public: //constructo
        Stack() {
            this->top = NULL;
            this->Size = 0;
        }
        ~Stack(){ //destructor
           clear();
        }
        void push(int data) {  //functions
            Node* newNode = new Node(data);
            if (this->top == NULL) {
                this->top = newNode;
            } else {
                newNode->setNext(this->top);
                this->top = newNode;
            }
            this->Size++;
        }
        void pop() {
            if (this->top == NULL) {
                cout << "Stack is empty" << endl;
            } else {
                Node* temp = this->top;
                this->top = this->top->getNext();
                delete temp;
                this->Size--;
            }
        }
        int peek() {
            if (this->top == NULL) {
                cout << "Stack is empty" << endl;
                return -1;
            } else {
                return this->top->getData();
            }
        }
        int size() {
            return this->Size;
        }
        bool isEmpty() {
            if (Size==0){
                return true;
            }
            return false;
        }
        void clear() {
            while (this->top != NULL) {
                Node* temp = this->top;
                this->top = this->top->getNext();
                delete temp;
            }
            this->Size = 0;
        }
        void printStack() {
            Node* temp = this->top;
            while (temp != NULL) {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
};
class Queue { //queue class
    private: //private attributes
        Node* top;
        int count;
    public: 
        Queue() {   //constructor
            this->top = NULL;
            this->count = 0;
        }
        ~Queue() { //destructor
            clear();
        }
        void enqueue(int data) { //functions
            Node* newNode = new Node(data);
            if (this->top == NULL) {
                this->top = newNode;
            } else {
                Node* temp = this->top;
                while (temp->getNext() != NULL) {
                    temp = temp->getNext();
                }
                temp->setNext(newNode);
            }
            this->count++;
        }
        void dequeue() {
            if (this->top == NULL) {
                cout << "Queue is empty" << endl;
            } else {
                Node* temp = this->top;
                this->top = this->top->getNext();
                delete temp;
                this->count--;
            }
        }
        bool isEmpty() {
            return count == 0;
        }
        int size() {
            return this->count;
        }
        void clear() {
            while (this->top != NULL) {
                Node* temp = this->top;
                this->top = this->top->getNext();
                delete temp;
            }
            this->count = 0;
        }
        void printQueue() {
            Node* temp = this->top;
            while (temp != NULL) {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
};


#endif