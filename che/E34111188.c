#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(NULL)); //time null is outside???
	int percent;
	int a=5;
	int t=1,r=1; // position
	char tur='T';
	char rab='H';
	printf("Bang!!!\n");
	printf("AND THEY ARE OFF!!!\n");
	while(a>0) //µL­­loop 
	{
	int Tpercent=rand()%10+1;
	int Rpercent=rand()&10+1;
	if(Tpercent>=1&&Tpercent<=5) //turtle fast plod
	{
	t=t+3;
	}	
	else if(Tpercent>=6&&Tpercent<=7) //turtle slip
	{
		t=t-6;
	}
	else if(Tpercent>=8&&Tpercent<=10)//turtle slow plod
	{
		t+=1;
	}
	
	
	 if(Rpercent>=3&&Rpercent<=4)//hare big hop
	{
		r=r+9;
	}
	else if(Rpercent==5)//hare big slip
	{
		r-=12;
	}
	else if(Rpercent>=6&&Rpercent<=8)//hare small hop
	{
		r+=1;
	}
	else if(Rpercent>=9&&Rpercent<=10)//hare small slip
	{
		r-=2;
	}
	
	if(t<1)
	{
		t=1;
	}
	else if(r<1) //left to position 0
	{
		r=1;
	}
	if(t==r)
	{
		printf("%*s\n",t-1,"OUCH!!!");
	}
	
	
	
	if(t>=70&&r>=70)
	{
		printf("Its a tie!!"); //priority of TIE
		break;
	}
	else if(t>=70)
	{
		printf("TORTOISE WINS");//turtle wins or hare wins
		break;
	}
	else if(r>=70)
	{
		printf("hare WINS");
		break;
	}
	
	
	//printf("r=%d t=%d\n",r,t);
	
	
	if(r>t)   				//print space
	{
	printf("%*c",t-1,tur);
	printf("%*c\n",r-t,rab);  
	}
	if(r<t)
	{
	printf("%*c",r-1,rab);
	printf("%*c\n",t-r,tur);  
	}
		
	
	}

	return 0;
}



