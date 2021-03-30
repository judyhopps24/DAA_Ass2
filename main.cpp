#include<bits/stdc++.h>
#define C 0
struct Point{
    int x;
    int y;
};
int main()
{
    int n;
    cin>>n;
    vector<Point> v(n+1);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[i]={x,y};
    }
    vector<vector<int>> error( n+1 , vector<int> (n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int sigxy=0, sigx=0,sigy=0,sigxsq=0;
            for(int k=i;k<j;k++)
            {
                sigxy += v.x * v.y;
                sigx += v.x;
                sigy += v.y;
                sigxsq += v.x * v.x ;
            }
            int a,b,N ;
            N = j-i;
            a=(N*sigxy - sigx * sigy) /( N* sigxsq - sigx*sigx )
            b=(sigy - a*sigx )/ N;

            int e = 0;
            for(int k=i;k<j;k++)
            {
                e  += (v.y  -  a*v.x - b)*(v.y  -  a*v.x - b);
            }
            error[i][j-1] =  e;
        }
    }
    vector<int> opt(n+1, 1e9);
    opt[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            opt[i]= min(opt[i],  error[j][i] + C + opt[j-1]);
        }
    }
            
}