
#include<bits/stdc++.h>
//#include<vector>
#include<fstream>
#include<iostream>
using namespace std;


ifstream f("date.in");
ofstream g("date.out");

struct Job
{
    int  idx;
    int deadLine, profit;
};
struct DisjointSet
{
    int *parent;

    DisjointSet(int n)
    {
        parent = new int[n+1];

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }


    int find(int s)
    {

        if (s == parent[s])
            return s;
        return parent[s] = find(parent[s]);
    }


    void merge(int u, int v)
    {

        parent[v] = u;
    }
};


bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}

int findMaxDeadline(vector<Job>arr)
{
    int n=arr.size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i].deadLine);
    return ans;
}

void printJobScheduling(vector<Job> arr)
{
    int sum=0;
    vector<int> res;
    int n=arr.size();

    sort(arr.begin(), arr.end(), cmp);


    int maxDeadline = findMaxDeadline(arr);
    DisjointSet ds(maxDeadline);


    for (int i = 0; i < n; i++)
    {

        int availableSlot = ds.find(arr[i].deadLine);


        if (availableSlot > 0)
        {

            ds.merge(ds.find(availableSlot - 1),
                             availableSlot);
            sum+=arr[i].profit;
           // cout << arr[i].id << " ";
            res.push_back(arr[i].idx);
        }
    }
    g<<sum<<'\n';
    for(int i=0;i<res.size();i++)
        g<<res[i]<<" ";
}

int main()
{
    int n;
    vector<Job>arr;

    f>>n;
    for(int i=0;i<n;i++)
    {
        Job x;
        arr.push_back(x);
        f>>arr[i].profit>>arr[i].deadLine;
        arr[i].idx=i+1;
    }

    printJobScheduling(arr);
    return 0;

}

