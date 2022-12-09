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
    
    
    void printAll(){
        cout << "Print starts" <<endl;
        Node* currentNode = head;
        
        while(currentNode->next != NULL){
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
        cout << currentNode->data <<endl;
        cout << "Print ends" <<endl;
        return;
    }
    
};

int main(int argc, const char * argv[]) {
    DoubleLinkList* DoubleLinkList1 = new DoubleLinkList;
    DoubleLinkList1->addTop(11);
    DoubleLinkList1->addTop(22);
    DoubleLinkList1->addTop(33);
    DoubleLinkList1->addTop(44);
    DoubleLinkList1->addBottom(55);
    
    DoubleLinkList1->printAll();
}
