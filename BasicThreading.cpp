#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#define ll long long
#define int unsigned long long
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

int oddSum = 0;
int evenSum = 0;

void findEven(int start,int end){
    for(int i=start;i<=end;i++){
        if((i&1)==0)
            evenSum+=i;
    }
}

void findOdd(int start,int end){
    for(int i=start;i<=end;i++){
        if((i&1)==1)
            oddSum+=i;
    }
}


class Base {
    public:
        void operator()(int x){
            while(x!=0){
                cout<<x<<endl;
                x--;
            }
        }
};


class BaseNonStatic {
    public:
        void run(int x){
            while(x!=0){
                cout<<x<<endl;
                x--;
            }
        }
};


class BaseStatic {
    public:
        static void run(int x){
            while(x!=0){
                cout<<x<<endl;
                x--;
            }
        }
};

int32_t main()
{
    FAST;
    int start = 0;
    int end = 1000000000;

    auto startTime = high_resolution_clock::now();

    // std::thread t1(findEven,start,end);
    // std::thread t2(findOdd,start,end);
    // std::thread t3(findEven,start,end);
    // std::thread t4(findOdd,start,end);
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();

    // findOdd(start,end);
    // findEven(start,end);
    // findOdd(start,end);
    // findEven(start,end);


    // auto stopTime = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stopTime-startTime);
    // cout<<"The Odd Sum is "<<oddSum<<endl;
    // cout<<"The Even Sum is "<<evenSum<<endl;
    // cout<<"The Duration int seconds is "<<duration.count()/1000000<<endl;
    
    // auto fun = [](int x){
    //     while(x!=0){
    //         cout<<x<<endl;
    //         x--;
    //     }
    // };
    // std::thread t(fun,10);
    // t.join();

    // std::thread t(Base(),10);
    // t.join();
    


    // BaseNonStatic b1;
    // std::thread t(&BaseNonStatic::run,&b1,10);
    // t.join();


    std::thread t(&BaseStatic::run,10);
    t.join();
    return 0;
}