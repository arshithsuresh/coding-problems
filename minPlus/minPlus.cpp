#include<iostream>
#include<string.h>
#include<vector>
#include<regex>

using namespace std;

int bestSol = 5001;

int checkSum(long long num, long sum, int level)
{
    //std::cout<<"        INSIDE -> checkSum( "<<num <<","<<sum<<","<<1<<")\n";
    if(level >= bestSol)
        return 0;
    if(bestSol > 0 && bestSol < level)
        return bestSol;

    if(sum==0 && num ==0)
    {   
        std::cout<<"      -> FOUND AT LEVEL " << level << "\n";
        bestSol = level;
        return level;
    }
        
    if(sum<0 || (num < sum))
        return 0;

    int nP = 0;    
    long tp=1;
    
    while(num/tp>0 || nP<5)
    {  
        long long newNum = num/(10*tp);
        long rem = num%(10*tp);
        
        //std::cout<<"checkSum( "<<newNum <<","<<sum-rem<<","<<level+1<<")\n";        

        int SolLevel = checkSum(newNum,sum-rem,level+1);
        if( SolLevel > 0 )
        {           
           return SolLevel;
        }    

        tp*=10;
        nP++;   
    }   

    return 0; 
}

int minimum_pluses(string A){

    
    long long num=0;    
    int i;
    int sum=0;
    int size = A.length();  
    int noZ = 0; 

    for(i =0;i<size && A[i]=='0';i++);
    
    noZ=i;

    int tempZ = 0;
    std::cout<< "InputLegnth : "<<size<< "\n";

    for(; i<size && A[i]!='=';i++){
        
        if(A[i]!='0')
            tempZ=0; 

        if(tempZ >=4)
        {
            noZ++;
            continue;
        }     
        
        if(A[i] == '0')
        {
            //continue;
            tempZ++;
        }
            
        
        
        num*=10;
        num += A[i]-'0';
        //std::cout<< num <<"\n";
    }  

    
    string nums= A.substr(i+1);    
    sum = std::stoi(A.substr(i+1));
    std::cout<<noZ<<"  "< 
    std::cout<<"checkSum( "<<num <<","<<sum<<","<<1<<")\n";
    int Sol = checkSum(num,sum,1);

    if(bestSol >5000)
        return -1;
    else 
        return noZ+bestSol-2;
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