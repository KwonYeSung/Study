#include <iostream>
#include "my_stack"
#include "my_queue"
using namespace std;

int main(void)
{
    my_stack<int> s;
    my_queue<int> q;
    for(int i = 1; i <= 9; i++){
        s.push(i * 10);
        q.enqueue(i * 10);
    }
    std::cout << "Stack: ";
    for(int i = 1; i <= 9; i++)
        std::cout << s.pop() << " ";
    std::cout << std::endl;

    std::cout << "Queue: ";
    for(int i = 1; i <= 9; i++)
        std::cout << q.dequeue() << " ";
    std::cout << std::endl;

    return 0;
}
