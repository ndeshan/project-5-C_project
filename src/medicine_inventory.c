#include <stdio.h>
#include <string.h>
#include "medicine_inventory.h"

void addMedicine()
{
    FILE *file = fopen("data/medicines.txt", "a");
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    Medicine m;
    printf("Enter Medicine ID: ");
    scanf("%d", &m.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", m.name);
    printf("Enter Quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter Price: ");
    scanf("%f", &m.price);

    fprintf(file, "%d %s %d %.2f\n", m.id, m.name, m.quantity, m.price);
    fclose(file);
    printf("Medicine added successfully.\n");
}

void displayMedicines()
{
    FILE *file = fopen("data/medicines.txt", "r");
    if (!file)
    {
        printf("No medicines found.\n");
        return;
    }

    Medicine m;
    printf("\n--- Medicine Inventory ---\n");
    while (fscanf(file, "%d %s %d %f", &m.id, m.name, &m.quantity, &m.price) != EOF)
    {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", m.id, m.name, m.quantity, m.price);
    }
    fclose(file);
}

void updateMedicineStock(int id, int new_quantity)
{
    FILE *file = fopen("data/medicines.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");
    if (!file || !temp)
    {
        printf("Error opening file.\n");
        return;
    }

    Medicine m;
    int updated = 0;
    while (fscanf(file, "%d %s %d %f", &m.id, m.name, &m.quantity, &m.price) != EOF)
    {
        if (m.id == id)
        {
            m.quantity = new_quantity;
            updated = 1;
        }
        fprintf(temp, "%d %s %d %.2f\n", m.id, m.name, m.quantity, m.price);
    }

    fclose(file);
    fclose(temp);
    remove("data/medicines.txt");
    rename("data/temp.txt", "data/medicines.txt");

    if (updated)
        printf("Medicine stock updated successfully.\n");
    else
        printf("Medicine ID not found.\n");
}