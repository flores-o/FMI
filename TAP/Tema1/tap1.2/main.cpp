#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct text
{
    double lung,frecv,idx;
};
bool cmp(text a ,text b)
{
    double r1= a.lung/a.frecv;
    double r2= b.lung/b.frecv;

    return r1<r2;
}
int main()
{
    int n;
    f>>n;
    vector<text> arr;
    for(int i=0;i<n;i++)
    {
        text x;
        arr.push_back(x);
        f>>arr[i].lung>>arr[i].frecv;
        arr[i].idx=i+1;


    }

    sort(arr.begin(),arr.end(),cmp);

    for(int i=0;i<arr.size();i++)
        g<<arr[i].idx<<" ";
    return 0;
}
