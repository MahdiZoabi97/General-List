#include "list.h"
#include <iostream>
#include <stdexcept>
#include <functional>
using namespace std;

template<typename T>
List<T>::~List(){
    Node<T>* current = head;
    while(current != NULL){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void List<T>::insertAtBeginning(T data){
    Node<T>* newnode = new Node<T>(data);
    newnode->next = head;
    head = newnode;
}

template<typename T>
void List<T>::insertAtEnd(T data){
    Node<T>* newnode = new Node<T>(data);
    if(head == NULL){
        head = newnode;
    }else{
        Node<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

}

template<typename T>
void List<T>::deleteNode(T key){
    Node<T>* temp = head;
    if( temp == NULL){
        return;
    }
    if(temp->data == key){
        head = head->next;
        delete temp;
        return;
    }
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if(temp->next == NULL){
        return;
    }
    Node<T>* temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;
}

template<typename T>
void List<T>::printList() const{
    Node<T>* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
T List<T>::min(std::function<bool(T, T)> compare) const{
    int min = 0;
    Node<T>* temp = head;
    if(temp == NULL){
        return min;
    }
    min = temp->data;
    while(temp != NULL){
        int mint = temp->data;
        if(mint < min){
            min = mint;
        }
        temp = temp->next;
    }
    return min;
}

template<typename T>
T List<T>::max(std::function<bool(T, T)> compare) const{
    int max = 0;
    Node<T>* temp = head;
    if(temp == NULL){
        return max;
    }
    max = temp->data;
    while(temp != NULL){
        int maxt = temp->data;
        if(maxt > max){
            max = maxt;
        }
        temp = temp->next;
    }
    return max;
}

template<typename T>
int List<T>::size(){
    int size = 0;
    Node<T>* temp = head;
    if(temp == NULL){
        return size;
    }
    while(temp != NULL){
        size++;
        temp = temp->next;
    }
    return size;
}



template<typename T>
bool List<T>::InList(T Key){
    bool tmp = false;
    Node<T>* temp = head;
    if(temp == NULL){
        return tmp;
    }
    while(temp != NULL){
        if(temp->data == Key){
            tmp = true;
            return tmp;
        }
        temp = temp->next;
    }
    return tmp;
}

template<typename T>
void List<T>::changedata(T olddata,T newdata){
    if(InList(olddata) == false){
        cout << "key not found" << endl;
        return;
    }
    Node<T>* temp = head;
    while(temp != NULL){
        if(temp->data == olddata){
            temp->data = newdata;
            cout << "key has changed" << endl;
            return;
        }
        temp = temp->next;
    }
    return;
}