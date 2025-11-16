#include <string.h>

//Function prototype
void removeWord(char *str, char *word);


/*  TASK: Implement removeWord()
	
	@param *str  - the string containing the sentence
	@param *word - the string containing the word to be removed from the sentence
	
	This function will search the sentence for all instances of the specified word
	and remove it.
	
	Example:
		Sentence: "Try again and again do not quit."
		Word    : "again"
		
		Result  : "Try and do not quit."
*/
void removeWord(char *str, char *word) {
    int i = 0; 
    int j;
    int len;
    int newlen;
	char newstr[100]; 
    char temp[100]; 

    newstr[0] = '\0'; 
    len = strlen(str);

    while (i < len) {
        
        j = 0;
        
        while (str[i] != ' ') {
            temp[j] = str[i];
            j++;
            i++;
        }
        temp[j] = '\0'; 

        
        if (strcmp(temp, word) != 0) {
            strcat(newstr, temp);
            strcat(newstr, " "); 
        }

        while ((str[i] == ' '))
            i++;
        
    }

    newlen = strlen(newstr);
    newstr[newlen - 1] = '\0'; 
    
    strcpy(str, newstr);
}