#include <stdio.h>
#include "billing.h"

void generateBill()
{
    FILE *file = fopen("data/billing.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Bill b;
    printf("Enter Patient ID: ");
    scanf("%d", &b.patient_id);
    printf("Enter Amount: ");
    scanf("%f", &b.amount);

    fprintf(file, "%d %.2f\n", b.patient_id, b.amount);
    fclose(file);
    printf("Bill generated successfully.\n");
}

void viewBills()
{
    FILE *file = fopen("data/billing.txt", "r");
    if (!file)
    {
        printf("No bills found.\n");
        return;
    }

    Bill b;
    printf("\n--- Bills ---\n");
    while (fscanf(file, "%d %f", &b.patient_id, &b.amount) != EOF)
    {
        printf("Patient ID: %d, Amount: %.2f\n", b.patient_id, b.amount);
    }
    fclose(file);
}