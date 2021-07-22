//����������� 

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
	
	//��̬�滮 
	FindLCS();
	PrintLCS(n,m);
	
	cout<<"\n������г���Ϊ��"<<table[n][m]<<endl;
	return 0;
}

//mark[i][j] = 1 ��ʾ��б�Ϸ�����  
//mark[i][j] = 2 ��ʾ���Ϸ�������������Ϊmark[i-1][j]�������� 
//mark[i][j] = 3 ��ʾ����������������Ϊmark[i][j-1]�������� 
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

//��ӡ ,���׷�� 
void PrintLCS(int x,int y){
	
	//׷�ٽ� 
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
