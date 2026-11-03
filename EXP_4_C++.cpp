#include <chrono>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>

template<class T> class MyStack {
    std::vector<T> data;
public:
    void push(const T& value) { 
        data.push_back(value); }
    void pop() { 
        if(data.empty()) 
            throw std::out_of_range("pop from empty stack"); 
        data.pop_back(); }
};
template<class T> class MyQueue {
    std::vector<T> data; 
    std::size_t front=0;
public:
    void enqueue(const T& value) {
         data.push_back(value); }
    void dequeue() { 
        if(front==data.size()) 
            throw std::out_of_range("dequeue from empty queue"); 
        ++front; }
};
template<class F> long long measureMicroseconds(F operation) {
    const auto start=std::chrono::high_resolution_clock::now(); 
    operation();
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()-start).count();
}
int main() {
    constexpr int n=10000;
    auto customStack=measureMicroseconds([]{ 
        MyStack<int> s; 
        for(int i=0;i<n;++i)s.push(i); 
            for(int i=0;i<n;++i)s.pop(); });
    auto stlStack=measureMicroseconds([]{ 
        std::stack<int> s; 
        for(int i=0;i<n;++i)s.push(i); 
            for(int i=0;i<n;++i)s.pop(); });
    auto customQueue=measureMicroseconds([]{ 
        MyQueue<int> q; 
        for(int i=0;i<n;++i)q.enqueue(i); 
            for(int i=0;i<n;++i)q.dequeue(); });
    auto stlQueue=measureMicroseconds([]{ 
        std::queue<int> q; 
        for(int i=0;i<n;++i)q.push(i); 
            for(int i=0;i<n;++i)q.pop(); });
    std::cout << "Custom stack: " << customStack << " us\nSTL stack: " << stlStack
              << " us\nCustom queue: " << customQueue << " us\nSTL queue: " << stlQueue << " us\n";
}
