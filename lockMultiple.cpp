#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

mutex m1,m2;

void taskA() {
    while(1){
        lock(m1,m2);
        cout<<"Task A"<<endl;
        m1.unlock();
        m2.unlock();
    }
}

void taskB() {
    while(1){
        lock(m2,m1);
        cout<<"Task "<<endl;
        m1.unlock();
        m2.unlock();
    }
}

int32_t main()
{
    FAST; 
    thread t1(taskA);
    thread t2(taskB);
    t1.join();
    t2.join();
    return 0;
}