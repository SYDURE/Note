#include<iostream>
using namespace std;

#define MAX 100
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

int Prim(int graph[][MAX], int n) { //��ά������Ϊ�������ʹ�ã�
	int sta[MAX];//���ĳһ���ߵ����ֵ
	int lowcost[MAX];//�����iΪ�յ�ĵıߵ���С��Ȩֵ
	int min,minid,sum=0;//min���������СȨֵ��minid�������Ȩֵ��С�ı�����Ӧ���յ�
	
	for(int i=2; i<=n; i++) {
		lowcost[i]=graph[1][i];//��ʼ��lowcost[i]���������ǵĳ�ʼֵ�������Ǵӽڵ�1������i��Ȩֵ
		sta[i]=1;//��㸳ֵΪ1
	}
	
	sta[1]=0;//�ڵ�1������С������
	
	for(int h=2; h<=n; h++) {
		min=MAXCOST;//�ҵ���С�ģ��������ϴ�ֵ
	
		for(int j=2; j<=n; j++) {
			if(lowcost[j]<min&&lowcost[j]!=0) { //����ҵ�Ȩֵ��С�ľ͸�ֵ��min�������յ�j��ֵ��minid��
				min=lowcost[j];
				minid=j;
			}
		}
	
		lowcost[minid]=0;//�������Ѿ�������С�����������԰�ֵ��Ϊ0
		sum+=min;
	
		for(int s=2; s<=n; s++) {
			if(lowcost[s]<graph[minid][s]) { //���ԭ�ȵ�lowcost[j]��ֵ������minidΪ��㵽�յ�j��Ȩֵ���������������������Ϊminid
				lowcost[s]=graph[minid][s];
				sta[s]=minid;
			}
		}
		
	}
	return sum;

}


int main() {
	int m,n,x,y,cost;
	
	cout<<"������ڵ���Ŀ�ͱߵ���Ŀ��"<<endl;
	cin>>m>>n;
	
	for(int i=1; i<=m; i++){ 
	
		for(int j=1; j<=m; j++)
			graph[i][j]=MAXCOST;
	
	}
	 
	for(int k=1; k<=n; k++) {
		cin>>x>>y>>cost;
		graph[x][y]=graph[y][x]=cost;
	}
	
	cost= Prim(graph,n);
	
	cout<<cost<<endl;
	return 0;
}
