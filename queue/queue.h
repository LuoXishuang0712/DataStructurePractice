#define _QUEUE
#define _LENGTH 64

template <class T>
class queue{
public:
    queue();
    queue(int len);
    ~queue();
    void destory();
    int status();
    void push(T element);
    T pop();
    void print();
private:
    void allowcate();
    T* _data;
    int _length=0;
    int _head=0;
    int _tail=0;
};