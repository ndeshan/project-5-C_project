#include <stdio.h>
#include "patient_management.h"
#include "doctor_management.h"
#include "appointment.h"
#include "billing.h"
#include "medicine_inventory.h"
#include "analytics.h"
#include "notifications.h"
#include "feedback.h"

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Medical and Channeling Center Management System ---\n");
        printf("1. Patient Management\n");
        printf("2. Doctor Management\n");
        printf("3. Appointment Scheduling\n");
        printf("4. Billing and Payment\n");
        printf("5. Medicine Inventory Management\n");
        printf("6. Analytics and Statistics\n");
        printf("7. Notifications and Reminders\n");
        printf("8. User Feedback and Rating System\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPatient();
            displayPatients();
            break;
        case 2:
            addDoctor();
            displayDoctors();
            break;
        case 3:
            scheduleAppointment();
            viewAppointments();
            break;
        case 4:
            generateBill();
            viewBills();
            break;
        case 5:
            addMedicine();
            displayMedicines();
            break;
        case 6:
            displayTotalPatients();
            displayTotalDoctors();
            displayTotalAppointments();
            displayRevenueStatistics();
            break;
        case 7:
            sendAppointmentReminder(1, "2023-10-30"); // Example reminder
            displayNotifications();
            break;
        case 8:
            submitFeedback();
            viewFeedback();
            break;
        case 9:
            printf("Exiting the system. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}