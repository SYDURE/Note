//输入案例：2 -5 8 11 -3 4 6 


#include<iostream>
#include<string>
using namespace std;

int A[101]={0};
int n;
int MaxSum();

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	MaxSum();
	
	return 0;	
} 

int MaxSum()
{
	int sum=0;
	int b=0;
	int c;
	for(int i=1;i<=n;i++){
		if(b>0){
			b = b+A[i]; 
		}
		else {
			b = A[i];
		}
		if(b>sum){
			sum = b;
			c = i;
		}
	}
	
	cout<<"最大子项和为："<<sum<<" \n";
	return 0;
}
