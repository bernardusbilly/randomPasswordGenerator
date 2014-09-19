#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <math.h>
#include <string.h>

void wait(long milliseconds);
void delay(int maxRandom);
void securityBlock(void);
void checkTime(int x, int y, int z);
void checkMax(int absxmax, int absymax);
void checkCode(char arrx[], char arry[]);
void setCode(char arrx[], char arry[]);
void shiftCode(char arrx[], char arry[], int absxmax, int absymax);
void unimportantLoop(char arrx[], char arry[]);
int string_length(char str[]);
void generateCode(char arrx[], char arry[]);


int main(void)
{
	/*key password
	a b c 1 d e f 2 g h i 3 j k l 4 m n
	o 5 p q r 6 s t u 7 v w x 8 y z 9 0
	*/


	//local variable
	int x, y, z;
	int xmax, ymax;
	int absxmax, absymax;

	char arrx[18];
	char arry[18];
	char temp[100];
	char* password;

	//securityBlock
	securityBlock();

	//set key
	setCode(arrx, arry);

	time_t t; //declare variable for time
	time(&t); //get time
	struct tm*now=localtime(&t);

	x=now->tm_mday;
	y=now->tm_hour;
	z=now->tm_min;

	//checkTime
	//checkTime(x, y, z);

	//highest point of parabola
	xmax=-y/(2*x);
	ymax=(x*xmax*xmax)+(y*xmax)+z;

	//taking the absolute value
	absxmax=abs(xmax);
	absymax=abs(ymax);

	//checkMax
	//checkMax(absxmax, absymax);

	//checkCode
	//checkCode(arrx, arry);

	//shift the code
	shiftCode(arrx, arry, absxmax, absymax);

	//checkCode
	//checkCode(arrx, arry);

	//unimportantLoop
	unimportantLoop(arrx, arry);

	//generateCode
	generateCode(arrx, arry);

	//last stop
	system("pause");
}

//http://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1045967760&id=1043284392
void wait(long milliseconds)
{
	long timeout = clock() + milliseconds;
	while( clock() < timeout ) continue;
}

void delay(int maxRandom)
{
	for(int i=0; i<(2+rand()%maxRandom); i++)
	{
		wait((rand()%maxRandom)*100);
		printf(".\n");
	}
}

void securityBlock(void)
{
	//local variable - later change to an inputted data from notepad
	char password[20];
	char keyPass[20]="charlie631";
	int n=3;

	printf("Please input the password: "); scanf("%s",&password);

	srand(time(NULL));

	while(strcmp(password, keyPass)!=0)
	{
		delay(10);

		if(n==0)
		{
			printf("\nProgram Terminated!\n");
			for(int i=5; i>0; i--)
			{	
				printf("%d\n", i);
				wait(1000);
			}
			exit(100);
		}

		printf("\nAccess Denied! ");
		printf("%d more times to try\n", n);
		n--;

		printf("Please input the password: "); scanf("%s",&password);
	}
}

void checkTime(int x, int y, int z)
{
	printf("day   : %d\n", x);
	printf("hour  : %d\n", y);
	printf("minute: %d\n\n", z);
}

void checkMax(int absxmax, int absymax)
{
	printf("Xmax: %d\n", absxmax);
	printf("Ymax: %d\n", absymax);
	printf("\n");
}

void checkCode(char arrx[], char arry[])
{
	for(int i=0; i<18; i++)
	{
		printf("%c", arrx[i]);
	}

	printf("\n");

	for(int i=0; i<18; i++)
	{
		printf("%c", arry[i]);
	}

	printf("\n\n");
}

void setCode(char arrx[], char arry[])
{
	//set x
	arrx[0]='a'; 
	arrx[1]='b';
	arrx[2]='c';
	arrx[3]='1';
	arrx[4]='d';
	arrx[5]='e';
	arrx[6]='f';
	arrx[7]='2';
	arrx[8]='g';
	arrx[9]='h';
	arrx[10]='i';
	arrx[11]='3';
	arrx[12]='j';
	arrx[13]='k';
	arrx[14]='l';
	arrx[15]='4';
	arrx[16]='m';
	arrx[17]='n';

	//set y
	arry[0]='o';
	arry[1]='5';
	arry[2]='p';
	arry[3]='q';
	arry[4]='r';
	arry[5]='6';
	arry[6]='s';
	arry[7]='t';
	arry[8]='u';
	arry[9]='7';
	arry[10]='v';
	arry[11]='w';
	arry[12]='x';
	arry[13]='8';
	arry[14]='y';
	arry[15]='z';
	arry[16]='9';
	arry[17]='0';
}

void shiftCode(char arrx[], char arry[], int absxmax, int absymax)
{
	//local variable
	char temp;

	//shift for x
	for(int i=0; i<absxmax; i++)
	{
		temp=arrx[0];
		
		for(int j=0; j<18-1; j++)
		{
			arrx[j]=arrx[j+1];
		}

		arrx[17]=temp;
	}

	//shift for y
	for(int i=0; i<absymax; i++)
	{
		temp=arry[0];
		
		for(int j=0; j<18-1; j++)
		{
			arry[j]=arry[j+1];
		}

		arry[17]=temp;
	}
}

void unimportantLoop(char arrx[], char arry[])
{
	delay(15);
	for(int i=0; i<(2000+(rand()%100)); i++)
	{
		wait(1);
		for(int i=0; i<rand()%18; i++)
		{
			printf("%c%d", arrx[i],rand()%10);
			for(int j=0; j<rand()%5; j++)
			{printf(" ");}
		}
		
		wait(1);
		for(int i=0; i<rand()%18; i++)
		{
			printf("%c%d", arry[i],rand()%10);
			for(int j=0; j<rand()%5; j++)
			{printf(" ");}
		}
	}
	wait(2000);
	system("cls");
}

//http://www.phanderson.com/C/str_len.html
int string_length(char str[])
{
   int i;
   for(i=0; i<80; i++)
   {
	 if(str[i]=='\0')
	 {
	    return(i);
	 }
   }
}

void generateCode(char arrx[], char arry[])
{
	char temp[30];
	char* password;
	char* genPassword;

	printf("Please input the original password: "); scanf("%s", temp);

	password = (char*) malloc (sizeof(temp));
	genPassword = (char*) malloc (sizeof(temp));

	strcpy(password, temp);
	strcpy(genPassword, temp);
	
	//for(int i=0; i<string_length(password); i++) {printf("%c\n", password[i]);}

	for(int i=0; i<string_length(password); i++)
	{
		for(int j=0; j<18; j++)
		{
			if(password[i]==arrx[j])
			{
				genPassword[i]=arry[j]; //printf("copy %c to %c\n", arrx[j], arry[j]);
			}
			else if(password[i]==arry[j])
			{
				genPassword[i]=arrx[j]; //printf("copy %c to %c\n", arry[j], arrx[j]);
			}
		}
	}

	printf("Generated password: %s \n", genPassword);

	//checkCode(arrx, arry);
}