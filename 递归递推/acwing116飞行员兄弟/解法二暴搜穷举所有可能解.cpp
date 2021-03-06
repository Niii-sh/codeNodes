/*
思路还是比较明确的
两道题做下来 我有一定信心再碰到这种题应该也能一次性A掉
需要注意的是memcpy的使用顺序
每次开始循环前都先将g 的值 复制到backup中 memcpy(backup,g,sizeof g)
                每次结束循环后还原 将backup值复制到g中 memcpy(g,backup,sizeof backup)
然后需要注意的是:
在turn_all的过程中
事实上中间的i,j点被turn了两次 一定要注意最后的是再turn一次
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

#define x first
#define y second

typedef pair<int,int>PII;

const int N = 10;
char g[N][N];
char backup[N][N];
int n;
void turn_all(int x,int y){
	auto turn_one = [](int x,int y,char g[][N])->int{
		if(g[x][y]=='-')
			g[x][y]='+';
		else 
			g[x][y]='-';
	};

	for(int i=0;i<4;i++){
		turn_one(x,i,g);
		turn_one(i,y,g);
	}

	turn_one(x,y,g);
}

int main(){
	n = 4;

	for(int i=0;i<4;i++)
			cin>>g[i];

	std::vector<PII> ans;

	for(int op=0;op<1<<16;op++){
		//复制
		memcpy(backup,g,sizeof g);
		std::vector<PII> tmp;
		for(int i=0;i<16;i++){
			if((op>>i)&1){
				turn_all(i/4,i%4);
				tmp.emplace_back(i/4,i%4);
			}
		}
		
		bool flag = false;
		
		for(int i=0;i<n;i++)
		    for(int j=0;j<n;j++){
		        if(g[i][j] == '+'){
		            flag = true;
		            break;
		        }
		        
		    }
        
        if(!flag)
		    if(ans.empty() || ans.size()>tmp.size()){
		    	ans = tmp;
		    }
		
		memcpy(g,backup,sizeof backup);
	}

	cout<<ans.size()<<endl;

	for(auto &p:ans){
		cout<<p.x+1<<' '<<p.y+1<<endl;
	}


	return 0;
}