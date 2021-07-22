#include<iostream>
using namespace std;

#define MAXN 101
#define MAXM 101

int n,m;//项目数，投资钱数
int f[MAXN][MAXM]={0};//效益函数
int F[MAXN][MAXM] = {0}; //Fk(x) 表示投资给前k个项目取得的最大收益值
int x[MAXN][MAXM] = {0}; //Xk(x) 表示取得最大收益值时第k个项目投资的钱数

void FindMaxf();
void PrintAns(); 


int main()
{
	cin>>n>>m;
	//输入效益函数 
	for(int i = 1;i<=n;i++){
		
		f[i][0] = 0; 
		for(int j = 1;j<=m;j++){
			cin>>f[i][j];
		}
	}
	
	FindMaxf(); 
	PrintAns();	
	return 0;
 }
 

//动态规划求最大效益值 
void FindMaxf(){
	int i,j,k,tmp;
	//递归边界条件，投资第一个项目 x={1,2,3,4,5} 
	for(i = 0;i<=m;i++) {F[1][i] = f[1][i];x[1][i] = i;} 
	
	//递归方程
	//投资前k 个项目 
	for(int i = 2;i<=n; i++){
		
		//给第k 个项目投资钱数  
		for(int j = 1;j<=m;j++){
			
			//投资当前项目的钱数 
			for(int k=0;k<=j;k++){
				tmp = f[i][k] + F[i-1][j-k];
				
				//备忘录，标记函数 
				if(tmp > F[i][j]){
					F[i][j] = tmp;
					x[i][j] = k;
				} 
				
			}
			
		}
		 
	} 
	
}

//打印结果 
void PrintAns(){
    int i,j;
   	for(int i=0;i<=n;i++)
   	{
   		for(int j=0;j<=m;j++)
   		{
   			cout<<F[i][j]<<","<<x[i][j]<<" 		";
		}
		cout<<endl;	
	}
    
    
    cout<<"每个项目的投资钱数为："<<endl;
	int xk[MAXN]={0};
	
	for(int i=n;i>=1;i--){
		m = m-xk[i+1]; //减去前面用过的钱数 
		xk[i] = x[i][m];
		cout<<"投资为第"<<i<<" 项目钱数为："<<xk[i]<<endl; 
	}  
}


