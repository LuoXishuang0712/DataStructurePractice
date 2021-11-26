#include<iostream>

void to_back_exp(char *exp);

int main(int argc, char const *argv[])
{
    using namespace std;
    char exp[]="1*2+(3+4*5)*6";
    to_back_exp(exp);
    cout<<exp<<endl;

    return 0;
}

void to_back_exp(char *exp){  //假定每个数字仅占一个字节，且符号只有+-*/()
    int weight[20],base_weight=0;
    char *p=exp,*q=NULL,*s=NULL;
    char tmp='\0';
    while(*p){  //处理权重
        if(*p=='+' || *p=='-'){
            weight[p-exp]=0+base_weight*3;
        }
        else if(*p=='*' || *p=='/'){
            weight[p-exp]=1+base_weight*3;
        }
        else if(*p>='0' && *p<='9'){
            weight[p-exp]=2+base_weight*3;
        }
        else if(*p=='('){
            base_weight+=1;
            weight[p-exp]=-1;
        }
        else if(*p==')'){
            base_weight-=1;
            weight[p-exp]=-1;
        }
        else{
            return ; //error
        }
        p++;
    }
    p=exp;
    while(*p){
        if(weight[p-exp]==-1 && (*p=='(' || *p==')')){  //去括号
            q=p+1;
            while(*q){
                *(q-1)=*q;
                weight[(q-1)-exp]=weight[q-exp];
                q++;
            }
            *(q-1)='\0';
            q=NULL;
        }
        else if(weight[p-exp]==-1){  //已处理的运算符
            p++;
        }
        else if(weight[p-exp]%3==2){  //数字
            p++;
        }
        else{  //运算符
            s=p+1;
            while(*s){
                if(weight[s-exp]/3 > weight[p-exp]/3){  //进入上级括号
                    s++;
                }
                else if(weight[s-exp]>weight[p-exp]){
                    s++;
                }
                else if(weight[s-exp]==-1 && (*s=='(' || *s==')')){
                    s++;
                }
                else{
                    break;
                }
            }
            tmp=*p;
            q=p+1;
            while(q<s){
                *(q-1)=*q;
                weight[(q-1)-exp]=weight[q-exp];
                q++;
            }
            *(q-1)=tmp;
            weight[(q-1)-exp]=-1;
            q=NULL;
            s=NULL;
        }
    }
}