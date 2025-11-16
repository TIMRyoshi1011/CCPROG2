/*
Programmed by: Marcus Timothy V. Ramos [12313408], Jon Regan S. Choa [12306282]
Last modified: Mar. 27, 2025; 5:22PM
Version: 3.1
//-----------------------------------------------------------------------------------//
Progress:
- Arrows Express Personnel Features is 90% complete
- Passenger Features is 99% complete
//-----------------------------------------------------------------------------------//
To do:
- special shuttle (worst case scenario)
- priority level (using sort algorithm)
- fix option 1 - 3 in arrows personel features (no. of passengers)
//-----------------------------------------------------------------------------------//
Updates: 
Ver. 2.3 Patch Notes:
1. Changed the UI for Arrows Personnel Menu
2. Added the files after encoding passenger information 

Ver. 2.4
 - Fixed the view passenger info bug where it goes to the bottom

Ver 2.5
Load passenger is now complete, just make a text file with the details (load.txt)
I moved the save to text file on option 7 apm, according to the specs
DEBUGGING

Ver 2.6
- changed typedef char String50[51] to typedef char String100[101]
- changed order in typedef struct {} fullName; (last name first)
- removed String100 embarkationPoint; (no need in embarkation card [from the specs pdf])
- removed conditions in idNoEntry() (assumed id no. input is valid from QnA)
- new function entry: embarkationandDropOff()
- added parameters in embarkationCardEntry()
- called embarkationandDropOff() in embarkationCardEntry() and loadPassenger()
- Changed order and added elements to confirmation of details in embarkationCardEntry()
- added parameters in saveData()
- added elements in fprintf in saveData()
- added variable String100 embarkationPoint; String100 dropOff; in main() (made them into arrays) and changed order of variables
- changed order of storing elements to embarakation card in structure in main() and removed embarkationPoint (no need, from the specs pdf)
- removed fscanf(trip, " %[^\n]s", embarkationPoint); from loadPassenger() (no need since trip number generates it na, says from the QnA pdf)
- fixed loadPassenger() function (it works well now)

Ver. 3.0
- added variables: lagunaIndex, manilaCtr[9], lagunaCtr[11] in main()
- added feature when trip is full (set every elemnt in manilaCtr[] and lagunaCtr[] to 13 to test, or set one to 12 and the rest 13)

Ver 3.1
- special trip is now available
- fixed feature for trip is full only for the last trip of both manila and laguna to activate special shuttle
- added #define MAX_PASSENGERS_SPECIAL 16
- added struct embarkationCard special_M[MAX_PASSENGERS_SPECIAL] 
    struct embarkationCard special_L[MAX_PASSENGERS_SPECIAL] 

    String100 specialEmbarkationPt[2][MAX_PASSENGERS_SPECIAL] 
    String100 specialDropOff[2][MAX_PASSENGERS_SPECIAL] 

    int specialMCtr = 0; 
    int specialLCtr = 0;

- added specialShuttleEntry() Function
- saving to struct is still unavailable
//-----------------------------------------------------------------------------------//

Notes from the gdocs QnA (that might be helpful):

Q7: If a passenger is moved over to the next shuttle, is it to the next trip number (Ex. AE101 to AE102) or to the next shuttle with the same route (Ex. AE101 to AE103)?
A7: Yes. They are moved to the NEXT shuttle after the one they were removed from regardless of their preferred drop-off point. Refer to Q26 for drop-off points for moved passengers.

Q16: For moving passengers in the event the shuttle is full and a higher priority wants to move, do we start from the 13th seat and go down the list until we find a lower priority 
or start from seat 1 and move up?
A16: Last in, first out. So if the last passenger was a lower priority, he/she is removed to accommodate the higher priority passenger.

Q19: Since it says that if the last trip is full and there are still passengers, wherein AE109 for (Manila to Laguna) and A160(Laguna to Manila) are the last shuttles of the day, 
does it mean whichever bus gets full first will have the special shuttle bus, but not both? (For example, AE109 is full but there are still passengers, then a special shuttle will 
be deployed here, even if AE160 is also full and there are still passengers)
A19: There will always be 1 SPECIAL shuttle for each campus. (1 for Manila and 1 for Laguna)

Q26: What happens if a passenger’s drop-off point is not part of a shuttle’s route when they are moved?
A26: It defaults to the other campus. Eg. If they boarded in Laguna, they get dropped off at the Manila campus (last drop-off point which is DLSU Manila South Gate).

Q41: Question po for the last trips (like AE109) if AE109 is full and an incoming passenger picks that trip number, do we first check if the incoming passenger has a higher priority than any of the passengers in AE109 or do we immediately move the incoming passenger to the special shuttle po?
A41: Yes. The priority number exists for a reason. If that passenger’s priority is high and a lower priority passenger is in the full shuttle, the lower one gets moved to the next shuttle.

Q55: Can a passenger choose to be assigned to the special shuttle, or is it automatically assigned to a passenger when no more trips are available for the day?
A55: No. The special shuttle is not a choice. It only becomes available when the last trip is full and the excess are automatically assigned to it.

Q59: Since there are 2 special shuttles (1 for each embarkation point), how do we name them? Do we write them as SPECIAL1 or SPECIAL2 (so that there won’t be conflict when trying to access the contents of the special shuttles) or any naming convention as long as it separates them? Or do we just give them the same name?
A59: SPECIAL_L (Laguna) and SPECIAL_M(Manila)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for system("cls");
#include <conio.h> //for getch();

#define MAX_PASSENGERS 13
#define MAX_TRIPS 20
#define MAX_PASSENGERS_SPECIAL 16 // new entry

typedef char String5[6];
typedef char String8[9];
typedef char String100[101];

typedef struct {
    String100 laName;
    String100 fName;
    char mIni;
} fullName;

struct embarkationCard {
    int priorityNum;
    fullName name;
    int idNum;
    int dropoffNum;
};

int displayDropOffPoint4() {
    int readEntry, dropoffPoint;

    printf("Via Buendia/LRT: (for Trip Numbers: AE150, AE152, AE154, AE156, AE158, AE160)\n");
    printf("------------------------------------------------------------------|\n");
    printf(" Drop-off point  |\t  Location   \t\t\t          |\n");
    printf("-----------------|------------------------------------------------|\n");
    printf("      [1]\t | College of St. Benilde (CSB) along Taft Avenue |\n");
    printf("      [2]\t | Gate 4: Gokongwei Gate\t\t\t  |\n");
    printf("      [3]\t | Gate 2: North Gate (HSSH) \t\t\t  |\n");
    printf("      [4]\t | Gate 1: South Gate (LS Building Entrance) \t  |\n");
    printf("------------------------------------------------------------------|\n\n");

    printf("Drop-off point: ");
    do {
        readEntry = scanf("%d", &dropoffPoint);
        getchar();

        if(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 4)
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 4);

    return dropoffPoint;
}

int displayDropOffPoint3() {
    int readEntry, dropoffPoint;

    printf("Via Estrada: (for Trip Numbers: AE151, AE153, AE155, AE157, AE159 and Special Shuttle)\n");
    printf("-------------------------------------------------------------------|\n");
    printf(" Drop-off point  |\t  Location   \t\t\t           |\n");
    printf("-----------------|-------------------------------------------------|\n");
    printf("      [1]\t | Petron Gasoline Station along Gil Puyat Avenue  |\n");
    printf("      [2]\t | Gate 4: Gokongwei Gate\t\t\t   |\n");
    printf("      [3]\t | Gate 2: North Gate (HSSH) \t\t\t   |\n");
    printf("      [4]\t | Gate 1: South Gate (LS Building Entrance) \t   |\n");
    printf("-------------------------------------------------------------------|\n\n");

    printf("Drop-off point: ");
    do {
        readEntry = scanf("%d", &dropoffPoint);
        getchar();

        if(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 4)
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 4);

    return dropoffPoint;
}

int displayDropOffPoint2() {
    int readEntry, dropoffPoint;

    printf("Via ETON Exit: (for Trip Numbers: AE102, AE104, AE106, AE108 and Special Shuttle)\n");
    printf("------------------------------------------------------------------------------------|\n");
    printf(" Drop-off point  |\t  Location   \t\t\t\t\t            |\n");
    printf("-----------------|------------------------------------------------------------------|\n");
    printf("      [1]\t | Laguna Blvd. Guard House (across Paseo PHOENIX Gasoline Station) |\n");
    printf("      [2]\t | Milagros Del Rosario (MRR) Building - East Canopy\t\t    |\n");
    printf("------------------------------------------------------------------------------------|\n\n");

    printf("Drop-off point: ");
    do {
        readEntry = scanf("%d", &dropoffPoint);
        getchar();

        if(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 2)
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 2);

    return dropoffPoint;
}

int displayDropOffPoint1() {
    int readEntry, dropoffPoint;

    printf("Via Mamplasan Exit: (for Trip Numbers: AE101, AE103, AE105, AE107, AE109)\n");
    printf("---------------------------------------------------------------------|\n");
    printf(" Drop-off point  |\t  Location   \t\t\t\t     |\n");
    printf("-----------------|---------------------------------------------------|\n");
    printf("      [1]\t | Mamplasan Toll Exit\t\t\t\t     |\n");
    printf("      [2]\t | Phase 5, San Jose Village \t\t\t     |\n");
    printf("      [3]\t | Milagros Del Rosario (MRR) Building - East Canopy |\n");
    printf("---------------------------------------------------------------------|\n\n");

    printf("Drop-off point: ");
    do {
        readEntry = scanf("%d", &dropoffPoint);
        getchar();

        if(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 3)
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || dropoffPoint < 1 || dropoffPoint > 3);

    return dropoffPoint;
}

int idNoEntry() {
    int readEntry, idNo;

    printf("Enter ID Number: ");
    do { 
        readEntry = scanf("%d", &idNo);
        getchar();

        if(readEntry != 1)
            printf("Invalid ID Number, Please Try Again: ");

    } while(readEntry != 1);

    return idNo;
}

char nameEntry(String100 lName, String100 fName1, String100 fName2) {
    int readEntry;
    char midIni;
    
    printf("Enter Last Name: ");
    do {
        scanf("%s", lName);
        readEntry = strcmp(lName, "A");

        if(readEntry == -1)
            printf("INVALID Name, Please Type Again: ");

    } while(readEntry == -1);

    printf("\n");

    printf("Note: can type up to 2 first names (add space), type NA after space if you have only 1 first name\n");
    printf("Enter First Name: ");
    do {
        scanf("%s %s", fName1, fName2);
        readEntry = strcmp(fName1, "A");

        if(readEntry == -1)
            printf("INVALID Name, Please Type Again: ");

    } while(readEntry == -1);

    printf("\n");

    printf("Note: Only input capital letters\n");
    printf("Enter Middle Initial: ");
    do {
        scanf(" %c", &midIni);

        if(midIni < 65 || midIni > 90)
            printf("INVALID Middle Initial, Please Type Again: ");

    } while(midIni < 65 || midIni > 90);

    return midIni;
}

int priorityNoEntry() {
    int readEntry, priorityNo;

    printf("Enter Priority No: ");
    do { 
        readEntry = scanf("%d", &priorityNo);
        getchar();

        if(readEntry != 1 || priorityNo < 1 || priorityNo > 6)
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || priorityNo < 1 || priorityNo > 6);

    return priorityNo;
}

void displayPriorityNumber() {
    printf("--------------------------------------------------------------------------------|\n");
    printf(" Priority Number |\t  Description\t\t\t\t\t\t|\n");
    printf("-----------------|--------------------------------------------------------------|\n");
    printf("      [1]\t | Faculty and ASF with Inter-campus assignments \t\t|\n");
    printf("      [2]\t | Students with Inter-campus enrolled subjects or enrolled     |\n\t\t | in thesis using Inter-campus facilities \t\t\t|\n");
    printf("      [3]\t | Researchers \t\t\t\t\t\t\t|\n");
    printf("      [4]\t | School Administrators (Academic Coordinators level and up    |\n\t\t | for Faculty and ASF, and Director level and up for APSP      |\n");
    printf("      [5]\t | University Fellows \t\t\t\t\t\t|\n");
    printf("      [6]\t | Employees and Students with official business \t\t|\n");
    printf("--------------------------------------------------------------------------------|\n");
}

int searchTripNumber(String5 tripNoEntry, String5 tripNo[], int size) {
    int i;

    for (i = 0; i < size; i++) 
        if (strcmp(tripNoEntry, tripNo[i]) == 0) 
            return i;

     return -1;
}

void embarkationandDropOff(String100 embarkationPoint[][MAX_PASSENGERS], int *dropoffPoint, String100 dropOff[][MAX_PASSENGERS], int searchresult) {
    int i;

    for (i = 0; i < MAX_PASSENGERS; i++){

        if (searchresult >= 0 && searchresult <= 8) {
            strcpy(embarkationPoint[searchresult][i], "DLSU Manila Campus - South Gate Driveway");   

            if(searchresult % 2 == 0) {

                if(*dropoffPoint == 1)
                    strcpy(dropOff[searchresult][i], "Mamplasan Toll Exit");
                
                else if(*dropoffPoint == 2)
                    strcpy(dropOff[searchresult][i], "Phase 5, San Jose Village");

                else 
                    strcpy(dropOff[searchresult][i], "Milagros Del Rosario (MRR) Building - East Canopy");
            }

            else {

                if(*dropoffPoint == 1)
                    strcpy(dropOff[searchresult][i], "Laguna Blvd. Guard House (across Paseo PHOENIX Gasoline Station)");

                else 
                    strcpy(dropOff[searchresult][i], "Milagros Del Rosario (MRR) Building - East Canopy");
            }

        }
                    
        else {
            strcpy(embarkationPoint[searchresult][i], "DLSU Laguna Campus - Milagros Del Rosario (MRR) Building - East Canopy");

            if(searchresult % 2 != 0) {

                if(*dropoffPoint == 1)
                    strcpy(dropOff[searchresult][i], "College of St. Benilde (CSB) along Taft Avenue");
                
                else if(*dropoffPoint == 2)
                    strcpy(dropOff[searchresult][i], "Gate 4: Gokongwei Gate");

                else if(*dropoffPoint == 3)
                    strcpy(dropOff[searchresult][i], "Gate 2: North Gate (HSSH)");

                else 
                    strcpy(dropOff[searchresult][i], "Gate 1: South Gate (LS Building Entrance)");
            }

            else {
                if(*dropoffPoint == 1)
                    strcpy(dropOff[searchresult][i], "Petron Gasoline Station along Gil Puyat Avenue");
                
                else if(*dropoffPoint == 2)
                    strcpy(dropOff[searchresult][i], "Gate 4: Gokongwei Gate");

                else if(*dropoffPoint == 3)
                    strcpy(dropOff[searchresult][i], "Gate 2: North Gate (HSSH)");

                else 
                    strcpy(dropOff[searchresult][i], "Gate 1: South Gate (LS Building Entrance)");
            }
        } 
    }
}

void embarkationCardEntry(String5 tripNo[], String100 embarkationPoint[][MAX_PASSENGERS], int *priorityNo, String100 lName, String100 fName1, String100 fName2, char *midIni, int *idNo, int *dropoffPoint, String100 dropOff[][MAX_PASSENGERS], int searchresult, String8 fixedTime[], String100 fixedRoute[]) {
    char confirmation;
    String100 embarkation;

    printf("You are now boarding the trip %s, ETD: %s, Route: ", tripNo[searchresult], fixedTime[searchresult]); 
        
    if (searchresult < 9)
        printf("%s\n\n", fixedRoute[0]);

    else 
        printf("%s\n\n", fixedRoute[1]);

    do {
        printf("Please Fill Up Your Embarkation Card:\n");
        displayPriorityNumber();
        printf("\n");

        *priorityNo = priorityNoEntry();
        printf("\n");

        *midIni = nameEntry(lName, fName1, fName2);
        printf("\n");

        *idNo = idNoEntry();
        printf("\n");
        
        if(searchresult == 0 || searchresult == 2 || searchresult == 4 || searchresult == 6 || searchresult == 8)
            *dropoffPoint = displayDropOffPoint1();

        else if(searchresult == 1 || searchresult == 3 || searchresult == 5 || searchresult == 7)
            *dropoffPoint = displayDropOffPoint2();

        else if(searchresult == 10 || searchresult == 12 || searchresult == 14 || searchresult == 16 || searchresult == 18)
            *dropoffPoint = displayDropOffPoint3();

        else 
            *dropoffPoint = displayDropOffPoint4();


        if(strcmp(fName2, "NA") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "na") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "Na") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "N/A") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "n/a") == 0)
            strcpy(fName2, "\0");
        
        else if(strcmp(fName2, "N/a") == 0)
            strcpy(fName2, "\0");
        
        else if(strcmp(fName2, "N") == 0)
            strcpy(fName2, "\0");
        
        else if(strcmp(fName2, "n") == 0)
            strcpy(fName2, "\0");

        else
            strcat(fName1, " ");

        strcat(fName1, fName2);

        if (searchresult >= 0 && searchresult <= 8)
            strcpy(embarkation, "DLSU Manila Campus - South Gate Driveway");
        
        else
            strcpy(embarkation, "DLSU Laguna Campus - Milagros Del Rosario (MRR) Building - East Canopy");

        embarkationandDropOff(embarkationPoint, dropoffPoint, dropOff, searchresult);

        printf("\nPlease Confirm if details are correct:\n\n");
        printf("Trip Number: %s\n", tripNo[searchresult]);
        printf("Embarkation Point: %s\n", embarkation);
        printf("Name: %s, %s %c.\n", lName, fName1, *midIni);    
        printf("ID Number: %d\n", *idNo);
        printf("Priority Number: %d\n", *priorityNo);
        printf("Drop-off Point: %d\n\n", *dropoffPoint);
        printf("Confirm? (y/n): ");
        do {
            scanf(" %c", &confirmation);

            if(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y')
                printf("Invalid Input, Please Try Again: ");

        } while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y');
        
    } while(confirmation != 'y' && confirmation != 'Y');
}

void specialShuttleEntry(String100 specialEmbarkationPt[][MAX_PASSENGERS_SPECIAL], int *priorityNo, String100 lName, String100 fName1, String100 fName2, char *midIni, int *idNo, int *dropoffPoint, String100 specialDropOff[][MAX_PASSENGERS_SPECIAL], int searchresult) {
    char confirmation;
    String100 embarkation;

    do {
        printf("Please Fill Up Your Embarkation Card:\n");
        displayPriorityNumber();
        printf("\n");

        *priorityNo = priorityNoEntry();
        printf("\n");

        *midIni = nameEntry(lName, fName1, fName2);
        printf("\n");

        *idNo = idNoEntry();
        printf("\n");

        if(searchresult < 9)
            *dropoffPoint = displayDropOffPoint2();

        else 
            *dropoffPoint = displayDropOffPoint3();


        if(strcmp(fName2, "NA") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "na") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "Na") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "N/A") == 0)
            strcpy(fName2, "\0");

        else if(strcmp(fName2, "n/a") == 0)
            strcpy(fName2, "\0");
        
        else if(strcmp(fName2, "N/a") == 0)
            strcpy(fName2, "\0");
        
        else if(strcmp(fName2, "N") == 0)
            strcpy(fName2, "\0");
        
        else if(strcmp(fName2, "n") == 0)
            strcpy(fName2, "\0");

        else
            strcat(fName1, " ");

        strcat(fName1, fName2);

        if (searchresult >= 0 && searchresult <= 8)
            strcpy(embarkation, "DLSU Manila Campus - South Gate Driveway");
        
        else
            strcpy(embarkation, "DLSU Laguna Campus - Milagros Del Rosario (MRR) Building - East Canopy");

        //embarkationandDropOff(specialEmbarkationPt, dropoffPoint, specialDropOff, searchresult);

        printf("\nPlease Confirm if details are correct:\n\n");
        printf("Embarkation Point: %s\n", embarkation);
        printf("Name: %s, %s %c.\n", lName, fName1, *midIni);    
        printf("ID Number: %d\n", *idNo);
        printf("Priority Number: %d\n", *priorityNo);
        printf("Drop-off Point: %d\n\n", *dropoffPoint);
        printf("Confirm? (y/n): ");
        do {
            scanf(" %c", &confirmation);

            if(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y')
                printf("Invalid Input, Please Try Again: ");

        } while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y');
        
    } while(confirmation != 'y' && confirmation != 'Y');
}

int tripNumberEntry(String5 tripNoEntry, String5 tripNo[]) {
    int searchResult;

    printf("Please Enter the Trip Number of the ride you wish to avail: ");
    do {
        scanf("%s", tripNoEntry);
        searchResult = searchTripNumber(tripNoEntry, tripNo, MAX_TRIPS);

        if(searchResult == -1)
            printf("That Trip Number is INVALID, Please Try Again: ");

    } while(searchResult == -1);

    return searchResult;
}

void displayTripNumber(String5 tripNo[], String8 fixedTime[], int size, String100 fixedRoute[]) {
    int i;

    printf("------------------------------------------------------------------------|\n");
    printf("Trip Number\t|\t  ETD\t\t|\t     Route\t\t|\n");
    printf("----------------|-----------------------|-------------------------------|\n");

    for (i = 0; i < size; i++) {
        printf(" [%s]\t|\t%s\t|", tripNo[i], fixedTime[i]);

        if (i == 4)
            printf("\t%s\t|\n", fixedRoute[0]);

        else if (i == 8)
            printf("\t\t\t\t|\n----------------|-----------------------|-------------------------------|\n");

        else if (i == 14)
            printf("\t%s\t|\n", fixedRoute[1]);

        else 
            printf("\t\t\t\t|\n");
    }
    
    printf("------------------------------------------------------------------------|\n");
}

int displayArrowsPersonnelMenu() {
    int readEntry, choice;

    printf("==========Arrows Peronnel Menu==========\n");
    printf("1 - View Passenger Count\n");
    printf("2 - View Drop-off Count\n");
    printf("3 - View Passenger Information\n");
    printf("4 - Load Passenger(Single Passenger)\n");
    printf("5 - Search Passenger\n");
    printf("6 - Load Recent Trip File (for viewing only)\n");
    printf("7 - Exit Program and Save to Text File\n");
    printf("Select an Option: ");
    do {
        readEntry = scanf("%d", &choice);
        getchar();

        if (readEntry != 1 || choice < 1 || choice > 7) 
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || choice < 1 || choice > 7);
    
    return choice;
}

int displayPassengerMenu() {
    int readEntry, choice;

    printf("==========Passenger Menu==========\n");
    printf("1 - Encode Passenger Information\n");
    printf("2 - Back to Main Menu\n");
    printf("Select an Option: ");
    do {
        readEntry = scanf("%d", &choice);
        getchar();

        if (readEntry != 1 || choice < 1 || choice > 2) 
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || choice < 1 || choice > 2);
    
    return choice;
}

int displayMainMenu() {
    int readEntry, choice;

    printf("==========Main Menu==========\n");
    printf("Select User Type: \n");
    printf("1 - Passenger\n");
    printf("2 - Arrows Personnel\n");
    printf("3 - Exit Program (End of day)\n");
    printf("User Type: ");
    do {
        readEntry = scanf("%d", &choice);
        getchar();

        if (readEntry != 1 || choice < 1 ||  choice > 3) 
            printf("Not a Valid Option, Please Try Again: ");

    } while(readEntry != 1 || choice < 1 || choice > 3);
    
    return choice;
}

void viewPassengerCount(struct embarkationCard trip[], String5 tripNoEntry) {
	
    int count = 0;
    int i;
    
    for (i = 0; i < MAX_PASSENGERS; i++) {
        if (trip[i].idNum != 0 && trip[i].priorityNum >= 1 && trip[i].priorityNum <= 6) {
            count++; 
        }
    }
    printf("\nPassenger Count for %s: %d\n", tripNoEntry, count);
	
	if (count == 13){
    	printf("This trip is full.\n");
	}

    printf("\n");
    printf("Legend:\n");
    printf("X - Taken\n");
    printf("O - Available\n");
    printf("\n");

	printf("Seating for Trip %s\n", tripNoEntry);

    for (i = 0; i < MAX_PASSENGERS; i++) {
        if (trip[i].idNum != 0){
		printf("[X] "); // Taken
		} 
        else 
		printf("[O] "); // Available
		
        if (i == 2 || i == 5 || i == 8 || i == 11){
		printf("\n"); // Formatting 
		}
		if (i == 12){
			printf("[Driver]\n"); // Driver Seat
		}
    }
    
    printf("\n");
    printf("View Passenger Count Complete, press any key to return to Main Menu . . . ");
    getch(); 
}

void viewDropoffPoint(struct embarkationCard trips[][MAX_PASSENGERS], String5 tripNoEntry, int searchresult) {
    int dropOffCount[5] = {0};  // dropOffCount[0] won't be used because they start at 1 (trips[searchresult][i].dropoffNum)
    int i;
    int count = 0;
    
    for (i = 0; i < MAX_PASSENGERS; i++){
        if (trips[searchresult][i].idNum != 0){
            dropOffCount[trips[searchresult][i].dropoffNum]++;
            count++;
        }
    }
	
	if (count == 13){
    	printf("\nThis trip is full.\n");
	}
	
    // Display the drop-off summary
    printf("Drop-off count for trip %s:\n", tripNoEntry);

    if (searchresult == 0 || searchresult == 2 || searchresult == 4 || searchresult == 6 || searchresult == 8){
        printf("1. Mamplasan Toll Exit: %d passengers\n", dropOffCount[1]);
        printf("2. Phase 5, San Jose Village: %d passengers\n", dropOffCount[2]);
        printf("3. Milagros Del Rosario (MRR) Building - East Canopy: %d passengers\n", dropOffCount[3]);
    } 
    else if (searchresult == 1 || searchresult == 3 || searchresult == 5 || searchresult == 7 /* or special shuttle*/){
        printf("1. Laguna Blvd. Guard House: %d passengers\n", dropOffCount[1]);
        printf("2. Milagros Del Rosario (MRR) Building - East Canopy: %d passengers\n", dropOffCount[2]);
    } 
    else if (searchresult == 10 || searchresult == 12 || searchresult == 14 || searchresult == 16 || searchresult == 18){
        printf("1. Petron Gasoline Station (Gil Puyat Ave): %d passengers\n", dropOffCount[1]);
        printf("2. Gate 4: Gokongwei Gate: %d passengers\n", dropOffCount[2]);
        printf("3. Gate 2: North Gate (HSSH): %d passengers\n", dropOffCount[3]);
        printf("4. Gate 1: South Gate (LS Building Entrance): %d passengers\n", dropOffCount[4]);
    } 
    else{
        printf("1. College of St. Benilde (CSB) along Taft Avenue: %d passengers\n", dropOffCount[1]);
        printf("2. Gate 4: Gokongwei Gate: %d passengers\n", dropOffCount[2]);
        printf("3. Gate 2: North Gate (HSSH): %d passengers\n", dropOffCount[3]);
        printf("4. Gate 1: South Gate (LS Building Entrance): %d passengers\n", dropOffCount[4]);
    }

    printf("\n");
    printf("View Drop-Off Point Complete, press any key to return to Main Menu . . . ");
    getch(); 
}

