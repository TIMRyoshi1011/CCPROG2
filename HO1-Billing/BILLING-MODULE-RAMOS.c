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
	
	Format and spacing for items: " <item code>\t\t|\t <item name>\t\t|\t <item price>\t\t|\t <discount>\n"
*/
void displayItems(String2 sCodes[], String30 sMenuItems[], float fItemPrices[][2]) {
	//Declare any variables you will need
	
	printf("ITEM CODE\t|\tITEM NAME\t\t\t|\tITEM PRICE\t|\tDISCOUNT\n");
	//Add your code starting from here. Also complete and use the following printf statement.
	int i, j = 0;

	for(i = 0; i < MENU_ITEMS; i++) 
		printf(" [%s]\t\t|\t %s\t\t|\t %.2f\t\t|\t %.2f%%\n", sCodes[i], sMenuItems[i], fItemPrices[i][j], fItemPrices[i][j+1] * 100);
}

/* TASK #2

	This function will initialize each element in sCustOrders to an empty string.
	
	@param: sCustOrders[] - array for customer orders which stores the item code of the items the customer picked
*/
void initCustOrders(String30 sCustOrders[]) {
	int i;

	for (i = 0; i < MAX_ORDER; i++)
		strcpy(sCustOrders[i], "\0");
}

/* TASK #3 
	
	This function will return the index if the item is found in sMenuItems otherwise it returns -1.
	
	@param: sCodes - the item code
	@param: sMenuCode[] - array containing the item codes
*/
int getItemIndex(String2 sCodes, String2 sMenuCode[]) {
	int i;

	for(i = 0; i < MENU_ITEMS; i++) 
		if (strcmp(sCodes, sMenuCode[i]) == 0) 
			return i;
		
	return -1; //Edit this to return the proper value
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
	int i;
	printf("\n");

	for(i = 0; i < MAX_ORDER; i++) {
		printf("\n");
		printf("Item Code: ");
		scanf("%s", sCustOrders[i]);

		if(strcmp(sCustOrders[i], END) == 0)
			i = 4;

		printf("Quanitity: ");
		scanf("%d", &dCustOrderDetail[i]);

		printf("\n");
	}

	return dCustOrderDetail[i]; //Edit this to return the proper value
}

/* TASK #5

	This function will print the bill which displays the item, quantity, unit price, discounted price and amount due.
	
	@param: nNumOrders - number of orders made by the customer
	@param: sCustOrders[] - array for customer orders which stores the item code of the items the customer picked
	@param: dCustOrderDetail[] - array storing the quantity specified for the item ordered
	@param: sCodes[] - array with the menu item codes
	@param: sMenuItems[] - array with the menu item names
	@param: fItemPrices[][2] - 2D array with the item prices and their discount
	@param: fSubTotals[] - Array for storing the sub-totals of each order
	
	Format and spacing for displayed items: "<item name>\t|\t <quantity>\t|\t<item price>\t\t|\t<discount>\t\t|\t<sub-total>\n"
*/
void printBill(int nNumOrders, String30 sCustOrders[], int dCustOrderDetail[], String2 sCodes[], String30 sMenuItems[], float fItemPrices[][2], float fSubTotals[]) {
	//Declare any variables you will need
	float amtDue = 0.00;
	
	if(nNumOrders == 0)
		printf("\nNO BILL SINCE THERE ARE NO VALID ORDERS MADE!\n");
	else
	{
		printf("\n====\n");
		printf("BILL\n");
		printf("====\n");
		printf("\tITEM\t\t|\tQTY\t|\tPRICE\t\t|\tDISCOUNT\t|\tSUB-TOTAL\n");
		
		//Add your code here. Also complete and use the following printf() statement.
		int i, j, index;
			//takeOrders(sCodes, sCustOrders, dCustOrderDetail);
			for(i = 0; i < MAX_ORDER; i++) {
				//k = getItemIndex(sCodes[i], sMenuItems[i]);
				fSubTotals[i] = dCustOrderDetail[i] * fItemPrices[i][j];

				for(j = 0; j < MAX_ORDER; j++) {
					if(strcmp(sCustOrders[j], sCodes[j]) == 0)
						index = getItemIndex(sCustOrders[i], sCodes);

						printf("%s\t|\t %d\t|\t%.2f\t\t|\t%.2f\t\t|\t%.2f\n", sMenuItems[index], dCustOrderDetail[i], fItemPrices[index][j], fItemPrices[index][j+1] * 100, fSubTotals[index]);
						amtDue += fSubTotals[i];
					}
				}
					
		printf("\nAMT. DUE:\t%.2f", amtDue);
	}

}
