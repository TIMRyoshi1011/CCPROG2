/*
   RESERVE problem source code.

   Encode your LASTNAME, FIRSTNAME: _______________________   SECTION: ___
   
   1. First make sure to rename this file by replacing LASTNAME with your own last name. For example, 
      if your last name is SANTOS, then this file should be named as RESERVE-SANTOS.c.
   
   2. Encode your solution using this file.  This is the C source file that you should submit/upload
      via the Canvas submission page.
   
      Follow all instructions in the Problem Specifications (PDF file), and the instructions written
      as comments in this skeleton file. Non-compliance will result to a reduction in score/grade 
      for this exam.

   3. Compile your C source file in the command line as follows:

           prompt> gcc -Wall RESERVE-LASTNAME.c  (press Enter)

      This will produce a.exe file by default if there is no error.  If there is a warning or an error, 
      fix it first, and then re-compile.

      Make sure that there are NO warnings before your run the exe file.

   4. Run/test your a.exe file in the command line as follows:

           prompt> a    

      The data to be used in the program will come from the contents of the accompanying INPUT.TXT file.

      Perform output redirection to store the output of your program into a text file as follows:

           prompt> a > ACTUAL-LASTNAME.TXT

   5. Compare the actual output of your program, i.e., ACTUAL-LASTNAME.TXT with the contents of the accompanying 
      EXPECTED.TXT file. It contains the expected results. They should be exactly the same -- even the spacing!  
      If they are not the same, then there's a strong probability that there's a logical error in your 
      solution, or you did not follow some specifications.     
      
   6. Debug your C source code if there are logical errors.  Repeat from Step 3.   

   7. Submit this C source file via the Canvas submission page.     
*/

#include <stdio.h>
#include <string.h>

/*
     Read & understand the contents of "reserve.h"
     Do NOT change/remove the #include in the next line!!!
*/
#include "reserve.h"


/*
     You may define any number of helper functions that you deem necessary below this comment.

     You are free to decide on the function return type, name, and parametrization of your helper functions.
*/




/* TASK #1

   Purpose: determine if key is in the string via linear search starting from index 0
   Returns: either the index where the 1st character matching the key is found or
            a -1 if the key is not found
   @param: key is the single character search key 
   @param: string is the name of the character array
   Pre-condition: the parameters contain valid values

   Example #1: SearchChar('a', "HELLO") returns -1 since 'a' is not found in "HELLO"
   Example #2: SearchChar('L', "HELLO") return 2 since 'L' is found, the 1st occurence of 'L' is at index 2
   Example #3: SearchChar('e', "HELLO") returns -1 since 'e' is not found (note: 'e' is different from 'E')
*/
int 
SearchChar(char key, char *string) {
   // You may declare & use your own local variables.

   // Do NOT call printf() or scanf() inside this function.

   return 888; // note that 888 is a dummy value only; you'll need to edit this line of code
}


/* TASK #2

   Purpose: Determine the availability of the venue on a given month and day
   Returns: 0 if the room is available both in the morning and afternoon
            1 if the room is already reserved in the morning only, so room is available in the afternoon
            2 if the room is already reserved in the afternoon only, so room is available in the morning
            3 if the room is already reserved both in the morning and afternoon, so room is NOT available
   @param: RESERVE refers to the 2D array containing the reservation data
   @param: month_index is from 0 to 11 
   @param: day_index is from 0 to 30
   Pre-condition: the parameters contain valid values
   Example: int result = CheckAvailability(RESERVE, 11, 24);
*/
int 
CheckAvailability(Str50 RESERVE[][NDAYS], int month_index, int day_index)
{
   // You may declare & use your own local variables.

   // You are NOT required to call within this function any of the required TASK #1 to #5 functions.
   // You may or may not call such a function. Should you decide to do a call, make sure that it makes logical sense.

   // Do NOT call printf() or scanf() inside this function.

   // NOTE: For simplicity reasons, you do NOT need to validate the month_index and day_index.  
   //       Assume that the values for these two parameters are already VALID,  
   //       i.e., there won't be any invalid input date such as Feb. 30.


   return 888; // note that 888 is a dummy value only; you'll need to edit this line of code
}


