#ifndef ANALYTICS_H
#define ANALYTICS_H

typedef struct
{
    int patient_id;
    float amount;
} Bill;

void displayTotalPatients();
void displayTotalDoctors();
void displayTotalAppointments();
void displayRevenueStatistics();

#endif