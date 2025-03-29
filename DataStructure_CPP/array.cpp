#include<iostream>

using namespace std; 
class Array{
    private:
    int *arr;
    int max_size,len;
    public:
    Array(int s=10){
        if(s <= 0 )
            max_size =10;
        else
            max_size = s; 
        arr = new int[max_size];
        len = 0;
    }
    ~Array(){
        delete [] arr ;
    }
    bool isempty(){
        return len;
    }
    bool isfull(){
        return (len == max_size);
    }
    int getsize(){
        return len ; 
    }
    int get_max_size(){
        return max_size ; 
    }
    void print(){
        cout <<  "arr : [";
        for(int i = 0 ; i <  len ; i++){
            cout << arr[i] << " ";
        }
        cout << "]\n";
    }
    void clear(){
        len =0 ;
    }
    
    void insert(int pos, int val){
        if(pos < 0 && pos > len){
            cout << "out of range.......!\n";
        }
        else if(isfull()){
            cout << "array is full.........!\n";
        }else{
            for(int i = len ; i > pos ; i--){
                arr[i] = arr[i-1];
            }
            arr[pos] = val; 
            len++;
        }
    }
    void insert(int val){ // overload to put element in  end
        if(isfull())
            cout << "array is full.........!\n";
        else{
            arr[len] = val;
            len++;
        }
    }
    void insert_no_dublicate(int pos,int val){
        if(search(val) == -1){
            insert(pos,val);
        }else{
            cout << "element is already there\n";
        }
    }
    void insert_no_dublicate(int val){
        if(search(val) == -1){
            insert(val);
        }else{
            cout << "element is already there\n";
        }
    }

    void removeAt(int pos){
        if(pos < 0 && pos >= len){
            cout << "Out of range........\n";
        }else{
            for(int i = pos ; i < len ; i++){
                arr[i] =arr[i+1];
            }
            len--;
        }
    }
    void remove(int val){
        int loc = search(val);
        if(loc == -1){
            cout << "this element (" << val << ") doesn't exist\n"; 
        }else{
            removeAt(loc);
        }
    }
    int search(int val){
            for(int i = 0 ; i < len ; i++){
                if(arr[i] == val){
                    return i;
                }
            }
            return -1;
    }
};
int main() {
    Array q(5);
    q.insert(0,4);
    q.insert(0,3);
    q.insert(0,2);
    q.insert(0,1);
    q.insert(5);
    q.insert(3);
    q.removeAt(5);
    q.removeAt(4);
    q.remove(4);
    cout << q.search(1)<<endl;
    cout << q.search(5)<<endl;
    cout << q.getsize()<<endl;
    cout << q.get_max_size()<<endl;
    q.print();
    q.clear();
    q.print();

    return 0 ;

}