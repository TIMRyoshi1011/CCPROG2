/* Problem: Yellow Pages

   Name: Marcus TImothy V. Ramos
   Section: S13B
   
NOTES: 
	1. Do NOT compile/run this file, add include statements, or call main() as it will result to 0 for this problem.
	2. Implement the functions below without changing any return type or parameter/s.
	3. You are only allowed to use statements and string functions taught in class.
		[strcpy, strcat, strcmp, strlen]
	3. MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	   If there is a compilation error, the score will be 0.
	4. You may compile and run the main.c ANYTIME to check your solutions.
		Just focus on the specific function you are implementing.
*/

/**
TASK 1: Implement this function to find the given category name within the directory list [5pts]
   
   @param dList - array of directories that stores the category names, # of businesses in it, and list of businesses
   @param category - category name to find in the array of directories
   
   @return int - index where the category name was found, -1 if not found 
   
NOTE: You can create any number of local variables and helper functions if you need.
	  Search is CASE-SENSITIVE.
**/
int
getCategory(directoryType dList[], String30 category)
{
	int i;

	for(i = 0; i < MAX; i++)
		if(strcmp(category, dList[i].category) == 0)
			return i;

	return -1; // you may update this line
}

/**
TASK 2: Implement this function to add a business to the category given found within the directory list [10pts]
   
   @param category - category name where to add the new business info
   @param dList - array of directories that stores the category names, # of businesses in it, and list of businesses
   @param newBusiness - business info to store into the array of the given category
   
   @return int - 1 is added successfully, 0 if not
   
NOTE:	You can create any number of local variables and helper functions if you need.
		You can only add to the category that does not exceed the MAX count yet.
		
REQUIREMENT: call the getCategory() and use it properly
**/
int
addBusiness(String30 category, directoryType dList[], businessType newBusiness)
{
	int index, i = 0;

	index = getCategory(dList, category);

	if(index != -1) {

		strcpy(dList[MAX - i + 1].b->name, newBusiness.name);
		strcpy(dList[MAX - i + 1].b->address, newBusiness.address);
		dList[MAX - i + 1].b->number = newBusiness.number;
		i++;

		return 1;
	}

	else 
		return 0; // you may update this line
}

/**
TASK 3: Implement this function to get the business info from the directory list given its name [10pts]
   
   @param *dList - array of directories that stores the categories, # of businesses in it, and list of businesses
   @param businessName - business name to find within the directory list
   
   @return businessType - data structure containing all business info
   
NOTE:	You can create any number of local variables and helper functions if you need.
		If the business is NOT found, return the business structure with the business name set to "NOT FOUND",
		its address set as empty, and number set as 0.
**/
businessType
getBusinessInfo(directoryType dList[], String40 businessName)
{
	int i;
	businessType searchedB;

	for(i = 0; i < MAX; i++) {
		if(strcmp(businessName, dList[i].b->name) == 0) {
			strcpy(searchedB.name, dList[i].b->name);
			strcpy(searchedB.address, dList[i].b->address);
			searchedB.number = dList[i].b->number;
		}

		else {
			strcpy(searchedB.name, "NOT FOUND");
			strcpy(searchedB.address, "\0");
			searchedB.number = 0;
		}
	}
	
		return searchedB; // you may update this line
}

