/* Hands-on 2: Consultation

   Name:    <Lastname>, <FirstName>
   Section: <Section>
*/

/* Instructions: 
   1. You are NOT allowed to put any printf() statements in the functions 
      you are required to implement.
   2. Read the comments to know the requirements and restrictions in 
      your implementation of each function. Not following requirements or
	  violating restrictions as indicated can result to no credit for the
	  entire function.
   3. You are NOT allowed to create other functions not indicated in the
      given template file.
   4. You can only use functions to C libraries and syntax found in the 
      CCPROG1 and CCPROG2 course materials that are within the coverage.
	  For example, you can only use strlen(), strcmp(), strcat(),
	  and strcpy() from string.h and scanf() and printf() (with NO 
	  regular expressions) from stdio.h.
   5. The main() should NOT be in this file.   
*/

#include "consult.h"  //Cannot modify this line


/*To Do: [10 pts]
  Complete the code in this function. Note that this will not 
  compile now, as there are portions of the code missing, thus
  syntax is wrong.  By the end of the 2 hours, if this function 
  still does not compile, it is recommended that you comment out 
  codes that causes the compile-time error, but do NOT 
  comment out the function header.
  
  This function gets input for 1 doctor.  Input sequence is
  based on the sequence in the structure declaration. If the
  input for the name is "888", the function should not 
  ask for the other information anymore and return 0 (to 
  signify no more valid data entered). If input information
  for all member fields are successfully done, the function
  should return 1.
  
  Requirements:
  1. Reiterating Instruction #1 and #4 above.
  2. You can use the provided getPhrase() to get a string of
     more than one word.
  	 
  @param pDoc - the address to the structure where data will be
                placed
  @return 1 if name is not "888", 0 otherwise
*/
int
inputDoctor(doctorType * pDoc)
{   int i = 0;
    int bStop = 0;
	/* no additional variables can be declared */
	
	/* get input for the name of the doctor */ 
	
	getPhrase((*pDoc).name);
	
	
	/* check if "888" is not the given input for the doctor's name */
	if (strcmp(pDoc->name, "888") != 0)
	{  
       /* get input for series of specializations as long as the 
          array can fit and as long as the input is not "ZZZ".
          The sentinel value is stored as part of array so this can
          be used as basis later on (eg., in the displayDoctor()) */
       do
	   {
		 /* get input for 1 specialization */
	     getPhrase((*pDoc).specializations[i]);
		 
		 /* check if given specialization is "ZZZ" */
	     if (strcmp(pDoc->specializations[i], "ZZZ") == 0)
		    bStop = 1;
	     else i++;
	   } while (!bStop && i < MAX_SPECIAL);
	   
	   for (i = 0; i < 7; i++)
	   {
		  /*Assume a doctor will have 1 clinic schedule per day only.*/
		 
		 //get input for start of clinic hours for the day
		 
		  scanf("%d ", &(*pDoc).aClinicSched[i].timeStart);
		  
		  /* get input for end of clinic hours for the day, 
		     ONLY if the timeStart given as input is not -1.
             No need to get input for timeEnd when timeStart is -1 */
		  if (pDoc->aClinicSched[i].timeStart != -1)
		    scanf("%d ",&pDoc->aClinicSched[i].timeEnd);
	   }
	   return 1;
	}
	else return 0;
}

/*To Do: [10 pts]
  This function copies the list of doctors who have clinic hours for
  the indicated day.  For example day is 1, then the function copies
  from drDirectory all doctors whose timeStart on index 1 (Monday) is 
  not -1. The contents in docsToday should not have skipped entries
  (i.e., copied data should be sequential). *pCur should also be 
  updated to store the initialized entries in docsToday.
  
  @param drDirectory - source array of doctors in the clinic
  @param numDoc - number of initialized entries in drDirectory
  @param day - day of the week to check. 0 means Sunday, 6 means Saturday
  @param docsToday - destination array of doctors who have clinic on the given day
  @param pCur - address where number of entries of docsToday is stored in
*/
void 
genDoctorsToday(doctorType drDirectory[], int numDoc, int day, 
                doctorType docsToday[], int *pCur)
{
	int i;
	*pCur = 0;
	
	for (i = 0; i < numDoc; i++)
	{
		if (drDirectory[i].aClinicSched[day].timeStart != -1)
		{
			docsToday[*pCur] = drDirectory[i];
			(*pCur)++;
		}
	}
}