/* TASK #3

   Purpose: Determine reservation info (NAME and NUMBER) for a schedule (month, day, morning/afternoon)
   Returns: none
   @param: RESERVE refers to the 2D array containing the reservation data
   @param: month_index is from 0 to 11 
   @param: day_index is from 0 to 30
   @param: flag is either 1 or 2 only
           -- flag == 1 means morning
           -- flag == 2 means afternoon
   @param: answer is the string that will contain the reservation info
           -- if there is no morning reservation, answer should be set to "NO-MORNING-RESERVATION"
           -- if there is no afternoon reservation, answer should be set to "NO-AFTERNOON-RESERVATION"
           -- otherwise, answer should be set to a string containing the name and contact number 
              of the client who made the reservation (ex. "ABC-91712") 
   Pre-condition: the parameters contain values
   Example #1: Who(RESERVE, 10, 24, 1, answer); to determine info in the morning of Nov. 25 
   Example #2: Who(RESERVE, 1, 13, 2, answer); to determine info in the afternoon of Feb. 14
*/
void 
Who(Str50 RESERVE[][NDAYS], int month_index, int day_index, int flag, Str50 answer)
{
   // You may declare & use your own local variables.

   // You are NOT required to call within this function any of the required TASK #1 to #5 functions.
   // You may or may not call such a function. Should you decide to do a call, make sure that it makes logical sense.

   // Do NOT call printf() or scanf() inside this function.

   // NOTE: For simplicity reasons, you do NOT need to validate the month_index, day_index and flag.  
   //       Assume that the values for these parameters are already VALID,  
   //       i.e., there won't be any invalid input date such as Feb. 30.

   
}


/* TASK #4

   Purpose: Book (add) a reservation on a given schedule (month, day, morning/afternoon), name and contact number 
   Returns: 1 if the venue was booked successfully
            0 if the venue cannot be booked because it is not available on the given schedule 
   @param: RESERVE refers to the 2D array containing the reservation data
   @param: month_index is from 0 to 11 
   @param: day_index is from 0 to 30
   @param: flag is either 1 or 2 only
           -- flag == 1 means morning
           -- flag == 2 means afternoon
   Pre-condition: the parameters contain valid values

   Example #1: int result = Book(RESERVE, 1, 13, 2, "JUAN", "91812");
   Example #2: int result = Book(RESERVE, 11, 24, 1, "MARIA", "90688");
*/
int 
Book(Str50 RESERVE[][NDAYS], int month_index, int day_index, int flag, char *name, char *number)
{
   // You may declare & use your own local variables.

   // You are NOT required to call within this function any of the required TASK #1 to #5 functions.
   // You may or may not call such a function. Should you decide to do a call, make sure that it makes logical sense.

   // Do NOT call printf() or scanf() inside this function.

   // NOTE: For of simplicity, you do NOT need to validate the month_index, day_index and flag.  
   //       Assume that the values for these parameters are already VALID,  
   //       i.e., there won't be any invalid input date such as Feb. 30.


   return 888; // note that 888 is a dummy value only; you'll need to edit this line of code
}


/* TASK #5

   Purpose: Determine the number of reservations for each month. Each reservation contributes 1 in the 
            total count.  This means, for example, that if there is a reservation in the morning
            as well as in the afternoon, the contibution to the count is 2 (not 1).
   Returns: none
   @param: RESERVE refers to the 2D array containing the reservation data
   @param: COUNT refers to the name of an array of integers with indices from 0 to NMONTHS - 1;
           COUNT[i] is the number of reservations for month number i, for example, COUNT[0] is the 
           number of reservations for month 0 (January), COUNT[1] for month 1 (February), and so on...
   Example: CountReservations(RESERVE, COUNT);
*/
void 
CountReservations(Str50 RESERVE[][NDAYS], int COUNT[])
{
   // You may declare & use your own local variables.

   // You are NOT required to call within this function any of the required TASK #1 to #5 functions.
   // You may or may not call such a function. Should you decide to do a call, make sure that it makes logical sense.

   // Do NOT call printf() or scanf() inside this function.
}



/*------------------------------------------------------------------
   Do NOT edit/delete the #include "main.c" below.
   The main.c file contains the main() functions and 
   other codes for testing your solution.  
--------------------------------------------------------------------*/
#include "main.c"

