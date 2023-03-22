#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

void findOdd(int start,int end){
    int oddSum = 0;
    for(int i=start;i<=end;i++){
        if((i&1)==1)
            oddSum+=i;
    }
}

int32_t main()
{
    FAST;
    int start = 0;
    int end = 1000000000;
    std::thread t(findOdd,start,end);
    t.join();
    return 0;
}