/*To Do: [10 pts]
  This function deletes the doctor entries from the array drDirectory if
  for all the days of the week, their timeStart are all -1. When deleting 
  an entry, the doctor in the next indices is moved one index less, thus
  maintaining the sequence and still not having skipped/garbage entries.
  The number of entries *pNumDoc should also be updated.  

  @param drDirectory - array of doctors in the clinic
  @param pNumDoc - address where number of initialized entries in 
                   drDirectory is stored
*/
void
trimList(doctorType drDirectory[], int *pNumDoc)
{
   int i = 0, j;
   int day;
     
   while (i < *pNumDoc)
   {
	   //check schedules if all timeStart are -1
	   day = 0;
	   while (day < 7 && drDirectory[i].aClinicSched[day].timeStart == -1)
	      day++;
	 
	   if (day == 7) //all are -1, should delete this entry
	   {  //deleting by moving entries 1 index up
	      for (j = i; j < *pNumDoc - 1; j++)
			  drDirectory[j] = drDirectory[j+1];
	      (*pNumDoc)--;
	   }
	   else i++;
   }
}

/*To Do: [10 pts]
  This function sorts the docsToday in ascending order based on their 
  availabity on the given day. If timeStart is same, then the one that has
  an earlier timeEnd should be in a smaller index than the one that ends later.
  Assume that no 2 schedules would be exactly the same.
  
  @param docsToday - array of doctors in the clinic
  @param numDoc - number of initialized entries in docsToday
  @param day - sorting will be based on this day's schedule only 
*/
void
sortAvail(doctorType docsToday[], int numDoc, int day)
{   int i, j;
    int minIndex;
	doctorType temp;
 
    //using selection sort
    for (i = 0; i < numDoc; i++)
    {   
         minIndex = i;
		//look for smallest value
		for (j = i + 1; j < numDoc; j++)
            if (docsToday[j].aClinicSched[day].timeStart <
 		        docsToday[minIndex].aClinicSched[day].timeStart)
				  minIndex = j;
		    else if (docsToday[j].aClinicSched[day].timeStart ==
 		        docsToday[minIndex].aClinicSched[day].timeStart &&
				docsToday[j].aClinicSched[day].timeEnd <
 		        docsToday[minIndex].aClinicSched[day].timeEnd)
				  minIndex = j;
				  
	    //if not in correct position, swap
		if (minIndex != i)
		{  temp = docsToday[i];
	       docsToday[i] = docsToday[minIndex];
		   docsToday[minIndex] = temp;
		}
	}
}

/* To Do: [10 pts]
   This function returns the address of the 1st doctor with the
   earliest availability this day with the needed specialization.
   Do not assume that the array docsToday is sorted.  You can 
   choose call sortAvail() as part of your solution for this function.

  @param docsToday - array of doctors in the clinic
  @param numDoc - number of initialized entries in docsToday
  @param day - checking of available doctors for this day
  @param specialization - specialization the doctor should have

  @return address to the doctor's info whose specialization includes
          the indicated specialization and has the earliest availability
		  on the given day. If there is more than one doctor with the 
		  indicated specialization and have the same timeStart, then the 
		  one with the earlier endTime will be the one chosen. 
		  If none found, 0 is returned.  */
doctorType *
reco(doctorType docsToday[], int numDoc, int day, string specialization)
{   int i, j, found = 0;

	sortAvail(docsToday, numDoc, day);
	
	i = 0; 
	while (i < numDoc && !found)
	{   j= 0;
        while (j < MAX_SPECIAL && !found &&
		       strcmp(docsToday[i].specializations[j], "ZZZ") != 0)
		  if (strcmp(docsToday[i].specializations[j], specialization) == 0)
		    found = 1;
		  else j++;
		
        if (!found)
           i++;
	}
    if (found)
      return &docsToday[i];
    return 0;  
}



/* Codes starting from this line cannot be modified or removed. */

/* This function gets an input string that can be more than 1 word.
   It is assumed that the input can fit in the capacity of the
   variable.
   
   @param s - starting address of the string
*/
void
getPhrase(char * s)
{
   char ch;
   int i = 0;
      
   do
   {
      scanf("%c", &ch);
	  if (ch != '\n')
	  {  s[i] = ch;
	     i++;
	     s[i] = '\0';
	  }
   }while (ch != '\n');  
}

/* This function displays the information about a patient.
   @param p - the patient information
*/
void displayDoctor(doctorType d)
{  int i;
   string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                     "Thursday", "Friday", "Saturday"};
   
   printf("***%s***\n", d.name);
   
   printf("Specializations:\n");
   i = 0;
   while (i < MAX_SPECIAL && strcmp(d.specializations[i], "ZZZ") != 0)
   {   if (i > 0)
	     printf(", ");
	 
       printf("%s", d.specializations[i]);
       i++;
   }
   printf("\n");
   
   printf("\nClinic Schedules:\n");
   for (i = 0; i < 7; i++)
      printf("%-12s", days[i]);
   printf("\n");

   for (i = 0; i < 7; i++)
          if (d.aClinicSched[i].timeStart == -1)
			  printf("%-12s", "none");
		  else
		  	  printf("%04d-%04d   ", d.aClinicSched[i].timeStart,
		                            d.aClinicSched[i].timeEnd);
   
   printf("\n\n");
}
