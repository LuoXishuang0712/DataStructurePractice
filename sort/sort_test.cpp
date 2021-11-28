#include<iostream>
#include "sort.cpp"

int main(int argc, char const *argv[])
{
    using namespace std;
    int count=50;
    int* arr=reverse(get_sequential_num(count,80,10),count);
    int i=0;
    cout<<"原数组"<<endl; //original array
    print_array(arr,count);
    cout<<endl;
    cout<<"直接插入排序"<<endl; //insert sort
    cout<<insert_sort(arr,count)<<endl;
    cout<<endl;
    cout<<"直接选择排序"<<endl; //insert sort
    cout<<select_sort(arr,count)<<endl;
    cout<<endl;
    cout<<"快速排序"<<endl; //insert sort
    cout<<swift_sort(arr,count)<<endl;
    cout<<endl;
    
    return 0;
}
