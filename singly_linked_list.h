#pragma once
#include <iostream>
#include <iterator>
class node {
public:
  int data;
  node *next;

  node(int k) {
    data = k;
    next = nullptr;
  }
};
class linked_list {
public:
  linked_list(){};
  ~linked_list() {
    node *current = first;

    while (current != nullptr) {
      node *next = current->next;
      delete current;
      current = next;
    }
  }

  void push_baki(int k) {
    node *temp = new node(k);
    if (first == nullptr) {
      first = temp;
    }
    if (last != nullptr) {
      last->next = temp;
    }
    last = temp;
  }
  void print() {
    node *current = first;
    while (current != nullptr) {
      std::cout << current->data << std::endl;
      current = current->next;
    }
  }

  void remover(int k) {
    node *current = first;
    node *previous = nullptr;

    if (current->data == k) {
      first = current->next;
      delete current;
      current = first;
    }
    while (current != nullptr) {
      if (current->data != k) {
        previous = current;
        current = current->next;
      } else {
        previous->next = current->next;
        delete current;
        current = previous->next;
      }
    }
  }

  int length() {
    node *temp = first;
    int xd = 0;
    while (temp != nullptr) {
      temp = temp->next;
      xd++;
    }
    return xd;
  }

  void remover_at(int x) {
    node *current = first;
    node *previous = nullptr;
    int mtv = 0;
    if (mtv == x) {
      first = current->next;
      delete current;
      current = first;
    }

    while (current != nullptr) {
      ++mtv;
      if (mtv != x) {
        previous = current;
        current = current->next;
      } else {
        previous->next = current->next;
        delete current;
        current = previous->next;
      }
    }
  }
  bool find(int x) {
    node *current = first;

    while (current != nullptr){
      if(current->data==x){
        return true; 
      }
      current = current->next;
    }

    return false;
}

 void replace(int old, int axali){
   node *current =first;
      while(current!=nullptr){
        if(current->data==old){
            current->data=axali;
        }
        current=current->next;
      }
 }
private:
  node *first;
  node *last;
};

