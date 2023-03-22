#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

condition_variable cv;
mutex m;
int balance = 0;

void addMoney(int money){
    lock_guard<mutex>lock(m);
    balance += money;
    cout<<"Current Balance is "<<balance<<endl;
    cv.notify_one();
}

void withdrawMoney(int money){
    unique_lock<mutex>uniqueLock(m);
    cv.wait(uniqueLock,[]{
        return (balance!=0)? true:false;
    });
    if(balance>=money){
        balance -= money;
        cout<<"Amount Deducted: "<<money<<endl;
    }
    else{
        cout<<"Current Balance less than Amount required to deduct"<<endl;
    }
    cout<<"Current Balance is "<<balance<<endl;
}


int32_t main()
{
    FAST; 
    thread t1(withdrawMoney,500);
    thread t2(addMoney,500);
    t1.join();
    t2.join();
    return 0;
}