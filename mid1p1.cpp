//COMSC 210 | Midterm 1, Part 1 | Anisha Rayapudi
//IDE used: VS 22

#include <iostream>
#include <vector> //using vectors to store list values
#include <cstdlib> // using for random list generation
#include <ctime> // using for random list generation
using namespace std; //using standard namespace to avoid std::
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20; // constant ranges for random and list size
class DoublyLinkedList { //Doubly linked list class with private node structure
private:
struct Node {
int data; // node stores integer value
Node* prev; //pointer to previous node in list
Node* next; // pointer to next node in list
Node(int val, Node* p = nullptr, Node* n = nullptr) { //initializing Node constructor and data
data = val; // store value in this node
prev = p; //previous node link
next = n; //next node link
}
};
Node* head; //pointer to head of list
Node* tail; // pointer to last node of list
public:
DoublyLinkedList() { head = nullptr; tail = nullptr; } // constructor intitialzes head and tail to null
void insert_after(int value, int position) { //node inserted after the node at index position
if (position < 0) { //check for negative position
cout << "Position must be >= 0." << endl;
return;
}
Node* newNode = new Node(value); //create a new node with value in parameter
if (!head) { // if list is empty the new node is the head and tail
head = tail = newNode;
return;
}
Node* temp = head; // traversing list starts at head
for (int i = 0; i < position && temp; ++i) // move foward based on position index
temp = temp->next; //move to next node
if (!temp) { //position out of range check
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode; //delete new node to avoid memory leak
return;
}
newNode->next = temp->next; //new node becomes next of temp
newNode->prev = temp; // new node previous is temp
if (temp->next)
temp->next->prev = newNode; //node after temp points back to new node
else
tail = newNode; //node points back to new node if temp is not tail
temp->next = newNode;  //temp to new node
}
void delete_val(int value) { //delete first node if data equals value
if (!head) return; //if list empty check -> return
Node* temp = head; //starting at head  of list
while (temp && temp->data != value)
temp = temp->next; //keep looking for value past unmatched ones
if (!temp) return;
if (temp->prev) //update links to surround temp
temp->prev->next = temp->next;
else
head = temp->next; // if temp is the head move forward
if (temp->next)
temp->next->prev = temp->prev;
else
tail = temp->prev; // if temp is tail move back
delete temp;
}
void delete_pos(int pos) { //delete node at the position pos
if (!head) { //empty list check
cout << "List is empty." << endl;
return;
}
if (pos == 1) { //if position is 1 call pop front method to delete head
pop_front();
return;
}
Node* temp = head; //temp ponter to head
for (int i = 1; i < pos; i++){ //run loop to move to position
if (!temp) { //invalid position check
cout << "Position doesn't exist." << endl;
return;
}
else
temp = temp->next; //move to next node
}
if (!temp) { //position check
cout << "Position doesn't exist." << endl;
return;
}
if (!temp->next) { // if position is tail call pop back to delete tail
pop_back();
return;
}
Node* tempPrev = temp->prev; //keeps pointer to previous node
tempPrev->next = temp->next; // previous node points to node after temp
temp->next->prev = tempPrev; // node after temp pints back to previus node
delete temp;
}
void push_back(int v) { //insert node to end of list with value v in parameter
Node* newNode = new Node(v); //create new node with value v
if (!tail) //list is empty if tail is null
head = tail = newNode; //if empty the new node is the head and tail
else {
tail->next = newNode; // otherwise the tail's next is the new node
newNode->prev = tail; //the new node previous is the old tail
tail = newNode; //the tail pointer is updated to the new node
}
}
void push_front(int v) { //insert node to head of list with value v in parameter
Node* newNode = new Node(v); //create new node with value v
if (!head) //list is empty if head is null
head = tail = newNode; //if empty the new node is the head and tail
else {
newNode->next = head; // otherwise the head's next is the new node
head->prev = newNode; //the new node previous is the old head
head = newNode; //the head pointer is updated to the new node
}
}

void pop_front() { //deletes at node at head of list
if (!head) { //empty list check
cout << "List is empty." << endl;
return;
}
Node * temp = head; //temp pointer to head
if (head->next) {
head = head->next; // move head forwrd
head->prev = nullptr; // new head previous is null
}
else
head = tail = nullptr; //otherwise head and tail are null
delete temp; //delete old head
}
void pop_back() { //deletes node at tail of list
if (!tail) {
cout << "List is empty." << endl;
return;
}
Node * temp = tail; // temp pointer to tail
if (tail->prev) { // if there is a previous node to tail
tail = tail->prev; // move back tail
tail->next = nullptr; // new tail next is now null
}
else
head = tail = nullptr; // othersie head and tail are null
delete temp; //delete old tail
}
void every_other_element(){
    Node * current = head; // starting traversal from head of list
    if (!current) { // condition to check for an empty list
        cout << "List is empty. " << endl;
        return;
    }
    // traverse list and only print the odd-numbered positions
    int idx = 1; // position index starting at 1
    while (current) {
        if (idx % 2 != 0){ // print even number position
            cout << current->data << " ";
        }
            current = current->next; //moving to next node
            idx++; //increment idx to next position
        
    }
}
~DoublyLinkedList() { //destructor
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
void print() { //print list head to tail
Node* current = head; //pointer current to head
if (!current) { //empty list check
cout << "List is empty." << endl;
return;
}
while (current) { // traverse list while current is not null
cout << current->data << " "; //print current node
current = current->next; //move to next
}
cout << endl;
}
void print_reverse() { //print in reverse tail to head
Node* current = tail; //pointer curent to tail
cout << "List is empty." << endl; //empty list check
return;

while (current) {
cout << current->data << " "; //print current node
current = current->prev; //move to previous
}
cout << endl;
}
};
int main() {
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
    vector<int> values; //random values stored in vector with size restrictions
    for (int i = 0; i < size; i++){
        values.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    } //push back into vector to shore
    DoublyLinkedList list;
    for (int v : values){ // to transfer values from vector to list
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
