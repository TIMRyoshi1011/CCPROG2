//Function prototypes
int isSlotEmpty(char medBox[], int slot);
int checkMed(char med);
int isValidSlot(char med, int slot);
void fillSlot(char medBox[], int slot);
void consumeMed(char medBox[], int slot);
void displayContent(char medBox[], int slots);

//NOTE: YOU ARE NOT ALLOWED TO CREATE ANY OTHER FUNCTIONS!

/*  DO NOT EDIT THIS FUNCTION!

	isSlotEmpty() checks if the specific slot in the medicine box is empty or not.
	If the content of the slot is a null character('\0') the function will return 1 otherwise
	it will return 0.
	
	@param medBox[] - the medicine box array
	@param slot - the specific slot in the box
*/
int isSlotEmpty(char medBox[], int slot) {
	int empty = 0;
	
	if(medBox[slot] == '\0')
		empty = 1;
	
	return empty;
}

/*  DO NOT EDIT THIS FUNCTION!
	
	checkMed() checks if the inputted medicine character is valid or not.
	If it is valid, it will return 1 otherwise, it will return 0.
	
	@param med - the medicine type
*/
int checkMed(char med) {
	int valid;
	
	switch(med)
	{
		case 'o':
		case 'O': //Omeprazole
		case 'g':
		case 'G': //G-1 Norm
		case 'm':
		case 'M': //Mucosta
		case 'u':
		case 'U': //Ursudeoxycholic Acid
			valid = 1;
			break;
		default:
			valid = 0;
	}
	
	return valid;
}

/*  DO NOT EDIT THIS FUNCTION!

	Each slot is assigned to a specific medicine. isValidSlot() checks 
	if the slot you are placing the medicine in is a valid slot. 
	If valid, the function will return 1 otherwise, it will return 0.
	
	Slot 1 - o or O
	Slot 2 - g or G
	Slot 3 - m or M
	Slot 4 - u or U
	
	@param med - the medicine type
	@param slot - the specific slot in the medicine box
*/
int isValidSlot(char med, int slot) {
	int valid = 0;
	switch(slot)
	{
		case 0:
			if(med == 'o' || med == 'O')
				valid = 1;
			break;
		case 1:
			if(med == 'g' || med == 'G')
				valid = 1;
			break;
		case 2:
			if(med == 'm' || med == 'M')
				valid = 1;
			break;
		case 3:
			if(med == 'u' || med == 'U')
				valid = 1;
			break;
		default:
			valid = 0;
	}
	return valid;
}

/*  TASK #1: Implement fillSlot()

	This function will first check if the specified slot is empty. If it is not,
	it will display a message saying that the slot is not empty otherwise,
	it will the user which medicine type he/she wants to place into the slot.  
	
	It will then check if the medicine type is the right one for the slot.
	If it is, the medicine type will be store in the slot and it will display a 
	message saying the slot was replenished otherwise it will display a message 
	saying the the medicine type is not for that slot.
	
	@param medBox[] - the medicine box array
	@param slot - the specific slot in the medicine box
	
	This function will call/make use of the following functions:
		isSlotEmpty()
		checkMed()
		isValidSlot()
	
	You are allowed to implement this function without using the above
	mentioned functions but for simplicity's sake, I suggest you use them otherwise your
	code will be longer than it has to be.
	
	You may declare as many variables as you need for this function.
*/
void fillSlot(char medBox[], int slot) {
	char med;

	if (!(isSlotEmpty(medBox, slot))) 
		printf("Slot is not empty!\n");
		
	else {
		printf("What medicine will you be placing(o, g, m, u)?");
		scanf(" %c", &med);

		if(checkMed(med) && isValidSlot(med, slot)) {
			medBox[slot] = med;	
			printf("Slot %d replenished!\n", slot);
		}

		else
			printf("Not a valid medicine for that slot!\n");
	}
}

/*  TASK #2: Implement consumeMed()

	This function will first check if the specified slot is empty.
	If it is empty (has '\0') then it will display a message telling
	the user that the slot is empty otherwise, it will replace the
	existing char value with a null character('\0') then display a message
	informing the user that the medicine in that slot was consumed.
	
	@param medBox[] - the medicine box array
	@param slot - the specific slot in the medicine box
	
	This function does not require any variables but you are allowed
	to declare some if you need to.
*/
void consumeMed(char medBox[], int slot) {
	if (isSlotEmpty(medBox, slot))
		printf("That slot is empty!\n");
	
	else 
		medBox[slot] = '\0';
		printf("Medicine in slot %d was consumed!\n", slot + 1);
}

/* TASK #3: Implement displayContent()

	This function will display all contents of the medicine box in
	the following format:
	
		[o][g][m][u]
	
	NOTE: If a medicine is consumed, the slot of that medicine will be
	      empty.
	      
	Example: Medicine g was consumed. The display will look like this:
		[o][][m][u]
		
	Be sure to print a next line(\n) at the end of this function.
	You are allowed to declare as many variable as you need.
*/
void displayContent(char medBox[], int slots) {
	int i;

	for (i=0; i < slots; i++) 
		printf("[%c]", medBox[i]);

	printf("\n");	
}

