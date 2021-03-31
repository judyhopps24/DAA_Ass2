#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};
int main()
{
    ofstream mfile("input.txt");
    //cout<<"enter the value of c\n";
    int C;
    //cout<<"enter the number of points\n";
    cin>>C;
    int n;
    cin>>n;
    //cout<<"enter points x1 y1\n";
    vector<Point> v(n+1);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mfile << x << " " << y ;
        mfile << "\n";
        v[i]={x,y};
    }
    mfile.close();
    vector<vector<double>> error( n+1 , vector<double> (n+1,0));
    vector<vector<double>> a( n+1 , vector<double> (n+1,0));
    vector<vector<double>> b( n+1 , vector<double> (n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double sigxy=0, sigx=0,sigy=0,sigxsq=0;
            for(int k=i;k<=j;k++)
            {
                sigxy += v[k].x * v[k].y;
                sigx += v[k].x;
                sigy += v[k].y;
                sigxsq += v[k].x * v[k].x ;
            }
            int N ;
            N = j-i +1;
            a[i][j]=(N*sigxy - sigx * sigy) /( N* sigxsq - sigx*sigx );
            b[i][j]=(sigy - a[i][j]*sigx )/ N;

            double e = 0;
            for(int k=i;k<=j;k++)
            {
                e  += (v[k].y  -  a[i][j]*v[k].x - b[i][j])*(v[k].y  -  a[i][j]*v[k].x - b[i][j]);
            }
            error[i][j] =  e;
        }
    }
    vector<double> opt(n+1);
    vector<int> index(n+1);
    for(int j=1;j<=n;j++)
    {
        opt[j] = error[1][j] + C;
        index[j] = 1;
        for(int i=2;i<=j;i++)
        {
            if (opt[i-1] + error[i][j] + C < opt[j])
            {
                opt[j] = opt[i-1] + error[i][j] + C;
                index[j] = i;
            }
        }
    }

    cout<<"Answer : "<<opt[n]<<"\n";


    ofstream lfile("lines.txt");
    for(int i=n;i>1;)
    {
        int a1 = v[i].x;
        int a2= v[index[i]].x;
        int b1 =  a[index[i]][i] * a1  + b[index[i]][i];
        int b2= a[index[i]][i] * a2  + b[index[i]][i];
        i=index[i]-1;
        lfile << a1 << " " << b1<<" "<<a2<<" "<<b2 ;
        lfile << "\n";
    }

            
}