#include<iostream>
#include<string.h>
#include<vector>
#include<map>
#include<cassert>


using namespace std;

int BestLevel=0;
std::map<string,int> memo;

string getKey(vector<int> arr)
{
    string key =to_string(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        key=key+","+to_string(arr[i]);
    }
    return key;
}
void setKey(vector<int> arr, int value)
{
    string key =getKey(arr);
    memo[key] = value;
}

void printVector( vector<int> arr)
{
    for(int i=0; i< arr.size();i++)
    {
        std::cout << arr[i] << " ";
    }
}

int getSum(vector<int> arr)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int call=0;
int NMcall=0;
int checkSum(vector<int> arr, int num, int level)
{

    
    string key=getKey(arr);
    std::cout<<"\nAt Level " << level <<"  ->  ";
    printVector(arr);

    NMcall++;
    if(memo.count(key)>0)
    {      
        std::cout<<"MEMO FOUND";
        return memo[key];
    }

    if(level<BestLevel)
    {
        return BestLevel;
    }
    
    call++;
    int sum = getSum(arr);
    std::cout << "SUM : " << sum ;

    if(sum == num)
    {
        std::cout<<"\t  Found at Level " << level <<"\n";        
        std::cout<<"\n";
       if(BestLevel<level)
       {
           BestLevel=level;
           setKey(arr,level);
       }
            
    }
    if(sum > num)
    {        
        setKey(arr,BestLevel);
        return BestLevel;
    }
         
    
    for(int i=0; i<arr.size()-1; i++)
    {
        vector<int> _arr;
        for(int j=0; j<arr.size() && j<i ; j++)
        {
            _arr.push_back(arr[j]);
        }

        int rem = arr[i+1];
        int tn =10;
        while(rem>9)
        {
            rem = rem/10;
            tn=tn*10;
        }
        _arr.push_back(arr[i]*tn+rr[i+1]);

        for(int j=i+2;j<arr.size(); j++)
        {
            _arr.push_back(arr[j]);
        }       
        
        checkSum(_arr,num, level+1);          
        std::cout<<"\n";
    }
    
}

int minimum_pluses(string A){

    vector<int> arr;
    int num,i;
    int size = A.length();    
    for(i=0; i<size && A[i]!='=';i++){
       arr.push_back((A[i]-'0'));
    }
    
    string nums= A.substr(i+1);    
    num = std::stoi(A.substr(i+1));

    checkSum(arr,num,1);

    int pluses =  i-BestLevel;    
    return pluses;    
}


int main()
{
    string A;
    std:: cin >> A;
    int result;
    result = minimum_pluses(A);
    cout<< "\n" <<result;
    cout<< "\n Best Level " << BestLevel;
    cout<< "\n TOTAL CALLS : "<<NMcall;
    cout<< "\n TOTAL CALLS After MEMO : "<<call;
    return 0;
}