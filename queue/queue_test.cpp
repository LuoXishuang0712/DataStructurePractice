#ifndef _QUEUE
#include "queue.cpp"
#endif//_QUEUE

#include <iostream>

void application();

int main(int argc, char const *argv[])
{
    using namespace std;

    //基本操作

    //队列初始化（默认长度64，可传递整数改变队列最大长度）
    queue<int> intqueue;
    int i;

    //判断队列状态及入队
    cout<<intqueue.status()<<endl;
    for(i=0;i<64;i++){
        intqueue.push(i);
    }
    cout<<intqueue.status()<<endl;
    cout<<endl;

    //出队并判断状态
    for(i=0;i<16;i++){
        cout<<intqueue.pop()<<" ";
    }
    cout<<endl;
    cout<<intqueue.status()<<endl;
    cout<<endl;

    //打印队列中所有元素
    intqueue.print();
    cout<<endl;

    //队列应用
    application();

    return 0;
}

void application(){
    using namespace std;
    queue<int> intqueue(5);
    int i,tmp=0;

    cout<<"请输入五个整数:";
    for(i=0;i<5;i++){
        cin>>tmp;
        intqueue.push(tmp);
    }
    cout<<"队列状态："<<intqueue.status()<<endl;
    cout<<endl;

    cout<<"出队三个元素：";
    for(i=0;i<3;i++){
        cout<<intqueue.pop()<<" ";
    }
    cout<<endl;
    cout<<"队列状态："<<intqueue.status()<<endl;
    cout<<endl;

    cout<<"出队两个元素：";
    for(i=0;i<2;i++){
        cout<<intqueue.pop()<<" ";
    }
    cout<<endl;
    cout<<"队列状态："<<intqueue.status()<<endl;
    cout<<endl;
}