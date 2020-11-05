#pragma once
#include <stdint.h>
#include "appconst.h"
#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED


typedef struct _program_ {
	int big_data_seats;
	int machine_learning_seats;
	int embedded_system_seats;

}Program;

Program program_seats();
void fill_seats(Program pg);
void display_seats(Program pg);
void display_TOTAL_FILLED_SEATS();
void manage_seats();
#endif