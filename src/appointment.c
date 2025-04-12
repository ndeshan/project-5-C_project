#include <stdio.h>
#include <string.h>
#include "appointment.h"

void scheduleAppointment()
{
    FILE *file = fopen("data/appointments.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Appointment a;
    printf("Enter Patient ID: ");
    scanf("%d", &a.patient_id);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctor_id);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf(" %[^\n]", a.date);

    fprintf(file, "%d %d %s\n", a.patient_id, a.doctor_id, a.date);
    fclose(file);
    printf("Appointment scheduled successfully.\n");
}

void viewAppointments()
{
    FILE *file = fopen("data/appointments.txt", "r");
    if (!file)
    {
        printf("No appointments found.\n");
        return;
    }

    Appointment a;
    printf("\n--- Appointments ---\n");
    while (fscanf(file, "%d %d %s", &a.patient_id, &a.doctor_id, a.date) != EOF)
    {
        printf("Patient ID: %d, Doctor ID: %d, Date: %s\n", a.patient_id, a.doctor_id, a.date);
    }
    fclose(file);
}