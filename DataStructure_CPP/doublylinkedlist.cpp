#include<iostream>
using namespace std;
class doublylinkedlist{
    private:
    struct node {
        int item ; 
        node*next,*prev;
    };
    node* first,*last;
    int length ;
    public:
    doublylinkedlist(){
        first = last = NULL;
        length =0 ; 
    }
    //insertion at the beginning of list
    bool isempty(){
        return (first==NULL);
    }
    void insertfirst(int val)
    {
        node* newnode = new node;
        newnode->item=val;
        newnode->prev = NULL;
        if(isempty()){
            first = last = newnode;
            newnode->next = NULL;
        }else{
            newnode->next = first;
            first->prev =newnode;
            first = newnode;
        }
        length++;
    }
    void insertlast(int val)
    {
        node* newnode = new node;
        newnode->item=val;
        newnode->next = NULL;
        if(isempty()){
            first = last = newnode;
            newnode->next = NULL;
        }else{
            newnode->prev = last;
            last->next =newnode;
            last = newnode;
        }
        length++;
    }
    void removefirst(){
        if(isempty()){
            cout << "the list is empty \n";
            return ; 
        }else{
            if(length == 1){
                delete first;
                first = last = NULL;
            }else{ 
                node*cur = first;
                first = first->next;
                first->prev = NULL;
                delete cur;
            }
            length--;
        }
    }
    void removelast(){
        if(isempty()){
            cout << "the list is empty \n";
            return ; 
        }else{
            if(length == 1){
                delete first;
                first = last = NULL;
            }else{ 
                node*cur = last;
                last = last->prev;
                last->next = NULL;
                delete cur;
            }
            length--;
        }
    }
    void insertAt(int pos,int val){
        if(pos <0 || pos > length)
            cout << "Out of range\n";
        else{
            if (pos ==0 )
                insertfirst(val);
            else if (pos == length)
                insertlast(val);
            else{
                node *newnode = new node; 
                newnode ->item = val;
                node*cur =first ;
                for(int i = 1 ; i < pos ; i++){
                    cur =cur->next;
                }
                newnode->prev = cur ;
                newnode->next = cur->next;
                cur->next->prev = newnode;
                cur->next = newnode;
                length++;
            }
        }
    }
    void remove(int val){
        if(isempty()){
            cout << "the list is empty.....\n";
        }else{
            if(first->item == val ){
                removefirst();
            }else{
                node* cur = first->next; 
                while((cur!=NULL && cur-> item != val)){
                    cur =cur->next;
                }
                if(cur == NULL){
                    cout << val <<" not found\n";
                }else if (cur->next == NULL){
                    removelast();
                }else{
                    cur->next->prev =cur->prev;
                    cur->prev->next = cur->next;
                    delete cur;
                    length--;
                }
            }
        }

    }
    void print(){
        cout << "list : [ ";
        node *cur =first;
        while(cur !=NULL){
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }   
     void printR(){
        cout << "Reversed list : [ ";
        node *cur =last;
        while(cur !=NULL){
            cout << cur->item << " ";
            cur = cur->prev;
        }
        cout << "]\n";
    }
};
int main() {
    doublylinkedlist d1;
    d1.insertfirst(20);
    d1.insertfirst(10);
    d1.insertfirst(0);
    d1.insertlast(30);
    d1.insertlast(50);
    d1.insertAt(0,-10);
    d1.insertAt(6,60);
    d1.insertAt(5,40);
    d1.remove(60);
    d1.remove(60);
    d1.remove(20);
    d1.remove(-10);
    d1.print();
    d1.printR();
    return 0;
}