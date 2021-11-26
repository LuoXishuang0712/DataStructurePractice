#define _TREE
#ifndef NULL
#define NULL 0b0
#endif//NULL
typedef char ElemType;
typedef long long unsigned int llui;

class tree{
public:
    tree();  //empty tree  //
    tree(char* exp);  //pre create tree  //
    ~tree();  //
    int create_tree(char* exp);  //for empty tree  //
    void print_tree();  //
    int is_empty();  //
    int count_leaf();
    int get_height();
    int count_nodes();
    void print_inorder();
    void find_node(ElemType ipt);
private:
    struct node{
        ElemType data;
        node* Lchild;
        node* Rchild;
        node(){
            Lchild=NULL;
            Rchild=NULL;
        }
    };
    node* find_node_data(node* node_,ElemType data_);
    void inorder_node(node* node_);
    int get_leaf_count(node* node_);
    int get_node_height(node* node_);
    void destory();  //
    void destory_node(node* node_);  //
    void print_tree_node(node* node_);  //
    node* tree_head;
};