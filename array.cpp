#include<iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"Enter 10 numbers-";
    for(int i = 0; i< 10; i++)
    {
        cin>>a[i];
    }
    
    cout<<endl;
    cout<<"Display 10 numbers-";
    for(int i = 0; i< 10; i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    for(int i = 0; i< 10; i++)
    {
        if(a[i] % 2 == 0)
        {
            cout<<a[i]<<" is even";
            cout<<endl;
        }
        else{
            cout<<a[i]<<" is odd";
            cout<<endl;
        }
    }
    return 0;
}
