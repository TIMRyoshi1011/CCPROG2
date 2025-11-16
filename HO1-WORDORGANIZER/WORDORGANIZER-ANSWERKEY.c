/* 
	Hands on Exam 1: WORD ORGANIZER
   
	Name:    <Replace this with your LASTNAME, FIRSTNAME>
   	Section: <Replace this with your SECTION>
*/

#include <string.h>
#include "defs.h"

/*
	TO DO #1: implement inputWords() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
*/
int inputWordsSolution(String25 words[], int size)
{
    /*
    	Declare your own local variables
    */
    int i, counter = 0;
    
	printf("Input any string with a max of 25 characters. You can input up to %d items.\n", size);
	printf("Input END! if you wish to end the input process.\n");    

	/*
		Place your code here. Do not forget that this function is supposed to return a value.
	*/
	for (i = 0; i < size; i++) {
		scanf("%s", words[i]);
		
		if (strcmp(words[i], "END!") == 0) {
			return counter;
		} else {
			counter++;
		}
	}
	
	return size; //You may edit this.
}

/*
	TO DO #2: implement displayDuplicates() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
*/
void displayDuplicatesSolution(String25 words[], int size)
{
	int i, j, currentSize = 0, isNewWord;
	String25 wordBucket[MAX] = {};
	int wordCount[MAX] = {};
	String25 wordCompare;
	/*
		Declare your own local variables.
		DO NOT call scanf in this function.
	*/
	
	for (i = 0; i < size; i++) {
		strcpy(wordCompare, words[i]);
		for (j = 0; j < strlen(wordCompare); j++) {
			if (wordCompare[j] >= 65 && wordCompare[j] <= 90) {
				wordCompare[j] += 32;
			}
		}
		
		if (currentSize == 0) {
			strcpy(wordBucket[i], wordCompare);
			wordCount[i]++;
		} else {
			isNewWord = 1;
			for (j = 0; j < currentSize; j++) {
				if (strcmp(wordCompare, wordBucket[j]) == 0) {
					isNewWord = 0;
					wordCount[j]++;
					break;
				}
			}
			
			if (isNewWord == 1) {
				strcpy(wordBucket[currentSize], wordCompare);
				wordCount[currentSize]++;
			}
		}
		currentSize++;
	}
	
	for (i = 0; i < currentSize; i++) {
		if (wordCount[i] > 1) {
			printf("%s - %d\n", wordBucket[i], wordCount[i]);
		}
	}
}

/*
	TO DO #3: implement sortWords() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
	@param: sortOrder - Integer value for the selected sorting order (1 for Ascending and 0 for Descending)
*/
void sortWordsSolution(String25 words[], int size, int sortOrder)
{
	/*
		Declare your own local variables.
		DO NOT call scanf in this function.
	*/
	int i, j, minOrMaxIdx;
    String25 temp;

    for (i = 0; i < size - 1; i++)
    {
        minOrMaxIdx = i;

        for (j = i + 1; j < size; j++)
        {
            if ((sortOrder == 1 && strcmp(words[j], words[minOrMaxIdx]) < 0) || 
                (sortOrder == 0 && strcmp(words[j], words[minOrMaxIdx]) > 0))
            {
                minOrMaxIdx = j;
            }
        }

        if (minOrMaxIdx != i)
        {
            strcpy(temp, words[i]);
            strcpy(words[i], words[minOrMaxIdx]);
            strcpy(words[minOrMaxIdx], temp);
        }
    }
}

/*
	TO DO #4: implement reverseWords() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
*/
void reverseWordsSolution(String25 words[], int size)
{
	/*
		Declare your own local variables.
		DO NOT call scanf in this function.
		You are NOT ALLOWED to use the strrev() function.
	*/
	int row, col, ch, len;
	char temp;
	
	for(row = 0; row < size; row++)
	{
		len = strlen(words[row]);
		ch = len - 1;
		for(col = 0; col <= ch; col++)
		{
			temp = words[row][col];
			words[row][col] = words[row][ch];
			words[row][ch] = temp;
			ch--;
		}
	}
}

/*
	TO DO #5: implement countPalindrome() as described in the problem specs.
	
	@param: words[] - Array storing the words / the list
	@param: size - Refers to the total number of items in the list
*/
int countPalindromeSolution(String25 words[], int size)
{
	int i, counter = 0, isPalindrome;
	int left, right, wordLength;
	String25 wordCheck;
	/*
		Declare your own local variables.
		DO NOT call scanf in this function.	
	*/
	for (i = 0; i < size; i++) {
		strcpy(wordCheck, words[i]);
		wordLength = strlen(wordCheck);
		isPalindrome = 1;
		left = 0;
		right = wordLength - 1;
		
		while (left < right) {
			if (wordCheck[left] >= 65 && wordCheck[left] <= 90) {
				wordCheck[left] += 32;
			}
			if (wordCheck[right] >= 65 && wordCheck[right] <= 90) {
				wordCheck[right] += 32;
			}
			
			if (wordCheck[left] != wordCheck[right]) {
				isPalindrome = 0;
			}
			
			left++;
			right--;
		}
		
		if (isPalindrome == 1) {
			counter++;
		}
	}
	
	return counter; //You may edit this line.
}
