#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<mutex>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

int X = 0;
int Y = 0;
mutex m1,m2;

void doSomeWorkForSeconds(int sec){
    this_thread::sleep_for(std::chrono::seconds(sec));
}

void incrementXY(int& XorY, mutex &m, const char* desc){
    for(int i=0;i<5;i++){
        m.lock();
            ++XorY;
        cout<<desc<<XorY<<endl;
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY() {
    //How many times I want to consume
    int useCount = 5;
    int XplusY = 0;
    while(true){
        int lockResult = try_lock(m1,m2);
        if(lockResult==-1){
            if(X!=0 && Y!=0){
                --useCount;
                XplusY += X+Y;
                X = 0;
                Y = 0;
                cout<<"XplusY "<<XplusY<<endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount==0)
                break;
        }
    }
}

int32_t main()
{
    FAST; 
    thread t1(incrementXY,ref(X),ref(m1),"X: ");
    thread t2(incrementXY,ref(Y),ref(m2),"Y: ");
    thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}