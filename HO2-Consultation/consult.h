/* You are NOT allowed to modify the contents of this file */

#include <stdio.h>
#include <string.h>

#define MAX_DOCS     50
#define MAX_SPECIAL   5

typedef char string[31];

//All string types can contain more than one word

struct schedTag
{   
    int timeStart, //start of clinic hours of doctor (ex. 830 means 8:30am) 
	               /* if timeStart is -1, it means no clinic hours for the day */
  	    timeEnd;   //end of clinic hours of doctor   (ex. 1800 means 6pm)
};
typedef struct schedTag schedType;

struct doctorTag
{
    string     name;    //doctor's name
	string     specializations[MAX_SPECIAL]; /* doctor's list of specializations
	                                  ex. Pediatrics, Internal Medicine,
									      Child Nutrition, etc.
                                      if entry is "ZZZ" means there are no more entries
                                   */									  
	schedType  aClinicSched[7]; /* index 0 is clinic sched for Sunday, 
	                               index 1 is clinic sched for Monday, etc.
								   Assume that a doctor will only have 1 clinic schedule per day.
							    */
};
typedef struct doctorTag doctorType;

//Function prototypes of functions already provided
void getPhrase(char * s);
void displayDoctor(doctorType d);


//Function prototypes of functions student has to implement
int inputDoctor(doctorType * pDoc);
void genDoctorsToday(doctorType drDirectory[], int numDoc, int day, 
                     doctorType docsToday[], int *pCur); 
void trimList(doctorType drDirectory[], int *pNumDoc);
void sortAvail(doctorType docsToday[], int numDoc, int day);
doctorType * reco(doctorType docsToday[], int numDoc, int day, 
                  string specialization);
