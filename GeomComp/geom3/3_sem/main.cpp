#include<iostream>
#include<fstream>
#include<climits>
#include<cstdlib>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r)
{
	int x = arr[r];
	int i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}

// Picks a random pivot element between l and r and partitions
// arr[l..r] arount the randomly picked element using partition()
int randomPartition(int arr[], int l, int r)
{
	int n = r-l+1;
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	return partition(arr, l, r);
}

int weighted_median(int a[],float w[],int l, int r)
{
    int pos = partition(a, l, r);
    float s1=0, s2=0;
    for(int i=0;i<pos;i++)
    s1+=w[i];


    if(s1<0.5)
      {
      if (s1+w[pos]>0.5)
          return a[pos];
          else weighted_median(a,w,pos+1,r);
      }
      else weighted_median(a,w,l,pos-1);
}
int main()
{

    cout<<"Citeste n:";
    f>>n;
    int a[n+1];
    float w[n+1];

    for(int i=0;i<n;i++)
    f>>a[i];
    for(int i=0;i<n;i++)
    f>>w[i];

    g<<weighted_median(a,w,0,n-1);



}
