#include <iostream>

#include<vector>
#include<algorithm>

using namespace std;
struct text
{
    double lung,idx;
};
bool cmp(text a ,text b)
{
  return a.lung<b.lung;
}
int main()
{
    int n,p;
    cin>>n>>p;
    vector<text> arr;
    for(int i=0;i<n;i++)
    {
        text x;
        arr.push_back(x);
        cin>>arr[i].lung;
        arr[i].idx=i+1;


    }

    sort(arr.begin(),arr.end(),cmp);



    for(int i=0;i<arr.size();i++)
    {
        cout<<"elementul "<<arr[i].idx<<" este pe linia"<<i%p+1<<endl;


    }

    return 0;
}

