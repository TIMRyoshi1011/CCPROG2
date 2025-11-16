#include <stdio.h>

/*
	This file contains the aliases for the structs and string that will
	be used in the activity.
	
	YOU ARE NOT ALLOWED TO CHANGE ANYTHING IN THIS FILE!
*/
typedef char string20[21]; //String that can have 20 characters

typedef struct {
	int dd; //day
	int mm; //month
	int yy; //year
}date;

typedef struct {
	int serialNo; //Product serial number
	date prodDate; //Product release date
	string20 prodBy; //Eg. Samsung, Sony, Apple, etc.
	string20 prodName; //Eg. S23 Ultra, Ally X. etc.
	string20 prodType; //Eg. cellphone, tablet, etc.
	string20 os; // Operating system
}device;

int addDevices(device list[], int dCount, string20 dataFile);
void printDeviceList(device list[], int dCount, string20 fileName);
