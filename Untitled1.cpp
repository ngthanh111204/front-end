#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Phanso{
	int Tuso;
	int Mauso;
};
typedef Phanso Ps;
void NhapPhanso(Ps *ps){
	printf("\nTu so: ");scanf("%d",&ps->Tuso);
	printf("\nMau so: ");scanf("%d",&ps->Mauso);
}

void InPhanso(Ps ps){
	if(ps.Mauso<0){
		ps.Tuso*=-1;
		ps.Mauso*=-1;
	}
	if(ps.Mauso==1){
		printf("%d",ps.Tuso);
	}
	else{
		printf("%d/%d",ps.Tuso,ps.Mauso);
	}
		
}
Phanso Conghaiphanso(Phanso ps1, Phanso ps2){
	Phanso Ketqua;
	// (a/b + c/d = (a*d+c*d)/(b*d)
	Ketqua.Tuso=ps1.Tuso*ps2.Mauso + ps2.Tuso*ps1.Mauso;
	Ketqua.Mauso=ps1.Mauso*ps2.Mauso;
	return Ketqua;
}
Phanso Truhaiphanso(Phanso ps1, Phanso ps2){
	Phanso Ketqua;
	// (a/b-c/d)=(a*d-c*d)/(b*d)
	Ketqua.Tuso=ps1.Tuso*ps2.Mauso - ps2.Tuso*ps1.Mauso;
	Ketqua.Mauso=ps1.Mauso*ps2.Mauso;
	return Ketqua;
}
Phanso Nhanhaiphanso(Phanso ps1, Phanso ps2){
	Phanso Ketqua;
	// (a/b * c/d) = (a*c)/(b*d)
	Ketqua.Tuso=ps1.Tuso*ps2.Tuso;
	Ketqua.Mauso=ps1.Mauso*ps2.Mauso;
	return Ketqua;
}
Phanso Chiahaiphanso(Phanso ps1, Phanso ps2){
	Phanso Ketqua;
	// (a/b * c/d) = (a*d)/(b*c)
	Ketqua.Tuso=ps1.Tuso*ps2.Mauso;
	Ketqua.Mauso=ps1.Mauso*ps2.Tuso;
	return Ketqua;
}
int main(){
	Phanso ps1,ps2;
	printf("Phan so thu nhat: ");
	NhapPhanso(&ps1);
	printf("\nPhan so thu hai: ");
	NhapPhanso(&ps2);
	printf("\nPhan so vua nhap la: ");
	InPhanso(ps1);
	printf(" \t ");
	InPhanso(ps2);
	printf("\nCong hai phan so: ");
	InPhanso(ps1);printf(" + ");InPhanso(ps2);printf(" = ");InPhanso(Conghaiphanso(ps1,ps2));
	printf("\nTru hai phan so: ");
	InPhanso(ps1);printf(" - ");InPhanso(ps2);printf(" = ");InPhanso(Truhaiphanso(ps1,ps2));
	printf("\nNhan hai phan so: ");
	InPhanso(ps1);printf(" * ");InPhanso(ps2);printf(" = ");InPhanso(Nhanhaiphanso(ps1,ps2));
	printf("\nChia hai phan so: ");
	InPhanso(ps1);printf(" : ");InPhanso(ps2);printf(" = ");InPhanso(Chiahaiphanso(ps1,ps2));
}
