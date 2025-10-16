//COMSC 210 | Midterm 1, Part 1 | Anisha Rayapudi
//IDE used: VS 22

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
class DoublyLinkedList {
private:
struct Node {
int data;
Node* prev;
Node* next;
Node(int val, Node* p = nullptr, Node* n = nullptr) {
data = val;
prev = p;
next = n;
}
};
Node* head;
Node* tail;
public:
DoublyLinkedList() { head = nullptr; tail = nullptr; }
void insert_after(int value, int position) {
if (position < 0) {
cout << "Position must be >= 0." << endl;
return;
}
Node* newNode = new Node(value);
if (!head) {
head = tail = newNode;
return;
}
Node* temp = head;
for (int i = 0; i < position && temp; ++i)
temp = temp->next;
if (!temp) {
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode;
return;
}
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next)
temp->next->prev = newNode;
else
tail = newNode;
temp->next = newNode;
}
void delete_val(int value) {
if (!head) return;
Node* temp = head;
while (temp && temp->data != value)
temp = temp->next;
if (!temp) return;
if (temp->prev)
temp->prev->next = temp->next;
else
head = temp->next;
if (temp->next)
temp->next->prev = temp->prev;
else
tail = temp->prev;
delete temp;
}
void delete_pos(int pos) {
if (!head) {
cout << "List is empty." << endl;
return;
}
if (pos == 1) {
pop_front();
return;
}
Node* temp = head;
for (int i = 1; i < pos; i++){
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
else
temp = temp->next;
}
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
if (!temp->next) {
pop_back();
return;
}
Node* tempPrev = temp->prev;
tempPrev->next = temp->next;
temp->next->prev = tempPrev;
delete temp;
}
void push_back(int v) {
Node* newNode = new Node(v);
if (!tail)
head = tail = newNode;
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
void push_front(int v) {
Node* newNode = new Node(v);
if (!head)
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
void pop_front() {
if (!head) {
cout << "List is empty." << endl;
return;
}
Node * temp = head;
if (head->next) {
head = head->next;
head->prev = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
void pop_back() {
if (!tail) {
cout << "List is empty." << endl;
return;
}
Node * temp = tail;
if (tail->prev) {
tail = tail->prev;
tail->next = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
void every_other_element(){
    Node * current = head; // starting traversal from head of list
    if (!current) { // condition to check for an empty list
        cout << "List is empty. " << endl;
        return;
    }
    // traverse list and only print the even-numbered positions
    int idx = 1; // position index starting at 1
    while (current) {
        if (idx % 2 == 0){ // print even number position
            cout << current->data << " ";
            current = current->next; //moving to next node
            idx++; //increment idx to next position
        }
    }
}
~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
void print() {
Node* current = head;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
void print_reverse() {
Node* current = tail;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->prev;
}
cout << endl;
}
};
int main() {
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
    vector<int> values;
    for (int i = 0; i < size; i++){
        values.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    }
    DoublyLinkedList list;
    for (int v : values){
        list.push_back(v);
    }
    cout << "List forward: \n";
    list.print();

    cout << "List backward: \n";
    list.print_reverse();

    cout << "Every other element(starting from 1st position): \n";
    list.every_other_element();
    list.print();


return 0;
}
