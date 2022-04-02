// hw2-3: garage of rich man
// environment: Notepad++ 8.2.1(64bits X64)
// C++ type: C++ 11
// g++ type: g++ version 6.3.0
#include <iostream>
#include <string>

using namespace std;

// car node
class Car{
public:
    Car* prev;
    Car* next;
    int code;
};

// insert at front (the end is the longest car haven't been driven)
void InsertNode(Car*& head, int code){
       // no head
       if(head==nullptr){
           head=new Car();
           head->next=nullptr;
           head->prev=nullptr;
           head->code=code;
       }
       // head exist
       else{
           Car* new_node=new Car();
           new_node->code=code;
           new_node->next=head;
           new_node->prev=head->prev;
           head->prev=new_node;
           head=new_node;
       }
    return;
}

// delete the end of linked list
void DeleteNode(Car*& head){
    if(head==nullptr){
        cout<<"Car list is empty\n";
        return;
    }
    // 2 situation: only 1 car left v.s. more than 1 car
    Car* restore_head=head;
    while(head!=nullptr){
        if(head->prev==nullptr&&head->next!=nullptr){ // only one car
            head=nullptr;
            return;
        }
        else if(head->next==nullptr){   // reach the last one car
            (head->prev)->next=nullptr;
            head->prev=nullptr;
            head->code=-1;
            head=nullptr;
        }   
        head=head->next;
    }
    head=restore_head;
    return;
}

// get car total count
int get_car_count(Car* head){
    int count=0;
    while(head!=nullptr){
        count++;
        head=head->next;
    }
    return count;
}

// search if specified code of car exist in garage
bool is_in_garage(Car* head, const int& code){
    while(head!=nullptr){
        if(head->code==code)return true;
        head=head->next;
    }
    return false;
} 

// garage process
void rich_man_garage(){
    int garage_size=0;
    cin>>garage_size;
    cout<<"The size of garage is "<<garage_size<<endl;
    string action;
    while(cin>>action){
        if(action=="buy"){
            
        }
        else if(action=="drive"){
            
        }
        else cout<<"> No corresponding function\n";
    }
    return;
}

int main(){
    
    rich_man_garage();
    
    system("pause");
    return 0;
}