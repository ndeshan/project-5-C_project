#include <stdio.h>
#include "analytics.h"

void displayTotalPatients()
{
    FILE *file = fopen("data/patients.txt", "r");
    if (!file)
    {
        printf("No patients found.\n");
        return;
    }

    int count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        count++;
    }
    fclose(file);
    printf("Total Patients: %d\n", count);
}

void displayTotalDoctors()
{
    FILE *file = fopen("data/doctors.txt", "r");
    if (!file)
    {
        printf("No doctors found.\n");
        return;
    }

    int count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        count++;
    }
    fclose(file);
    printf("Total Doctors: %d\n", count);
}

void displayTotalAppointments()
{
    FILE *file = fopen("data/appointments.txt", "r");
    if (!file)
    {
        printf("No appointments found.\n");
        return;
    }

    int count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        count++;
    }
    fclose(file);
    printf("Total Appointments: %d\n", count);
}

void displayRevenueStatistics()
{
    FILE *file = fopen("data/billing.txt", "r");
    if (!file)
    {
        printf("No bills found.\n");
        return;
    }

    float total_revenue = 0;
    Bill b;
    while (fscanf(file, "%d %f", &b.patient_id, &b.amount) != EOF)
    {
        total_revenue += b.amount;
    }
    fclose(file);
    printf("Total Revenue: %.2f\n", total_revenue);
}