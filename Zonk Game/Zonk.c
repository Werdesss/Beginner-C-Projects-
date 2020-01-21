// YUSUF MERT KÖSEOÐLU	2152072		SECTION 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int roll_a_dice(void);
int play_user(void);
int play_computer(void);
int computer_strategy_decider(int,int,int,int,int,int);
void scoresheet(int,int,int,int);
int main(){
	int round,dice,i,dc,dp,c_point=0,p_point=0;
	char YN;
	srand(time(NULL));
	printf("Welcome to the Zonk game.\nHow many rounds would you like to play?");
	scanf("%d",&round);
	printf("OK, lets get started!\n");
	dc=roll_a_dice(); // Computer dice
	printf("I have rolled the dice and got %d!",dc);
	printf("\nAre you ready to Zonk! Shall I roll the dice for you (Y/N)?");
	fflush(stdin);
	scanf("%c",&YN);
	if (YN=='Y'){
		dp=roll_a_dice();
		printf("I have rolled the dice for you and you got %d!\n",dp);	// Player dice
		for (i=1;i<=round;i++){   // The number of rounds they will play
			if (dc>dp){
				c_point=play_computer();
				p_point=play_user();
				scoresheet(p_point,c_point,i,round); // i and the round are to decide who is the winner in total
			}
			else if (dp>dc){
				p_point=play_user();
				c_point=play_computer();
				scoresheet(p_point,c_point,i,round);	
			}
			while (dp==dc){ // if dices are equal
				printf("Again!!!\n");
				dc=roll_a_dice();
				printf("I have rolled the dice and got %d!\n",dc);
				dp=roll_a_dice();
				printf("I have rolled the dice for you and you got %d!\n",dp);
				i--;
			}
		}
	}
	else if (YN=='N')
		printf("Bye!!!!");
	else
		printf("Invalid Input");
	return 0;
}



int roll_a_dice(void){
	return ((rand()%6)+1);
}



int play_user(void){
	char YN;
	int d1,d2,d3,d4,d5,d6,point,c1,c2,c3;
	printf("Your Turn:\n===========================================================\n");
	printf("Are you ready to Zonk! Shall I roll them for you (Y/N)?");
	fflush(stdin);
	scanf("%c",&YN);
	d1=roll_a_dice();
	d2=roll_a_dice();
	d3=roll_a_dice();
	d4=roll_a_dice();
	d5=roll_a_dice();
	d6=roll_a_dice();
	if (YN=='Y'){
		printf("You got [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d [Dice 4]: %d [Dice 5]: %d [Dice 6]: %d",d1,d2,d3,d4,d5,d6);
		printf("\nDo you want to continue (Y/N)?");
		fflush(stdin);
		scanf("%c",&YN);
		if (YN=='Y'){
			printf("Which ones you want to roll again?"); // Couldn't make the 3's rules
			scanf("%d %d %d",&c1,&c2,&c3);
			if ((d1==1 || d2==1 || d3==1 || d4==1 || d5==1 || d6==1) && (d1==2 || d2==2 || d3==2 || d4==2 || d5==2 || d6==2) && (d1==3 || d2==3 || d3==3 || d4==3 || d5==3 || d6==3) && (d1==4 || d2==4 || d3==4 || d4==4 || d5==4 || d6==4) && (d1==5 || d2==5 || d3==5 || d4==5 || d5==5 || d6==5) && (d1==6 || d2==6 || d3==6 || d4==6 || d5==6 || d6==6))
				point=1500;
			else if ((d1==1 && d2==1 && d3==1 && d4==1 && d5==1 && d6==1) || (d1==2 && d2==2 && d3==2 && d4==2 && d5==2 && d6==2) || (d1==3 && d2==3 && d3==3 && d4==3 && d5==3 && d6==3) || (d1==4 && d2==4 && d3==4 && d4==4 && d5==4 && d6==4) || (d1==5 && d2==5 && d3==5 && d4==5 && d5==5 && d6==5) || (d1==6 && d2==6 && d3==6 && d4==6 && d5==6 && d6==6))
				point=1000;
			else if (d1==1 || d2==1 || d3==1 || d4==1 || d5==1 || d6==1 )
				point=100;
			else if (d1==5 || d2==5 || d3==5 || d4==5 || d5==5 || d6==5 )
				point=50;
			else{
				printf("ZONK!!!!");
				point=0;
			}
			if (point==0)
				printf("Your score:Z\n");
			else
				printf("Your score:%d\n",point);
		}
		else if (YN=='N'){
			if ((d1==1 || d2==1 || d3==1 || d4==1 || d5==1 || d6==1) && (d1==2 || d2==2 || d3==2 || d4==2 || d5==2 || d6==2) && (d1==3 || d2==3 || d3==3 || d4==3 || d5==3 || d6==3) && (d1==4 || d2==4 || d3==4 || d4==4 || d5==4 || d6==4) && (d1==5 || d2==5 || d3==5 || d4==5 || d5==5 || d6==5) && (d1==6 || d2==6 || d3==6 || d4==6 || d5==6 || d6==6))
				point=1500;
			else if ((d1==1 && d2==1 && d3==1 && d4==1 && d5==1 && d6==1) || (d1==2 && d2==2 && d3==2 && d4==2 && d5==2 && d6==2) || (d1==3 && d2==3 && d3==3 && d4==3 && d5==3 && d6==3) || (d1==4 && d2==4 && d3==4 && d4==4 && d5==4 && d6==4) || (d1==5 && d2==5 && d3==5 && d4==5 && d5==5 && d6==5) || (d1==6 && d2==6 && d3==6 && d4==6 && d5==6 && d6==6))
				point=1000;
			else if (d1==1 || d2==1 || d3==1 || d4==1 || d5==1 || d6==1 )
				point=100;
			else if (d1==5 || d2==5 || d3==5 || d4==5 || d5==5 || d6==5 )
				point=50;
			else{
				printf("ZONK!!!!");
				point=0;
			}
			if (point==0)
				printf("Your score:Z\n");
			else
				printf("Your score:%d\n",point);
		}
		else
			printf("Invalid Input\n");
		return point;	
		
	}
	else if (YN=='N')
		printf("Bye!!!!\n");
	else
		printf("Invalid Input\n");
}



