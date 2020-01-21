#include<stdio.h>
#include<math.h>
int main(){
	int control,base,b_input,A,B,C_IN,SUM,C_OUT,remainder,i=1,binary,AXB,CAAXB,AB,changer;
	char hexadecimal;
	printf("Welcome to Full Adder!\n");
	printf("(1) Compute and display the output\n");
	printf("(2) Quit\n");
	printf("You choose:");
	scanf("%d",&control);
	printf("You have chosen number:%d",control);
	if (control==2)
		printf("\nByee!!");
	
	// CHECKÝNG CONTROL
		
	while(control!=1 && control!=2){
		printf("\nInvalid number.Please try again!\n");
		printf("\n(1) Compute and display the output\n");
		printf("(2) Quit\n");
		printf("You choose:");
		scanf("%d",&control);
		printf("\nYou have chosen number:%d",control);
		if (control==2)
			printf("\nByee!!");
	}
	while (control==1){
		printf("\nWhich base will you use to enter data lines (base 16/8/2)?:");
		scanf("%d",&base);
		while (base!=16 && base!=8 && base!=2){
			printf("Invalid number.Please try again!\n");
			printf("Which base will you use to enter data lines (base 16/8/2)?:");
			scanf("%d",&base);
		}
		
	
	//     BASE 2
	
	
		if (base==2){
			printf("Please enter input:");
			scanf("%d",&b_input);
			while (b_input!=0 && b_input!=1 && b_input!=10 && b_input!=11 && b_input!=100 && b_input!=101 && b_input!=110 && b_input!=111){
				printf("Invalid number. Please try again!");
				printf("\nPlease enter input:");
				scanf("%d",&b_input);
			}
			
			//		DEFINING A B and C_IN
			
			A=b_input%10;
			B=(b_input/10)%10;
			C_IN=(b_input/100)%10;
			
			
			//		SUM
			
			
			//		A XOR B
			
			if (A==B)
				AXB=0;
			else
				AXB=1;
				
			//		C_IN XOR A XOR B
			
			if (C_IN==AXB)
				SUM=0;
			else
				SUM=1;
			
				
			//		C_OUT
			
			
			//		C_IN AND A XOR B
			
			if (C_IN==1){
				if (AXB==1)
					CAAXB=1;
			}
			else
				CAAXB=0;
			
			//		A AND B
			
			if (A==1){
				if (B==1)
					AB=1;
			}
			else
				AB=0;
			
			//		(A AND B) OR (C_IN AND (A XOR B))
			
			if (AB==0){
				if (CAAXB==0)
					C_OUT=0;
			}
			else
				C_OUT=1;
			
			// PRINT
			
			printf("Sum is %d C_out is %d",SUM,C_OUT);
			
		}
	
	
	//     BASE 8
	
	
		else if (base==8){
			printf("Please enter input:");
			scanf("%d",&b_input);
			while (b_input>7 || b_input<0){
				printf("Octal %d cannot be represented with 3 bits! Please try again!",b_input);
				printf("\nPlease enter input:");
				scanf("%d",&b_input);
			}
			
			//		CONVERTÝNG DECÝMAL TO BÝNARY
			
			binary=0;
			remainder=0;
			i=1;
			while(b_input>0){
				remainder=b_input%2;
				binary=binary+(i*remainder);
				i*=10;
				b_input/=2;	
			}
			
			//		DEFINING A B and C_IN
			
			A=binary%10;
			B=(binary/10)%10;
			C_IN=(binary/100)%10;
			
			
			//		SUM
			
			
			//		A XOR B
			
			if (A==B)
				AXB=0;
			else
				AXB=1;
				
			//		C_IN XOR A XOR B
			
			if (C_IN==AXB)
				SUM=0;
			else
				SUM=1;
			
				
			//		C_OUT
			
			
			//		C_IN AND A XOR B
			
			if (C_IN==1){
				if (AXB==1)
					CAAXB=1;
			}
			else
				CAAXB=0;
			
			//		A AND B
			
			if (A==1){
				if (B==1)
					AB=1;
			}
			else
				AB=0;
			
			//		(A AND B) OR (C_IN AND (A XOR B))
			
			if (AB==0){
				if (CAAXB==0)
					C_OUT=0;
			}
			else
				C_OUT=1;
			
			// PRINT
			
			printf("Sum is %d C_out is %d",SUM,C_OUT);
			
			
		}
	
	
	//     BASE 16
	
	
		else{
			printf("Please enter input:");
			fflush(stdin);
			scanf("%c",&hexadecimal);
			while (hexadecimal!='0' && hexadecimal!='1' && hexadecimal!='2' && hexadecimal!='3' && hexadecimal!='4' && hexadecimal!='5' && hexadecimal!='6' && hexadecimal!='7'){
				while (hexadecimal!='0' && hexadecimal!='1' && hexadecimal!='2' && hexadecimal!='3' && hexadecimal!='4' && hexadecimal!='5' && hexadecimal!='6' && hexadecimal!='7' && hexadecimal!='8' && hexadecimal!='9' && hexadecimal!='A' && hexadecimal!='B' && hexadecimal!='C' && hexadecimal!='D' && hexadecimal!='E' && hexadecimal!='F'){
					printf("Invalid char.Please try again!\n");
					printf("Please enter input:");
					fflush(stdin);
					scanf("%c",&hexadecimal);
				}
				if (hexadecimal!='0' && hexadecimal!='1' && hexadecimal!='2' && hexadecimal!='3' && hexadecimal!='4' && hexadecimal!='5' && hexadecimal!='6' && hexadecimal!='7'){
					printf("Hexadecimal %c can not be represented with 3 bits!Please try again!",hexadecimal);
					printf("\nPlease enter input:");
					fflush(stdin);
					scanf("%c",&hexadecimal);
				}	
			}
			
			//		CONVERTÝNG CHAR TO ÝNT
			
			switch(hexadecimal){
				case '0':changer=0;break;
				case '1':changer=1;break;
				case '2':changer=2;break;
				case '3':changer=3;break;
				case '4':changer=4;break;
				case '5':changer=5;break;
				case '6':changer=6;break;
				case '7':changer=7;break;
			}
			
			//		CONVERTÝNG DECÝMAL TO BÝNARY
			
			binary=0;
			remainder=0;
			i=1;
			while(changer>0){
				remainder=changer%2;
				binary=binary+(i*remainder);
				i*=10;
				changer/=2;	
			}
			
			//		DEFINING A B and C_IN
			
			A=binary%10;
			B=(binary/10)%10;
			C_IN=(binary/100)%10;
			
			
			//		SUM
			
			
			//		A XOR B
			
			if (A==B)
				AXB=0;
			else
				AXB=1;
				
			//		C_IN XOR A XOR B
			
			if (C_IN==AXB)
				SUM=0;
			else
				SUM=1;
			
				
			//		C_OUT
			
			
			//		C_IN AND A XOR B
			
			if (C_IN==1){
				if (AXB==1)
					CAAXB=1;
			}
			else
				CAAXB=0;
			
			//		A AND B
			
			if (A==1){
				if (B==1)
					AB=1;
			}
			else
				AB=0;
			
			//		(A AND B) OR (C_IN AND (A XOR B))
			
			if (AB==0){
				if (CAAXB==0)
					C_OUT=0;
			}
			else
				C_OUT=1;
			
			// PRINT
			
			printf("Sum is %d C_out is %d",SUM,C_OUT);	
		}
		
		// LOOP
		
		printf("\n\n\nWelcome to Full Adder!\n");
		printf("(1) Compute and display the output\n");
		printf("(2) Quit\n");
		printf("You choose:");
		scanf("%d",&control);
		printf("You have chosen number:%d",control);
		if (control==2)
			printf("\nByee!!");
			
		// CHECKÝNG CONTROL
		
		while(control!=1 && control!=2){
			printf("\nInvalid number.Please try again!\n");
			printf("\n(1) Compute and display the output\n");
			printf("(2) Quit\n");
			printf("You choose:");
			scanf("%d",&control);
			printf("\nYou have chosen number:%d",control);
			if (control==2)
				printf("\nByee!!");
		}
	}
	return 0;
}
