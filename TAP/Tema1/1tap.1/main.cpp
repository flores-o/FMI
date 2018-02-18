#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");
struct cub
{
    int l,cul,ind;
};
bool comp (cub a ,cub b)
{
    return a.l>b.l;
}
int main()
{
    int n,p;
    vector<cub> a;
    f>>n>>p;
    for(int i=0;i<n;i++)
        {
            cub x;
            a.push_back(x);
            f>>a[i].l>>a[i].cul;
            a[i].ind=i+1;
        }

   sort(a.begin(),a.end(),comp);

    vector<cub> res;
    res.push_back(a[0]);
    int h=a[0].l;

    for(int i=1;i<n;i++)
    {
        if(a[i].cul != res.back().cul)
        {
            res.push_back(a[i]);
            h +=a[i].l;
        }

    }


    g<<h<<endl;

    for(int i=0;i<res.size();i++)
        g<<res[i].ind<<" ";

    return 0;

}
