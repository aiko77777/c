#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
int binarysearch(double b[],double c);
void bubblesort(double p[]);
int main(){
	srand(time(NULL));
	float amountzno;
	float k1=9300;
	float nk1=740;
	float k2=3150;
	float nk2=14400;
	float k3=0.075;
	float k4=420000000;
	double o3aq=552;//aM
	double zno=0;
	double o3ad=0;
	double odot=0;
	double o2aq=0;
	double h2o=55.5*pow(10,7);
	double h2o2=0;
	double hodot=0;
	double kt1=9300*(o3aq+zno);
	double kt2=740*(o3ad);
	double kt3=3150*(o3ad);
	double kt4=14400*(o2aq+odot);
	double kt5=0.075*(odot+h2o);
	double kt6=420000000*(h2o2);
	double ktsum=kt1+kt2+kt3+kt4+kt5+kt6;
	double a[5];
	double A[5];
	FILE*output;
	output=fopen("o3decompose.dat","w");
	int i,j,l;
	int m;
	double k;
	double u1,u2,ktu;
	int w=0;
	double t=0;
	double dt=0;
	printf("enter the amount of zno\n");
	scanf("%f",&amountzno);
	printf("#MC-step	times			[o3]uM");
	zno=amountzno*10000000/81380; //aM for zno
while(w>-1){

	u1=(double)rand()/(RAND_MAX);
	u2=(double)rand()/(RAND_MAX);
	ktu=ktsum*u1;
	dt=log(1/u2)/(ktsum*0.0000001);
	t=t+dt;
//	printf("%f",log(1/u2)/(ktsum*0.0000001));
a[0]=kt1;a[1]=kt2;a[2]=kt3;a[3]=kt4;a[4]=kt5;a[5]=kt6;
bubblesort(a);

A[0]=a[0];
for(j=1;j<5;j++)
{
	A[j]=A[j-1]+a[j];
}
	m=binarysearch(A,ktu);
if(a[m]==kt1)
{
	o3aq-=1;
	zno-=1;
	o3ad+=1;
}
else if(a[m]==kt2)
	{
		o3ad-=1;
		zno+=1;
		o3ad+=1;
	}
else if(a[m]==kt3)
{
	o3ad-=1;
	odot+=1;
	o2aq+=1;
}
else if(a[m]==kt4)
{
	odot-=1;
	o2aq-=1;
	o3ad+=1;
}
else if(a[m]==kt5)
{
	odot-=1;
	h2o-=1;
	h2o2+=1;	
}
else if(a[m]==kt6)
{
	h2o2-=1;
	hodot+=1;
	zno+=1;
}
w++;
if(w%100==0&&w!=0)
{
	printf("\n");
printf("w=%d",w);
printf("		%6f",t);
if(o3aq>0)
{printf("		%f\n",o3aq/10);}
else{printf("		%f\n",0);}


fprintf(output,"\n");
fprintf(output,"w=%d",w);
fprintf(output,"		%6f",t);
if(o3aq>0)
{fprintf(output,"		%f\n",o3aq/10);}
else{fprintf(output,"		%f\n",0);}


}
if(t>1800)
{
	break;
}
}
	fclose(output);
	return 0;
}

void bubblesort(double p[])
{
	//int data[SIZE];
	double tem;
	int i,r;
	for(r=0;r<4;r++){
	for(i=0;i<4;i++){
		if(p[i]>p[i+1])
		{
		tem=p[i];
		p[i]=p[i+1];
		p[i+1]=tem;
		}
	}	
}
}
int binarysearch(double b[],double c)//c=ktu
{
	int L=0,U=4,M=(L+U)/2;
	int result;
	while(U>=L){
	if(b[M-1]<c&&b[M]>c){
		result=M;
		break;
	}
	else if(b[M]>c&&b[M-1]>c)
	{
		U=M-1;
	}
	else if(b[M]<c&&b[M-1]<c)
	{
		L=M+1;
	}
	M=(L+U)/2;
}
return result;
}


