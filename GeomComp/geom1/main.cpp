#include <iostream>

using namespace std;
struct punct
{
    double x,y,z;
}a1,a2,a3;
int main()
{
    cin>>a1.x>>a1.y>>a1.z;
    cin>>a2.x>>a2.y>>a2.z;
    cin>>a3.x>>a3.y>>a3.z;

    if(a1.x==a2.x && a1.y==a2.y && a1.z==a2.z)
    {
        cout<<"Punctele sunt coliniare"<<endl;
        cout<<"a1=1*a2+0*a3";
        return 0;
    }
    double a;

    if((a2.x-a1.x)!=0)
        a=(a3.x-a1.x)/(a2.x-a1.x);
    else  if((a2.y-a1.y)!=0)
        a=(a3.y-a1.y)/(a2.y-a1.y);
        else
            a=(a3.z-a1.z)/(a2.z-a1.z);

    if((a3.x-a1.x)==a*(a2.x-a1.x) && (a3.y-a1.y)==a*(a2.y-a1.y) && (a3.z-a1.z)==a*(a2.z-a1.z))
    {
        cout<<"Punctele sunt coliniare"<<endl;
        cout<<"a3="<<1-a<<"*a1+"<<a<<"*a2";

    }
    else cout<<"punctele nu sunt coliniare";

    return 0;
}
