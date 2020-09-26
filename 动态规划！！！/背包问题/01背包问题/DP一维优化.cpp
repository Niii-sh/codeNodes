#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int n,m;
int w[N];
int v[N];
int f[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i] >> w[i];
    
    for(int i=1;i<=n;i++)   
        for(int j=m;j>=v[i];j--)
            f[j] = max(f[j-v[i]]+w[i],f[j]);
    
    cout<<f[m]<< endl;
    
    return 0;    
}