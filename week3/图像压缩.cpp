#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX_SIZE 22
#define header 11
#define Lmax 256

int P[MAX_SIZE]={0}; //灰度序列值 
int S[MAX_SIZE]={0}; //最优分段的最小位数 
int L[MAX_SIZE]={0}; // 最优值后的最后一段的灰度值个数 
int B[MAX_SIZE]={0}; // 每个值需要的存储位数 
int n; 

int Length(int x);
void Compress(); 
void OutPut();


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>P[i];
	
	Compress();
	OutPut();
	
		
	
	return 0;
}


void Compress()
{
	S[0] = 0;
	int b_max=0;
	for(int i=1;i<=n;i++)
	{
		B[i] = Length(P[i]);
		b_max = B[i];
		S[i] = S[i-1]+b_max*1;
		L[i] = 1; 
		
		
		for(int j=2;j<=min(i,Lmax);j++){
			
			//找当前检索段中的最大的占位bit个数 
			if (b_max<Length(P[i-j+1])){
				b_max = Length(P[i-j+1]);
			}
			
			//找到更少的存储位数 
			if(S[i] > S[i-j] + j*b_max){
				
				S[i] = S[i-j] + j*b_max;
				L[i] = j;
			} 
			
		}
		S[i] = S[i]+header;
	}
	
}


//像素点x 占用的bit位 
int Length(int x)
{
	int x_bit=1;
	x = x/2;
	while(x>0){
		x_bit++;
		x = x/2;
	}
	return x_bit; 
}

//输出
void OutPut()
{
	int C[MAX_SIZE]={0};
	int j=1;
	cout<<"占用的最少的bit位是: "<<S[n]<<"\n";
	 
	//从后向前追踪 
	stack ss;
	while(n!=0){
		C[j] = L[n];
		cout<<"每段的长度为："<<C[j]<<" \n"; 
		
		n = n-L[n];
		j++;
	}
	
} 
