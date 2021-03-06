/*
基本思路:
最基本的DP 即斐波那契数列
定义dp[] 
dp[] = dp[i-1] + dp[i-2]
c b a 
  c  b
由于这题N 较大 但是不用取模所以是高精度
如果N 非常大 而且要取模那么应该用矩阵快速幂
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 5010;
int n;

struct Node{
    vector<int>nums;
    vector<int> add(vector<int>&a,vector<int>&b){
        vector<int>c;
        int t=0;
        for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0;i--,j--){
            t+= i>=0? a[i]:0;
            t+= j>=0? b[j]:0;
            c.push_back(t%10);
            t/=10;
        }
        if(t)
            c.push_back(1);
        reverse(c.begin(),c.end());
        //for(vector<int>::iterator it=c.begin() ; it!=c.end();it++){
        //    cout<<*it ;
        //}
        return c;
    }

    Node operator+(Node&t){
        Node tmp;
        tmp.nums = add(nums,t.nums);
        return tmp;
    }   
};

int main(){
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }

    
    Node a,b;
    a.nums.push_back(1);
    b.nums.push_back(1);

    Node c;

    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }

    if(n==1)
        cout<<1;
    else
        for(int i=0;i<c.nums.size();i++)
            cout<<c.nums[i];

    return 0;
}