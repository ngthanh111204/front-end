#include<iostream>
#include<cstring>

struct Sach
{ char masach[6];
char tensach[50]; 
char tacgia[30]; 
int soluong; 
};

using namespace std;
int a(Sach t[],int c){
	int result = 2;
	for(int i = 1; i <= c;i++){
		 result = strcmp(t[i-1].masach,t[i].masach);
	}
	if(result == 0){
		return 1;
	}return 0;
}
int b(Sach a[],int &g){
	int u;
	for(int i = 0;i < g;i++){
		if(a[i].soluong < 5){
			a[i] = a[g-1];
			g--;
			u++;
		}
	}return u;
}

int main(){
	int n;
	int c;
	int max = 0;
	cin >> n;
	Sach dausach[n];
	for(int i = 0; i < n;i++){
		fflush(stdin);
		do{
			cout <<"nhap ma sach:";
		   gets(dausach[i].masach);
		   
		}while(a(dausach,i));
		cout <<"nhap ten sach:";
		gets(dausach[i].tensach);
		cout <<"nhap ten tac gia:";
		gets(dausach[i].tacgia);
		cout <<"nhap so luong:";
		cin >> dausach[i].soluong;
		if(dausach[i].soluong > max){
			max = dausach[i].soluong;
		}cout << endl;
	}
	for(int i = 0;i < n;i++){
		if(max == dausach[i].soluong){
			cout << "ten sach:" << dausach[i].tensach <<" " << "ten tac gia:" << dausach[i].tacgia <<" " << "soluong:" << dausach[i].soluong << endl;
			c++;
		}
	}cout << "so luong dau sach lon nhat:" << c << endl;
	cout <<"so luong dau sach bi xoa:" << b(dausach,n) << endl;
	
}
