#define _STACK

template <class T>
class stack{
public:
    struct stack_node{
        T* data;
        stack_node* pre;
    };
    stack();
    ~stack();
    void push(T const& elem);
    T pop();
    int count();
    int isempty();
    T top();
    void clean_stack();
    void print_stack();
private:
    stack_node* _top;
    int _count;
    void free_node(stack_node* node);
};