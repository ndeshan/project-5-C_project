#include <stdio.h>
#include <time.h>
#include "notifications.h"

void sendAppointmentReminder(int patient_id, char date[])
{
    FILE *file = fopen("data/notifications.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Notification n;
    n.recipient_id = patient_id;
    snprintf(n.message, sizeof(n.message), "Reminder: You have an appointment on %s.", date);
    time_t t = time(NULL);
    strftime(n.timestamp, sizeof(n.timestamp), "%Y-%m-%d %H:%M:%S", localtime(&t));

    fprintf(file, "%d %s %s\n", n.recipient_id, n.message, n.timestamp);
    fclose(file);
    printf("Notification sent successfully.\n");
}

void displayNotifications()
{
    FILE *file = fopen("data/notifications.txt", "r");
    if (!file)
    {
        printf("No notifications found.\n");
        return;
    }

    Notification n;
    printf("\n--- Notifications ---\n");
    while (fscanf(file, "%d %[^\n]", &n.recipient_id, n.message) != EOF)
    {
        printf("Recipient ID: %d, Message: %s\n", n.recipient_id, n.message);
    }
    fclose(file);
}