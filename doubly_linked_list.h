#pragma once
#include<iostream>
#include<iterator>
#include<algorithm>


class node{
public: 
    int data;
    node* next;
    node* prev;

    node(int k){
        data = k;
        next = nullptr;
        prev = nullptr;
    }
};

class double_linked_list{
public:
    double_linked_list(){}
    ~double_linked_list(){

        node* current =first;
        while (current != nullptr) {
            node* next = current->next;
            node* prev = current->prev;
            delete current;
            current = next;
        }
    }
    void push_bac(int k){
        node* temp = new node(k);
        if(first==nullptr){
            first=temp;
            temp->prev=nullptr;
        }
        if(last != nullptr){
            temp->prev=last;
            last->next=temp;
        }
        last = temp;
        if(temp==nullptr){
            last->next=nullptr;
        }
    }   
    void print() {
        node *current = first;

        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
    void remove(int k){
        node* current =first;
        bool xd =true ;
        while(current!=nullptr && current->data!=k){
            current=current->next;
        }
        if(first->data==k){
            first=first->next;
            delete current;
            xd = false;
        }
        if(last->data==k){
            last=last->prev;
            delete current;
            current =last;
            last->next=nullptr;
            xd=false;
        }
        if(xd){
            current=current->prev;
            current->next=current->next->next;
            current=current->next->next;
            current->prev=current->prev->prev;
            delete current->prev;
        }
    }
    void length(){
        node* current = first;
        int xd=0;
        while(current!=nullptr){
            ++xd;
            current=current->next;
        }
        std::cout<<xd<<std::endl;
    }
    void find(int k){
        node* current =first;
        bool xd;
        while(current!=nullptr){
            if(current->data==k){
                xd=true;
                break;
            }
            else{
                xd = false;
            }
            current=current->next;
        }
        std::cout<<xd<<std::endl;
    }
    void swap_nodes(int k,int x){
        node* current=first;
        node* pirveli;
        node* meore;
        int xd =0;
        while(current!=nullptr){
            if(current->data==k && xd==0){
                pirveli=current;
                ++xd;
            }
            if(current->data==x&&xd==1){
                meore=current;
            }
            current=current->next;
        }
         if (pirveli==nullptr||meore ==nullptr){
            std::cout<<"put avilable node data"<<std::endl;
         }
        else{
        std::swap(pirveli->prev,meore->prev);
        std::swap(pirveli->next,meore->next);
        std::swap(pirveli->prev->next,meore->prev->next);
        std::swap(pirveli->next->prev,meore->next->prev);

        }
    }
    void remove_at(int k){
        node* current =first;
        bool xd =true ;
        int x=1;
        while(current!=nullptr && x!=k){
            current=current->next;
            ++x;
        }
        if(x==1){
            first=first->next;
            delete current;
            xd = false;
        }
        if(x==k&&current==last){
            last=last->prev;
            delete current;
            current =last;
            last->next=nullptr;
            xd=false;
        }
        if(xd){
            current=current->prev;
            current->next=current->next->next;
            current=current->next->next;
            current->prev=current->prev->prev;
            delete current->prev;
        }
    }
private:
    node* first;
    node* last;
};
