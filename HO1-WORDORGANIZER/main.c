/*
    This is the main.c file.  It contains the main() function for the WORD LIST SORTER AND REVERSER problem.
	
	DO the following to test your WORDORGANIZER-LASTNAME.c solution: 
	
	1. Edit Line 39 below to include your own source file.
	2. Compile this main.c file to produce main.exe.  Make sure to use -Wall compiler directive!
	3. If there are no compilation errors and/or warnings, go to the Command Line Interface via CMD. 
	4. Run main.exe in the command line with I/O redirection as follows:
   
           	main < INPUT1.txt > ACTUAL-LASTNAME.txt           	

	   where INPUT1.txt is an accompanying sample text files that contain input data 
	   read via scanf() in the inputWords() function.

       For example, if your lastname is SANTOS, you should run main.exe as:
	   
       		main < INPUT1.txt > ACTUAL-SANTOS.txt
		      
    5. Using Notepad (or other text editors), open and compare your LASTNAME-ACTUAL.txt with the 
	   contents of the accompanying EXPECTED.TXT file. They should be exactly the same -- even the spacing!
	   If they are not the same, then there's a strong probability that there's a logical error in your 
	   solution, or you did not follow some specifications.  

	6. Debug and retry until you get the correct results.    
	   
	7. Devise your own tests. Do NOT simply depend on the sample INPUT and EXPECTED text files.
*/

/* Do NOT change  the #include below.  You are NOT allowed to include other files. */
#include <stdio.h>

#include "defs.h" /* Make sure you read/understand the contents of this header file. */

/*
    TO DO: change the #include below to your own file/solution. For example if your 
	lastname is SANTOS, then it should be changed to #include "WORDORGANIZER-SANTOS.c".
*/
#include "WORDORGANIZER-LASTNAME.c"

/*
    This is the main() function for testing your solution.  
	
	You are not supposed to modify the contents and the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
	copy this file, and make changes on your copy.
	
	Note that the teacher-in-charge of checking your solution may use another set of input data 
	and a different main() function.  
	
	Your functions should work correctly even with a different set of input data and a different main() function.
*/

void displayList(String25 words[], int count)
{
	int i;
	
	for(i = 0; i < count; i++)
		printf("%s\n", words[i]);
}

int main()
{    
    String25 listWords[MAX] = {}; //Array for inputWords function
	int countWords, totalWords, countPalindromeWords;
    
    printf("How many words do you want to add to the list? ");
    scanf("%d", &countWords);
    
    totalWords = inputWords(listWords, countWords);
    if (totalWords != countWords) {
    	countWords = totalWords;
	}
	printf("\nThe following words have been saved:\n");
	displayList(listWords, countWords);
    
    printf("\nDuplicate words with count:\n");
    displayDuplicates(listWords, countWords);
        
    printf("\nWords in descending order:\n");
    sortWords(listWords, countWords, 0);
    displayList(listWords, countWords);
    printf("\nWords in ascending order:\n");
    sortWords(listWords, countWords, 1);
    displayList(listWords, countWords);
    
    printf("\nReverse words:\n");
    reverseWords(listWords, countWords);
	displayList(listWords, countWords);
    
    countPalindromeWords = countPalindrome(listWords, countWords);
    printf("\nNumber of palindrome words in list = %d", countPalindromeWords);
    
    return 0;
}
