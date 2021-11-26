#ifndef NULL
#define NULL 0
#endif//NULL

#ifndef BUFF_LENGTH
#define BUFF_LENGTH 40
#endif//BUFF_LENGTH

void int_to_char(int i,char* &p);

void to_back_exp(char *exp,char* ans){
    int weight[BUFF_LENGTH],base_weight=0;
    int comb=0;
    int cpy[BUFF_LENGTH]={0};
    char *p=exp;
    int *pp=NULL,*s=NULL,*q=NULL;
    char tmp='\0';
    p=exp;pp=cpy;
    while(*p){  //处理待处理字符串及字符特征值
        if(*p>='0' && *p<='9'){
            comb=comb*10+(*p-'0');
        }
        else{
            if(comb!=0){
                weight[pp-cpy]=2+base_weight*3;
                *(pp++)=comb;
                comb=0;
            }
            if(*p=='+' || *p=='-'){
                weight[pp-cpy]=0+base_weight*3;
                *(pp++)=*p;
            }
            else if(*p=='*' || *p=='/'){
                weight[pp-cpy]=1+base_weight*3;
                *(pp++)=*p;
            }
            else if(*p=='('){
                base_weight+=1;
            }
            else if(*p==')'){
                base_weight-=1;
            }
            else{
                return ; //error
            }
        }
        p++;
    }
    if(comb!=0){
        weight[pp-cpy]=2+base_weight*3;
        *(pp++)=comb;
    }
    p=NULL;
    pp=cpy;
    while(*pp){
        if(weight[pp-cpy]==-1){  //已处理的运算符
            pp++;
        }
        else if(weight[pp-cpy]%3==2){  //数字
            pp++;
        }
        else{  //运算符
            s=pp+1;
            while(*s){
                if(weight[s-cpy]/3 > weight[pp-cpy]/3){  //进入上级括号
                    s++;
                }
                else if(weight[s-cpy]>weight[pp-cpy]){
                    s++;
                }
                else{
                    break;
                }
            }
            tmp=*pp;
            q=pp+1;
            while(q<s){
                *(q-1)=*q;
                weight[(q-1)-cpy]=weight[q-cpy];
                q++;
            }
            *(q-1)=tmp;
            weight[(q-1)-cpy]=-1;
            q=NULL;
            s=NULL;
        }
    }
    pp=cpy;
    p=ans;
    while(*pp){
        if(weight[pp-cpy]%3==2){
            int_to_char(*pp,p);
            *(p++)='#';
            pp++;
        }
        else{
            *(p++)=*(pp++);
        }
    }
}

void int_to_char(int i,char* &p){  //利用系统栈，反向对字符串写入
    int t=i/10;
    if(i>=10){
        int_to_char(t,p);
    }
    *p=i%10+'0';
    p++;
}