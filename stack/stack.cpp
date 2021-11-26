#include "stack.h"
#include<cstdlib>
#include<iostream>

template <class T>
stack<T>::stack(){
    stack::_top=NULL;
    stack::_count=0;
}

template <class T>
void stack<T>::free_node(stack_node* node){
    free(node->data);
    node->data=NULL;
    free(node);
    node=NULL;
}

template <class T>
void stack<T>::push(T const& elem){
    stack_node* present=(stack_node*)malloc(sizeof(stack_node));
    present->pre=_top;
    present->data=(T*)malloc(sizeof(T));
    *(T*)(present->data)=elem;
    _top=present;
    _count++;
}

template <class T>
T stack<T>::pop(){
    T backup;
    stack_node* bak=_top;
    if(!_count){
        throw("stack<>::pop: stack has no elements.");
    }
    backup=*(T*)(_top->data);
    _top=_top->pre;
    _count--;
    free_node(bak);
    bak=NULL;
    if(!_count){
        _top=NULL;
    }
    return backup;
}

template <class T>
int stack<T>::count(){
    return _count;
}

template <class T>
int stack<T>::isempty(){
    return _count?0:1;
}

template <class T>
T stack<T>::top(){
    if(!_count){
        throw("stack<>::pop: stack has no elements.");
    }
    return *(_top->data);
}

template <class T>
void stack<T>::clean_stack(){
    while(_top){
        pop();
    }
}

template <class T>
stack<T>::~stack(){
    clean_stack();
}

#ifndef _STACK_NO_PRINT
template <class T>
void stack<T>::print_stack(){
    using namespace std;
    stack_node* p;
    p=_top;
    while(p){
        cout<<*(T*)(p->data)<<" ";
        p=p->pre;
    }
    cout<<endl;
}
#endif