#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <cassert>

using namespace std;
int minVal = -1;
std::map<std::string,int> memo;
void setValue(std::string key, int value)
{    
    memo[key] = value;
}

int getMin(int x, int y)
{
    if(x==-1 && y==-1)
        return -1;

    if(x==-1)
        return y;

    if(y==-1)
        return x;

    if(x < y)
        return x;

    return y;
}

int minimumWithdrawal(std::vector<int> ATM,int X, int i, int j)
{

    if(X<0)
        return -1;    
        
    if(X == 0)
    {        
        return i+(ATM.size()-j-1);
    }        
    
    if(i>j)
        return -1;
    
    std::string key = to_string(i)+","+to_string(j)+","+to_string(X);

    if(memo.count(key) > 0)
    {
        return memo[key];
    }

    //std::cout << "minimumWithdrawal(" << ","<< X - ATM[i]<< "," << i+1 << "," << j << ")\n";
    int  left = minimumWithdrawal(ATM, X - ATM[i], i+1,j);

    //std::cout << "minimumWithdrawal("<< ","<< X - ATM[j]<< "," << i << "," << j-1 << ")\n";
    int right = minimumWithdrawal(ATM, X - ATM[j], i,j-1);

    int ans = getMin(left,right);
    //std::cout<<"      Min Ans:  "<<ans;    
    setValue(key,ans);    

    return ans;



}
int main(){
    int N;
    cin>>N;
    std::vector<int> ATM(N);
    for(int j = 0;j < N;j++){
        cin>>ATM[j];
    }

    int X;
    cin>>X;
    int result;
    result = minimumWithdrawal(ATM,X,0,N-1);
    result = result==-1?-1:result;
    cout<<result;
    return 0;
}