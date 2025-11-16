#include <stdio.h>
#include "defs.h"
#include "files-RAMOS.c" //Edit LASTNAME with your last name

/*
	Except for line#3, your are not allowed to edit anything in this file!
*/
int main() {
	device latest[2];
	string20 fileName = "Gadgets.txt";
	string20 dataFile = "Gadget_Data.dat";
	
	if(addDevices(latest, 2, dataFile))
	{
		printf("%s successfully loaded!\n", dataFile);
		printDeviceList(latest, 2, fileName);
		printf("%s file created!\n", fileName);
	}
	else
		printf("%s not found/Invalid file!\n", dataFile);		

	return 0;
}
