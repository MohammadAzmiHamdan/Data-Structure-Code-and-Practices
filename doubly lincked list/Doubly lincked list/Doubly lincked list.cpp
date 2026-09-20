
#include <iostream>
using namespace std; 
class Node {
public : 
    int Data;
    Node* Prev;
    Node* Next;
};
void PrintList(Node* head) {
    if (head != nullptr) {
        cout << "\n";
        while (head != NULL) {
            cout << head->Data << " ";
            head = head->Next;
        }cout << endl;
     }
}
void InsertAtBeginning(Node*& head, int Data) {
    Node* New_Node = new Node();
    New_Node->Data = Data;
    New_Node->Prev = NULL;
    New_Node->Next = head;

    if (head != NULL) {

        head->Prev = New_Node;

    }

    head = New_Node;

}
void PrintNodeDetails(Node* head)
{

    if (head->Prev != NULL)
        cout << head->Prev->Data;
    else
        cout << "NULL";

    cout << " <--> " << head->Data << " <--> ";

    if (head->Next != NULL)
        cout << head->Next->Data << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->Next;
    }
}
Node* Find(Node* head, int Data) {

    while (head != nullptr) {
        if (head->Data == Data) {
            return head;
        }
        head = head ->Next;
    }
    return NULL;

}
void InsertAfter(Node* Current, int Data)
{
    if (Current == nullptr)
        return;

    Node* New_Node = new Node();

    New_Node->Data = Data;

    New_Node->Next = Current->Next;
    New_Node->Prev = Current;

    if (Current->Next != nullptr)
    {
        Current->Next->Prev = New_Node;
    }

    Current->Next = New_Node;
}
void InsertAtEnd(Node* &head, int Data) {
    Node* New_Node = new Node();
    New_Node->Data = Data;
    New_Node->Next = NULL;
    if (head == NULL)
    {
        New_Node->Prev = NULL;
        head = New_Node;
    }
    else {
        Node* LastNode = head;
        while (LastNode->Next != NULL) {
            LastNode = LastNode->Next;
        }
        LastNode->Next = New_Node;
        New_Node->Prev = LastNode;
    }
}
void DeleteNode(Node* & head, Node*& NodeToDelete) {

    if (head == NULL || NodeToDelete == NULL)
        return;
    if (NodeToDelete == head) {
        head = NodeToDelete->Next;
    }
    if ( NodeToDelete->Next != NULL) {

        NodeToDelete->Next->Prev = NodeToDelete->Prev;
    }
    if (NodeToDelete->Prev != NULL) {
        NodeToDelete->Prev->Next = NodeToDelete->Next;
    }

    delete NodeToDelete;

}
void DeleteFirstNode(Node*& head) {

    if (head == NULL)
        return; 

    Node* temp = head; 
    head = head->Next;

    if (head != NULL) {
        head->Prev = NULL;
    }
    delete temp;
}
void DeleteLastNode(Node*& head) {
    if (head == NULL)

        return;

    if (head->Next == NULL) {
        delete head; 
        head = NULL;
        return;
    }

    Node* Befor_Last = head;


    while (Befor_Last->Next->Next != NULL)
    {
        Befor_Last = Befor_Last->Next;
    }

    Node* tmp = Befor_Last->Next;

    Befor_Last->Next = NULL;

    delete tmp;

}
int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    
    DeleteLastNode(head);
    DeleteLastNode(head);
    DeleteLastNode(head);

    cout << "\n\n\nLinked List Contenet after delete:\n";
    PrintList(head);
    system("pause>0");



}
