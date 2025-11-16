/*
   DO NOT CHANGE/EDIT THIS C SOURCE FILE!!!

   It contains the main() function and several other functions for testing your source code RESERVE-LASTNAME.c.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reserve.h"

/*
   Set each element of the RESERVE array to "-#-" which means that there are NO reservations (yet).
*/
void Initialize(Str50 RESERVE[][NDAYS])
{    
     int i, j;
     
     for (i = 0; i < NMONTHS; i++) {
        for (j = 0; j < NDAYS; j++)
            strcpy(RESERVE[i][j], "-#-");  // "-#-" means no reservation, i.e., venue is available
     }
}

/*
   NOTE: there is NO NEED for you to understand the meaning of the steps in this function.
*/
void Populate(Str50 RESERVE[][NDAYS])
{
     FILE *fp;
     int row_index, col_index;
     Str50 str;


     fp = fopen("INPUT.TXT", "r");
     if (fp != NULL) {
         while ( fscanf(fp, "%d %d %s", &row_index, &col_index, str) == 3) {
             strcpy(RESERVE[row_index][col_index], str);
             //printf("row_index = %d, col_index = %d, str = %s\n", row_index, col_index, str);
         }         
     fclose(fp);          
     }   
     else {
         fprintf(stderr, "ERROR: File INPUT.TXT not found.  Pls inform your teacher about this.\n");
         exit(0);
    }
}

   
//--- Test Function #1: SearchChar() ---
void 
Test_TASK1()
{
    int retval;

    printf("**Test-Function-#1-SearchChar()**\n");
    retval = SearchChar('A', "HELLO");
    printf("  TESTCASE#1: %d\n", retval);
    
    retval = SearchChar('L', "HELLO");
    printf("  TESTCASE#2: %d\n", retval);

    retval = SearchChar('e', "HELLO");
    printf("  TESTCASE#3: %d\n", retval);

    retval = SearchChar('O', "HELLO");
    printf("  TESTCASE#4: %d\n", retval);

    retval = SearchChar('E', "HELLO");
    printf("  TESTCASE#5: %d\n", retval);
    
    printf("\n");
}

   
//--- Test Function #2: CheckAvailability() ---
void 
Test_TASK2()
{
    int DATE[5][2] = {  
                        { 0,  0},                     
                        { 1,  0},
                        { 1,  2},
                        { 1, 27},
                        {11,  0},
                     };

    Str50 RESERVE[NMONTHS][NDAYS];
    int retval;

    Initialize(RESERVE);
    Populate(RESERVE);

    printf("**Test-Function-#2-CheckAvailability()**\n");
    for (int i = 0; i < 5; i++) { 
         int month_index = DATE[i][0];
         int day_index = DATE[i][1];
         
         retval = CheckAvailability(RESERVE, month_index, day_index);
         printf("  TESTCASE#%d: %d\n", i+1, retval);
    }  

    printf("\n");
}


//--- Test Function #3: Who() ---
void 
Test_TASK3()
{
    int SCHED[10][3] = {  
                          {0, 0, 1},
                          {0, 0, 2},
                          {1, 0, 1},
                          {1, 0, 2},
                          {1, 2, 1},
                          {1, 2, 2},
                          {1, 27, 1},
                          {1, 27, 2},
                          {8, 8, 1},
                          {8, 8, 2},                     
                     };
    Str50 answer;
    Str50 RESERVE[NMONTHS][NDAYS];
 
    Initialize(RESERVE);
    Populate(RESERVE);

    printf("**Test-Function-#3-Who()**\n");
    for (int i = 0; i < 10; i++) { 
         int month_index = SCHED[i][0];
         int day_index = SCHED[i][1];
         int flag = SCHED[i][2];
         strcpy(answer, "WAKARANAI");
       
         Who(RESERVE, month_index, day_index, flag, answer);
         printf("  TESTCASE#%d: %s\n", i+1, answer);
    }

    printf("\n");
}

//--- Test Function #4: Book() ---
void 
Test_TASK4()
{
    int SCHED[6][3] = {  
                          {0, 0, 1},
                          {0, 0, 2},
                          {1, 2, 1},
                          {1, 2, 2},
                          {5, 5, 1},
                          {5, 5, 2},
                      };
    char NAME[6][10] =  { "ALPHA", "BETA", "CHARLIE", "DELTA", "EPSILON", "FOXTROT"};
    char NUMBER[6][6] = { "11111", "22222", "33333",  "44444", "55555",   "66666"  };
    Str50 RESERVE[NMONTHS][NDAYS];

    Initialize(RESERVE);
    Populate(RESERVE);

    printf("**Test-Function-#4-Book()**\n");
    for (int i = 0; i < 6; i++) {
         int month_index = SCHED[i][0];
         int day_index = SCHED[i][1];
         int flag = SCHED[i][2];

         int retval = Book(RESERVE, month_index, day_index, flag, NAME[i], NUMBER[i]);
         printf("  TESTCASE#%d: %d %s\n", i+1, retval, RESERVE[month_index][day_index]);
    }
    printf("\n");
}


//--- Test Function #5: Book() ---
void 
Test_TASK5()
{
    Str50 RESERVE[NMONTHS][NDAYS];
    int COUNT[NDAYS];

    //          
    // NOTE: the info added via Book() function calls will NOT appear in this test.
    //       This ensures that only the logic of CountReservations() without the effect of Book() is checked.
    //
    Initialize(RESERVE);
    Populate(RESERVE);

    printf("**Test-Function-#5-Count()**\n");
    for (int i = 0; i < NMONTHS; i++)
        COUNT[i] = 888; // note: this is just a dummy value used for testing purposes only

    CountReservations(RESERVE, COUNT);

    for (int i = 0; i < NMONTHS; i++)
        printf("  COUNT[%d] %d\n", i, COUNT[i]);
}

/*
    This is the main() function for testing your solution.  
	
    You are not supposed to modify the contents and the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
    copy this file, and make changes on your copy.
	
    Note that the teacher-in-charge of checking your solution may use another set of input data 
    and a different main() function.  
	
    Your functions should work correctly even with a different set of input data and a different main() function.
*/
int 
main()
{   
    Test_TASK1();
    Test_TASK2();
    Test_TASK3();
    Test_TASK4();
    Test_TASK5();
    
    return 0;
}