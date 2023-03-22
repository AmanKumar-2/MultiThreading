#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

mutex m1;
mutex m2;

void func1() {
    m1.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m2.lock();
    cout<<"Critical Section of thread 1"<<endl;
    m1.unlock();
    m2.unlock();
}

void func2() {
    m2.lock();
    this_thread::sleep_for(chrono::seconds(1));
    m1.lock();
    cout<<"Critical Section of thread 2"<<endl;
    m1.unlock();
    m2.unlock();
}

int32_t main()
{
    FAST; 
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
    return 0;
}