
#include <iostream>
using namespace std; 
class Node {
public : 
    int  Value; 
    Node* Next;
    Node(int Value = 0, Node* Next = NULL) {

        this->Value = Value;
        this->Next = Next;
    }
};
void InsertAtBeginning(Node* &head, int Data) {
    head = new Node(Data, head);

}
void PrintList(Node* head) {
    while (head != NULL) {
        cout << head->Value << "  ";
        head = head->Next;
    }cout << "\n";
}
Node* Find(Node* head, int Data) {
    while (head != NULL) {
        if (head->Value == Data) {
            return head;
        }
        head = head->Next;
    }
    return NULL;
}
void InsertAfter(Node* Prev_node, int Data) {
    if (Prev_node == NULL) {
        cout << " The Previos Node can't be NULL" << endl;
        return;
    }
    Prev_node->Next = new Node(Data, Prev_node->Next);

}
void InsertAtEnd(Node*& head, int Data) {
    Node* New_Node = new Node(Data);
    if (head == NULL) {
        head = New_Node;
        return; 
    }
    Node* LastNode = head;
    
    while (LastNode->Next != NULL) {
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_Node;
}
void DeleteNode(Node*& head, int Data) {
   
    if (head == NULL) 
        return;

    Node* prev = head;
    Node* current = head;


    if (current->Value == Data) {

        head = current->Next;
        delete current;
        return;
    }


    while (current != NULL && current->Value != Data) {
        prev = current; 
        current = current->Next; 

    }

    if (current == NULL) {
        return;
    }

    prev->Next = current->Next;

    delete current;

}
void DeleteFirstNode(Node*& head) {
    if (head == NULL) return;
    Node* Current = head;
    head = Current->Next;
    delete Current;
}
void DeleteLastNode(Node* &head) {
    if (head == NULL)
        return; //empty 

    Node* Prev = head;
    Node* Current = head;

    if (Current->Next == NULL) { // one node 
        head = NULL; 
        delete Current; 
        return;
    }

    while (Current != NULL && Current->Next != NULL) 
    {
        Prev = Current;
        Current = Current->Next; 
    }

    Prev->Next = NULL;
    delete Current;

}


int main()
{
    Node* head=nullptr;


    InsertAtEnd(head, 500);
    InsertAtEnd(head, 1000);
    InsertAtEnd(head, 1500);
    InsertAtEnd(head, 2000);
    InsertAtEnd(head, 2500);
    PrintList(head);
    DeleteLastNode(head);
  
    PrintList(head);
    system("pause>0");
    return 0;
}

