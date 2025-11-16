#include <stdio.h>
#include <string.h>

int main() {

    FILE *test;
    //char s[51] = "keystrokes.txt";
    // char c1, c2, c3, c4;
    char skill;

    //do {

        // printf("Enter File Name: ");
        // scanf("%s", s);

        test = fopen("keystrokes.txt", "r");

        if(test != NULL)
            printf("File succesfully opened!\n");

        else 
            printf("File open unsuccessful!\n\n");
        
    //} while(test == NULL);

    fscanf(test, " %c", &skill);
    while(!feof(test)) {

    //while(fscanf(test, " %c", &skill) == 1) {
        // if(skill == 'Q')
        //     printf("Null Sphere\n");
        
        // else if(skill == 'W')
        //     printf("Nether Blade\n");

        // else if(skill == 'E')
        //     printf("Force Pulse\n");

        // else if(skill == 'R')
        //     printf("Rift Walk\n");

        switch(skill) {
            case 'Q':
                printf("Null Sphere\n");
                break;

            case 'W':
                printf("Nether Blade\n");
                break;

            case 'E':
                printf("Force Pulse\n");
                break;

            case 'R':
                printf("Rift Walk\n");
        }
        fscanf(test, " %c", &skill);
    }


    // while(fscanf(test, " %c %c %c %c", &c1, &c2, &c3, &c4) == 4)
    //     printf("%c %c %c %c", c1, c2, c3, c4);
        
    // fscanf(test, " %c", &c1);
    // fscanf(test, " %c", &c2);
    // fscanf(test, " %c", &c3);
    // fscanf(test, " %c", &c4);

    fclose(test);

    // printf("%c %c %c %c", c1, c2, c3, c4);

    // while(test == NULL){
    //     printf("Invalid file or file not found!\n");
    //     printf("Enter File Name: ");
    //     scanf("%s", s);
    //     test = fopen(s, "r");
    // }

    return 0;
}