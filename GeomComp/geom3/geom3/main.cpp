// C++ Implementation. To find the point of
// intersection of two lines
#include <bits/stdc++.h>
using namespace std;

// This pair is used to store the X and Y
// coordinates of a point respectively
#define pdd pair<double, double>

int min(int a ,int b)
{
    if(a<=b) return a ;
        else return b ;
}
int max(int a,int b)
{
    if(a>=b) return a ;
        else return b ;
}
bool collinear(pdd A, pdd B , pdd C)
{
    if ((C.second - B.second)*(B.first - A.first) == (B.second - A.second)*(C.first - B.first))
        return true;
    else
        return false;
}
void swap(pdd *A,pdd* B)
{
    pdd *temp = A;
    A=B;
    B = temp ;
}
// Function used to display X and Y coordinates
// of a point
void displayPoint(pdd P)
{
	cout << "(" << P.first << ", " << P.second
		<< ")" << endl;
}

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
	// Line AB represented as a1x + b1y = c1
	double a1 = B.second - A.second;
	double b1 = A.first - B.first;
	double c1 = a1*(A.first) + b1*(A.second);

	// Line CD represented as a2x + b2y = c2
	double a2 = D.second - C.second;
	double b2 = C.first - D.first;
	double c2 = a2*(C.first)+ b2*(C.second);

	double determinant = a1*b2 - a2*b1;

	if (determinant == 0)
	{
		// The lines are parallel. This is simplified
		// by returning a pair of FLT_MAX
		return make_pair(FLT_MAX, FLT_MAX);
	}
	else
	{
		double x = (b2*c1 - b1*c2)/determinant;
		double y = (a1*c2 - a2*c1)/determinant;
		return make_pair(x, y);
	}
}

// Driver code
int main()
{
	pdd A = make_pair(0, 0);
	pdd B = make_pair(2, 2);
	pdd C = make_pair(3, 3);
	pdd D = make_pair(1, 1);



	if (collinear(A,B,C)&&collinear(B,C,D))
	{
	    cout<<"punctele sunt coliniare \n";
	    if(A.first>B.first) swap(A,B);
	    if(C.first>D.first) swap(C,D);

	    if(C.first<B.first)
	    {
	        displayPoint(C);

	        if(B.first<D.first)
	           displayPoint(B);
	           else displayPoint(D);
	    }
	    else cout<<"Segmentele nu se intersecteaza";

	    return 0;
	}

	pdd intersection = lineLineIntersection(A, B, C, D);

	if (intersection.first == FLT_MAX &&
		intersection.second==FLT_MAX)
	{
		cout << "The given lines AB and CD are parallel.\n";
	}

	else
	{
	    //verificam daca punctul de inters al liniile apartine segmentelor

	    if(min(A.first,B.first)<=intersection.first && intersection.first<=max(A.second,B.second)&&
           min(A.second,B.second)<=intersection.second && intersection.second<=max(A.second , B.second) &&
           min(C.first,D.first)<=intersection.first && intersection.first<=max(C.second,D.second)&&
           min(C.second,D.second)<=intersection.second && intersection.second<=max(C.second , D.second))
      {


		cout << "The intersection of the given segments AB "
				"and CD is: ";
        displayPoint(intersection);
      }
       else cout<<"Segmentele nu se intersecteaza , doar liniile "<<endl;
	}



	return 0;
}