void viewPassengerInfo(struct embarkationCard trip[], String5 tripNoEntry){
	
    int i;
	int j;
	int count = 0;
	int notEmpty = 0;
    struct embarkationCard temp; 
    struct embarkationCard sortedTrip[MAX_PASSENGERS]; // We're going to make a copy of the passengers data and put them here

	// I made a new struct for sorted trips here, so that it won't tamper with the original trip array. 
	// It's like a placeholder for this function only
    for (i = 0; i < MAX_PASSENGERS; i++){
        sortedTrip[i] = trip[i];  
    }

    // Bubble Sort Algo for priority number (highest to lowest)
    for (i = 0; i < MAX_PASSENGERS - 1; i++){
        for (j = 0; j < MAX_PASSENGERS - i - 1; j++){
            if (sortedTrip[j].priorityNum > sortedTrip[j + 1].priorityNum){
                temp = sortedTrip[j];
                sortedTrip[j] = sortedTrip[j + 1];
                sortedTrip[j + 1] = temp;
            }
        }
    }

    printf("\nCurrent Passengers in %s:\n", tripNoEntry);
    
    for (i = 0; i < MAX_PASSENGERS; i++){
        if (sortedTrip[i].idNum != 0){
            count++;
            printf("Passenger %d: %s %c. %s (ID: %d, Priority: %d)\n", count, sortedTrip[i].name.fName, 
			sortedTrip[i].name.mIni, sortedTrip[i].name.laName, sortedTrip[i].idNum, sortedTrip[i].priorityNum);
            notEmpty = 1;
            // Displays the name, ID number, priority number
        }
    }
	
	if (count == 13){
    	printf("This trip is full.\n");
	}
	
    if (!notEmpty) {// Empty
        printf("There are no passengers yet!\n");
    }
    
	printf("\n");
    printf("\nView Passenger Information Complete, press any key to return to Main Menu . . . ");
    getch();
}

