#ifndef LINKLIST_H
#define LINKLIST_H

#include <bits/stdc++.h>
using namespace std;

template<class type>
class linkList{
    class node; //done
    node *head = nullptr;
    node *current = nullptr;
    int size_list = 0;

    public:
    linkList(type value = type()); //done
    void push(type value);  //done
    void pop(); //done
    void insert(int index , type value); //done
    bool contain(type value); //done
    void swap(type first_value , type sec_value); //done
    void print(); //done
    int size();
    linkList reverse(); //done
    type operator[](int index);

    private:
    type find_index(int index); //done
    node *search(type value); //done
};

template<class type>
class linkList<type> :: node{
    public:
    type value;
    node *next = nullptr;
};

template<class type>
void linkList<type> :: print(){
    for(node *p=this->head ; p!=nullptr ; p=p->next){
        cout << p->value << " ";
    }
}

template<class type>
linkList<type> :: linkList(type value){
    if(value != type()){
        this->head = new node();
        this->head->value = value;
        this->current = this->head;
        this->size_list++;
    }
}

template<class type>
void linkList<type> :: push(type value){
    if(this->head == nullptr){
        this->head = new node();
        this->head->value = value;
        this->current = this->head;
    }
    else{
        node *temp = new node();
        temp->value = value;
        this->current->next = temp;
        this->current = temp;
    }
    this->size_list++;
}

template<class type>
void linkList<type> :: pop(){
    for(node *p=this->head ; p!=nullptr ; p=p->next){
        if(p->next == this->current){
            p->next = nullptr;
            this->current = p;
        }
    }
    this->size_list--;
}

template<class type>
type linkList<type> :: find_index(int index){
    int i=0;
    for(node *p=this->head ; p!=nullptr ; p=p->next){
        if(i == index){
            return p->value;
        }
        i++;
    }
    return type();
}

template<class type>
void linkList<type> :: insert(int index , type value){
    node *temp = new node();
    temp->value = value;
    if(index == 0){
        temp->next = this->head;
        this->head = temp;
    }
    else if(index == this->size_list-1){
        this->current->next = temp;
        this->current = temp;
    }
    else{
        int i=0;
        for (node *p = this->head; p != nullptr; p = p->next , ++i) {
            if (i == index) {
                temp->next = p->next;
                p->next = temp;
                break;
            }
        }
    }
    this->size_list++;
}

template<class type>
bool linkList<type> :: contain(type value){
    for(node *p=this->head ; p!=nullptr ; p=p->next){
        if(p->value == value){
            return true;
        }
    }
    return false;
}

template<class type>
void linkList<type> :: swap(type first_value , type sec_value){
    if (first_value == sec_value) return;
    node *first = nullptr, *second = nullptr, *prevFirst = nullptr, *prevSecond = nullptr;
    node* temp = head;
    while (temp) {
        if (temp->next && temp->next->value == first_value) {
            prevFirst = temp;
            first = temp->next;
        }
        if (temp->next && temp->next->value == sec_value) {
            prevSecond = temp;
            second = temp->next;
        }
        if (temp->value == first_value) {
            first = temp;
        }
        if (temp->value == sec_value) {
            second = temp;
        }
        temp = temp->next;
    }
    if (!first || !second) return;
    if (prevFirst) {
        prevFirst->next = second;
    } else {
        head = second;
    }
    if (prevSecond) {
        prevSecond->next = first;
    } else {
        head = first;
    }
    temp = first->next;
    first->next = second->next;
    second->next = temp;
}

template<class type>
typename linkList<type>::node * linkList<type>::search(type value){
    for(node *p=this->head ; p!=nullptr ; p=p->next){
        if(p->value==value){
            return p;
        }
    }
    return nullptr;
}

template<class type>
linkList<type> linkList<type> :: reverse(){
    linkList<type> *rev = new linkList(); 
    node *cur = this->current;
    for(int i=1 ; i<=this->size_list ; ++i){
        for(node *p=this->head ; p!=nullptr ; p=p->next){
            if(p->next == cur){
                rev->push(cur->value);
                cur = p;
            }
        }
    }
    rev->push(this->head->value);
    return *rev;
}

template<class type>
type linkList<type> :: operator[](int index){
    return this->find_index(index);
}

template<class type>
int linkList<type> :: size(){
    return this->size_list;
}

#endif