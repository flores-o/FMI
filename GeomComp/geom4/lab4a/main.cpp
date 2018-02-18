#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define VAL 57.2957795
using namespace std;

struct punct
{
    int x,y;
}m;
bool cmp(punct a, punct b)
{
    if(a.x==b.x) return a.y<b.y;
            else return a.x<=b.x;
}
double prod_vect(punct a, punct b)
{
   return a.x*b.x + a.y*b.y;
}
double dist(punct a , punct b)
{
    return sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}





int main()
{
    vector<punct> a;
    for(int i=0;i<3;i++)
    {
        a.push_back(punct());
        cout<<"coordonatele punctului "<<i<<endl;
        cin>>a[i].x>>a[i].y;

    }

   // sort(a.begin(),a.end(),cmp);

    cout<<"coordonatele celui de-al patrulea punct"<<endl;
    //punct m;
    cin>>m.x>>m.y;

    for (int i=1;i<3;i++)
    {
        if(dist(m,a[i])>dist(m,a[0]))
          swap(a[i],a[0]);
    }
    for(int i=0;i<3;i++)
    cout<<a[i].x<<a[i].y<<endl;

    punct vect_a0_a1 , vect_a0_a2;
    vect_a0_a1.x=a[1].x-a[0].x;
    vect_a0_a1.y=a[1].y-a[0].y;
    vect_a0_a2.x=a[2].x-a[0].x;
    vect_a0_a2.y=a[2].y-a[0].y;


    double cos_a1= prod_vect(vect_a0_a1,vect_a0_a2)/(dist(a[0],a[1])*dist(a[0],a[2]));

    double a1=acos(cos_a1);
    //cout<<"a1 "<<a1*VAL<<endl;


    punct vect_m_a1 , vect_m_a2;
    vect_m_a1.x=a[1].x-m.x;
    vect_m_a1.y=a[1].y-m.y;
    vect_m_a2.x=a[2].x-m.x;
    vect_m_a2.y=a[2].y-m.y;


    double cos_m= prod_vect(vect_m_a1,vect_m_a2)/(dist(m,a[1])*dist(m,a[2]));

    double _m=acos(cos_m);
    //cout<<"m"<<_m*VAL<<endl;

    //cout<<(a1+_m)*VAL<<endl;
    if(abs((a1+_m)*VAL-180)<0.01)
    cout<<"punctul m se afla pe cerc"<<endl;
      else if((a1+_m)*VAL>180)
      cout<<"punctul m se afla in interiorul cercului"<<endl;
       else
        cout<<"punctul se afla in ext cercului"<<endl;

    a.push_back(m);
    sort(a.begin(),a.end(),cmp);


    /*cout<<dist(a[0],a[1])+dist(a[2],a[3])<<endl;
    cout<<dist(a[0],a[3])+dist(a[1],a[2])<<endl;
    */
    if(dist(a[0],a[1])+dist(a[2],a[3])==dist(a[0],a[2])+dist(a[1],a[3]))
       cout<<"patrulaterul este circumscriptibil";
       else cout<<"patrulaterul nu este circumsriptibil";

    return 0;
}
