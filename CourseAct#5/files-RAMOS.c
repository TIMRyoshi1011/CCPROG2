/* TASK #1: Implement the addDevices() function

	@param: list[] - array of the device structure
	@param: dCount - size of the array
	@param: dataFile - string containing the file name
	returns: 1 or 0
	
	This function will read the Gadget_Data.dat file. If the file cannot 
	be read or is not found, this function will return 0, otherwise it will read
	the file and place the data into the appropriate members of the structure in 
	the array and then return 1.
	
	NOTE: You may declare as many variables as you need for this function.
*/
//Read data from binary file and store into the elements of the array of struct's members
int addDevices(device list[], int dCount, string20 dataFile) {
	int i;
	FILE *data;

	data = fopen(dataFile, "rb");

	if(data == NULL)
		return 0;

	else {

		for(i = 0; i < dCount; i++) {
			fread(&list[i].serialNo, sizeof(int), 1, data);
			fread(&list[i].prodDate.mm, sizeof(int), 1, data);
			fread(&list[i].prodDate.dd, sizeof(int), 1, data);
			fread(&list[i].prodDate.yy, sizeof(int), 1, data);
			fread(list[i].prodBy, sizeof(string20), 1, data);
			fread(list[i].prodName, sizeof(string20), 1, data);
			fread(list[i].prodType, sizeof(string20), 1, data);
			fread(list[i].os, sizeof(string20), 1, data);
		}
		
		return 1; //Edit the value to return the expected value
	}	
}

/* TASK #2: Implement the printDeviceList() function

	@param: list[] - array of the device structure
	@param: dCount - size of the array
	@param: dataFile - string containing the file name
	returns: nothing
	
	This function will write all the struct data from the struct array
	to a text file. Refer to the output.txt file for the format.
	
	NOTE: You may declare as many variables as you need for this function.
*/
//Write struct data with format to text file
void printDeviceList(device list[], int dCount, string20 fileName) {
	int i;
	FILE *data;

	data = fopen(fileName, "w");

	fprintf(data, "LATEST GADGETS LIST:\n\n");
	printf("\nLATEST GADGETS LIST:\n\n");

	for(i = 0; i < dCount; i++) {
		fprintf(data, "Serial Number: %d\n", list[i].serialNo);
		fprintf(data, "Date Released: %02d / %02d / %02d\n", list[i].prodDate.mm, list[i].prodDate.dd, list[i].prodDate.yy);
		fprintf(data, "Company: %s\n", list[i].prodBy);
		fprintf(data, "Device Name: %s\n", list[i].prodName);
		fprintf(data, "Device Type: %s\n", list[i].prodType);
		fprintf(data, "Device OS: %s\n", list[i].os);
		fprintf(data, "\n");

		printf("Serial Number: %d\n", list[i].serialNo);
		printf("Date Released: %02d / %02d / %02d\n", list[i].prodDate.mm, list[i].prodDate.dd, list[i].prodDate.yy);
		printf("Company: %s\n", list[i].prodBy);
		printf("Device Name: %s\n", list[i].prodName);
		printf("Device Type: %s\n", list[i].prodType);
		printf("Device OS: %s\n", list[i].os);
		printf("\n");
	}

	fclose(data);
}
