#include <stdio.h>
#include <string.h>
#include "feedback.h"

void submitFeedback()
{
    FILE *file = fopen("data/feedback.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Feedback f;
    printf("Enter Patient ID: ");
    scanf("%d", &f.patient_id);
    printf("Enter Rating (1-5): ");
    scanf("%d", &f.rating);
    printf("Enter Feedback: ");
    scanf(" %[^\n]", f.feedback_text);

    fprintf(file, "%d %d %s\n", f.patient_id, f.rating, f.feedback_text);
    fclose(file);
    printf("Feedback submitted successfully.\n");
}

void viewFeedback()
{
    FILE *file = fopen("data/feedback.txt", "r");
    if (!file)
    {
        printf("No feedback found.\n");
        return;
    }

    Feedback f;
    printf("\n--- Feedback ---\n");
    while (fscanf(file, "%d %d %[^\n]", &f.patient_id, &f.rating, f.feedback_text) != EOF)
    {
        printf("Patient ID: %d, Rating: %d, Feedback: %s\n", f.patient_id, f.rating, f.feedback_text);
    }
    fclose(file);
}