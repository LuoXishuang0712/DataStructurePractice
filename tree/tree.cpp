//二叉树默认定义为字符型char
#include "tree.h"
#include <cstdlib>
#include <iostream>
#define _STACK_NO_PRINT  //关闭栈定义中的打印，避免类型检查报错
#include "../stack/stack.cpp"  //记得修改路径

tree::tree(){
    tree_head=NULL;
}

tree::tree(char* exp){
    tree_head=NULL;
    create_tree(exp);  //normally no error
}

tree::~tree(){
    if(tree_head){
        destory();
    }
}

int tree::create_tree(char* exp){
    stack<node*> nodestack;
    node* present=NULL;
    char* p=exp;
    int k;  //k表示当前处理的节点状态
    if(!is_empty()){
        return -1; //not an empty tree
    }
    while(*p){
        switch (*p){
            case '(':
                nodestack.push(present);
                k=1;
                break;
            case ')':
                nodestack.pop();
                k=0;  //will not be accessed
                break;
            case ',':
                k=2;
                break;
            default:{
                present=(node*)malloc(sizeof(node));
                present->data=*p;
                present->Rchild=NULL;present->Lchild=NULL;
                if(!tree_head){  //如果是头节点
                    tree_head=present;
                }
                else{  //如果不是头节点（有父节点）
                    switch (k){
                        case 1:
                            nodestack.top()->Lchild=present;
                            break;
                        case 2:
                            nodestack.top()->Rchild=present;
                            break;
                        default:
                            return -2;
                    }
                }
            }
        }
        p++;
    }
    return 0;
}

void tree::print_tree(){
    print_tree_node(tree_head);
}

int tree::is_empty(){
    return tree_head?false:true;
}

int tree::count_leaf(){
    return get_leaf_count(tree_head);
}

int tree::get_height(){
    return get_node_height(tree_head);
}

int tree::get_node_height(node* node_){
    if(node_){
        if(node_->Lchild || node_->Rchild){  //枝节点
            return get_node_height(node_->Lchild)>get_node_height(node_->Rchild)?
                    get_node_height(node_->Lchild)+1:get_node_height(node_->Rchild)+1;
        }
        else{  //叶节点
            return 1;
        }
    }
    else{
        return 0;
    }
}

void tree::find_node(ElemType ipt){
    using namespace std;
    node* ret=find_node_data(tree_head,ipt);
    if(ret){
        printf("查找的节点%c位于0x%016llx  ",ret->data,(llui)ret);
        if(ret->Lchild){
            printf("其左子节点为%c(0x%016llx)  ",ret->Lchild->data,(llui)ret->Lchild);
        }
        if(ret->Rchild){
            printf("其右子节点为%c(0x%016llx)  ",ret->Rchild->data,(llui)ret->Rchild);
        }
    }
    else{
        printf("未找到包含%c的节点  ",ipt);
    }
    cout<<endl;
}

//private function
//the node type is private, to prevent accident access

tree::node* tree::find_node_data(node* node_,ElemType data_){
    if(node_){
        if(node_->data==data_){
            return node_;
        }
        return (node*)((llui)find_node_data(node_->Lchild,data_)+(llui)find_node_data(node_->Rchild,data_)+0);
    }
    return 0;
}

void tree::print_inorder(){
    inorder_node(tree_head);
}

void tree::inorder_node(node* node_){
    using namespace std;
    if(node_){
        inorder_node(node_->Lchild);
        cout<<node_->data;
        inorder_node(node_->Rchild);
    }
}

int tree::get_leaf_count(node* node_){
    if(node_->Lchild || node_->Rchild){  //枝节点
        return (node_->Lchild?get_leaf_count(node_->Lchild):0)+
                (node_->Rchild?get_leaf_count(node_->Rchild):0);
    }
    else{  //叶节点
        return 1;
    }
}

void tree::print_tree_node(node* node_){
    using namespace std;
    cout<<node_->data;
    if(node_->Lchild || node_->Rchild){
        cout<<'(';
        if(node_->Lchild){
            print_tree_node(node_->Lchild);
        }
        cout<<',';
        if(node_->Rchild){
            print_tree_node(node_->Rchild);
        }
        cout<<')';
    }
}

void tree::destory(){
    destory_node(tree_head);
    tree_head=NULL;
}

void tree::destory_node(node* node_){
    if(node_->Lchild){
        destory_node(node_->Lchild);
    }
    if(node_->Rchild){
        destory_node(node_->Rchild);
    }
    free(node_);
}