#ifndef APPOINTMENT_H
#define APPOINTMENT_H

typedef struct
{
    int patient_id;
    int doctor_id;
    char date[20];
} Appointment;

void scheduleAppointment();
void viewAppointments();

#endif