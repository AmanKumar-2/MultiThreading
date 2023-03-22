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
int buffer = 0;

void task(const char* threadNum, int loopFor){
    // m1.lock();
    lock_guard<mutex>lock(m1);
    for(int i=1;i<=loopFor;i++){
        buffer++;
        cout<<"ThreadNum : "<<threadNum<<"  "<<buffer<<endl;
    }
    // m1.unlock();
}

int32_t main()
{
    FAST; 
    thread t1(task,"T0",10);
    thread t2(task,"T1",10);
    t1.join();
    t2.join();
    return 0;
}