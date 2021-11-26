#ifndef _QUEUE
#include "queue.h"
#endif//_QUEUE

#include <iostream>
#include <cstdlib>

template <class T>
void queue<T>::allowcate(){
    _data=(T*)malloc(sizeof(T)*_length);
}

template <class T>
queue<T>::queue(){
    _length=_LENGTH+1;
    allowcate();
}

template <class T>
queue<T>::queue(int len){
    _length=len+1; //一个空间会被用于头指针与尾指针的分割
    allowcate();
}

template <class T>
void queue<T>::destory(){
    free(_data);
    _data=NULL;
    _length=0;
    _head=0;
    _tail=0;
}

template <class T>
queue<T>::~queue(){
    destory();
}

template <class T>
int queue<T>::status(){
    if(_head==_tail){
        return 0; //empty
    }
    else if(_tail==_head-1){
        return -1; //queue full
    }
    else if(_tail==_length-1 && _head==0){
        return -1; //queue full         
    }
    else{
        return 1; //queue not full
    }
}

template <class T>
void queue<T>::push(T element){
    if(status()==-1){
        throw("too much elements.");
    }
    _data[_tail]=element;
    _tail=(_tail+1)%_length;
}

template <class T>
T queue<T>::pop(){
    if(status()==0){
        throw("too few elements.");
    }
    T bak;
    bak=_data[_head];
    _head=(_head+1)%_length;
    return bak;
}

template <class T>
void queue<T>::print(){
    using namespace std;
    int i;
    for(i=_head;i!=_tail;i=(i+1)%_length){
        cout<<_data[i]<<" ";
    }
    cout<<endl;
}