int apmValidEntry(String5 tripNoEntry, String5 tripNo[]) {
    int searchresult;

    printf("Enter Trip Number (Case Sensitive): ");
    do {
        scanf("%s", tripNoEntry);
        searchresult = searchTripNumber(tripNoEntry, tripNo, MAX_TRIPS);

        if (searchresult == -1) 
            printf("Invalid trip number. Please try again: ");

    } while(searchresult == -1);

    return searchresult;
}

void loadPassenger(struct embarkationCard trips[][MAX_PASSENGERS], String5 tripNo[], String100 embarkationPoint[][MAX_PASSENGERS], int *priorityNo, String100 lName, String100 fName1, String100 fName2, char *midIni, int *idNo, int *dropoffPoint, String100 dropOff[][MAX_PASSENGERS]){
	
	
    int searchresult;
    int i;	
    String5 tripNoEntry;
    int found = 0; 
    String100 embarkation;
    String100 embarkationTemp; 
	FILE *trip;
    trip = fopen("load.txt", "r");

    if (trip == NULL)
        printf("\nError opening file! Please make a text file with a filename \"load.txt\" to manually input passengers\n\n");
     
	else{
		
        fscanf(trip, "%s", tripNoEntry);
		fscanf(trip, " %[^\n]s", embarkationTemp);   // This wont go anywhere. Only for formatting purposes
        fscanf(trip, "%s %s %s  %c", lName, fName1, fName2, midIni);    
        fscanf(trip, "%d", idNo);     
        fscanf(trip, "%d", priorityNo);  
        fscanf(trip, "%d", dropoffPoint); 

        fclose(trip);

        searchresult = searchTripNumber(tripNoEntry, tripNo, MAX_TRIPS);

        embarkationandDropOff(embarkationPoint, dropoffPoint, dropOff, searchresult);
        
        if (searchresult == -1){
            printf("Invalid trip number!\n");
        } 
		
		else{

        if (searchresult >= 0 && searchresult <= 8)
            strcpy(embarkation, "DLSU Manila Campus - South Gate Driveway");
        
        
        else{
            strcpy(embarkation, "DLSU Laguna Campus - Milagros Del Rosario (MRR) Building - East Canopy");
}	

		strcat(fName1, " "); //only for this function so that it can register spaces
		strcat(fName1, fName2);
		

        printf("\nManual Passenger Loading Details:\n\n");
        printf("Trip Number: %s\n", tripNoEntry);
        printf("Embarkation Point: %s\n", embarkation);
        printf("Name: %s, %s %c.\n", lName, fName1, *midIni);    
        printf("ID Number: %d\n", *idNo);
        printf("Priority Number: %d\n", *priorityNo);
        printf("Drop-off Point: %d\n\n", *dropoffPoint);
        
            for (i = 0; i < MAX_PASSENGERS; i++){
                if (trips[searchresult][i].idNum == 0 && found == 0){ 
                    strcpy(trips[searchresult][i].name.laName, lName);
                    strcpy(trips[searchresult][i].name.fName, fName1);
                    trips[searchresult][i].name.mIni = *midIni;
                    trips[searchresult][i].idNum = *idNo;
                    trips[searchresult][i].priorityNum = *priorityNo;
                    trips[searchresult][i].dropoffNum = *dropoffPoint;

                    found = 1; 
                    printf("Load Passenger Complete!\n\n");
                }
            }

            if (!found){
                printf("No available seats for this trip.\n");
            }
        }
    }
    printf("Press any key to return to Main Menu . . . ");
    getch();
}

