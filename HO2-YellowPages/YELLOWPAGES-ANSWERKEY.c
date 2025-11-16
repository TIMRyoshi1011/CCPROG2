/* Problem: Yellow Pages

   Name: 
   Section:
   
NOTES: 
	1. Do NOT run this file, add include statements, or call main() as it will result to 0 for this problem.
	2. Implement the functions below without changing any return type or parameter/s.
	3. You are only allowed to use statements and string functions taught in class.
		[strcpy, strcat, strcmp, strlen]
	3. MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	   If there is a compilation error, the score will be 0.	
*/

/**
TASK 1: Implement this function to find the given category name within the directory list [5pts]
   
   @param dList - array of directories that stores the category names, # of businesses in it, and list of businesses
   @param category - category name to find in the array of directories
   
   @return int - index where the category name was found, -1 if not found 
   
NOTE: You can create any number of local variables.
**/
int
getCategory(directoryType dList[], String30 category)
{
	int i=0, index=-1;
	
	// use loop to access and check each category member in array
	// continue while counter i is within capacity and category is not yet found
	while(i<MAX && index==-1){ 
		// check if category is the category in current dList data
		if(strcmp(dList[i].category, category)==0)
			// yes: get i as index where it is found
			index = i;
		i++;
	}
	
	return index;
}

/**
TASK 2: Implement this function to add a business to the category given found within the directory list [10pts]
   
   @param category - category name where to add the new business info
   @param dList - array of directories that stores the category names, # of businesses in it, and list of businesses
   @param newBusiness - business info to store into the array of the given category
   
   @return int - 1 is added successfully, 0 if not
   
NOTE:	You can create any number of local variables.
		You can only add to the category that does not exceed the MAX count yet.
REQUIREMENT: call the getCategory() and use it properly
**/
int
addBusiness(String30 category, directoryType dList[], businessType newBusiness)
{
 	int in, size, ret=0;
 	
 	// use getCategory() to get index of the category in dList
 	in = i_getCategory(dList, category);
 	
 	// check that category exists
 	if(in >= 0){
	 	// yes: get the number of businesses in that category
	 	size = dList[in].count;
 	
	 	// check if size is within capacity
	 	if(size < MAX){
	 		// yes: save newBusiness at next free location
	 		dList[in].b[size] = newBusiness;
	 		// increment size of businesses in the category
	 		dList[in].count = size+1;
	 		// update return value
	 		ret = 1;
	 	}
 	}
 	
 	return ret;
}

/**
TASK 3: Implement this function to get the business info from the directory list given its name [10pts]
   
   @param *dList - array of directories that stores the categories, # of businesses in it, and list of businesses
   @param businessName - business name to find within the directory list
   
   @return businessType - data containing all business info
   
NOTE:	You can create any number of local variables.
		If the business is NOT found, the business name to be returned should be "NOT FOUND",
		its address as empty, and number as 0.
**/
businessType
getBusinessInfo(directoryType dList[], String40 businessName)
{
 	int i, j, catFlag = 0, busFlag = 0;
 	
 	// create a temporary businessType variable
 	businessType business;
 	
 	// set to default
 	strcpy(business.name,"NOT FOUND");
 	strcpy(business.address, "");
 	business.number = 0;
 	
 	// loop to access each category in directory structure, use flag to stop the loop once found
 	for(i=0; i<MAX && !catFlag; i++){
 		// loop to access each business in the category, use flag to stop the loop once found
 		for(j=0; j<dList[i].count && !busFlag; j++){
 			// check if current business name is the one we are looking for
 			if(strcmp(dList[i].b[j].name, businessName)==0){
 				// yes: assign values to temporary variable overriding the default
 				business = dList[i].b[j];
 				busFlag = 1;
 				catFlag = 1;
 			}
 		}
 	}
 	
 	return business; 
}

/**
TASK 4: Implement this function to get the first business info given the city and category [10pts]
   
   @param city - a keyword for the city such as Mkti, Mla, QC
   @param category - category containing list of businesses to find in the given city
   
   @return businessType - data containing all business info
   
NOTE:	You can create any number of local variables.
		If the business is NOT found, the business name to be returned should be "NOT FOUND",
		its address as empty, and number as 0.
**/
businessType
findBusinessInCityCategory(String30 city, directoryType category)
{
	int i, flag=0, start;
	String30 bCity;
	
	// get the length of city to use in extracting city from address
	int cityLen = strlen(city);
	
 	// create a temporary businessType variable
 	businessType business;
 	
 	// set to default
 	strcpy(business.name,"NOT FOUND");
 	strcpy(business.address, "");
 	business.number = 0;

	// loop to access each business in category, use flag to stop the loop once found
	for(i=0; i<MAX && !flag; i++){
		// get the starting index where to extract the expected city string
		start = strlen(category.b[i].address)-cityLen;
		// copy string from address starting at start index until null byte
		strcpy(bCity, category.b[i].address+start);
		// check if extracted string is equivalent to the city where to search
		if(strcmp(bCity, city) == 0){
			// yes: assign values to temporary variable overriding the default
			business = category.b[i];
			flag = 1;
		}
	}
	
	return business;
} 

/**
TASK 5: Implement this function to store the sorted list of directory
		by CATEGORY and BUSINESSES within it in ascending order [15pts]
   
   @param dList - array of directories that stores the categories, # of businesses in it, and list of businesses
   @param sortedList - business name to find within the directory list
   
   @return void
   
NOTE:	You can create any number of local variables.
		BOTH the category name and each businesses within it should be in ascending order.
**/
void
sortCatBusiness(directoryType dList[], directoryType sortedList[]){	
	int i, j, k, min;
	directoryType dTemp;
	businessType bTemp;
	
	// make a copy of all values in dList to sortedList
	for(i=0; i<MAX; i++){
		sortedList[i] = dList[i];
	}
	
	// SORT CATEGORY
	// loop to access each category for selection sort
	for(i=0; i<MAX-1; i++){
		// set the current unsorted value's index as min
		min=i;
		// loop to access succeeding values
		for(j=i+1; j<MAX; j++){
			// check if current value comes before the min
			if(strcmp(sortedList[j].category, sortedList[min].category) < 0)
				// yes: update min index
				min = j;
		}
		// after identifying the final min, swap
		dTemp = sortedList[i];
		sortedList[i] = sortedList[min];
		sortedList[min] = dTemp;
	}
	
	// SORT BUSINESSES WITHIN CATEGORIES
	// loop to access each category
	for(k=0; k<MAX; k++){
		// loop to access each business in the current category for selection sort
		for(i=0; i<MAX-1; i++){
			// set the current unsorted value's index as min
			min = i;
			// loop to access succeeding values
			for(j=i+1; j<sortedList[k].count; j++){
				// check if current value comes before the min
				if(strcmp(sortedList[k].b[j].name, sortedList[k].b[min].name) < 0)
					// yes: update min index
					min = j;
			}
			// after identifying the final min, swap
			bTemp = sortedList[k].b[i];
			sortedList[k].b[i] = sortedList[k].b[min];
			sortedList[k].b[min] = bTemp;
		}
	}
}

 
