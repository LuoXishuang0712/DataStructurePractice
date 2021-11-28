#include "sort.h"
#include<iostream>
#include<random>
#include<cstdlib>
#include<ctime>

int* get_random_num(int count,int right,int left){
    int* arr=NULL;
    int i=0;
    if(left>right){
        return NULL;
    }
    arr=(int*)malloc(sizeof(int)*count);
    srand(time(NULL));
    for(i=0;i<count;i++){
        arr[i]=(rand()%(right-left))+left;
    }
    return arr;
}

int* get_sequential_num(int count,int right,int left){
    int* arr=NULL;
    int gap=right-left,i=0;
    if(gap<0){
        return NULL;
    }
    double cell=(double)gap/(count-1);
    arr=(int*)malloc(sizeof(int)*count);
    for(i=0;i<count;i++){
        arr[i]=left+(int)(cell*i);
    }
    return arr;
}

void print_array(int* array,int count){
    using namespace std;
    int i=0;
    for(i=0;i<count;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int* reverse(int* arr,int count){
    int i=0;
    for(i=0;i<(count/2);i++){
        exchange(&arr[i],&arr[count-i-1]);
    }
    return arr;
}

int cmp(int a,int b,int mode){
    if(mode){
        return a>=b;
    }
    else{
        return a<=b;
    }
}

int exchange(int* a,int* b){
    int c;
    c=*a;*a=*b;*b=c;
    return 0;
}

void arr_cpy(int* source,int* target,int count){
    int i=count;
    while(i--){
        target[i]=source[i];
    }
}

int insert_sort(int* array,int count,int* output,int mode){
    int* ans=NULL;
    int i=0,j=0,t=0;
    int cmp_count=0;
    if(output==NULL){
        ans=(int*)malloc(sizeof(int)*count);
    }
    else{
        ans=output;
    }
    arr_cpy(array,ans,count);
    for(i=1;i<count;i++){
        t=ans[i];
        for(j=i-1;j>=0;j--){
            cmp_count++;
            if(cmp(ans[j],t,mode)){
                ans[j+1]=ans[j];
            }
            else{
                break;
            }
        }
        ans[j+1]=t;
    }
    if(!output){
        print_array(ans,count);
        free(ans);
        ans=NULL;
    }
    return cmp_count;
}

int select_sort(int* array,int count,int* output,int mode){
    int* ans=NULL;
    int i=0,j=0,t=0;
    int cmp_count=0;
    if(output==NULL){
        ans=(int*)malloc(sizeof(int)*count);
    }
    else{
        ans=output;
    }
    arr_cpy(array,ans,count);
    for(i=0;i<count;i++){
        t=i;
        for(j=i+1;j<count;j++){
            if(cmp(ans[t],ans[j],mode)){
                t=j;
            }
            cmp_count++;
        }
        if(t!=i){
            exchange(&ans[i],&ans[t]);
        }
    }
    if(!output){
        print_array(ans,count);
        free(ans);
        ans=NULL;
    }
    return cmp_count;
}

int swift_sort(int* array,int count,int* output,int mode){
    int* ans=NULL;
    int cmp_count=0;
    if(output==NULL){
        ans=(int*)malloc(sizeof(int)*count);
    }
    else{
        ans=output;
    }
    arr_cpy(array,ans,count);
    cmp_count=swift_sort_core(ans,count,mode);
    if(!output){
        print_array(ans,count);
        free(ans);
        ans=NULL;
    }
    return cmp_count;

}

int swift_sort_core(int* array,int count,int mode){
    int cmp_count=0;
    int i=0,j=0;
    int t=0;
    if(count<=1){
        return 0;
    }
    t=0;
    i=0;j=count-1;
    while(i<j){
        while((cmp_count++ , cmp(array[j],array[t],mode) && i<j)){
            j--;
        }
        while((cmp_count++ , cmp(array[t],array[i],mode) && i<j)){
            i++;
        }
        exchange(&array[i],&array[j]);
    }
    if(i==j){
        exchange(&array[t],&array[i]);
    }
    return swift_sort_core(array,i,mode)+swift_sort_core(array+i+1,count-i-1,mode)+cmp_count;
}