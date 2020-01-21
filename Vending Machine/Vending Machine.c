

#include<stdio.h>
void ShowMenu(void);
void MakeSelection();
void ReturnChange(float *,int []);
int DisplayErrorMessage(int,float,int,int []);
void Maintenance(int [],int []);
int main(){
	ShowMenu();
	MakeSelection();
	return 0;
}

void ShowMenu(void){
	printf("1. Water 1.00 TL\n2. Coke 1.20 TL\n3. Diet Coke 1.20 TL\n4. Iced Tea 1.00 TL\n5. Swiss Chocolate 1.50 TL\n6. Candy 0.95 TL\n7. Chips 2.50 TL\n8. Bubble Gum 1.50 TL\n9. Turkish Delight 2.00 TL");	
}

void MakeSelection(){
	int items[9]={10,10,10,10,10,10,10,10,10},total_money[5]={10,10,10,10,10},selection=1,error,password,error_item;// total money = 1 tl ,0.5 tl , .....
	float *deposit_p,deposit,deposit_m;
	while (selection!=-1){				// Loop until -1
		printf("\n\nEnter amount of money:");
		scanf("%f",&deposit);
		deposit_p=&deposit;
		printf("Select an item:");
		scanf("%d",&selection);
		switch(selection){
			case 1:items[0]--;*deposit_p=*deposit_p-1.0;break;
			case 2:items[1]--;*deposit_p=*deposit_p-1.2;break;
			case 3:items[2]--;*deposit_p=*deposit_p-1.2;break;
			case 4:items[3]--;*deposit_p=*deposit_p-1.0;break;
			case 5:items[4]--;*deposit_p=*deposit_p-1.5;break;
			case 6:items[5]--;*deposit_p=*deposit_p-0.95;break;
			case 7:items[6]--;*deposit_p=*deposit_p-2.5;break;
			case 8:items[7]--;*deposit_p=*deposit_p-1.5;break;
			case 9:items[8]--;*deposit_p=*deposit_p-2.0;break; 
		}
		deposit_m=*deposit_p;		// it doesnt work with direct array for error function so I did this	
		if (selection==-1){
			printf("Password:");
			scanf("%d",&password);
			if (password==123456){				//Password
				Maintenance(items,total_money);
			}
		}
		else{
			error_item=items[selection-1];	// it doesnt work with direct array for error function so I did this
			error=DisplayErrorMessage(1,1,error_item,total_money); 	// 1's and 0's for not give other errors
			if (error!=0){
				error=DisplayErrorMessage(selection,0,1,0); 	// 1's and 0's for not give other errors
				if (error!=0){
					error=DisplayErrorMessage(1,deposit_m,1,0);	// 1's and 0's for not give other errors
					if (error!=0){
						ReturnChange(deposit_p,total_money);
					}
					else{
						switch(selection){		//	even if money is insufficent it proceeds but this way it takes back what it does
							case 1:items[0]++;break;
							case 2:items[1]++;break;
							case 3:items[2]++;break;
							case 4:items[3]++;break;
							case 5:items[4]++;break;
							case 6:items[5]++;break;
							case 7:items[6]++;break;
							case 8:items[7]++;break;
							case 9:items[8]++;break;
						}
					}
				}	
			}
		}
	}
}

void ReturnChange(float *deposit,int money[]){
	int i;
	float return_cash,deposit_saver;
	return_cash=*deposit;
	while (return_cash>=1 && money[0]>0){		// && money[] are for to continue to use other moneys(1,0.5,...)
		return_cash=return_cash-1;
		money[0]--;
	}
	while (return_cash>=0.5 && money[1]>0){
		return_cash=return_cash-0.5;
		money[1]--;
	}
	while (return_cash>=0.2 && money[2]>0){
		return_cash=return_cash-0.2;
		money[2]--;
	}
	while (return_cash>=0.1 && money[3]>0){
		return_cash=return_cash-0.1;
		money[3]--;
	}
	while (return_cash>=0.01 && money[4]>0){
		return_cash=return_cash-0.01;
		money[4]--;
	}
	printf("Get your item! Change: %.2f TL\n",*deposit);
}

int DisplayErrorMessage(int selection,float deposit,int item,int money[]){
	int left_money;
 	//it again doesnt work without printf(?) if money and item's money equals each other
	if (selection==-1)
		return 1;
	else if (selection>9 || selection<1){
		printf("Error! Invalid selection!");
		return 0;
	}
	if (deposit<0.0){
		printf("Error! Insufficient amount of money! Take your money back!");
		return 0;
	}
	left_money=money[0]*1+money[1]*0.5+money[2]*0.2+money[3]*0.1+money[4]*0.01;
	if(deposit>left_money)																						// I dont know why but it gives a run time error
		printf("Error! Insufficient amount of change in vending machine! Take your money back!");
	else if (money[0]>0 && money[1]>0 && money[2]>0 && money[3]>0 && money[4]>0)
		printf("Error! Insufficient amount of change in vending machine! Take your money back!");
	if(item<=0){
		printf("Error! Insufficient amount of item! Take your money back!");
		return 0;
	}

}

void Maintenance(int items[],int money[]){
	float total=0;
	int i;
	printf("\nDAILY REPORT\n\nNumber of items left:\n1. Water: %d TL\n2. Coke: %d TL\n3. Diet Coke: %d TL\n4. Iced Tea: %d TL\n5. Swiss Chocolate: %d TL\n6. Candy: %d TL\n7. Chips: %d TL\n8. Bubble Gum: %d TL\n9. Turkish Delight: %d TL",items[0],items[1],items[2],items[3],items[4],items[5],items[6],items[7],items[8]);
	printf("\n\nNumber of coins left:\n1 TL: %d\n0.5 TL: %d\n0.2 TL: %d\n0.1 TL: %d\n0.01 TL: %d",money[0],money[1],money[2],money[3],money[4]);
	total=(10-items[0])*1+(10-items[1])*1.2+(10-items[2])*1.2+(10-items[3])*1+(10-items[4])*1.5+(10-items[5])*0.95+(10-items[6])*2.5+(10-items[7])*1.5+(10-items[8])*2;
	printf("\nNet income:%f",total);
	for (i=0;i<10;i++)
		items[i]=10;
	for (i=0;i<5;i++)
		money[i]=10;
	printf("\nItems and money restocked\n");
}
