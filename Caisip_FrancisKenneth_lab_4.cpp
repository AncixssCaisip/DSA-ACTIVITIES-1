#include <iostream>
using namespace std;

struct song {
    string song;
    int priority;
};

song karaoke_queue[100];

int front = -1;
int rear = -1;
int max_queue = 10;

bool isFull(){
    return (front == 0 && rear == max_queue - 1) || (rear == (front - 1) % (max_queue - 1));
}

bool isEmpty(){
    return front ==-1;
}

void displayrearandfront(){
    cout << "Front: " << front << ", Rear: " << rear << endl;
}

string enqueue(string song, int priority){
    if (isFull()) {
        return "The queue is full. Try again later";
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == max_queue - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    karaoke_queue[rear] = {song, priority};

    return "A new song has been added to the queue";
}

string dequeue(){
    if (isEmpty()) {
        return "There is no song in the queue. Try adding first!";
    }

    string song = karaoke_queue[front].song;

    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % max_queue;
    }

    displayrearandfront();
    return song;
}

int main() {
    
    cout << enqueue("Scott Street", 4) << endl;
    cout << enqueue("The Night We Met", 1) << endl; 
    cout << enqueue("The Cut That Always Bleeds", 2) << endl;
    cout << enqueue("Daylight", 5) << endl;
    cout << enqueue("Favorite Vice", 3) << endl;
    
    cout << dequeue() << " Now playing: " << endl;
    cout << dequeue() << " Now playing: " << endl;
    
    cout << enqueue("Here With Me", 9) << endl;
    cout << enqueue("Hung Up", 6) << endl; 
    
    cout << dequeue() << " Now playing: " << endl;
    
    cout << enqueue("If I Knew", 10) << endl;
    cout << enqueue("I'll Be", 8) << endl;
    cout << enqueue("Too Good To Say Goodbye", 7) << endl;
    
    cout << dequeue() << " Now playing: " << endl;
    cout << dequeue() << " Now playing: " << endl;
    cout << dequeue() << " Now playing: " << endl;
    
    return 0;
}