//例子：https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376 

#include<iostream>
#include<queue> 
using namespace std;

//广式优先搜索
//迪克拉斯算法求最短路径 
int n,m,c1,c2;
const int MAXV=505;
const int INF = 0x3f3f3f3f;
int G[MAXV][MAXV],d[MAXV],r[MAXV];//距离，每个城市消防员的个数 
bool vis[MAXV]={false};
int xnum[MAXV]={0},rnum[MAXV]={0};//每个城市消防员的数量 
//每个城市到目标城市的最短路径的个数

void Dijkstra(int c1,int c2){
	fill(d,d+MAXV,INF);
	d[c1]=0;
	xnum[c1]=r[c1];
	rnum[c1]=1;
	
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<MIN){
				u=j;
				MIN = d[j];
			}
		}
		
		if(u==-1) return;
		vis[u]=true;
		
		for(int v=0;v<n;v++){
			if(vis[v]==false && G[u][v]!=INF){
				if(d[v]==d[u]+G[u][v]){
					rnum[v]+=rnum[u];//道路数目相加
					xnum[v]=max(xnum[v],xnum[u]+r[v]);//比较消防员数目 
				}
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					rnum[v]=rnum[u];//道路条数保持不变
					xnum[v]=xnum[u]+r[v]; 
				} 
			}
			
		}
	} 
	
} 

int main(){
	
	int u,v,w;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&r[i]);
	}
	fill(G[0],G[0]+MAXV*MAXV,INF); 
	for(int j=0;j<m;j++){
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
		G[v][u]=w;
	}
	Dijkstra(c1,c2);
	
	printf("%d %d",rnum[c2],xnum[c2]); 
	
	return 0;
}
