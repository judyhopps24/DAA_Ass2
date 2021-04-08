#include <bits/stdc++.h>     
using namespace std;

double randomize() 
{   
    return (rand() % 500); 
}
  
int main () 
{
    double n;
    cout<<"enter no points \n";
    cin>>n;

    srand(time(NULL));     
    vector<double> vecx(n); 
    vector<double> vecy(n); 
    generate(vecx.begin(), vecx.end(), randomize);
    sort(vecx.begin(),vecx.end());
    for(int i=0;i<n-1;i++)
    {
        if(vecx[i]==vecx[i+1])
        {   
            vecx[i]=vecx[vecx.size()-1]+1;
            sort(vecx.begin(),vecx.end());
        }
    }
    


    double s;
    cout<<"enter number of segments \n";
    cin>>s;
    vector<double>segbreaks(s+1);
    cout<<"enter breaks points start with 0 and end with n\n";
    for(int i=0;i<s+1;i++)
    {
        cin>>segbreaks[i];
    }

    for(int i=0;i<s;i++)
    {
        double m,c;
        cout<<"enter m and c for this segment\n";
        cin>>m>>c;
        for(int j=segbreaks[i];j<segbreaks[i+1];j++)
        {
            vecy[j]=vecx[j]*m + c;
        }
    }
    
    for(auto x :  vecx)
        cout<<x<<" ";
    cout<<"\n";
    for(auto y :  vecy)
        cout<<y<<" ";
    cout<<"\n";


    ofstream infile("generatedInput.txt"); 
    for(int i=0;i<n;i++)  
        infile << vecx[i] << " " << vecy[i]<<"\n";
    infile.close();

        
  return 0;
}