#include "tree.cpp"
#include<iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    char exp[]="A(B(D(,G)),C(E,F))";
    tree empty_tree;
    tree present_tree(exp);

    cout<<empty_tree.is_empty()<<endl;
    cout<<present_tree.is_empty()<<endl;

    empty_tree.create_tree(exp);

    cout<<endl;
    empty_tree.find_node('A');
    cout<<endl;
    
    return 0;
}
