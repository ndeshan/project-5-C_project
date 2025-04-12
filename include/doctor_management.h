#ifndef DOCTOR_MANAGEMENT_H
#define DOCTOR_MANAGEMENT_H

typedef struct
{
    int id;
    char name[50];
    char specialization[50];
} Doctor;

void addDoctor();
void displayDoctors();

#endif