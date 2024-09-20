// stream operator overloading in file;
/*
syntax :
public:
friend istream &operator >>(ostream &,class names&)
// for stream extraction operator
friend ostream &operator<<(ostream &,class name&)
//  for stream insertion operator 
*/
// example problem of stream operator overloading in file
// wap to overload stream operator to read and display that the time units hr,min,sec;

#include<iostream>

using namespace std;

class time
{
    int hr;
    int min;
    int sec;
    public:
    time()
    {
        hr=0.0;
        min=0.0;
        sec=0.0;
    }
    friend istream &operator >>(istream & is,time &t1);
    friend ostream &operator << (ostream &os,time &t1);
};
istream &operator >> (istream &is,time &t1)
{ 
    is >>t1.hr>>t1.min>>t1.sec;
    return is;
}
ostream &operator << (ostream &os,time &t1)
{
    // os<<t1.hr<<t1.min<<t1.sec;
    printf("%d:%d:%d", t1.hr, t1.min, t1.sec);
    return os;
}
int main()
{
    time t;
    cout<<"enter the time:";
    cin>>t;
    cout<<"the entered time is:";
    cout<<t;
    return 0;
}
