#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int main()
{

    int n;
    string s,word;
    vector<string> v;

    f>>n;

    v.push_back("0");
    v.push_back("1");

    for(int i=0; i<n; i++)
    {
        f>>s;
        v.push_back(s);

    }

    f>>word;

    int l[word.size()+1];
    vector <string> res;

    l[0] = 0;
    for(int i=1; i<=word.size(); i++)
    {
        int min = INT_MAX;
        string M;
        for(int j=0; j<v.size(); j++)
            if(v[j].size()<=i)
            {
                string substr = word.substr(i-v[j].size(),v[j].size());

                if(substr.compare(v[j]) == 0)
                    if(l[i - v[j].size() ] < min)
                    {
                        min = l[i - v[j].size() ];
                        M = v[j];

                    }
            }

        res.push_back(M);

        l[i] = min +1;
    }

    int val = word.size();
    stack<string> st;
    while(val -1 >= 0)
    {
        st.push(res[val-1]);
        val = val - res[val-1].size();
    }

    while(!st.empty())
    {
        g<<" + "<<st.top();
        st.pop();
    }



    return 0;
}
