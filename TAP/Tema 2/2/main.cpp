#include <iostream>

using namespace std;
struct point
{
    int x;
    int y;
};
void tile (point left_cor,point empty,int n,int **a)
{
    static int index =0;
    index++;

    point empty1,empty2,empty3,empty4;
    empty1.x=empty2.x=left_cor.x+(n-1)/2;
    empty3.x=empty4.x=left_cor.x+(n-1)/2+1;
    empty1.y=empty3.y=left_cor.y+(n-1)/2;
    empty2.y=empty4.y=left_cor.y+(n-1)/2+1;

    point empty2_aux=empty2;
    point empty3_aux=empty3;

    if(empty.x<=empty1.x)
    {
        if(empty.y<=empty1.y)
        {
            a[empty2.x][empty2.y]= a[empty3.x][empty3.y]= a[empty4.x][empty4.y]=index;
            empty1=empty;
        }
        else
        {
            a[empty1.x][empty1.y]= a[empty3.x][empty3.y]= a[empty4.x][empty4.y]=index;

            empty2=empty;

        }

    }
    else
    {
         if(empty.y<=empty1.y)
         {
             a[empty1.x][empty1.y]= a[empty2.x][empty2.y]= a[empty4.x][empty4.y]=index;

             empty3=empty;
         }
         else
         {
             a[empty1.x][empty1.y]= a[empty2.x][empty2.y]= a[empty3.x][empty3.y]=index;
             empty4=empty;
         }

    }

    if(n==2) return ;


    point left_cor1,left_cor2,left_cor3,left_cor4;
    left_cor1.x=left_cor2.x=left_cor.x;
    left_cor3.x=left_cor4.x=empty3_aux.x;
    left_cor1.y=left_cor3.y=left_cor.y;
    left_cor2.y=left_cor4.y=empty2_aux.y;

    tile(left_cor1,empty1,n/2,a);
    tile(left_cor2,empty2,n/2,a);
    tile(left_cor3,empty3,n/2,a);
    tile(left_cor4,empty4,n/2,a);



}
int main()
{
    point empty,left_cor;
    int n;

    left_cor.x=left_cor.y=0;
    cout<<"dimensiunea matricei(o putere de 2)"<<endl;
    cin>>n;
    cout<<"coord. punctului empty"<<endl;
    cin>>empty.x>>empty.y;

    int ** a =new int* [n];
    for(int i=0;i<n;i++)
    a[i]=new int[n];

    a[empty.x][empty.y]=0;

    tile(left_cor,empty,n,a);

    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
     cout<<a[i][j]<<" ";

     cout<<endl;
    }

    return 0;
}
