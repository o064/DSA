#include <iostream>
using namespace std;
class linkedlist
{
private:
    struct node
    {
        int item;
        node *next;
    };
    node *first, *last;
    int length;

public:
    linkedlist()
    {
        first = last = NULL;
        length = 0;
    }
    bool isempty()
    {
        return !length;
    }
    void insertfirst(int item)
    {
        node *newnode = new node;
        newnode->item = item;
        if (isempty())
        {
            newnode->next = NULL;
            first = last = newnode;
        }
        else
        {
            newnode->next = first;
            first = newnode;
        }
        length++;
    }
    void insertlast(int item)
    {
        node *newnode = new node;
        newnode->item = item;
        if (isempty())
        {
            newnode->next = NULL;
            first = last = newnode;
        }
        else
        {
            last->next = newnode;
            newnode->next = NULL;
            last = newnode;
        }
        length++;
    }
    void insert(int pos, int item)
    {
        if (pos < 0 || pos > length)
            cout << "out of range \n";
        else
        {
            if (pos == 0)
            {
                insertfirst(item); // if list is empty then call insertfirst() function.
            }
            else if (pos == length)
            {
                insertlast(item);
            }
            else
            {
                node *newnode = new node;
                newnode->item = item;
                node *cur = first;
                for (int i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }
                newnode->next = cur->next;
                cur->next = newnode;
                length++;
            }
        }
    }
    void removefirst()
    {
        if (isempty())
        {
            cout << "the list is empty\n";
            return;
        }
        else
        {

            if (length == 1)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                node *temp = first;
                first = first->next;
                delete temp;
            }
            length--;
        }
    }
    void removelast()
    {
        if (isempty())
        {
            cout << "the list is empty\n";
            return;
        }
        else
        {
            if (length == 1)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                node *prev = first, *cur = first->next;
                while (cur != last)
                {
                    prev = cur;
                    cur = cur->next;
                }
                delete cur;
                prev->next = NULL;
                last = prev;
            }
            length--;
        }
    }
    void remove(int element)
    {
        if (isempty())
        {
            cout << "the list is empty\n";
            return;
        }
        else
        {
            node *cur, *prev;
            if (first->item == element)
            {
                cur = first;
                first = first->next;
                delete cur;
                length--;
                if (length == 0)
                    last = NULL; 
                // removefirst(); //or use this
            }
            else
            {
                cur = first->next;
                prev = first;
                while (cur != NULL)
                {
                    if (cur->item == element)
                        break;
                    prev = cur;
                    cur = cur->next;
                }
                if (cur == NULL)
                {
                    cout << element << " is not found\n";
                }
                else
                {
                    prev->next = cur->next;
                    if (last == cur)
                        last = prev;
                    delete cur;
                    length--;
                }
            }
        }
    }
    void removeAt(int pos){
        if( pos < 0  || pos >= length){
            cout << "Out of range\n";
            return ; 
        }else if (length == 0){
            cout << "list is empty";
            return  ; 
        }else{
            if(pos == 0 ){
                removefirst();
            }else if( pos == length-1){
                removelast();
            }else{
                node*cur = first->next , *prev = first;
                for(int i=1 ; i < pos ; i++){
                    prev = cur ;
                    cur =cur->next;
                }
                prev->next = cur->next; 
                cur->next = NULL;
                delete cur ;
                length--;
            }
        }
    }
    int search(int ele){
        node* cur ;
        int pos = 0 ;
        while(cur != NULL){
            if(cur-> item ==  ele){
                return pos;
            }
            cur = cur->next; 
            pos++;
        }
        return -1 ;
    }
    void reverse(){
        node* prev,*cur , *next;
        prev = NULL;
        cur =first;
        while(cur!=NULL){
            next =cur->next;
            cur->next = prev;
            prev =cur ;
            cur = next ; 
        }
        first =prev ; 
    }
    void print()
    {
        cout << "printing the linkedlist : [";
        node *cur = first;
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }

};
int main()
{
    linkedlist l;
    l.insertfirst(20);
    l.insertfirst(10);
    l.insertlast(30);
    l.insert(0, 0);
    l.insert(4, 50);
    l.insert(4, 40);
    l.print();
    l.reverse();
    l.print();
    return 0;
}