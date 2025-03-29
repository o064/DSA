#include<iostream>
#include<cassert>
using namespace std;
class queue{
    private:
    int front,rear,count; 
    int max_size;
    int *arr; //dynamic array 
    public:
    queue(int size){
        if(size <=0)
            max_size = 100;
        else
            max_size =size;
        arr =new int [max_size];
        front = 0;
        rear  = max_size-1;
        count=0;
        
    }
    bool isempty(){
        return count == 0 ;
    }
    bool isfull(){
        return count == max_size;
    }
    void enqueue(int val){
        if(isfull()){
            cout << "queue is full\n";
        }else{
            rear = (rear+1)%max_size;
            arr[rear] = val;
            count++;

        }
    }
    void dequeue(){
        if(isempty()){
            cout << "queue is empty\n";
            return ;
        }else{
            front = (front+1)%max_size;
            count--;
        }
    }
    void dequeue(int &val){
        if(isempty()){
            cout << "queue is empty\n";
            return ;
        }else{
            val = arr[front] ;
            front = (front+1)%max_size;
            count--;
        }
    }
    int getsize(){
        return count;
    }
    int getfront(){
        assert(!isempty());
        return arr[front];
    }
    int getrear(){
        assert(!isempty());
        return arr[rear];
    }
    void display(){
        cout << "[";
        for(int i = front ; i != rear; i = (i+1)%max_size){
            cout << arr[i] << " ";
        }
        cout << arr[rear] ;
        cout << "]\n";
    }
    int search(int val){
        int pos =-1;
        if(!isempty()){
            for(int i = front ; i != rear ; i = (i+1)%max_size){
                if(arr[i] == val){
                    pos = i ;
                    break;
                }
            }
            if(pos == -1){
                if(arr[rear] == val)
                pos = rear;
            }
        }else 
            cout << "queue is empty\n";
        return pos;
    }
};
int main(){
    queue q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(120);
    cout << q1.search(50);
    return 0 ; 
}