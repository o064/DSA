#include<iostream>
using namespace std;
class stack{
    private:
        struct node{
            int item;
            node *next;
        };
        node *Top,*cur;
    public:
        stack(){
            Top =NULL;
        }
        void push(int newitem){
            node* newitemptr = new node;
            newitemptr->item = newitem;
            newitemptr->next =Top;
            Top = newitemptr;
        }
        bool isempty(){
            return Top == NULL;
        }
        void pop(){
            if(isempty())
                cout << "stack is empty on pop \n";
            else{
                node *temp =  Top;
                Top = Top->next;
                temp->next= NULL;
                delete temp; 
            }
        }
        void pop(int &item){
            if(isempty())
                cout << "stack is empty on pop \n";
            else{
                item = Top->item;
                node *temp =  Top;
                Top = Top->next;
                temp->next= NULL;
                delete temp; 
            }
        }
        void gettop(int &item){
            if(isempty())
                cout << "stack is empty on gettop \n";
            else{
                item = Top->item;
            }
        }
        void display(){
            cur =Top;
            cout <<"[";
            while (cur !=NULL) {
                cout << cur->item << " ";
                cur = cur->next;
            }
            cout <<"]\n";
        }

};

int main(){
    int x =8;
    int* ptr =&x;
    cout<< ptr;

    return 0 ;
}