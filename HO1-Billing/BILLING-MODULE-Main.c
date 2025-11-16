//DO NOT EDIT ANYTHING IN THIS FILE EXCEPT FOR LINE 3.
#include <stdio.h>
#include "BILLING-MODULE-RAMOS.c" //Edit this line. Change LASTNAME with your last name.

int main()
{
	int nNumOrders = 0;
	
	String2 sCodes[MENU_ITEMS] = {"BT", "BE", "PS", "CW", "OM", "GS", "CB", "BB"}; // Item Codes
	String30 sMenuItems[MENU_ITEMS] = {				//Item Names
							"Beef Tapa w/ rice",
							"Bacon & Eggs w/ rice",
							"Pancake & Sausages",
							"Chicken & Waffles",
							"Omelette Special",
							"German Sausage & rice",
							"Crispy Bangus w/ rice",
							"Big Breakfast Meal"
						  };
	float fItemPrices[MENU_ITEMS][2] = {{80.00, 0.0},  //Item Prices
										{95.50, 0.0},
										{75.50, 0.1},
										{85.50, 0.2},
										{60.00, 0.0},
										{99.75, 0.2},
										{65.00, 0.1},
										{120.00, 0.25},
									   };
	String30 sCustOrders[MAX_ORDER]; //Customer order (Stores item codes)
	int dCustOrderDetail[MAX_ORDER] = {}; //Customer order details (quantity of the order of the customer)
	float fSubTotals[MAX_ORDER]; //For storing the sub-totals of each order
	
	printf("Welcome to BnB Breakfast Cafe!\n\n");
	displayItems(sCodes, sMenuItems, fItemPrices);
	
	initCustOrders(sCustOrders);
	
	printf("\nPlease tell me your order!");
	nNumOrders = takeOrders(sCodes, sCustOrders, dCustOrderDetail);
	
	printBill(nNumOrders, sCustOrders,  dCustOrderDetail, sCodes, sMenuItems, fItemPrices, fSubTotals);
	
	return 0;
}
