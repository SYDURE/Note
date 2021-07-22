#include<iostream>
using namespace std;

#define MAXN 101
#define MAXM 101

int n,m;//��Ŀ����Ͷ��Ǯ��
int f[MAXN][MAXM]={0};//Ч�溯��
int F[MAXN][MAXM] = {0}; //Fk(x) ��ʾͶ�ʸ�ǰk����Ŀȡ�õ��������ֵ
int x[MAXN][MAXM] = {0}; //Xk(x) ��ʾȡ���������ֵʱ��k����ĿͶ�ʵ�Ǯ��

void FindMaxf();
void PrintAns(); 


int main()
{
	cin>>n>>m;
	//����Ч�溯�� 
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
 

//��̬�滮�����Ч��ֵ 
void FindMaxf(){
	int i,j,k,tmp;
	//�ݹ�߽�������Ͷ�ʵ�һ����Ŀ x={1,2,3,4,5} 
	for(i = 0;i<=m;i++) {F[1][i] = f[1][i];x[1][i] = i;} 
	
	//�ݹ鷽��
	//Ͷ��ǰk ����Ŀ 
	for(int i = 2;i<=n; i++){
		
		//����k ����ĿͶ��Ǯ��  
		for(int j = 1;j<=m;j++){
			
			//Ͷ�ʵ�ǰ��Ŀ��Ǯ�� 
			for(int k=0;k<=j;k++){
				tmp = f[i][k] + F[i-1][j-k];
				
				//����¼����Ǻ��� 
				if(tmp > F[i][j]){
					F[i][j] = tmp;
					x[i][j] = k;
				} 
				
			}
			
		}
		 
	} 
	
}

//��ӡ��� 
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
    
    
    cout<<"ÿ����Ŀ��Ͷ��Ǯ��Ϊ��"<<endl;
	int xk[MAXN]={0};
	
	for(int i=n;i>=1;i--){
		m = m-xk[i+1]; //��ȥǰ���ù���Ǯ�� 
		xk[i] = x[i][m];
		cout<<"Ͷ��Ϊ��"<<i<<" ��ĿǮ��Ϊ��"<<xk[i]<<endl; 
	}  
}


