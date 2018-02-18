#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

ifstream f("date.in");
ofstream g("date.out");

struct Job
{
    int p, d, t, id;
};
bool comp(Job a, Job b)
{
    return a.d<=b.d;
}

int main()
{
    int n,d=0;
    f>>n;
    vector<Job> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(Job());
        f>>v.back().p>>v.back().d>>v.back().t;
        if(v.back().d > d) d = v.back().d;
        v.back().id = i+1;

    }

    sort(v.begin(),v.end(),comp);
    int A[n+1][d+1];

    for(int t=0;t<=d;t++)
    A[0][t] = 0;



   for(int i=1;i<=n;i++)
   for(int t=0;t<=d;t++)
   {
       int _t = min(t, v[i].d) - v[i].t;
       if(_t < 0)
          A[i][t] = A[i-1][t];
          else
          A[i][t] = max( A[i-1][t], A[i-1][_t] + v[i].p );
   }
  g<<A[n][d]<<'\n';

  stack <int> res;

  int i = n, t = d;
  while(1)
  {
      if(i==0) break;

      if(A[i][t] != A[i-1][t])
      {
          res.push( v[i].id );
          int _t = min(t, v[i].d) - v[i].t;
      }
      i=i-1;
  }

  while(!res.empty())
  {
      g<<res.top()<<" ";
      res.pop();
  }

  return 0;

}
