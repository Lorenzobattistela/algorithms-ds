#include <iostream>
#include "exceptions.cpp"

class ArrayStack {
    private:
        int top;
        int capacity;
        int *array;
        int size;

        void initializeArrayStack() {
            for(int i = 0; i < capacity; i++) {
                array[i] = 0;
            }
        }

    public:
        ArrayStack(int capacity) {
            this->top = -1;
            this->capacity = capacity;
            this->array = new int[capacity];
            this->size = 0;
            initializeArrayStack();
        }

        int getTop() {
            return array[top];
        }

        int getSize() {
            return size;
        }

        bool isEmptyStack() {
            return size == 0;
        }

        bool isFullStack() {
            return size == capacity;
        }

        void push(int val) {
            if(isFullStack()) {
                throw FullStackException();
            }

            top++;
            array[top] = val;
            size++;
        }

        int pop() {
            if(isEmptyStack()) {
                throw EmptyStackException();
            }

            int poppedElement = array[top];
            top--;
            size--;
            return poppedElement;
        }

        void printStack() {
            for(int i = 0; i <= top; i++) {
                std::cout << array[i] << std::endl;
            }
        }

        ~ArrayStack() {
            delete[] array;
        }
};
