#include <stdio.h>
#include <string.h>

typedef char string20[21];

struct birthDate {
    string20 month;
    int day;
    int year;
};

/*
struct date {
    struct nameTag fullName;
};
*/

void changeDate(struct birthDate *date) {
    strcpy(date->month, "October");
}

int main() {

    struct birthDate date;

    //strcpy(student.fullName.fName, "Test");

    //printf("%s", student.fullName.fName);

    scanf("%s", date.month);
    scanf("%d", &date.day);
    scanf("%d", &date.year);

    changeDate(&date);

    printf("\n");
    printf("%s %d, %d", date.month, date.day, date.year);
    
    return 0;
}