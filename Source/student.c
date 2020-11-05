#include <string.h>
#include"student.h"
#include"program.h"
#include <assert.h>
#include <stdio.h>


void student_reg(Student* st) {
    int application_number;
    int get;
    printf("\nENTER APPLICATION NUMBER:");
    scanf("%d", &application_number);
    printf("\nENTER STUDENT MARKS");
    scanf("%d", &st[application_number].marks);
    get = check_status(st[application_number].marks);
    if (!get) {
        strcpy(st[application_number].status, "ADMITTED");
    }
    else {
        strcpy(st[application_number].status, "WAITING");;
    }
    printf("\nENTER STUDENT NAME:");
    scanf("%s", &st[application_number].name);
    printf("\nENTER REGISTRATION NUMBER:");
    scanf("%d", &st[application_number].regnumber);
    printf("\nENTER PROGRAM NAME:");
    scanf("%s", &st[application_number].program);
    update_seats(st[application_number].program);
    printf("\nENTER EMAIL ID:");
    scanf("%s", &st[application_number].email);

}

int check_status(int marks) {
    if (marks > 5) {
        assert(marks < 10);                                             //assert failed if marks are more than 10
        return 0;
    }
    else {
        return 1;
    }
}

void display(Student* st) {
    int iteration;

    for (iteration = 1;iteration <= TOTAL_FILLED_SEATS;iteration++) {
        printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n", st[iteration].name, st[iteration].regnumber, st[iteration].program, st[iteration].email, st[iteration].marks, st[iteration].status);
    }
}

void waiting_students(Student* st) {
    int iteration;
    for (iteration = 1;iteration <= TOTAL_FILLED_SEATS;iteration++) {
        if (!strcmp(st[iteration].status, "WAITING")) {
            if (!strcmp(st[iteration].program, "BDA") && TOTAL_BDA_SEATS != 50) {
                strcpy(st[iteration].status, "ACCEPTED");
            }
            else if (!strcmp(st[iteration].program, "ML") && TOTAL_ML_SEATSs != 50) {
                strcpy(st[iteration].status, "ACCEPTED");
            }
            else if (!strcmp(st[iteration].program, "ES") && TOTAL_EMDS_SEATS != 50) {
                strcpy(st[iteration].status, "ACCEPTED");
            }
            else {
                strcpy(st[iteration].status, "REJECTED");
            }
        }

    }
}

void display_waiting_students(Student* st) {
    int iteration;
    for (iteration = 1;iteration <= TOTAL_FILLED_SEATS;iteration++) {
        if (!strcmp(st[iteration].status, "WAITING")) {
            printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n", st[iteration].name, st[iteration].regnumber, st[iteration].program, st[iteration].email, st[iteration].marks, st[iteration].status);

        }

    }
}