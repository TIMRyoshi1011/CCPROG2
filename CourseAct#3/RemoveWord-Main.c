#include <stdio.h>
#include "RemoveWord-RAMOS.c" //Edit this line where LASTNAME is your last name.

//DO NOT EDIT BEYOND THIS POINT!!!

typedef char String50[51];

int main() {
	
	String50 str = "the magic of the Unicorn.";
	
	removeWord(str, "the");
	
	printf("%s", str);
	
	return 0;
}
