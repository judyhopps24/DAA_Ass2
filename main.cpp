#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
//struct point has members x and y denote x and y co=ordinates respectively
struct Point{
    long double x,y;
};
bool pointComp(Point a, Point b){
    //Comparator to determine smaller of the two pointd in terms of x and y co-ordinate
    return (a.x < b.x) || (a.x == b.x && a.y < b.y) ;
}

int main()
{
    //take input
    ofstream mfile("input.txt");
    int C,n;
    cin>>C>>n;
    vector<Point> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].x>>v[i].y;
        mfile << v[i].x << " " << v[i].y ;
        mfile << "\n";
    }
    mfile.close();
    //start the timer
    auto start = std::chrono::system_clock::now();
    //sort the points
    sort(v.begin(),v.end(),pointComp);

    // initialise error, a, b
    vector<vector<long double>> error( n+1 , vector<long double> (n+1,0)),a( n+1 , vector<long double> (n+1,0)),b( n+1 , vector<long double> (n+1,0));

    //find SSE for all intervals of points.
    //error[i][j] denotes the error of the points from i to j with a best fit of the points from i to j
    //a[i][j] and b[i][j] stores the values of a and b from the line y=ax+b of the best fit line found above
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            long double sigxy=0, sigx=0,sigy=0,sigxsq=0;
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

            long double e = 0;
            for(int k=i;k<=j;k++)
            {
                e  += (v[k].y  -  a[i][j]*v[k].x - b[i][j])*(v[k].y  -  a[i][j]*v[k].x - b[i][j]);
            }
            error[i][j] =  e;
        }
    }
    //dynamic programming to find a sequence of best fit segments
    //index keeps track of the best division index 
    // index[j] denotes that there is one segment from index[j]+1 to j and a new segment brings ffrom index[j]
    vector<long double> opt(n+1);
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
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    
    cout<<"C :"<<C<<"\n";
    cout<<"Error : "<<opt[n]<<"\n";

    ofstream paramsfile("param.txt");
    paramsfile << C << " " << opt[n];
    paramsfile<< "\n";
    paramsfile.close();

    ofstream lfile("lines.txt");   
    int segments=0; 
    //find the value of points on the line to plot the lines
    for(int i=n;i>1;)
    {
        int a1 = v[i].x;
        int a2= v[index[i]].x;
        int b1 =  a[index[i]][i] * a1  + b[index[i]][i];
        int b2= a[index[i]][i] * a2  + b[index[i]][i];
        i=index[i]-1;
        lfile << a1 << " " << b1<<" "<<a2<<" "<<b2 ;
        segments+=1;
        lfile << "\n";
    }
    lfile.close();
    

    cout<<"Segments : "<<segments<<"\n";
    cout<<"Error for a beast fit single line is :"<<error[1][n]<<"\n";
    cout<<"Time taken : "<<elapsed_seconds.count()*1000<<" milli seconds\n";  
    cout<<"Memory usage : "<<((n+1)*(n+1)*3*16  + (n+1)*4 + (n+1)*16 + (n+1)*16*2)/1024.0<<"  kilo bytes\n";    
            
}