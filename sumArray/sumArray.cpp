#include<iostream>
#include<map>
#include<cassert>

using namespace std;

std::map<int,int> memo;

//Brute Forcing
// int canSum(int rem, int arr[],int size)
// {
//     if(rem == 0)
//         return 1;
//     if(rem < 0)
//         return 0;
        
//     for(int i=0; i<size;i++)
//     {
//         int _rem = rem - arr[i];
//         if(canSum(_rem,arr,size) == 1)
//             return 1;
//     }

//     return 0;    
// }

//Using memoization
int canSum(int rem, int arr[],int size)
{
    if(rem == 0)
        return 1;
    if(rem < 0)
        return 0;

    if(memo.count(rem))
    {
        return memo[rem];
    }    
        
    for(int i=0; i<size;i++)
    {
        int _rem = rem - arr[i];
        if(canSum(_rem,arr,size) == 1)
        {
            memo[rem]=1;
            return 1;
        }
            
    }
    
    memo[rem]=0;
    return 0;    
}

void printArray(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main(){
    int num,n;
    
    std::cin >> num;
    std::cin >> n;

    int *arr = new int[n];

    std::cout << num << " " << n << "\n";
    for(int i=0;i<n;i++)
    {
        std:cin >> arr[i];
    }

    std::cout << canSum(num,arr,n);    
    return 0;
}