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
int balance = 0;

void addMoney(int val){
    m1.lock();
    balance += val;
    m1.unlock();
}

int32_t main()
{
    FAST; 
    thread t1(addMoney,100);
    thread t2(addMoney,200);
    t1.join();
    t2.join();
    cout<<"The Final Balance is "<<balance<<endl;
    return 0;
}