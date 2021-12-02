#include<iostream>
#include "sort.cpp"

int main(int argc, char const *argv[])
{
    using namespace std;
    int count=50;
    int* arr=reverse(get_random_num(count),count);
    int* out=(int*)malloc(sizeof(int)*count);
    int find=0,find_index=0;;
    int i=0;

    //排序部分
    cout<<"原数组"<<endl; //original array
    print_array(arr,count);
    cout<<endl;
    cout<<"直接插入排序"<<endl; //insert sort
    cout<<insert_sort(arr,count)<<endl;
    cout<<endl;
    cout<<"直接选择排序"<<endl; //select sort
    cout<<select_sort(arr,count)<<endl;
    cout<<endl;
    cout<<"快速排序"<<endl; //swift sort
    cout<<swift_sort(arr,count)<<endl;
    cout<<endl;

    //查找部分
    swift_sort(arr,count,out);
    cout<<"查找用数组"<<endl;
    print_array(out,count);
    cout<<endl;
    cout<<"请输入要查找的整数：";
    cin>>find;
    find_index=dichonomy_search(out,count,find);  //逆序查找，可将数组reverse并设mode=0
    if(find_index!=-1){
        cout<<"找到了"<<out[find_index]<<"，位于"<<find_index<<"。"<<endl;
    }
    else{
        cout<<"未找到该整数"<<endl;
    }
    
    return 0;
}
