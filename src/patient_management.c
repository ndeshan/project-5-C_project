#include <stdio.h>
#include <string.h>
#include "patient_management.h"

void addPatient()
{
    FILE *file = fopen("data/patients.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Patient p;
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf(" %[^\n]", p.gender);

    fprintf(file, "%d %s %d %s\n", p.id, p.name, p.age, p.gender);
    fclose(file);
    printf("Patient added successfully.\n");
}

void displayPatients()
{
    FILE *file = fopen("data/patients.txt", "r");
    if (!file)
    {
        printf("No patients found.\n");
        return;
    }

    Patient p;
    printf("\n--- Patient List ---\n");
    while (fscanf(file, "%d %s %d %s", &p.id, p.name, &p.age, p.gender) != EOF)
    {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s\n", p.id, p.name, p.age, p.gender);
    }
    fclose(file);
}