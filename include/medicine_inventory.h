#ifndef MEDICINE_INVENTORY_H
#define MEDICINE_INVENTORY_H

typedef struct
{
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

void addMedicine();
void displayMedicines();
void updateMedicineStock(int id, int new_quantity);

#endif