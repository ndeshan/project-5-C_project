#ifndef BILLING_H
#define BILLING_H

typedef struct
{
    int patient_id;
    float amount;
} Bill;

void generateBill();
void viewBills();

#endif