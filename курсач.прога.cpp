#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* p;

    Node(int key) : key(key), p(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->p;
            delete temp;
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    bool isFull() const {
        // Предположим, что стек может быть "переполнен" только из-за ограничения памяти.
        // Так как мы используем динамический список, то ограничение памяти может быть достигнуто только в случае, если память для нового узла не выделится.
        // Но в текущей реализации это может быть проверено только при добавлении нового узла. 
        Node* temp = new (std::nothrow) Node(0);
        if (temp == nullptr) {
            delete temp;
            return true;
        }
        return false;
    }

    void push(int key) {
        if (isFull()) {
            std::cout << "Стек переполнен" << std::endl;
        }
        else {
            Node* newNode = new Node(key);
            newNode->p = top;
            top = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Стек пуст" << std::endl;
        }
        else {
            Node* temp = top;
            std::cout << "Удаленный элемент :" << temp->key << std::endl;
            top = top->p;
            delete temp;
        }
    }

    void remove() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->p;
            delete temp;
        }
    }

    void length() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->p;
        }
        std::cout << "Длина стека: " << count << std::endl;
    }

    void print() {
        if (isEmpty()) {
            std::cout << "Стек пуст" << std::endl;
            return;
        }
        std::cout << "Элементы стека: ";
        Node* temp = top;
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->p;
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Stack stack;
    int choice, element;

    do {
        std::cout << "Выберите операцию:" << std::endl;
        std::cout << "1. Push\n2. Pop\n3. Remove\n4. Length\n5. Print\n6. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            stack.push(element);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.remove();
            break;
        case 4:
            stack.length();
            break;
        case 5:
            stack.print();
            break;
        case 6:
            std::cout << "Выход из программы" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 6);
    return 0;
}

