#include <iostream>
#include<cstring>
#include <fstream>
#include <stack>
#include<utility>
#include<algorithm>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int main()
{
    int n,m;
    f>>n>>m;
    int a[n][m],dp[n][m];

    memset(dp,0,n*m*sizeof(int));

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    f>>a[i][j];

    for(int i=n-1;i>=0;i--)
    for(int j=0;j<m;j++)
    dp[i][j]=max(((j-1 >= 0) ? dp[i][j-1] : 0) , ((i+1 < n) ? dp[i+1][j] : 0)) + a[i][j];



    g<<dp[0][m-1]<<'\n';

    int i=0,j=m-1;

    stack<pair<int,int>> st;

    while(1)
    {
        st.push(make_pair(i+1,j+1));
        if(i== n-1 && j==0) break;
         else
       {
         if(i==n-1) j=j-1;
            else
            if(j == 0) i=i+1;
            else
            {
                if(dp[i][j-1] > dp[i+1][j])
                    j=j-1;
                else
                    i=i+1;
            }

    }


    }

     while(!st.empty())
     {
         g<<st.top().first<<" "<<st.top().second<<'\n';
         st.pop();
     }



    return 0;
}
