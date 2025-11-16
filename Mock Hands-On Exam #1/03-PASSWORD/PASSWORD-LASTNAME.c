/*
    Skeleton file for PASSWORD problem.
	
    lASTNAME, FIRSTNAME: 
	SECTION: 
	DATE: 
	
    Violation of any of the RESTRICTIONS will result to point deduction. 
*/


/* Do NOT include other header files.  

   Do NOT use library functions that we did not discuss/cover in class.
*/
#include <stdio.h>
#include <string.h>

/* Use these string typedefs. */
typedef char String30[31];
typedef char String60[61];



/*
    TO DO: 
    
    Implement the functions as specified in the PASSWORD.PDF file.
	
	RESTRICTIONS:
	1. Make sure that you follow the function prototypes specified in population.h
	2. Do NOT call printf() or scanf() in any of the required function definition
	   EXCEPT in the main() function.
	3. Use only the library function that we discussed in class.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
*/


/* 
   Step 1: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/


/* 
   Step 1: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void addUnderscore(String30 firstName, String30 lastName, String60 password) {
    strcat(firstName, "_");
    strcat(firstName, lastName);
    strcpy(password, firstName);
}

/* 
   Step 2: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void stringLength(String30 firstName, String30 lastName, String60 password) {

    int len, i, j;
    len = strlen(password);

    if (len < 8) {
        for(i = 0; i < 9; i++) {
            if (password[i] == '\0') {

                if (j == 122) 
                    j = 97;

                else 
                    j = password[i-1] + 1;

                password[i] = j; 
            }

            password[8] = '\0';
            
        }
    }  
}


/* 
   Step 3: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void capitalizeFirst(String30 firstName, String30 lastName, String60 password) {
    
	int i, len;
	len = strlen(password);
    password[0] = password[0] - 32;

    for (i = 0; i < len; i++) 
        if (password[i] == '_')
            password[i+1] = password[i+1] - 32;
}

/* 
   Step 4: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void changeVowels(String30 firstName, String30 lastName, String60 password) {
    int i, len;
    len = strlen(password);

    for (i = 0; i < len; i++) {
		
        switch(password[i]) {
            case 'a':
                password[i] = '@';
                break;

            case 'e':
            password[i] = '3';
            break;

            case 'i':
                password[i] = '1';
                break;

            case 'o':
            password[i] = '0';
            break;

            case 'u':
                password[i] = '^';
                break;
        }
    }
}

/* 
   Step 5: Define the function that will achieve this step right after this comment. 
           Do NOT call print(), scanf() and other library functions that we did not
		   discuss in class.
*/
void changeConsonants(String30 firstName, String30 lastName, String60 password) {
    int i, len;
    len = strlen(password);

    for (i = 0; i < len; i++) {

        switch(password[i]) {
            case 's':
                password[i] = '*';
                break;

                case 't':
                password[i] = '?';
                break;
        }
    }
}

int main()
{
	String30 firstName, lastName;
	String60 password;
	
	// Do NOT add any printf() for prompts before the scanf() function calls.
	scanf("%s", firstName);
	scanf("%s", lastName);
	
	
	// Call Step 1 function after this comment and before the printf() statement.
	addUnderscore (firstName, lastName, password);
	printf("%s\n", password);  // prints the password value after step 1.
	
	
	// Call Step 2 function after this comment and before the printf() statement.
	stringLength (firstName, lastName, password);
	printf("%s\n", password);  // prints the password value after step 2.
	
	
	// Call Step 3 function after this comment and before the printf() statement.
	capitalizeFirst(firstName, lastName, password);
	printf("%s\n", password);  // prints the password value after step 3.
	
	
	// Call Step 4 function after this comment and before the printf() statement.
	changeVowels(firstName, lastName, password);
	printf("%s\n", password);  // prints the password value after step 4.
	
	
	// Call Step 5 function after this comment and before the printf() statement.
	changeConsonants(firstName, lastName, password);
	printf("%s\n", password);  // prints the FINAL password value after step 5.
	
	return 0;
}

	
	
	
