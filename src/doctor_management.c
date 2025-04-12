#include <stdio.h>
#include <string.h>
#include "doctor_management.h"

void addDoctor()
{
    FILE *file = fopen("data/doctors.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Doctor d;
    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter Specialization: ");
    scanf(" %[^\n]", d.specialization);

    fprintf(file, "%d %s %s\n", d.id, d.name, d.specialization);
    fclose(file);
    printf("Doctor added successfully.\n");
}

void displayDoctors()
{
    FILE *file = fopen("data/doctors.txt", "r");
    if (!file)
    {
        printf("No doctors found.\n");
        return;
    }

    Doctor d;
    printf("\n--- Doctor List ---\n");
    while (fscanf(file, "%d %s %s", &d.id, d.name, d.specialization) != EOF)
    {
        printf("ID: %d, Name: %s, Specialization: %s\n", d.id, d.name, d.specialization);
    }
    fclose(file);
}