/**
TASK 4: Implement this function to get the FIRST business info given the city and category [10pts]
   
   @param city - a keyword for the city such as Mkti, Mla, QC
   @param specificCategory - category containing list of businesses to find in the given city
   
   @return businessType - data containing all business info found
   
NOTE:	You can create any number of local variables and helper functions if you need.
		If the business is NOT found, the business name to be returned should be "NOT FOUND",
		its address as empty, and number as 0.
		
ASSUMPTIONS:	Address will always have the city at the end.
				City name length will always be less than the length of whole address.
**/
businessType
findBusinessInCityCategory(String30 city, directoryType specificCategory)
{
	int i = 0;
	businessType searchedB;

	while (specificCategory.b->address[i] != '\0') {
		if (specificCategory.b->address[i] == 'Q'){
			if(specificCategory.b->address[i+1] == 'C') {
				strcpy(searchedB.name, specificCategory.b->name);
				strcpy(searchedB.address, specificCategory.b->address);
				searchedB.number = specificCategory.b->number;
			}

			else {
				strcpy(searchedB.name, "NOT FOUND");
				strcpy(searchedB.address, "\0");
				searchedB.number = 0;
			}
		}

		else if (specificCategory.b->address[i] == 'P') {
			if(specificCategory.b->address[i+1] == 's') {
				if(specificCategory.b->address[i+2] == 'g') {
					strcpy(searchedB.name, specificCategory.b->name);
					strcpy(searchedB.address, specificCategory.b->address);
					searchedB.number = specificCategory.b->number;
				}
			}

			else {
				strcpy(searchedB.name, "NOT FOUND");
				strcpy(searchedB.address, "\0");
				searchedB.number = 0;
			}
		}

		else if (specificCategory.b->address[i] == 'M') {
			if(specificCategory.b->address[i+1] == 'l') {
				if(specificCategory.b->address[i+2] == 'a'){
					strcpy(searchedB.name, specificCategory.b->name);
					strcpy(searchedB.address, specificCategory.b->address);
					searchedB.number = specificCategory.b->number;
				}
			}

			else {
				strcpy(searchedB.name, "NOT FOUND");
				strcpy(searchedB.address, "\0");
				searchedB.number = 0;
			}
		}

		else if (specificCategory.b->address[i] == 'M') {
			if (specificCategory.b->address[i+1] == 'k') {
				if (specificCategory.b->address[i+2] == 't') {
					if (specificCategory.b->address[i+3] == 'i') {
						strcpy(searchedB.name, specificCategory.b->name);
						strcpy(searchedB.address, specificCategory.b->address);
						searchedB.number = specificCategory.b->number;
					}
				}
			}

			else {
				strcpy(searchedB.name, "NOT FOUND");
				strcpy(searchedB.address, "\0");
				searchedB.number = 0;
			}
		}

		else if (specificCategory.b->address[i] == 'V') {
			if (specificCategory.b->address[i] == 'a') {
				if (specificCategory.b->address[i] == 'l') {
					strcpy(searchedB.name, specificCategory.b->name);
					strcpy(searchedB.address, specificCategory.b->address);
					searchedB.number = specificCategory.b->number;
				}
			}

			else {
				strcpy(searchedB.name, "NOT FOUND");
				strcpy(searchedB.address, "\0");
				searchedB.number = 0;
			}
		}

		else {
			strcpy(searchedB.name, "NOT FOUND");
			strcpy(searchedB.address, "\0");
			searchedB.number = 0;
		}
		i++;
	}
	
 	return searchedB; // you may update this line
} 

/**
TASK 5: Implement this function to store the sorted list of directory
		by CATEGORY and BUSINESSES within it in ascending order [15pts]
   
   @param dList - array of directories that stores the categories, # of businesses in it, and list of businesses
   @param sortedList - storage for the sorted array of directories
   
   @return void
   
NOTE:	You can create any number of local variables and helper functions if you need.
		dList should NOT be modified.
		BOTH the category names and each business name within it should be in ascending order.
**/
void
sortCatBusiness(directoryType dList[], directoryType sortedList[]){	
	int i, j, min;

	for(i = 0; i < MAX - 1; i++) {
		min = i;

		for(j = i + 1; j < MAX; j++)
			if(strcmp(dList[min].category, dList[j].category) && strcmp(dList[min].b->name, dList[j].b->name) == 1)
				min = j;

		if(strcmp(dList[i].category, dList[min].category) && strcmp(dList[i].b->name, dList[min].b->name)!= 0) {
			strcpy(sortedList[min].category, dList[i].category);
			sortedList[min].count = dList[i].count;
			strcpy(sortedList[min].b->name, dList[i].b->name);
			strcpy(sortedList[min].b->address, dList[i].b->address);
			sortedList[min].b->number = dList[i].b->number;
		}

	}
}

 
