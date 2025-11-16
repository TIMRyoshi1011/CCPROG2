/*
Programmed by: Marcus Timothy V. Ramos [12313408]
Last modified: Mar. 09, 2025; 12:12AM
Version: 1.0 (Update to the next version)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //for system("cls");

typedef char String5[6];
typedef char String8[9];
typedef char String50[51];

typedef struct {
    String50 fName;
    char mIni;
    String50 laName;
} fullName;

struct embarkationCard {
    int priorityNum;
    fullName name;
    int idNum;
    int dropoffNum;
};

/*
Notes:
- special shuttle (worst case scenario) is still unavailable
- option 3 in main menu should not end the program but rather end the day (fix this on the 3rd week)
- Passenger Features is 80% complete
- missing are text files and special shuttle assignment
- Priority levels are still not fixed (do this on the 3rd week)
- ALL invalid inputs are now fixed (can still test just to be sure)
- to test each information inputted, can use these codes (Note: put these before i++; and make sure to 
    comment out systm("cls"); before using the codes, and change the name according to trip number)

    printf("\n");
    printf("Final in struct (For AE101 only):\n");
    printf("Priority Number: %d\n", tripAE101[i].priorityNum);
    printf("Name: %s %c. %s\n", tripAE101[i].name.fName, tripAE101[i].name.mIni, tripAE101[i].name.laName);
    printf("ID Number: %d\n", tripAE101[i].idNum);
    printf("Drop-off Point: %d\n\n", tripAE101[i].dropoffNum);

- Feature for both types is still unavailable (notification if the trip is full) (do this on the 3rd week)
- Arrows Express Personnel Features is still unavailable (start this after Hands-On Exam #2, must finish on that week, max=50%)

Schedule:
1. Finish Arrows Express Personnel Features after HOE#2
2. Finish Feature for both types and fixing of other features on the 3rd week (can do bonus feature if there's extra time)
3. Do some finishing touches, testing, debugging, adding comments, and making of the test script on the 4th and final week
*/

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

        if(readEntry != 1 || idNo < 10000000 || idNo > 99999999)
            printf("Invalid ID Number, Please Try Again: ");

    } while(readEntry != 1 || idNo < 10000000 || idNo > 99999999);

    return idNo;
}

