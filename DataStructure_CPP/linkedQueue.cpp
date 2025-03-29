#include<iostream>
#include <cassert>
using namespace std;

template<class t>
class Queue {
private:
    struct node {
        t item;
        node* next;
    };
    node *front,*rear;
    int len;
public:
    Queue(){
        front =rear =NULL;
        len = 0;
    }
    bool isempty(){
        if(rear == NULL){
            return true;
        }else{
            return false;
        }
    }
    void enqueue(t element){
        if(isempty()){
            front = new node;
            front->item = element;
            rear =front;
        }else{
            node *newptr = new node;
            newptr->item = element;
            newptr->next = NULL;
            rear->next = newptr;
            rear = newptr;
        }
        len++;
    }
    void dequeue(){
        if(isempty()){
            cout << "queue is empty........\n";
        }else if(len ==1 ){
            delete front ; 
            rear = NULL;
            len =0;
        }else{
            node* temp = front ; 
            front = front->next; 
            delete temp;
            len--;
        }
    }
    void clear(){
        node *cur; 
        while(front != NULL){
            cur =front; 
            front  =front->next;
            delete cur; 
        }
        rear = NULL;
        len = 0;
    }
    void display(){
        node *temp=front;
        cout << "Item in the queue :[ ";
        while(temp != NULL){
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << "]\n";
        delete temp;
    }
    t getfront(){
        assert(!isempty());
        return front->item;
    }  
    t getrear(){
        assert(!isempty());
        return rear->item;
    }
    int getsize(){
        return len;
    }
    void search(t ele){
        assert(!isempty());
        int pos =-1;
        bool found =false;
        for(node* temp =front; temp != NULL ; temp = temp->next ){
            pos++;
            if(temp->item == ele){
                cout << ele << " is found in index : " << pos <<endl;
                found =true;
                break;
            }
        }
        if(!found) cout <<  "this value (" << ele << ") doesn't exist\n"; 
    }
};

int main() {
    Queue <int> q1;
    q1.enqueue (1);
    q1.enqueue (2);
    q1.enqueue (3);
    q1.enqueue (4);
    q1.dequeue ();
    q1.display();
    q1.search(2) ; 
    q1.search(1) ; 
    cout << q1.getfront() << endl;
    cout << q1.getrear() << endl;
    q1.clear();
    q1.display();
    return 0;
}