#include <iostream>
#include<algorithm>
using namespace std;

#define MAX 100
struct edge {
	int x,y;
	int w;
} e[MAX];

int fa[MAX];
int rank[MAX];
int sum;

int cmp(edge a,edge b) { //������
	if(a.w!=b.w)	return a.w<b.w;

	else return a.x<b.x;
}

void make_set(int x) { //��ʼ���ڵ�
	fa[x]=x;
	rank[x]=0;
}


int find(int x) { //���Ҹ��ڵ�
	return fa[x]==x?x:fa[x]=find(fa[x]);
}


void union_set(int x,int y,int w) { //�ϲ��ڵ�
	if(rank[x]>rank[y]) {
		rank[y]=x;
	}
	 
	else  if(rank[x]<rank[y]) {
		rank[x]=y;
	}
	 
	else {
		rank[x]++;
		rank[y]=x;
	}
	
	sum+=w;//��Ȩֵ����w
}


int main() {
	int x,y,w;
	int m,n;//n�ǵ�,m�Ǳ�

	cin>>n>>m;

	for(int i=0; i<m; i++) {
		cin>>x>>y>>w;
		e[i].x=x;
		e[i].y=y;
		e[i].w=w;
		make_set(x);
		make_set(y);
	}

	sort(e,e+m,cmp);
	sum=0;

	for(int  i=0; i<n; i++) {
		x=find(e[i].x);
		y=find(e[i].y);
		w=e[i].w;

		if(x!=y) {
			union_set(x,y,w);
		}
	}

	cout<<sum<<endl;
	return 0;
}