char nameEntry(String50 lName, String50 fName1, String50 fName2) {
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

    printf("Enter First Name 1: ");
    do {
        scanf("%s", fName1);
        readEntry = strcmp(fName1, "A");

        if(readEntry == -1)
            printf("INVALID Name, Please Type Again: ");

    } while(readEntry == -1);

    printf("Note: type NA if you have only 1 First Name\n");
    printf("Enter First Name 2: ");
    do {
        scanf("%s", fName2);
        readEntry = strcmp(fName2, "A");

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

void embarkationCardEntry(String5 tripNoEntry, String5 tripNo[], int *priorityNo, String50 lName, String50 fName1, String50 fName2, char *midIni, int *idNo, int *dropoffPoint) {
    int tripNumber;
    char confirmation;

    tripNumber = searchTripNumber(tripNoEntry, tripNo, 20);

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
        
        if(tripNumber == 0 || tripNumber == 2 || tripNumber == 4 || tripNumber == 6 || tripNumber == 8)
            *dropoffPoint = displayDropOffPoint1();

        else if(tripNumber == 1 || tripNumber == 3 || tripNumber == 5 || tripNumber == 7)
            *dropoffPoint = displayDropOffPoint2();

        else if(tripNumber == 10 || tripNumber == 12 || tripNumber == 14 || tripNumber == 16 || tripNumber == 18)
            *dropoffPoint = displayDropOffPoint3();

        else 
            *dropoffPoint = displayDropOffPoint4();


        if(strcmp(fName2, "NA") == 0)
            strcpy(fName2, "\b\0");

        strcat(fName1, " ");
        strcat(fName1, fName2);

        printf("\nPlease Confirm if details are correct:\n\n");
        printf("Priority Number: %d\n", *priorityNo);
        printf("Name: %s %c. %s\n", fName1, *midIni, lName);
        printf("ID Number: %d\n", *idNo);
        printf("Drop-off Point: %d\n\n", *dropoffPoint);
        printf("Confirm? (y/n): ");
        do {
            scanf(" %c", &confirmation);

            if(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y')
                printf("Invalid Input, Please Try Again: ");

        } while(confirmation != 'n' && confirmation != 'N' && confirmation != 'y' && confirmation != 'Y');

        system("cls");
        
    } while(confirmation != 'y' && confirmation != 'Y');
}

int tripNumberEntry(String5 tripNoEntry, String5 tripNo[]) {
    int searchResult;

    printf("Please Enter the Trip Number of the ride you wish to avail: ");
    do {
        scanf("%s", tripNoEntry);
        searchResult = searchTripNumber(tripNoEntry, tripNo, 20);

        if(searchResult == -1)
            printf("That Trip Number is INVALID, Please Try Again: ");

    } while(searchResult == -1);

    return searchResult;
}

void displayTripNumber(String5 tripNo[], String8 fixedTime[], int size, String50 fixedRoute[]) {
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
    printf("6 - Load Recent Trip File for Viewing\n");
    printf("7 - Back to Main Menu\n");
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

int main() {

    int mmchoice;
    int pmchoice;
    int apmchoice;
    int searchresult;

    String5 tripNo[20] = {"AE101", "AE102", "AE103", "AE104", "AE105", "AE106", "AE107", "AE108", "AE109", "AE150", "AE151", "AE152", "AE153", "AE154", "AE155", "AE156", "AE157", "AE158", "AE159", "AE160"};
    String8 fixedTime[20] = {"06:00 am", "07:30 am", "09:30 am", "11:00 am", "01:00 pm", "02:30 pm", "03:30 pm", "05:00 pm", "06:15 pm", "05:30 am", "05:45 am", "07:00 am", "07:30 am", "09:00 am", "11:00 am", "01:00 pm", "02:30 pm", "03:30 pm", "05:00 pm", "06:15 pm"};
    String50 fixedRoute[2] = {"Manila to Laguna", "Laguna to Manila"};
    
    String5 tripNoEntry;

    int priorityNo;
    String50 lName, fName1, fName2;
    char midIni;
    int idNo;
    int dropoffPoint;

    struct embarkationCard tripAE101[13];
    struct embarkationCard tripAE102[13];
    struct embarkationCard tripAE103[13];
    struct embarkationCard tripAE104[13];
    struct embarkationCard tripAE105[13];
    struct embarkationCard tripAE106[13];
    struct embarkationCard tripAE107[13];
    struct embarkationCard tripAE108[13];
    struct embarkationCard tripAE109[13];

    struct embarkationCard tripAE150[13];
    struct embarkationCard tripAE151[13];
    struct embarkationCard tripAE152[13];
    struct embarkationCard tripAE153[13];
    struct embarkationCard tripAE154[13];
    struct embarkationCard tripAE155[13];
    struct embarkationCard tripAE156[13];
    struct embarkationCard tripAE157[13];
    struct embarkationCard tripAE158[13];
    struct embarkationCard tripAE159[13];
    struct embarkationCard tripAE160[13];

    printf("\nWelcome to the De La Salle University Arrows Express Line Embarkation System!\n\n");

    do {
        mmchoice = displayMainMenu();

        if(mmchoice == 1) {
            printf("\n");
            pmchoice = displayPassengerMenu();

            if (pmchoice == 1) {
                system("cls");
                printf("Here is the schedule of the Arrows Express Line\n");
                displayTripNumber(tripNo, fixedTime, 20, fixedRoute);
                printf("\n");
                searchresult = tripNumberEntry(tripNoEntry, tripNo);
                system("cls");
                
                printf("\nYou have chosen the trip %s, ETD: %s, Route: ", tripNo[searchresult], fixedTime[searchresult]);

                if (searchresult < 9)
                    printf("%s\n", fixedRoute[0]);

                else 
                    printf("%s\n", fixedRoute[1]);

                printf("\n=========================================================================\n\n");
                
                embarkationCardEntry(tripNoEntry, tripNo, &priorityNo, lName, fName1, fName2, &midIni, &idNo, &dropoffPoint);
                
                if (searchresult == 0) {
                    int i = 0;

                    tripAE101[i].priorityNum = priorityNo;
                    strcpy(tripAE101[i].name.fName, fName1);
                    tripAE101[i].name.mIni = midIni;
                    strcpy(tripAE101[i].name.laName, lName);
                    tripAE101[i].idNum = idNo;
                    tripAE101[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 1) {
                    int i = 0;

                    tripAE102[i].priorityNum = priorityNo;
                    strcpy(tripAE102[i].name.fName, fName1);
                    tripAE102[i].name.mIni = midIni;
                    strcpy(tripAE102[i].name.laName, lName);
                    tripAE102[i].idNum = idNo;
                    tripAE102[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 2) {
                    int i = 0;

                    tripAE103[i].priorityNum = priorityNo;
                    strcpy(tripAE103[i].name.fName, fName1);
                    tripAE103[i].name.mIni = midIni;
                    strcpy(tripAE103[i].name.laName, lName);
                    tripAE103[i].idNum = idNo;
                    tripAE103[i].dropoffNum = dropoffPoint;
                    
                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 3) {
                    int i = 0;

                    tripAE104[i].priorityNum = priorityNo;
                    strcpy(tripAE104[i].name.fName, fName1);
                    tripAE104[i].name.mIni = midIni;
                    strcpy(tripAE104[i].name.laName, lName);
                    tripAE104[i].idNum = idNo;
                    tripAE104[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 4) {
                    int i = 0;

                    tripAE105[i].priorityNum = priorityNo;
                    strcpy(tripAE105[i].name.fName, fName1);
                    tripAE105[i].name.mIni = midIni;
                    strcpy(tripAE105[i].name.laName, lName);
                    tripAE105[i].idNum = idNo;
                    tripAE105[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 5) {
                    int i = 0;

                    tripAE106[i].priorityNum = priorityNo;
                    strcpy(tripAE106[i].name.fName, fName1);
                    tripAE106[i].name.mIni = midIni;
                    strcpy(tripAE106[i].name.laName, lName);
                    tripAE106[i].idNum = idNo;
                    tripAE106[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 6) {
                    int i = 0;

                    tripAE107[i].priorityNum = priorityNo;
                    strcpy(tripAE107[i].name.fName, fName1);
                    tripAE107[i].name.mIni = midIni;
                    strcpy(tripAE107[i].name.laName, lName);
                    tripAE107[i].idNum = idNo;
                    tripAE107[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 7) {
                    int i = 0;

                    tripAE108[i].priorityNum = priorityNo;
                    strcpy(tripAE108[i].name.fName, fName1);
                    tripAE108[i].name.mIni = midIni;
                    strcpy(tripAE108[i].name.laName, lName);
                    tripAE108[i].idNum = idNo;
                    tripAE108[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 8) {
                    int i = 0;

                    tripAE109[i].priorityNum = priorityNo;
                    strcpy(tripAE109[i].name.fName, fName1);
                    tripAE109[i].name.mIni = midIni;
                    strcpy(tripAE109[i].name.laName, lName);
                    tripAE109[i].idNum = idNo;
                    tripAE109[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 9) {
                    int i = 0;

                    tripAE150[i].priorityNum = priorityNo;
                    strcpy(tripAE150[i].name.fName, fName1);
                    tripAE150[i].name.mIni = midIni;
                    strcpy(tripAE150[i].name.laName, lName);
                    tripAE150[i].idNum = idNo;
                    tripAE150[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 10) {
                    int i = 0;

                    tripAE151[i].priorityNum = priorityNo;
                    strcpy(tripAE151[i].name.fName, fName1);
                    tripAE151[i].name.mIni = midIni;
                    strcpy(tripAE151[i].name.laName, lName);
                    tripAE151[i].idNum = idNo;
                    tripAE151[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 11) {
                    int i = 0;

                    tripAE152[i].priorityNum = priorityNo;
                    strcpy(tripAE152[i].name.fName, fName1);
                    tripAE152[i].name.mIni = midIni;
                    strcpy(tripAE152[i].name.laName, lName);
                    tripAE152[i].idNum = idNo;
                    tripAE152[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 12) {
                    int i = 0;

                    tripAE153[i].priorityNum = priorityNo;
                    strcpy(tripAE153[i].name.fName, fName1);
                    tripAE153[i].name.mIni = midIni;
                    strcpy(tripAE153[i].name.laName, lName);
                    tripAE153[i].idNum = idNo;
                    tripAE153[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 13) {
                    int i = 0;

                    tripAE154[i].priorityNum = priorityNo;
                    strcpy(tripAE154[i].name.fName, fName1);
                    tripAE154[i].name.mIni = midIni;
                    strcpy(tripAE154[i].name.laName, lName);
                    tripAE154[i].idNum = idNo;
                    tripAE154[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 14) {
                    int i = 0;

                    tripAE155[i].priorityNum = priorityNo;
                    strcpy(tripAE155[i].name.fName, fName1);
                    tripAE155[i].name.mIni = midIni;
                    strcpy(tripAE151[i].name.laName, lName);
                    tripAE155[i].idNum = idNo;
                    tripAE155[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 15) {
                    int i = 0;

                    tripAE156[i].priorityNum = priorityNo;
                    strcpy(tripAE156[i].name.fName, fName1);
                    tripAE156[i].name.mIni = midIni;
                    strcpy(tripAE156[i].name.laName, lName);
                    tripAE156[i].idNum = idNo;
                    tripAE156[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 16) {
                    int i = 0;

                    tripAE157[i].priorityNum = priorityNo;
                    strcpy(tripAE157[i].name.fName, fName1);
                    tripAE157[i].name.mIni = midIni;
                    strcpy(tripAE157[i].name.laName, lName);
                    tripAE157[i].idNum = idNo;
                    tripAE157[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 17) {
                    int i = 0;

                    tripAE158[i].priorityNum = priorityNo;
                    strcpy(tripAE158[i].name.fName, fName1);
                    tripAE158[i].name.mIni = midIni;
                    strcpy(tripAE158[i].name.laName, lName);
                    tripAE158[i].idNum = idNo;
                    tripAE158[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 18) {
                    int i = 0;

                    tripAE159[i].priorityNum = priorityNo;
                    strcpy(tripAE159[i].name.fName, fName1);
                    tripAE159[i].name.mIni = midIni;
                    strcpy(tripAE159[i].name.laName, lName);
                    tripAE159[i].idNum = idNo;
                    tripAE159[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                else if (searchresult == 19) {
                    int i = 0;

                    tripAE160[i].priorityNum = priorityNo;
                    strcpy(tripAE160[i].name.fName, fName1);
                    tripAE160[i].name.mIni = midIni;
                    strcpy(tripAE160[i].name.laName, lName);
                    tripAE160[i].idNum = idNo;
                    tripAE160[i].dropoffNum = dropoffPoint;

                    i++;
                    //insert codes in making a text file here
                }

                //insert else statement for special shuttle here
                system("cls");
            }
            printf("\n");     
        }

        else if(mmchoice == 2) {
            
            printf("\n");
            apmchoice = displayArrowsPersonnelMenu();

            if (apmchoice == 1) {
                printf("\n");
                printf("Pending\n"); 
            }

            else if (apmchoice == 2) {
                printf("\n");
                printf("Pending\n"); 
            }

            else if (apmchoice == 3) {
                printf("\n");
                printf("Pending\n"); 
            }

            else if (apmchoice == 4) {
                printf("\n");
                printf("Pending\n"); 
            }

            else if (apmchoice == 5) {
                printf("\n");
                printf("Pending\n"); 
            }

            else if (apmchoice == 6) {
                printf("\n");
                printf("Pending\n"); 
            }

            printf("\n");
        }

    } while(mmchoice != 3);

    printf("\nThank you for using the Arrows Express Line Embarkation System!\n");

    return 0;
}