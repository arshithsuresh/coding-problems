#include<iostream>


using namespace std;

int beautifulFunction(long n){    
    
    if(n<9)
    {
        return 9;
    }
    n++;
    while(n%10 == 0)
    {
        n=n/10;
    }

    return 1+beautifulFunction(n);

}
int main(){
    long N;
    cin>>N;
    int result;
    result = beautifulFunction(N);
    cout<<result;
    return 0;
}