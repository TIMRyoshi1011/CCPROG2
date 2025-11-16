#include<stdio.h>
#include<string.h>

#include "header.h"
#include "helpers.c"

#include "YellowPages-RAMOS.c"

int
main()
{
	directoryType dList[MAX];		// initial array of directory structure
	directoryType sortedList[MAX];	// storage for sorted directory structure
	
	String30 task;	// storage for task name to call
	String30 cat;	// storage for category name
	String30 key;	// storage for keyword to be used in searching
	businessType newB;		// storage for new business structure data
	businessType searchedB;	// storage for found business data
	
	populate(dList); // populate array of structures
	displayDirectory(dList); // showing initial values
	
	// TASK 1
	strcpy(task, "getCategory");
	displayTask(1, task);
	strcpy(cat, "Apartments");
	printf("Test 1 (existing category): %d\n", getCategory(dList, cat));
	strcpy(cat, "Chemicals");
	printf("Test 2 (non-existing category): %d\n", getCategory(dList, cat));
	strcpy(cat, "Computer");
	printf("Test 3 (multi-similar category): %d\n", getCategory(dList, cat));
	
	// TASK 2
	strcpy(task, "addBusiness");
	displayTask(2, task);
	strcpy(newB.name, "Test New Business Name");
	strcpy(newB.address, "Test New Business Address");
	newB.number = 12345678;	
	strcpy(cat, "Computer Software");
	printf("Test 1 (adding to category with no values): %d\n", addBusiness(cat, dList, newB));
	strcpy(cat, "Computer");
	printf("Test 2 (adding to category with > 1 < 5 values): %d\n", addBusiness(cat, dList, newB));
	strcpy(cat, "Beverages");
	printf("Test 3 (adding to category with 5 values): %d\n", addBusiness(cat, dList, newB));
	
	// displayDirectory(dList); // YOU MAY UNCOMMENT to show updated values after adding new business data
	
	// TASK 3
	strcpy(task, "getBusinessInfo");
	displayTask(3, task);
	strcpy(key, "Krispy Kreme");
	searchedB = getBusinessInfo(dList, key);
	printf("Test 1 (info for non-existing Krispy Kreme): %s %s %ld\n", searchedB.name, searchedB.address, searchedB.number);
	strcpy(key, "Big Chill");
	searchedB = getBusinessInfo(dList, key);
	printf("Test 2 (info for existing Big Chill): %s %s %ld\n", searchedB.name, searchedB.address, searchedB.number);
	strcpy(key, "Pepsico");
	searchedB = getBusinessInfo(dList, key);
	printf("Test 3 (info for existing but inc Pepsico): %s %s %ld\n", searchedB.name, searchedB.address, searchedB.number);

	// TASK 4
	strcpy(task, "findBusinessInCityCategory");
	displayTask(4, task);
	strcpy(key, "QC");
	searchedB = findBusinessInCityCategory(key, dList[2]);
	printf("Test 1 (find in QC, Apartments): %s %s %ld\n", searchedB.name, searchedB.address, searchedB.number);
	strcpy(key, "Psg");
	searchedB = findBusinessInCityCategory(key, dList[0]);
	printf("Test 2 (find in Psg, Computers): %s %s %ld\n", searchedB.name, searchedB.address, searchedB.number);
	
	// TASK 5
	strcpy(task, "sortCatBusiness");
	displayTask(5, task);
	printf("%s%s%s= SORTED ==%s%s%s\n", "===============", "===============", "===============",
			"===============", "===============", "===============");
	sortCatBusiness(dList, sortedList);
	displayDirectory(sortedList); // showing sortedList values	

	return 0;
}
