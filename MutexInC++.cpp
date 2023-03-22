#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

int myAmount = 0;
std::mutex m;

void addMoney() {
    m.lock();
    for(int i=0;i<100000;i++)
        ++myAmount;
    m.unlock();
}

int32_t main()
{
    FAST; 
    thread t1(addMoney);
    thread t2(addMoney);

    t1.join();
    t2.join();

    cout<<"The Amount is "<<myAmount<<endl;
    return 0;
}