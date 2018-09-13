// CECS 525	Matthew Vierling	copyright (c)
// C/assembler calculator


#include <stdio.h>
//#include <stdlib.h>

int cadd(int, int);
int csub(int, int);
int cmult(int, int);
int cdiv(int, int);

extern int  remainder;

void main(void){

	int exit = 1;
	int select;

	int a;
	int b;
	char ch;

	while(exit == 1){

		printf("********************************\n");
		printf("*    C/assembler Calculator    *\n");
		printf("********************************\n");
		printf("* 1: add                       *\n");
		printf("* 2: subtract                  *\n");
		printf("* 3: multiply                  *\n");
		printf("* 4: divide                    *\n");
		printf("* 9: exit		       *\n");
		printf("*			       *\n");
		printf("********************************\n");
		scanf("%d", &select);

		switch(select){
			case 1:
				printf("enter two numbers to add seperated by comma.\n");
				scanf("%d,%d", &a, &b);
				printf("add result: %d\n\n", cadd(a, b));
				break;
			case 2:
				printf("enter two numbers in form number1-number2 as number1,number2.\n");
				scanf("%d,%d", &a, &b);
				printf("sub relust: %d\n\n", csub(a,b));
				break;
			case 3:
				printf("enter two numbers in form number1*number2 as number1,number2.\n");
				scanf("%d,%d", &a, &b);
				printf("multiplication result: %d\n\n", cmult(a,b));
				break;
			case 4:
				printf("enter two number in form number1/number2 as number1,number2.\n");
				scanf("%d,%d", &a, &b);
				printf("division result is %d r %d\n\n", cdiv(a,b), remainder);
				break;
			case 9:
				exit = 0;
				break;
			default:
				exit = 0;
		}//switch


		if(exit != 0){
			printf("press enter to continue.\n");
			scanf("%c", &ch);
			scanf("%c", &ch);
			//system("clear");
		}

	}//while

	printf("exiting now.\n");

	return;

}//main

