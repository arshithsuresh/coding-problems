#include<iostream>
#include<string.h>
#include<vector>
#include<regex>


using namespace std;

int main()
{
    string A;
    std:: cin >> A;

    std::regex in("^0*([[:d:]]*=[[:d:]]*)");

    std::cout<< A <<"\n";
    std::cout<< std::regex_replace(A,in, "$1$2") <<"\n";
}
