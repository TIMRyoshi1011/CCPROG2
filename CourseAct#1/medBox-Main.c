#include <stdio.h>
#include "medBox-RAMOS.c" //Edit this line to match your filename

/*
	YOU ARE NOT ALLOWED TO MAKE ANY CHANGES TO THIS FILE
	EXCEPT FOR LINE 2.
*/
int main(){

	char medBox[4] = {'o', 'g', 'm', 'u'};
	int choice = 0, slot;
	
	do
	{
		printf("Select an action:\n");
		printf("1 - Display box content\n");
		printf("2 - Consume Medicine\n");
		printf("3 - Replenish slot\n");
		printf("4 - Exit\n");
		printf("Action: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch(choice)
		{
			case 1:
				printf("Current box content:\n");
				displayContent(medBox, 4);
				printf("\n");
				break;
			
			case 2:
				printf("Consume medicine:\n");
				printf("From which slot will you consume(1, 2, 3, 4)? ");
				scanf("%d", &slot);
				consumeMed(medBox, slot - 1);
				displayContent(medBox, 4);
				printf("\n");
				break;
			case 3:
				printf("Refill medicine:\n");
				printf("Which slot will you refill(1, 2, 3, 4)? ");
				scanf("%d", &slot);
				fillSlot(medBox, slot - 1);
				displayContent(medBox, 4);
				printf("\n");
				break;
			case 4:
				printf("Goodbye and have a nice day!\n");
				break;
			default:
				printf("Not a valid action!\n");
		}
		
	}while(choice != 4);
	
	return 0;
}

