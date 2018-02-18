#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>
#define space 2

using namespace std;

ifstream f("date.in");
ofstream g("date.out");



string v[] = {"A","C", "G", "T"};


int main()
{
    unordered_map < string , int > map;

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            string s = v[i] + v[j];
            if(v[i]==v[j]) map[s] = 0;
            else if( s.compare("AC") == 0 || s.compare("CA") == 0 || s.compare("GT") == 0 || s.compare("TG") == 0)
                map[s] = 1;
            else
                map[s] = 3;
        }



    string s1,s2;
    f>>s1>>s2;

    vector< vector<int> > dp( s1.size()+1,vector<int>(s2.size()+1) );
    vector< vector<string> > back ( s1.size()+1,vector<string>(s2.size()+1) );



    dp[0][0]=0;
    for(int i=1; i<=s1.size(); i++)
    {
        dp[i][0] = dp[i-1][0] + space ;
        back[i][0] = "above";
    }

    for(int j=1; j<=s2.size(); j++)
    {
        dp[0][j] = dp[0][j-1] + space;
        back[0][j] = "left";
    }

    for(int i=1; i<=s1.size(); i++)
        for(int j=1; j<=s2.size(); j++)
        {

            int diag  = dp[i-1][j-1] + map[s1.substr(i-1,1)+s2.substr(j-1,1)];
            int left  = dp[i][j-1] + space;
            int above = dp[i-1][j] + space;

            if(diag <= left)
            {
                dp[i][j] = diag;
                back[i][j] = "diag";
            }
            else
            {
                dp[i][j] = left;
                back[i][j] = "left";
            }

            if(above <= dp[i][j])
            {
                dp[i][j] = above;
                back[i][j] = "above";
            }
        }


    g<<dp[s1.size()][s2.size()]<<'\n';

    int i=s1.size(), j=s2.size();
    string align1="",align2="";
    while(1)
    {
        if (back[i][j]=="diag")
        {

            align1 = s1.substr(i-1,1) + align1;
            align2 = s2.substr(j-1,1) + align2;

            i=i-1;
            j=j-1;
        }
        else if(back[i][j]=="left")

        {
            align1 = "-" + align1;
            align2 = s2.substr(j-1,1) + align2;

            j=j-1;
        }

        else
        {


            align1 = s1.substr(i-1,1) + align1;
            align2 = "-" + align2;

            i=i-1;


        }


        if(i==0 && j==0) break;
    }

     g<<align1<<endl<<align2;



    return 0;
}
