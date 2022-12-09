#include <iostream>
using namespace std;

class Node{
public :
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkList{
public:
    Node* head;
    
    int addTop(int val){
        Node* NewNode = new Node();
        NewNode->data = val;
        if(head==NULL){
            head = NewNode;
            return head->data;
        }else{
            head->prev = NewNode;
            NewNode->next = head;
            head = NewNode;
            return head->data;
        }
    }
    
    int addBottom(int val){
        Node* NewNode = new Node();
        NewNode->data = val;
        if(head==NULL){
            head = NewNode;
        }
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        
        NewNode->prev = currentNode;
        currentNode->next = NewNode;
        return currentNode->next->data;
    }
    
    int addAt(int val , int index){
        
        if(index==0){
            return addTop(val);
        }else if(index == size()){
            return  addBottom(val);
        }
        
        Node* NewNode = new Node();
        NewNode->data = val;
        
        int currentNodeNum = 0;
        Node* currentNode = head;
        while (currentNodeNum != index-1) {
            currentNodeNum++;
            currentNode = currentNode->next;
        }
        
        NewNode->next = currentNode->next;
        currentNode->next->next->prev = NewNode;
        currentNode->next = NewNode;
        NewNode->prev = currentNode;
        
        return NewNode->data;
    }
    
    int removeTop(){
        if(head==NULL){
            return -1;
        }
        int removedVal = head->data;
        head->next->prev = NULL;
        head = head->next;
        return removedVal;
    }
    
    int removeBottom(){
        if(size()==0){
            cout << "Notthing to remove" << endl;
        }
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        int removedVal = currentNode->data;
        
        return removedVal;
    }
    
    void removeAt(int index){
        int count = 0;
        Node* currentNode = head;
        Node* prevNode = currentNode->prev;
        Node* NextNode = currentNode->next;
        while (count != index-1) {
            prevNode = currentNode;
            currentNode = currentNode->next;
            NextNode = currentNode->next;
            count++;
        }
        currentNode->next = currentNode->next->next;
        currentNode->next->next->prev = currentNode;
//        NextNode->prev = currentNode;
//        cout << "node to be removed : " << currentNode->data <<endl;
    }
    
    int valAtHead(){
        return head->data;
    }
    
    int valAtBottom(){
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }
    
    //=>Returns value of a node at a particular index
    //=>if index is negative returns -1
    //=>if index is greater than the size then returns -1
    int valAt(int index){
        if(index<0){
            return -1;
        }else if(index>size()-1){
            return -1;
        }
        Node* currentNode = head;
        int count = 0;
        while (count != index) {
            currentNode = currentNode->next;
            count++;
        }
        
        return currentNode->data;
    }
    
    
    void printAll(){
        if(size()==0){
            cout << "Nothing to print" << endl;
            return;
        }
        cout << "Print starts" << endl;
        Node* currentNode = head;
        while(currentNode->next != NULL){
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
        cout << currentNode->data << endl;
        cout << "Print ends" << endl;
        return;
    }
    
    int size(){
        if(head == NULL){
            return 0;
        }
        Node* currentNode = head;
        int size = 0;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
            size++;
        }
        return size+1;
    }
    
};

int main(int argc, const char * argv[]) {
    DoubleLinkList* DoubleLinkList1 = new DoubleLinkList;
    DoubleLinkList1->addTop(11);
    DoubleLinkList1->addTop(22);
    DoubleLinkList1->addTop(33);
    DoubleLinkList1->addTop(44);
    DoubleLinkList1->addBottom(55);
    DoubleLinkList1->removeTop();
    DoubleLinkList1->addAt(99, 2);
    DoubleLinkList1->removeAt(2);
    cout << "val at 4 : " << DoubleLinkList1->valAt(3) <<endl;
    cout << "Size : " << DoubleLinkList1->size() <<endl;
    DoubleLinkList1->printAll();
    
    
}