int play_computer(void){
	int d1,d2,d3,d4,d5,d6,point;
	printf("My Turn:\n===========================================================\n");
	d1=roll_a_dice();
	d2=roll_a_dice();
	d3=roll_a_dice();
	d4=roll_a_dice();
	d5=roll_a_dice();
	d6=roll_a_dice();
	printf("I got [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d [Dice 4]: %d [Dice 5]: %d [Dice 6]: %d",d1,d2,d3,d4,d5,d6);
	point=computer_strategy_decider(d1,d2,d3,d4,d5,d6);
	return point;
}



int computer_strategy_decider(int d1,int d2,int d3,int d4,int d5,int d6){
	int point;
	if ((d1==1 || d2==1 || d3==1 || d4==1 || d5==1 || d6==1) && (d1==2 || d2==2 || d3==2 || d4==2 || d5==2 || d6==2) && (d1==3 || d2==3 || d3==3 || d4==3 || d5==3 || d6==3) && (d1==4 || d2==4 || d3==4 || d4==4 || d5==4 || d6==4) && (d1==5 || d2==5 || d3==5 || d4==5 || d5==5 || d6==5) && (d1==6 || d2==6 || d3==6 || d4==6 || d5==6 || d6==6))
		point=1500;
		else if ((d1==1 && d2==1 && d3==1 && d4==1 && d5==1 && d6==1) || (d1==2 && d2==2 && d3==2 && d4==2 && d5==2 && d6==2) || (d1==3 && d2==3 && d3==3 && d4==3 && d5==3 && d6==3) || (d1==4 && d2==4 && d3==4 && d4==4 && d5==4 && d6==4) || (d1==5 && d2==5 && d3==5 && d4==5 && d5==5 && d6==5) || (d1==6 && d2==6 && d3==6 && d4==6 && d5==6 && d6==6))
			point=1000;
		else if (d1==1 || d2==1 || d3==1 || d4==1 || d5==1 || d6==1 )
			point=100;
		else if (d1==5 || d2==5 || d3==5 || d4==5 || d5==5 || d6==5 )
			point=50;
	else{
		printf("ZONK!!!!");
		point=0;
	}
	if (point==0)
		printf("My score:Z\n");
	else
		printf("\nMy score:%d\n",point);
	return point;			
}



void scoresheet(int p_point,int c_point,int i,int round){
	static int t_p_points,t_c_points;
	t_p_points+=p_point;
	t_c_points+=c_point;
	printf("\nOur scoresheet:\n=====================\nMy score	Your score\n%d		%d\n\n",t_c_points,t_p_points);
	if (round==i){
		if (t_p_points>t_c_points)
			printf("\nYOU ARE THE WINNER!");
		else if (t_p_points<t_c_points)
			printf("\nI AM THE WINNER!");
		else 
			printf("\nDRAW!");
	}
}

