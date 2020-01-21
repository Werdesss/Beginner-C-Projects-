
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct scoreboard{
	char team_n[50];
	int G, WH, LH, WA, LA, TW, TL, TP;
};
int Load_Scoreboard_Table(char file_n[], struct scoreboard **p){
	FILE *file;
	file=fopen(file_n,"r");
	int size,x;
	if (file==NULL){		//Checking file 
		printf("The file was not succesfully opened");
		exit(1);
	}
	else 
		printf("Score records file has been successully loaded!");
	while ((x=fgetc(file))!=EOF){	
		if (*p==NULL)
			*p=malloc(sizeof(struct scoreboard));	//to allocate the TW, TL and TP
		fscanf(file, "%s %d %d %d %d %d",(*p)[size].team_n, &(*p)[size].G,&(*p)[size].WH, &(*p)[size].LH, &(*p)[size].WA, &(*p)[size].LA);
		(*p)[size].TW = (*p)[size].WH + (*p)[size].WA;
		(*p)[size].TL = (*p)[size].LH + (*p)[size].LA;
		(*p)[size].TP = 2*(*p)[size].TW + (*p)[size].TL;
		size++;
	}
	return size;
}
void Display_Scoreboard_Table(struct scoreboard *p, int size){
	int i=0;
	printf("Following records have been loaded:\n");
	printf("Team 		G	WH	LH	WA	LA	Win	Lost Points\n");
	for (;i<size;i++){
		printf("%s 		%d	%d	%d	%d	%d	%d	%d	%d\n", p[i].team_n, p[i].G, p[i].WH, p[i].LH, p[i].WA, p[i].LA, p[i].TW, p[i].TL, p[i].TP);
	}
}
int Search(struct scoreboard *p, int size, char team_n[]){
	int i=0;
	for (;i<size;i++){
		if (strcmp(team_n,p[i].team_n)==0)		//equal or not 
			return i;
	}
	return -1;
}
void Interactive_board(struct scoreboard *p,int size, char sort){
	int i,j;
	struct scoreboard temp;
	if (sort=='G'){
		for (i=0;i<size;i++){
			for (j=0;j<size-i;j++){
				if ((p[j-1].G)>(p[j].G))
					temp=p[j];								// Bubble sort
					p[j]=p[j-1];
					p[j-1]=temp;
			}
		}
	}
	else{
		for (i=0;i<size;i++){
			for (j=0;j<size-i;j++){
				if ((p[j-1].TP)>(p[j].TP))					// Bubble sort
					temp=p[j];
					p[j]=p[j-1];
					p[j-1]=temp;
			}
		}
	}
	Display_Scoreboard_Table(p,size);
}
int main(){
	struct scoreboard *p=NULL;
	char file_n[50],team_n[50],sort;
	int size,control;
	printf("Please enter the filename:");
	scanf("%s",&file_n);
	size=Load_Scoreboard_Table(file_n,&p);
	Display_Scoreboard_Table(p,size);
	do{
		printf("Enter the name of the team (Exit - X, Sort - S):");
		scanf("%s", team_n);
		if(strcmp(team_n, "S") == 0){
			printf("Sort by (G: games, P: points):");
			scanf("%s",&sort);
			Interactive_board(p,size,sort);
		}
		else if (strcmp(team_n,"X")==0){
			printf("Bye!!");
			exit(1);
		}
		else{
			int s=Search(p, size, team_n);
			if(s==-1) 
				printf("That team is unknown! Please try again!\n");
			else 
				printf("%s has %d win, %d lost and total of %d points!\n", p[s].team_n, p[s].TW, p[s].TL, p[s].TP);
		}
		printf("Enter the name of the team (Exit - X, Sort - S):");
		scanf("%s", team_n);
	}while (strcmp(team_n,"X")!=0);
	return 0;
}

