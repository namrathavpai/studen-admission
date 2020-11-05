#pragma once
#include <stdint.h>
#include "appconst.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

typedef struct _student_ {
	char name[STUDENT_NAME_LEN];
	int regnumber;
	char program[PROGRAM_NAME_LEN];
	char email[STUDENT_EMAIL_LEN];
	int marks;
	char status[STATUS_LEN];
}Student;

Student student_new(char name[], int reg, char prg[], char email[]);
int check_status(int marks);
void update_seats(char* program);
void student_reg(Student* st);
void display(Student* st);
void waiting_student(Student* st);
void display_waiting_students(Student* st);


#endif