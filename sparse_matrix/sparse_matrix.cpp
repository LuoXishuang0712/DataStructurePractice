#include <iostream>
#include <cstdlib>
#define Elem_Size 64  //最多元素个数
#define Max_Size 256  //矩阵单边最大大小
#include <random>
#include <ctime>

typedef int ElemType;
struct node{
    int row=0,col=0;
    ElemType data;
};
struct matrix{
    int size_r=0,size_c=0,length=0;
    node *Elem;
    matrix(){  //结构体初始化
        Elem=(node*)malloc(sizeof(node)*Elem_Size);
    }
};

void print_matrix(matrix mat);
void modify_node(node* elm,int row,int col,ElemType data);
void gene_data(matrix &mat,int size_r,int size_c);
void transpose(matrix &mat);
 
int main(){
    srand(time(NULL));
    matrix mat1;
    gene_data(mat1,20,10);
    print_matrix(mat1);
    std::cout<<"------------------"<<std::endl;
    transpose(mat1);
    print_matrix(mat1);
}

void transpose(matrix &mat){
    int num[Max_Size]={0},k[Max_Size]={0};
    node* p=mat.Elem;
    node* target=(node*)malloc(sizeof(node)*Elem_Size);
    int i=0,t=0;
    for(i=0;i<mat.length;i++){
        num[p->col]++;
        p++;
    }
    for(i=1;i<mat.size_c;i++){
        k[i]=k[i-1]+num[i-1];
    }
    p=mat.Elem;
    for(i=0;i<mat.length;i++){
        modify_node(&target[k[p->col]],p->col,p->row,p->data);
        k[p->col]++;
        p++;
    }
    p=mat.Elem;
    mat.Elem=target;
    free(p);
    p=NULL;
    t=mat.size_c;
    mat.size_c=mat.size_r;
    mat.size_r=t;
}

void gene_data(matrix &mat,int size_r,int size_c){
    int i=0,j=0,count=0,add=0;
    int max_rand=(size_r+size_c)/2;
    node* p=mat.Elem;
    mat.size_r=size_r;
    mat.size_c=size_c;
    while(j<size_r){
    	do{
			add=rand()%max_rand;
		}while(!add);
        i+=add;
        j+=i/size_c;
        i%=size_c;
        if(j<size_r){
            modify_node(p,j,i,rand()%100);
            p++;
            count++;
        }
    }
    mat.length=count;
}

void modify_node(node* elm,int row,int col,ElemType data){
    elm->row=row;
    elm->col=col;
    elm->data=data;
}

void print_matrix(matrix mat){
    using namespace std;
    int i=0,j=0;
    node* p=mat.Elem;
    for(i=0;i<mat.size_r;i++){
        for(j=0;j<mat.size_c;j++){
            if(p->row==i && p->col==j){
                printf("%3d ",p->data);
                p++;
            }
            else{
                printf("%3d ",0);
            }
        }
        cout<<endl;
    }
}