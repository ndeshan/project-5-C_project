#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

typedef struct
{
    int recipient_id;
    char message[200];
    char timestamp[20];
} Notification;

void sendAppointmentReminder(int patient_id, char date[]);
void displayNotifications();

#endif