void searchPassenger(struct embarkationCard trips[][MAX_PASSENGERS], String5 tripNo[], String100 lName) {
   
    int found = 0;
    int i; 
    int j;
    int count = 0;
    

    for (i = 0; i < MAX_TRIPS; i++){
        for (j = 0; j < MAX_PASSENGERS; j++) {
            if (strcmp(trips[i][j].name.laName, lName) == 0){
				count++;                
                printf("\nPassenger %d: %s %c. %s in Trip Number %s.\n", count, trips[i][j].name.fName, trips[i][j].name.mIni, trips[i][j].name.laName, tripNo[i]);
            	found = 1;
            	// Displays passenger name along with trip number
            }
        }
    }
	
    if (!found){ // Not found
        printf("\nWe searched far and wide, but %s is not in any of the trips.\n", lName);
    }

    printf("\n");
    printf("Search Passenger Complete, press any key to return to Main Menu . . . ");
    getch(); 
}

void viewRecentTripFile(struct embarkationCard trips[][MAX_PASSENGERS], String5 tripNo[], String100 embarkationPoint[][MAX_PASSENGERS], int *priorityNo, String100 lName, String100 fName1, String100 fName2, char *midIni, int *idNo, int *dropoffPoint, String100 dropOff[][MAX_PASSENGERS]) {
    
    FILE *trip;
    
    String5 tripNoEntry;
    String100 embarkation;
    int searchresult;
    String100 embarkationTemp;
    
    int readEntry;
    int day, month;
	int d1, d2, m1, m2;
	char c1, c2, c3, c4;
    char nameofFile[20] = "Trip-dd-mm-2025.txt";

    printf("\nEnter Day (1-31): ");
    do {
        readEntry = scanf("%d", &day);
        getchar();

        if(readEntry != 1 || day > 31 || day < 1)
            printf("Invalid Day No., Please Try Again: ");

    }while(readEntry != 1 || day > 31 || day < 1);

    printf("Enter Month (1-12): ");
    do {
        readEntry = scanf("%d", &month);
        getchar();

        if(readEntry != 1 || month > 12 || month < 1)
            printf("Invalid Month No., Please Try Again: ");

    }while(readEntry != 1 || month > 12 || month < 1);
    
    d1 = day / 10;
	d2 = day % 10;              // extracting each digit
	m1 = month / 10;
	m2 = month % 10;                
    //----------------------------------------------------------------------------------------------------/
    c1 = d1 + 48;
	c2 = d2 + 48;               // converting each digit into char
	c3 = m1 + 48;
	c4 = m2 + 48;                   
    //----------------------------------------------------------------------------------------------------/
	nameofFile[5] = c1;
	nameofFile[6] = c2;         //assigning each character to array nameofFile
	nameofFile[8] = c3;
	nameofFile[9] = c4;
    //----------------------------------------------------------------------------------------------------/
    trip = fopen(nameofFile, "r");
    
    if (trip == NULL) {
        printf("\nError opening file! Please make a text file with a filename \"date.txt\" to read passengers\n\n");
    }
    
	else
    while (!feof(trip)){
       
	      	fscanf(trip, "%s", tripNoEntry);
			fscanf(trip, " %[^\n]s", embarkationTemp); 
	        fscanf(trip, "%s %s %s  %c", lName, fName1, fName2, midIni);    
	        fscanf(trip, "%d", idNo);     
	        fscanf(trip, "%d", priorityNo);  
	        fscanf(trip, "%d", dropoffPoint);
            
            searchresult = searchTripNumber(tripNoEntry, tripNo, MAX_TRIPS);

            embarkationandDropOff(embarkationPoint, dropoffPoint, dropOff, searchresult);
            
            if (searchresult == -1){
            printf("Invalid trip number!\n");
        } 
		
			else{
	
	        if (searchresult >= 0 && searchresult <= 8)
	            strcpy(embarkation, "DLSU Manila Campus - South Gate Driveway");
	        
	        
	        else{
	            strcpy(embarkation, "DLSU Laguna Campus - Milagros Del Rosario (MRR) Building - East Canopy");
			}	
            
                strcat(fName1, " ");
                strcat(fName1, fName2);
                
                printf("Trip Number: %s\n", tripNoEntry);
                printf("Embarkation Point: %s\n", embarkation);
                printf("Name: %s %s %c.\n", lName, fName1, *midIni);
                printf("ID Number: %d\n", *idNo);
                printf("Priority Number: %d\n", *priorityNo);
                printf("Drop-off Point: %d\n\n", *dropoffPoint);
            }
        
    }

    fclose(trip);

    printf("\nView Recent Trip File Complete, press any key to return to Main Menu . . . ");
    getch(); 
}


