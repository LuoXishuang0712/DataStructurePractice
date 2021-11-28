#ifndef NULL
#define NULL 0b0
#endif//NULL

int* get_random_num(int count,int right=100,int left=0);
int* get_sequential_num(int count,int right=100,int left=0);
void print_array(int* array,int count);
int* reverse(int* arr,int count);

int insert_sort(int* array,int count,int* output=NULL,int mode=1);  //return compare count
int select_sort(int* array,int count,int* output=NULL,int mode=1);
int swift_sort(int* array,int count,int* output=NULL,int mode=1);
int swift_sort_core(int* array,int count,int mode);
int cmp(int a,int b,int mode);
int exchange(int* a,int* b);
void arr_cpy(int* source,int* target,int count);