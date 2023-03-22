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
timed_mutex m;

//Play with Values in try_lock_for
// void increment(int threadNum) {
//     if(m.try_lock_for(std::chrono::seconds(1))){
//         myAmount++;
//         this_thread::sleep_for(std::chrono::seconds(2));
//         cout<<"Thread "<<threadNum<<" entered"<<endl;
//         m.unlock();
//     }
//     else{
//         cout<<"Thread "<<threadNum<<" couldn't enter"<<endl;
//     }
// }

void increment(int threadNum) {
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now+std::chrono::seconds(1))){
        myAmount++;
        this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"Thread "<<threadNum<<" entered"<<endl;
        m.unlock();
    }
    else{
        cout<<"Thread "<<threadNum<<" couldn't enter"<<endl;
    }
}

int32_t main()
{
    FAST; 
    thread t1(increment,1);
    thread t2(increment,2);
    t1.join();
    t2.join();
    cout<<"The Amount is "<<myAmount<<endl;
    return 0;
}