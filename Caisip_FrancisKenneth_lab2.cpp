#include <iostream>

using namespace std;

typedef struct Node {
    string songName;
    Node* link;
} Node;

Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
}

void traverse(Node* head) {
    Node* temp = head;
    
    cout << "My Playlist" << endl;
    while (temp != NULL) {
        cout << temp->songName << " -> ";
        if (temp->link == NULL) {
            cout << "NULL" << endl;
        }
        temp = temp->link;
    }
}

Node* insertAtEnd(string data, Node* head) {
    if (head == NULL) {
        Node* newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    
    Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    
    Node* newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node* insertAtBeginning(string data, Node* head) {
    Node* newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" << endl;
    
    return head;
}

string insertAfter(string after, string data, Node* head) {
    Node* temp = new Node;
    temp = head;
    
    while (temp != NULL && temp->songName != after) {
        temp = temp->link;
    }

    if (temp == NULL) {
        return "No such song exists, please try again later.";
    }
    
    Node* newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "A new node has been added after " + after + "\n";
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }
    
    if(head->link == NULL){
        delete head;
        return"The head has been deleted \n";
    }
    
    Node *temp = new Node;
    temp = head;
    
    while(temp->link->link !=NULL){
        temp = temp->link;
    }
    
    temp->link = NULL;
    
    return"A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" << endl;
        return NULL;
    }
    
    if(head->link == NULL){
        delete head;
    }
    
    head = head->link;
    
    cout << "A node has been delete from the beginning \n" << endl;
    
    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n";
        return NULL;
    }
    
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node " + givenNode + "has been deleted \n"
    }
}
int main() {
    Node *head = createNode("Santuary by Joji");
    
    head = insertAtEnd("Bahaghari by Dionela", head);
    head = insertAtEnd("Musika by Dionela", head);
    head = insertAtEnd("Oksihina by Dionela", head);
    
    head = insertAtBeginning("Lagi by BINI", head);
    head = insertAtBeginning("Blink Twice by BINI", head);
    head = insertAtBeginning("Out Of My Head by BINI", head);
    head = insertAtBeginning("Zero Pressure by BINI", head);
    
    cout = insertAfter("Pangarap Lang Kita by Parokya Ni Edgar", head);
    cout = insertAfter("Harana by Parokya Ni Edgar", head);
    cout = insertAfter("Gitara by Parokya Ni Edgar", head);
    
    traverse(head);

    return 0;
}
