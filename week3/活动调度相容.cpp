//活动调度问题
//6
//1 1 4
//2 3 5
//3 2 6
//4 5 7
//5 4 9
//6 5 9

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

#define Max_size 101

struct Node{
	int flag; //标号 
	int start;
	int end;	
} Act[Max_size];

int n;
Node A[Max_size];//保存活动 

void GreedySelect();

bool cmp(Node A,Node B){
	return A.end < B.end; 
} 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Act[i].flag>>Act[i].start>>Act[i].end;
	}
	//按照结束时间排序	
	sort(Act,Act+n,cmp);
	GreedySelect();
	
	
	return 0;	
} 

void GreedySelect(){
	A[0] = Act[0];
	int k=1,j=0;
	
	for(int i=1;i<n;i++){
		
		if(Act[i].start > Act[j].end){
			A[k++] = Act[i];
			j = i;		
		}	
	}
	
	//输出
	cout<<"可以举办"<<k-1<<"个活动"<<endl; 
	for(int i=0;i<k;i++){
		cout<<"活动的标号为："<<A[i].flag<<" 开始时间为："<<A[i].start<<"结束时间为："<<A[i].end<<endl; 
		
	} 
		
} 
 
