#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

int counter = 0;
std::mutex m;

void increaseTheCounter100000() {
    for(int i=0;i<100000;i++){
        // if(m.try_lock()){
        //     ++counter;
        //     m.unlock();
        // }
        m.lock();
        ++counter;
        m.unlock();
    }
}

int32_t main()
{
    FAST; 
    thread t1(increaseTheCounter100000);
    thread t2(increaseTheCounter100000);

    t1.join();
    t2.join();
    cout<<"The Counter Value is  "<<counter<<endl;
    return 0;
}