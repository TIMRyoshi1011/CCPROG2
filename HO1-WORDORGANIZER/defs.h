/*
	Header file for WORDORGANIZER problem.
	
	DO NOT change this file.
	
	Concentrate only on Lines 10 - 23. You do not need to be concerned with the other lines.
*/

/* DO NOT change the four #defines below */
#define MAX (1000)

/* DO NOT change the two typedef below */
typedef char String25[26];

/* Function prototypes for the functions that the student need to define in the source file LASTNAME-WORDLIST.c */
int inputWords(String25 words[], int size);
void displayDuplicates(String25 words[], int size); 
void sortWords(String25 words[], int size, int sortOrder);
void reverseWords(String25 words[], int size);
int countPalindrome(String25 words[], int size);

/* The definitions for the following functions are already provided in the LASTNAME-WORDLIST.c file */
void displayList(String25 words[], int count);
