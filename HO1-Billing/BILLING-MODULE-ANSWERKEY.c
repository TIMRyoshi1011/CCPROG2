/*
    HANDS-ON 1 - Billing module for POS.
    
    Name:
    Section:
    
    To Do:
    1. Rename this file accordingly. Write your name and section on this header. 
    2. Implement the tasks stated in the exam. You may write additional functions, if needed.
    3. Follow the format of the output given in the sample run (see exam).

*/
#include <string.h>
#define MAX_ORDER 4
#define MENU_ITEMS 8
#define END "ED"

typedef char String30[31];
typedef char String2[3];

/* TASK #1 

	This function will display the menu items and their corresponding price and discount.\
	Refer to sample run for what the display should look like.
	
	@param: sCodes[] - array with the menu item codes
	@param: sMenuItems[] - array with the menu item names
	@param: fItemPrices[][2] - 2D array with the item prices and their discount
	
	Format and spacing for displayed items: " <item code>\t\t|\t <item name>\t\t|\t <item price>\t\t|\t <discount>\n"
*/
void displayItems(String2 sCodes[], String30 sMenuItems[], float fItemPrices[][2]) {
	int i;
	
	printf("ITEM CODE\t|\tITEM NAME\t\t\t|\tITEM PRICE\t|\tDISCOUNT\n");
	for(i = 0; i < MENU_ITEMS; i++)
	{
		printf(" [%s]\t\t|\t %s\t\t|\t %.2f\t\t|\t %.2f%%\n", sCodes[i], sMenuItems[i], fItemPrices[i][0], fItemPrices[i][1] * 100);
	}
}

/* TASK #2

	This function will initialize each element in sCustOrders to an empty string.
	
	@param: sCustOrders[] - array for customer orders which stores the item code of the items the customer picked
*/
void initCustOrders(String30 sCustOrders[]) {
	int i;
	
	for(i = 0; i < MAX_ORDER; i++)
		strcpy(sCustOrders[i], "");
}

/* TASK #3 
	
	This function will return the index if the item is found in sMenuItems otherwise it returns -1.
	
	@param: sCodes - the item code
	@param: sMenuCode[] - array containing the item codes
*/
int getItemIndex(String2 sCodes, String2 sMenuCode[]) {
	int found = -1;
	int i;
	
	for(i = 0; i < MENU_ITEMS; i++)
	{
		if(strcmp(sCodes, sMenuCode[i]) == 0)
		{
			found = i;
			i = MENU_ITEMS;
		}
	}
	
	return found;
}

/* TASK #4

	This function will ask the customer for their order. Specifically the item code and quantity.
	Any invalid item codes will not be added to the customer orders array and customer order detail array.
	This function returns the number of line items ordered. Any invalid orders will not be counted to the total
	number of line items ordered.
	
	@param: sCodes[] - array with the menu item codes
	@param: sCustOrders[] - array for customer orders which stores the item code of the items the customer picked
	@param: dCustOrderDetail[] - array storing the quantity specified for the item ordered
	
*/
int takeOrders(String2 sCodes[], String30 sCustOrders[], int dCustOrderDetail[]) {
	String2 itemCode;
	int qty, ctr = 0, ctr2 = 0;
	do
	{
		printf("\n\n");
		printf("Item Code: ");
		scanf("%s", itemCode);
		if(strcmp(END, itemCode) != 0)
		{
			printf("Quantity: ");
			scanf("%d", &qty);
						
			if(getItemIndex(itemCode, sCodes) != -1)
			{
				strcpy(sCustOrders[ctr2], itemCode);
				dCustOrderDetail[ctr2] = qty;
				ctr2++;
			}
			
			ctr++;
		}
	}while(ctr < 4 && strcmp(END, itemCode) != 0);

	return ctr2;
}

/* TASK #5

	This function will print the bill which displays the item, quantity, unit price, discounted price and amount due.
	
	@param: nNumOrders - number of orders made by the customer
	@param: sCustOrders[] - array for customer orders which stores the item code of the items the customer picked
	@param: dCustOrderDetail[] - array storing the quantity specified for the item ordered
	@param: sCodes[] - array with the menu item codes
	@param: sMenuItems[] - array with the menu item names
	@param: fItemPrices[][2] - 2D array with the item prices and their discount
	@param: float fSubTotals[] - The array where all sub-totals will be stored
	
	Format and spacing for displayed items: "<item name>\t|\t <quantity>\t|\t<item price>\t\t|\t<discounted>\n"
*/
void printBill(int nNumOrders, String30 sCustOrders[], int dCustOrderDetail[], String2 sCodes[], String30 sMenuItems[], float fItemPrices[][2], float fSubTotals[]) {
	int i, qty, code;
	float price, sub, amtDue = 0;
	
	if(nNumOrders == 0)
		printf("\nNO BILL SINCE THERE ARE NO VALID ORDERS MADE!\n");
	else
	{
		printf("\n====\n");
		printf("BILL\n");
		printf("====\n");
		printf("\tITEM\t\t|\tQTY\t|\tPRICE\t\t|\tDISCOUNT\t|\tSUB-TOTAL\n");
		
		for(i = 0; i < nNumOrders; i++)
		{
			code = getItemIndex(sCustOrders[i], sCodes);
			qty = dCustOrderDetail[i];
			price = fItemPrices[code][0];
			sub = price * qty;
			fSubTotals[i] = sub - sub * fItemPrices[code][1];
			printf("%s\t|\t %d\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\n",
			sMenuItems[code], qty, price, price * fItemPrices[code][1], fSubTotals[i]);
			amtDue += sub - sub * fItemPrices[code][1];
		}
		printf("\nAMT. DUE:\t%.2f", amtDue);		
	}

}
