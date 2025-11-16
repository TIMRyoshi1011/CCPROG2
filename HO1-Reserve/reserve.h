/*
    reserve.h  

    Header file for RESERVE problem.
	
    DO NOT change this file.
	
    Concentrate only on Lines 18 to 28. You do not need to be concerned with the other lines.
*/

#include <stdio.h>
#include <string.h>

#ifndef RESERVE_DEFINE

  #define RESERVE_DEFINE (1)

  #define NMONTHS (12)
  #define NDAYS (31)

  typedef char Str50[51];

  /* Function prototypes for the functions that the student need to define in the source file RESERVE-LASTNAME.c */
  int SearchChar(char key, char *string);
  int CheckAvailability(Str50 RESERVE[][NDAYS], int month_index, int day_index);
  void Who(Str50 RESERVE[][NDAYS], int month_index, int day_index, int flag, Str50 answer);
  int Book(Str50 RESERVE[][NDAYS], int month_index, int day_index, int flag, char *name, char *number);
  void CountReservations(Str50 RESERVE[][NDAYS], int COUNT[]);

#endif


