#include<iostream>

#ifndef _STACK
#include "stack.cpp"
#endif //_STACK

#include "exp_trans.cpp"

void decimal2any();
void expression_calc();

int main(int argc, char const *argv[])
{
    using namespace std;
    int i;

    //功能测试

    //创建空栈
    stack<char> charstack;
    stack<int> intstack;
    cout<<charstack.count()<<endl;
    cout<<intstack.isempty()<<endl;
    cout<<endl;

    //入栈操作
    for(i=0;i<10;i++){
        charstack.push('a'+i);
        intstack.push(i);
    }

    //打印栈中所有元素
    charstack.print_stack();
    intstack.print_stack();
    cout<<endl;

    //出栈操作
    while(!charstack.isempty()){
        cout<<charstack.pop()<<" ";
    }
    cout<<endl;
    cout<<endl;

    //清空栈
    charstack.clean_stack();
    cout<<charstack.isempty();
    cout<<endl;
    cout<<endl;

    //销毁栈
    charstack.~stack();
    intstack.~stack();

    //应用

    decimal2any();
    cout<<endl;
    expression_calc();
    
    return 0;
}

void decimal2any(){ //进制转换
    using namespace std;
    int dec=0,base=0;
    int res=0;
    stack<char> charstack;

    cout<<"请输入一个十进制整数:";
    cin>>dec;
    cout<<"请输入目标进制(2-36):";
    cin>>base;
    if(base<2 || base>36){
        cout<<"进制输入范围错误！"<<endl;
        return ;
    }

    while(dec){
        res=dec%base;
        if(res<10){
            charstack.push('0'+res);
        }
        else{
            charstack.push('A'+(res-10));
        }
        dec/=base;
    }

    cout<<"转换后的数字为：";
    charstack.print_stack();
    cout<<endl;

    charstack.~stack();
    return ;
}

void expression_calc(){ //表达式计算
    using namespace std;

    char exp[BUFF_LENGTH]={0},ans[BUFF_LENGTH]={0};
    char *p=NULL;
    stack<double> numstack;
    double tmp=0,store=0;;

    cout<<"请输入中缀表达式";
    cin>>exp;
    to_back_exp(exp,ans);

    p=ans;
    while(*p){
        switch(*p){
            case '+':
                tmp=numstack.pop();
                numstack.push(numstack.pop()+tmp);
                break;
            case '-':
                tmp=numstack.pop();
                numstack.push(numstack.pop()-tmp);
                break;
            case '*':
                tmp=numstack.pop();
                numstack.push(numstack.pop()*tmp);
                break;
            case '/':
                tmp=numstack.pop();
                numstack.push(numstack.pop()/tmp);
                break;
            case '#':
                numstack.push(store);
                store=0;
                break;
            default:
                store=store*10+*p-'0';
                break;
        }
        p++;
    }

    cout<<"计算结果为："<<numstack.pop()<<endl;

    numstack.~stack();  //销毁栈
}