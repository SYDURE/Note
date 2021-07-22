#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX_SIZE 22
#define header 11
#define Lmax 256

int P[MAX_SIZE]={0}; //�Ҷ�����ֵ 
int S[MAX_SIZE]={0}; //���ŷֶε���Сλ�� 
int L[MAX_SIZE]={0}; // ����ֵ������һ�εĻҶ�ֵ���� 
int B[MAX_SIZE]={0}; // ÿ��ֵ��Ҫ�Ĵ洢λ�� 
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
			
			//�ҵ�ǰ�������е�����ռλbit���� 
			if (b_max<Length(P[i-j+1])){
				b_max = Length(P[i-j+1]);
			}
			
			//�ҵ����ٵĴ洢λ�� 
			if(S[i] > S[i-j] + j*b_max){
				
				S[i] = S[i-j] + j*b_max;
				L[i] = j;
			} 
			
		}
		S[i] = S[i]+header;
	}
	
}


//���ص�x ռ�õ�bitλ 
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

//���
void OutPut()
{
	int C[MAX_SIZE]={0};
	int j=1;
	cout<<"ռ�õ����ٵ�bitλ��: "<<S[n]<<"\n";
	 
	//�Ӻ���ǰ׷�� 
	stack ss;
	while(n!=0){
		C[j] = L[n];
		cout<<"ÿ�εĳ���Ϊ��"<<C[j]<<" \n"; 
		
		n = n-L[n];
		j++;
	}
	
} 
