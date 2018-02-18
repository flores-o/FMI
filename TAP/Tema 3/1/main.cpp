#include <iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct cub
{
    int  l,col;

};
bool comp(cub a,cub b)
{
    return a.l>=b.l ;
}
int main()
{
    int n,p;
    f>>n>>p;

    vector<cub> a;
    vector<int> nr(n+1);
    vector<int> h(n+1);
    vector<int> prev(n+1,-1);

    for(int i=0; i<n; i++)
    {
        a.push_back(cub());
        f>>a[i].l>>a[i].col;
    }

    sort(a.begin(),a.end(),comp);
    a.push_back(cub());
    a.back().l=0;
    a.back().col=p+1;

    h[0]=a[0].l;
    prev[0]=-1;

    int i=0;
    while(a[i].l==a[0].l && i<a.size())
    {
        nr[i]=1;
        i++;
    }
    for(int i=1; i<n+1; i++)
    {
        int max=0;

        for(int j=0; j<i; j++)
            if(a[j].l>a[i].l && a[j].col!=a[i].col)
                if (h[j]>max)
                {
                    max=h[j];
                    nr[i]=nr[j];
                    prev[i]=j;
                }

                else if(h[j]==max)
                    nr[i]+=nr[j];

        h[i]=max+a[i].l;
    }



    int max=0;
    for(int i=1; i<n; i++)
        if (h[i]>h[max]) max=i;


    g<<h[max]<<endl;

    stack<int> st;



    while(max!=-1)
    {
        st.push(max);
        max=prev[max];
    }

    while(st.size()>0)
    {
        g<<a[st.top()].l<<" "<<a[st.top()].col<<'\n';

        st.pop();
    }

    g<<nr[a.size()-1];


    return 0;
}
