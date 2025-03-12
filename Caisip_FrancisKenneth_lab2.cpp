#include <iostream>

using namespace std;

struct Node {
    string songName;
    string artist;
    Node* link;
};

Node* createNode(string song, string artist) {
    Node* newNode = new Node;
    newNode->songName = song;
    newNode->artist = artist;
    newNode->link = newNode;
    return newNode;
}

void traverse(Node* head) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\nMy Playlist:\n";
    do {
        cout << temp->songName << " by " << temp->artist << " -> ";
        temp = temp->link;
    } while (temp != head);
    cout << "(Back to Head)\n";
}

Node* insertAtEnd(string song, string artist, Node* head) {
    Node* newNode = createNode(song, artist);
    
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }

    temp->link = newNode;
    newNode->link = head;

    cout << "A new song has been added at the end.\n";
    return head;
}

Node* insertAtBeginning(string song, string artist, Node* head) {
    Node* newNode = createNode(song, artist);
    
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }

    temp->link = newNode;
    newNode->link = head;

    cout << "A new song has been added at the beginning.\n";
    return newNode;
}

string insertAfter(string afterSong, string song, string artist, Node* head) {
    if (head == NULL) return "Playlist is empty.\n";

    Node* temp = head;
    do {
        if (temp->songName == afterSong) {
            Node* newNode = createNode(song, artist);
            newNode->link = temp->link;
            temp->link = newNode;
            return "A new song has been added after " + afterSong + ".\n";
        }
        temp = temp->link;
    } while (temp != head);

    return "Song not found.\n";
}

string deleteAtEnd(Node* head) {
    if (head == NULL) return "Playlist is empty.\n";

    if (head->link == head) {
        delete head;
        return "Last song deleted. Playlist is now empty.\n";
    }

    Node* temp = head;
    while (temp->link->link != head) {
        temp = temp->link;
    }

    delete temp->link;
    temp->link = head;

    return "A song has been deleted from the end.\n";
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return NULL;
    }

    if (head->link == head) {
        delete head;
        cout << "Last song deleted. Playlist is now empty.\n";
        return NULL;
    }

    Node* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }

    Node* newHead = head->link;
    temp->link = newHead;
    delete head;

    cout << "A song has been deleted from the beginning.\n";
    return newHead;
}

Node* deleteFromGivenNode(string givenSong, Node* head) {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return NULL;
    }

    if (head->songName == givenSong) {
        return deleteFromBeginning(head);
    }

    Node* temp = head;
    Node* prev = NULL;
    
    do {
        if (temp->songName == givenSong) {
            prev->link = temp->link;
            delete temp;
            cout << "The song \"" << givenSong << "\" has been deleted.\n";
            return head;
        }
        prev = temp;
        temp = temp->link;
    } while (temp != head);

    cout << "Song not found.\n";
    return head;
}

int main() {
    Node* head = createNode("Sanctuary", "Joji");

    head = insertAtEnd("Bahaghari", "Dionela", head);
    traverse(head);
    head = insertAtEnd("Musika", "Dionela", head);
    traverse(head);
    head = insertAtEnd("Oksihina", "Dionela", head);
    traverse(head);

    head = insertAtBeginning("Lagi", "BINI", head);
    traverse(head);
    head = insertAtBeginning("Blink Twice", "BINI", head);
    traverse(head);
    head = insertAtBeginning("Out Of My Head", "BINI", head);
    traverse(head);
    head = insertAtBeginning("Zero Pressure", "BINI", head);
    traverse(head);

    cout << insertAfter("Sanctuary", "Pangarap Lang Kita", "Parokya Ni Edgar", head);
    traverse(head);
    cout << insertAfter("Pangarap Lang Kita", "Harana", "Parokya Ni Edgar", head);
    traverse(head);
    cout << insertAfter("Harana", "Gitara", "Parokya Ni Edgar", head);
    traverse(head);

    cout << deleteAtEnd(head);
    traverse(head);
    head = deleteFromBeginning(head);
    traverse(head);
    head = deleteFromGivenNode("Gitara", head);
    traverse(head); 
    
   return 0;
}