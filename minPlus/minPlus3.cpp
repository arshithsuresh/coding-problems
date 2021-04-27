#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

vector<int> bestSol;

int checkSum(string num, int sum, int level)
{
    if(bestSol.size() > 0 && bestSol[0] <= level)
        return bestSol[0];

    if(sum==0 && num.length() == 0)
    {   
        //std::cout<<"    ->FOUND at level " << level <<"\n";
        bestSol.push_back(level);
        return level;
    }
        
    if(sum<0 || num =="")
        return 0;

    int nP = 1; 
    int length = num.length();

    while(nP<5)
    {
        int toLength = length - nP;
        if(toLength < 0)
        {
            return 0;
        }
            

        string newNumStr = num.substr(0,toLength);
        string remStr = num.substr(toLength,length);

        int rem = std::stoi(remStr);

        std::cout<<"\n       checkSum( "<<newNumStr <<","<<sum-rem<<","<<level+1<<")\n";
        
        int sol = checkSum(newNumStr,(sum-rem),level+1);        
        if(sol>0)
        {
            return sol;
        }
        nP++;
    }  

    return 0;  
}

int minimum_pluses(string A){

    string num;    
    int i;
    int sum=0;
    int size = A.length(); 
    long long trZ = 0;
    for(i=0;A[i]=='0';i++);
    trZ=i;   
    
    for(i=trZ; i<size && A[i]!='=';i++){        
        //std::cout<< num <<"\n";
    }  

    string nums= A.substr(i+1);    
    sum = std::stoi(A.substr(i+1));
    num = A.substr(trZ,i-trZ);
    std::cout<<"checkSum( "<<num <<","<<sum<<","<<1<<")\n";
    checkSum(num,sum,0);
    int Sol = bestSol.size()>0?bestSol[0]:0;

    return (Sol==0)?-1:trZ+Sol-1;
    
}


int main()
{
    string A;
    std:: cin >> A;
    int result;
    result = minimum_pluses(A);
    cout <<result;
    return 0;
}