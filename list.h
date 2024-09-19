#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <functional>


template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T data) : data(data), next(NULL) {}
};

template<typename T>
class List {
private:
    Node<T>* head;
public:
    List() : head(NULL) {}
    ~List();
    void insertAtBeginning(T data);
    void insertAtEnd(T data);
    void deleteNode(T key);
    void printList() const;
    T min(std::function<bool(T, T)> compare) const;
    T max(std::function<bool(T, T)> compare) const;
    int size();
    bool InList(T key);
    void changedata(T olddata, T newdata);
};

#endif // LINKED_LIST_H

