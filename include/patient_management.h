#ifndef PATIENT_MANAGEMENT_H
#define PATIENT_MANAGEMENT_H

typedef struct
{
    int id;
    char name[50];
    int age;
    char gender[10];
} Patient;

void addPatient();
void displayPatients();

#endif