void saveData(struct embarkationCard trips[][MAX_PASSENGERS], String5 tripNo[], String100 embarkationPoint[][MAX_PASSENGERS], String100 dropOff[][MAX_PASSENGERS]){
	
	FILE *trip;

    int readEntry;
    int day, month;
	int d1, d2, m1, m2;
	char c1, c2, c3, c4;
    char nameofFile[20] = "Trip-dd-mm-2025.txt";

    printf("\nEnter Day (1-31): ");
    do {
        readEntry = scanf("%d", &day);
        getchar();

        if(readEntry != 1 || day > 31 || day < 1)
            printf("Invalid Day No., Please Try Again: ");

    }while(readEntry != 1 || day > 31 || day < 1);

    printf("Enter Month (1-12): ");
    do {
        readEntry = scanf("%d", &month);
        getchar();

        if(readEntry != 1 || month > 12 || month < 1)
            printf("Invalid Month No., Please Try Again: ");

    }while(readEntry != 1 || month > 12 || month < 1);
    
    d1 = day / 10;
	d2 = day % 10;              // extracting each digit
	m1 = month / 10;
	m2 = month % 10;                
    //----------------------------------------------------------------------------------------------------/
    c1 = d1 + 48;
	c2 = d2 + 48;               // converting each digit into char
	c3 = m1 + 48;
	c4 = m2 + 48;                   
    //----------------------------------------------------------------------------------------------------/
	nameofFile[5] = c1;
	nameofFile[6] = c2;         //assigning each character to array nameofFile
	nameofFile[8] = c3;
	nameofFile[9] = c4;
    //----------------------------------------------------------------------------------------------------/

	int i, j;

    trip = fopen(nameofFile, "a");

 	for (i = 0; i < MAX_TRIPS; i++){
        for (j = 0; j < MAX_PASSENGERS; j++){
            if (trips[i][j].idNum != 0){ 
                fprintf(trip, "%s\n", tripNo[i]); 
                fprintf(trip, "%s\n", embarkationPoint[i][j]); 
                fprintf(trip, "%s, %s %c\n", trips[i][j].name.laName, trips[i][j].name.fName, trips[i][j].name.mIni); // new entries in fprintf srting
                fprintf(trip, "%d\n", trips[i][j].idNum); 
                fprintf(trip, "%d\n", trips[i][j].priorityNum); 
                fprintf(trip, "%d\n\n", trips[i][j].dropoffNum); 
            }
        }
    }

    fclose(trip);
}

