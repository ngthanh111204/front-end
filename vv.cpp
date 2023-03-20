#include<iostream>
#include<string>
using namespace std;
struct SinhVien{
	char mahp[50];
	char tenhp[50];
	int sotc;
};
int KTMT(SinhVien x[],int n,char ma[]){
	for(int i=0;i<n;i++){
		if((x[i].mahp,ma)==0){
		return 1;
		}
	return 0;	
	}
}

int main(){
	int n;char mahp[50];char *ma;
	while(n>=0 && n<10){
		cin>>n;
	}
	SinhVien x[n];
	for(int i=0;i<n;i++){
		fflush(stdin);
		do{
			cout<<"Nhap ma hoc phan "<<i<<":";gets(x[i].mahp);
		}
		while(KTMT(x,i,x[i].mahp)==1);
		cout<<"Nhap ten hoc phan:";
		gets(x[i].tenhp);
		cout<<"Nhap so tin chi";
		cin>> x[i].sotc;
		 }
	gets(ma);                                             
	for(int i=0;i<n;i++){
		if(ma==x[i].mahp){
			cout <<"Khong ton tai hoc phan nay";
		}
		else{
			cout <<"Ma hoc phan:"<< x[i].mahp<<" "<<"Ten hoc phan:"<<x[i].tenhp<<" "<<"So tin chi:"<<x[i].sotc<<endl;
			}
		}	 
	for(int i=0;i<n;i++){
		cout <<"Ma hoc phan:"<< x[i].mahp<<" "<<"Ten hoc phan:"<<x[i].tenhp<<" "<<"So tin chi:"<<x[i].sotc<<endl;
			}
	return 0;
}
