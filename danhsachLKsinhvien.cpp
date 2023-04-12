#include "stdio.h"
#include "string.h"
#include "time.h"

struct date{
	int ngay;
	int thang;
	int nam;
};

struct SinhVien{
	char holot[50];
	char ten[50];
	char gioiTinh[5];
	date ngaySinh;
	int tuoi;
	float diemMon1;
	float diemMon2;
	float diemMon3;
	float diemTong;
	char hocLuc[10];
};
typedef SinhVien SV;



void nhapSinhVien(SV &sv);
void inSinhVien(SV sv);
//void tinhTuoi(SV &sv);
void tinhTongdiem(SV *sv);
void xepLoai(SV &sv);
void capNhatSinhVien(SV &sv);

void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}

void nhapSinhVien(SV &sv){
	printf("\nHo lot: "); fflush(stdin); fgets(sv.holot, sizeof(sv.holot), stdin); xoaXuongDong(sv.holot);
	printf("\nTen: "); fflush(stdin); fgets(sv.ten, sizeof(sv.ten), stdin); xoaXuongDong(sv.ten);
	printf("\nGioi tinh: "); fflush(stdin); fgets(sv.gioiTinh, sizeof(sv.gioiTinh), stdin); xoaXuongDong(sv.gioiTinh);
	printf("\nNgay sinh:"); scanf("%d%d%d", &sv.ngaySinh.ngay, &sv.ngaySinh.thang, &sv.ngaySinh.nam);
	printf("\nDiem Mon 1: "); scanf("%f", &sv.diemMon1);
	printf("\nDiem Mon 2: "); scanf("%f", &sv.diemMon2);
	printf("\nDiem Mon 3: "); scanf("%f", &sv.diemMon3);
}

void inSinhVien(SV sv){
	printf("%20s | %20s | %10s | %2d/%d/%d | %6.2f | %6.2f | %6.2f | %6.2f | %5s  ", sv.holot, sv.ten, sv.gioiTinh, sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam, sv.diemMon1, sv.diemMon2, sv.diemMon3, sv.diemTong, sv.hocLuc);
}

//void tinhTuoi(SV &sv){
//	time_t TTIME = time(0);
//	tm* NOW = localtime(&TTIME);
//	int namHienTai = NOW->tm_year+1900;
//	sv.tuoi = namHienTai - sv.ngaySinh.nam;
//}


void tinhTongdiem(SV *sv){
	sv->diemTong = (sv->diemMon1+sv->diemMon2+sv->diemMon3);
}

void xepLoai(SV &sv){
	if(sv.diemTong>=30){
		strcpy(sv.hocLuc, "XUAT SAC");
	}else if(sv.diemTong>20){
		strcpy(sv.hocLuc, "GIOI");
	}else if(sv.diemTong>10){
		strcpy(sv.hocLuc, "KHA");
	}else if(sv.diemTong>5){
		strcpy(sv.hocLuc, "TRUNG BINH");
	}else{
		strcpy(sv.hocLuc, "YEU");
	}
	
}

void capNhatSinhVien(SV &sv){
	nhapSinhVien(sv);
	tinhTongdiem(&sv);
	xepLoai(sv);
}
int main(){
	SV sv1;
	capNhatSinhVien(sv1);
	printf("%20s | %20s | %10s | %10s | %6s | %6s | %6s | %6s | %5s ", "Ho lot", "Ten", "Gioi Tinh", "Ngay Sinh", "Diem 1", "Diem 2", "Diem 3", "Diem TB", "XepLoai");
	printf("\n");
	inSinhVien(sv1);
}
