#include <iostream>
#include "list.cpp"
#include <functional>
using namespace std;


bool compareIntDescending(int a, int b) {
    return a > b;
}

int main() {
    List<int> list;
    // Insert elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    // Print the list
    std::cout << "List after inserting elements: ";
    list.printList();
    cout << list.max(compareIntDescending) << endl;
    cout << list.min(compareIntDescending) << endl;
    cout << list.size() << endl;
    std::cout << std::boolalpha;
    cout << list.InList(20) << endl;
    list.changedata(3,10);
    list.changedata(20,3);

    // Delete an element
    list.deleteNode(20);
    list.changedata(20,3);

    // Print the list after deletion
    std::cout << "List after deleting 20: ";
    list.printList();
    cout << list.max(compareIntDescending) << endl;
    cout << list.min(compareIntDescending) << endl;
    cout << list.size() << endl;
    std::cout << std::boolalpha;
    cout << list.InList(20) << endl;

    return 0;
}