int main() {
    int terminated = 0;

    int mmchoice;
    int pmchoice;
    int apmchoice;
    int searchresult;
    int lagunaIndex;

    int manilaCtr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // copy paste this if you want to test: {13, 13, 13, 13, 13, 13, 13, 12, 12}
    int lagunaCtr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    String5 tripNo[MAX_TRIPS] = {"AE101", "AE102", "AE103", "AE104", "AE105", "AE106", "AE107", "AE108", "AE109", 
                           "AE150", "AE151", "AE152", "AE153", "AE154", "AE155", "AE156", "AE157", "AE158", "AE159", "AE160"};
    String8 fixedTime[MAX_TRIPS] = {"06:00 am", "07:30 am", "09:30 am", "11:00 am", "01:00 pm", "02:30 pm", 
                             "03:30 pm", "05:00 pm", "06:15 pm", "05:30 am", "05:45 am", "07:00 am", 
                             "07:30 am", "09:00 am", "11:00 am", "01:00 pm", "02:30 pm", "03:30 pm", 
                             "05:00 pm", "06:15 pm"};
    String100 fixedRoute[2] = {"Manila to Laguna", "Laguna to Manila"};

    String5 tripNoEntry;
    String100 embarkationPoint[MAX_TRIPS][MAX_PASSENGERS] = {{{0}}};; 
    String100 lName, fName1, fName2;
    char midIni;
    int idNo;
    int priorityNo;
    int dropoffPoint;
    String100 dropOff[MAX_TRIPS][MAX_PASSENGERS] = {{{0}}};; 
	
    struct embarkationCard trips[MAX_TRIPS][MAX_PASSENGERS] = {{{0}}};
    struct embarkationCard special_M[MAX_PASSENGERS_SPECIAL] = {{0}};  //new entry
    struct embarkationCard special_L[MAX_PASSENGERS_SPECIAL] = {{0}};  //new entry

    String100 specialEmbarkationPt[2][MAX_PASSENGERS_SPECIAL] = {{{0}}};  //new entry
    String100 specialDropOff[2][MAX_PASSENGERS_SPECIAL] = {{{0}}};  //new entry 

    int specialMCtr = 0;  //new entry
    int specialLCtr = 0;  //new entry

    printf("\nWelcome to the De La Salle University Arrows Express Line Embarkation System!\n\n");

    do {
        mmchoice = displayMainMenu();

        if (mmchoice == 1) {
            printf("\n");
            pmchoice = displayPassengerMenu();

            if (pmchoice == 1) {
                system("cls");
                printf("Here is the schedule of the Arrows Express Line\n");
                displayTripNumber(tripNo, fixedTime, MAX_TRIPS, fixedRoute);
                printf("\n");

                searchresult = tripNumberEntry(tripNoEntry, tripNo);

                printf("\n=========================================================================\n\n");
                
                if(searchresult < 9) {
        
                    if(manilaCtr[8] == MAX_PASSENGERS) {
                        printf("The Last Trip from Manila to Laguna is now full, you are now redirected to the Special Shuttle\n\n");
                        specialShuttleEntry(specialEmbarkationPt, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint, specialDropOff, searchresult);
                        specialMCtr++;
                    }

                    else {
                        while (manilaCtr[searchresult] == MAX_PASSENGERS) {
                            printf("Trip %s is already full, redirecting to the next trip. . .\n", tripNo[searchresult]);
                            searchresult++;
                        }

                        if(manilaCtr[searchresult] < MAX_PASSENGERS){
                            manilaCtr[searchresult]++;
                        }

                        embarkationCardEntry(tripNo, embarkationPoint, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint, dropOff, searchresult, fixedTime, fixedRoute);
                        
                        int i; 
                        int stored = 0;
                        for (i = 0; i < MAX_PASSENGERS; i++) {
                            if (trips[searchresult][i].idNum == 0 && stored == 0) {  
                                trips[searchresult][i].priorityNum = priorityNo;
                                strcpy(trips[searchresult][i].name.laName, lName); 
                                strcpy(trips[searchresult][i].name.fName, fName1);
                                trips[searchresult][i].name.mIni = midIni;
                                trips[searchresult][i].idNum = idNo;
                                trips[searchresult][i].dropoffNum = dropoffPoint;
                                
                                stored = 1;        
                            }
                        }
                    }  
                } 
                    
                else {
                    if(lagunaCtr[10] == MAX_PASSENGERS){
                        printf("The Last Trip from Laguna to Manila is now full, you are now redirected to the Special Shuttle\n\n");\
                        specialShuttleEntry(specialEmbarkationPt, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint, specialDropOff, searchresult);
                        specialLCtr++;
                    }

                    else {
                        lagunaIndex = searchresult - 9;

                        while (lagunaCtr[lagunaIndex] == MAX_PASSENGERS) {
                            printf("Trip %s is already full, redirecting to the next trip. . .\n", tripNo[searchresult]);
                            lagunaIndex++;
                            searchresult++;
                        }

                        if(lagunaCtr[lagunaIndex] < MAX_PASSENGERS) {
                            lagunaCtr[lagunaIndex]++; 
                        }

                        embarkationCardEntry(tripNo, embarkationPoint, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint, dropOff, searchresult, fixedTime, fixedRoute);

                        int i; 
                        int stored = 0;
                        for (i = 0; i < MAX_PASSENGERS; i++) {
                            if (trips[searchresult][i].idNum == 0 && stored == 0) {  
                                trips[searchresult][i].priorityNum = priorityNo;
                                strcpy(trips[searchresult][i].name.laName, lName); 
                                strcpy(trips[searchresult][i].name.fName, fName1);
                                trips[searchresult][i].name.mIni = midIni;
                                trips[searchresult][i].idNum = idNo;
                                trips[searchresult][i].dropoffNum = dropoffPoint;
                                
                                stored = 1;        
                            }
                        }
                    } 
                }      
            }
            system("cls");
            // for (int i = 0; i < 9; i++)
            //     printf("%d ", manilaCtr[i]);

            // printf("\n");

            // for (int j = 0; j < 11; j++)
            //     printf("%d ", lagunaCtr[j]);

            // printf("\n\n");
        }

        else if (mmchoice == 2) {
            printf("\n");
            apmchoice = displayArrowsPersonnelMenu();

            switch (apmchoice) {
                case 1: 
                    system("cls");
                    searchresult = apmValidEntry(tripNoEntry, tripNo);
                    viewPassengerCount(trips[searchresult], tripNoEntry);
                    system("cls");
                    break;

                case 2:
                    system("cls");
                    searchresult = apmValidEntry(tripNoEntry, tripNo);
                    viewDropoffPoint(trips, tripNoEntry, searchresult);
                    system("cls");
                    break;

                case 3: 
                    system("cls");
                    searchresult = apmValidEntry(tripNoEntry, tripNo);
                    viewPassengerInfo(trips[searchresult], tripNoEntry);
                    system("cls");
                    break;

                case 4:
                    system("cls");
                    loadPassenger(trips, tripNo, embarkationPoint, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint, dropOff);
                    system("cls");
                    break;

                case 5:
                    system("cls");
                	printf("Search Passenger by Last Name: ");
                	scanf("%s", lName);
                    searchPassenger(trips, tripNo, lName);
                    system("cls");
                    break;

                case 6:
                    system("cls");
                    viewRecentTripFile(trips, tripNo, embarkationPoint, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint, dropOff);
                    system("cls");
                    break;

                case 7:
                  	terminated = 1; 
            }
        }
    } while (mmchoice != 3 && !terminated);

    saveData(trips, tripNo, embarkationPoint, dropOff);
    printf("\nExiting Program and Saving to Text File, press any key to continue. . .\n");
    getch();
    printf("\nThank you for using the Arrows Express Line Embarkation System!\n");

    return 0;
}
