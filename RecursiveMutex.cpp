#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

recursive_mutex m1;
int buffer = 0;

void recursion(char c,int loopFor){
    if(loopFor<=0)
        return;

    m1.lock();
    buffer++;
    cout<<"Thread ID : "<<c<<" "<<buffer<<endl;
    recursion(c,--loopFor);
    m1.unlock();
    cout<<"Unlocked by thread "<<c<<endl;
}

int32_t main()
{
    FAST; 
    // thread t1(recursion,'1',10);
    // thread t2(recursion,'2',10);
    // t1.join();
    // t2.join();

    for(int i=1;i<=5;i++){
        m1.lock();
        cout<<"locked "<<i<<endl;
    }
    for(int i=1;i<=5;i++){
        m1.unlock();
        cout<<"unlocked "<<i<<endl;
    }
    return 0;
}