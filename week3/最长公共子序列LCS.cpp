//最长公共子序列 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define MAX_SIZE 1001

int table[MAX_SIZE][MAX_SIZE]={0};
int mark[MAX_SIZE][MAX_SIZE]={0};
string X,Y; 
int n,m;

void FindLCS();
void PrintLCS(int x,int y);

int main(){
	
	cin>>X;
	cin>>Y;
	n = X.length();
	m = Y.length();
	
	//动态规划 
	FindLCS();
	PrintLCS(n,m);
	
	cout<<"\n最长子序列长度为："<<table[n][m]<<endl;
	return 0;
}

//mark[i][j] = 1 表示向斜上方收缩  
//mark[i][j] = 2 表示向上方收缩，子序列为mark[i-1][j]的子序列 
//mark[i][j] = 3 表示向左方收缩，子序列为mark[i][j-1]的子序列 
void FindLCS(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(X[i-1] == Y[j-1]){
				
				table[i][j] = table[i-1][j-1]+1;
				mark[i][j] = 1;
			}
			else {
				if(table[i-1][j] > table[i][j-1]){
					
					table[i][j] = table[i-1][j];
					mark[i][j] = 2;
				}
				else{
					
					table[i][j] = table[i][j-1];
					mark[i][j] = 3;	
				} 
							
			} 
			
		}
		
	}
}

//打印 ,解的追踪 
void PrintLCS(int x,int y){
	
	//追踪解 
	if(x==0 || y==0) return ;
	
	if(mark[x][y] == 1){
		cout<<X[x-1];
		PrintLCS(x-1,y-1);
	}
	else if(mark[x][y] == 2){
		PrintLCS(x-1,y);
	}
	else PrintLCS(x,y-1);
	
} 
