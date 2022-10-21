//HoTen: Nguyen Tran Anh Tan
//Lop: CNTT
//MSSV: 6251071087
#include<math.h>
#include<stdio.h>
int main(){
	int n,M,x[100],y[100],dem=0,duong,am;
	float dodai=0,dd[100],max;
	do{
		printf("Nhap so diem:");
		scanf("%d",&n);
	}
	while(n>100||n<0);
	for(int i=0;i<n;i++){
		printf("M%d=",i+1);
		scanf("%d%d",&x[i+1],&y[i+1]);
	}
	for(int i=0;i<n;i++){
		dodai=dodai+sqrt((x[i+2]-x[i+1])*(x[i+2]-x[i+1])+(y[i+2]-y[i+1])*(y[i+2]-y[i+1]));
		if(i+2==n&&i+2>2){
			dodai=dodai+sqrt((x[1]-x[n])*(x[1]-x[n])+(y[1]-y[n])*(y[1]-y[n]));
			break;
		}
	}
	if(n==1||n==0) printf("Khong co do dai duong gap khuc\n");
	else printf("Do dai duong gap khuc = %.2f\n",dodai);
	dd[n]=sqrt((x[1]-x[n])*(x[1]-x[n])+(y[1]-y[n])*(y[1]-y[n]));
	max=dd[n];
	for(int i=0;i<n;i++){
		dd[i+1]=sqrt((x[i+2]-x[i+1])*(x[i+2]-x[i+1])+(y[i+2]-y[i+1])*(y[i+2]-y[i+1]));
		if(max<dd[i+1]) max=dd[i+1];
	}
	printf("Doan co do dai lon nhat la %.2f\n",max);
	for(int i=0;i<n;i++){
		if(x[i+1]>0) duong++;
		else if(x[i+1]<0) am++;
		else continue;
	}
	printf("So doan cat Oy = %d\n",duong*am);
	for(int i=0;i<n;i++) if(x[i+1]>0&&y[i+1]>0) dem++;
	printf("So diem thuoc goc phan tu thu nhat la %d",dem);
}
