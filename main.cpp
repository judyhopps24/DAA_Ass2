#include <bits/stdc++.h>
using namespace std;
#define C 0
struct Point{
    int x,y;
};
int main()
{
    ofstream mfile("Points.txt");
    int n;
    cin>>n;
    vector<Point> v(n+1);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mfile << x << "," << y ;
        mfile << "\n";
        v[i]={x,y};
    }
    mfile.close();
    vector<vector<int>> error( n+1 , vector<int> (n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sigxy=0, sigx=0,sigy=0,sigxsq=0;
            for(int k=i;k<j;k++)
            {
                sigxy += v[k].x * v[k].y;
                sigx += v[k].x;
                sigy += v[k].y;
                sigxsq += v[k].x * v[k].x ;
            }
            int a,b,N ;
            N = j-i;
            a=(N*sigxy - sigx * sigy) /( N* sigxsq - sigx*sigx );
            b=(sigy - a*sigx )/ N;

            int e = 0;
            for(int k=i;k<j;k++)
            {
                e  += (v[k].y  -  a*v[k].x - b)*(v[k].y  -  a*v[k].x - b);
            }
            error[i][j-1] =  e;
        }
    }
    vector<int> opt(n+1, 1e9);
    opt[0]=0;
    for(int i=1;i<=n;i++)
    {
        //int prev= opt[i];
        for(int j=1;j<=i;j++)
        {
            opt[i]= min(opt[i],  error[j][i] + C + opt[j-1]);
            // if(opt[i]!=prev)
            //     opt[]
        }
    }

            
}