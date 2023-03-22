#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

void findOdd(promise<int>&& OddSumPromise,int start,int end){
    int oddSum = 0;
    for(int i=start;i<=end;i++){
        if((i&1)==1)
            oddSum+=i;
    }
    OddSumPromise.set_value(oddSum);
}

int32_t main()
{
    FAST;
    int start = 0;
    int end = 1000000000;
    promise<int>OddSum;
    future<int>OddFuture = OddSum.get_future();
    cout<<"Thread Created"<<endl;
    std::thread t(findOdd,move(OddSum),start,end);
    cout<<"Waiting for results!!"<<endl;
    cout<<"The OddSum is "<<OddFuture.get()<<endl;
    t.join();
    return 0;
}