#include <stdio.h>
#include <string.h>

typedef char String50[51];
typedef String50 list5[5];

void displayString(String50 str[], int len) {
    int i;

    for(i = 0; i < len; i++) 
        printf("%s ", str[i]);
}

void sortString(String50 str[], int len) {
	int i, j, min;
	String50 temp;

    for (i = 0; i < len - 1; i++) {
        min = i;

        for (j = i + 1; j < len; j++) 
            if (strcmp(str[min], str[j]) == 1)
                min = j;

        if(strcmp(str[i], str[min]) != 0){
            strcpy(temp, str[i]);
            strcpy(str[i], str[min]);
            strcpy(str[min], temp);
        }
    }
}

int main() {

    int len;
	
	list5 str = {"the", "magic", "of", "the", "Unicorn."};

    len = strlen(str);
	
	sortString(str, 5);
    displayString(str, 5);

    //printf("\n\n%d", len);
	
	//printf("%s", str);
	
	return 0;
}
