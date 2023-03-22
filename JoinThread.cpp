#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

void run(int count){
    while(count-- > 0){
        cout<<"Value of Count is "<<count<<endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}

int32_t main()
{
    FAST;
    thread t1(run,10);
    cout<<"main()"<<endl;
    // t1.join();
    // if(t1.joinable())
    //     t1.join();
    t1.detach();
    if(t1.joinable())
        t1.detach();
    cout<<"main() after"<<endl;
    return 0;
}