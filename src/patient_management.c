#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addPatient();
void displayAllPatients();
void searchPatient();

typedef struct
{
    char name[50];
    int id;
    int age;
    int conNumber;
    char gender[];
} Patient;

int main()
{
    int number;
    printf("\x1b[32m");
    printf("  ########        ##        ############ ########## ##########  ####      ##  ###########  \n");
    printf("  ##     ##      ## ##           ##          ##     ##          ## ##     ##       ##      \n ");
    printf("  ##     ##     ##   ##          ##          ##     ##          ##  ##    ##       ##      \n ");
    printf("  #######      #########         ##          ##     ##########  ##   ##   ##       ##      \n");
    printf("  ##          ##       ##        ##          ##     ##          ##    ##  ##       ##    \n");
    printf("  ##         ##         ##       ##          ##     ##          ##     ## ##       ##   \n ");
    printf("  ##        ##           ##      ##      ########## ##########  ##      ####       ##     \n ");
    printf("\v");
    printf("                  ##  ##     ##    ##  #    ##    ###     #####  ##  #  #####\n ");
    printf("                # # #  #   ####   # # #   ####   #   ##  ##     # # #    # \n");
    printf("                 #  ##  #  #    #  #  ##  #    #   #####  #####  #  ##    #  \n");
    printf("\x1b[0m");
    while (1)
    {

        printf("\n\t\t........... P a t i e n t   M a n a g e m e n t ......................\n\n");
        printf("1. Add Patient.\n");
        printf("2. Search Patient use ID.\n");
        printf("3. Display All the Patient details.\n");
        printf("0. Exit.\n");
        printf("\nEnter the number you want to go : ");
        scanf("%d", &number);
        switch (number)
        {
        case 1:
            addPatient();
            break;
        case 2:
            searchPatient();
            break;
        case 3:
            displayAllPatients();
            break;
        case 0:
            printf("Exiting the program...\n");
            exit(0);
            break;
        default:
            printf("Invalid number. Please try again.\n");
            break;
        }
    }

    return 0;
}

void addPatient()
{

    FILE *patientFile;

    patientFile = fopen("data/patients.txt", "w");

    if (patientFile == NULL)
    {
        printf("Error! file are not exist...\n");
        exit(1);
    }
    Patient p1;

    int num;

    printf("\nEnter the number of patients you want to add: ");
    scanf("%d", &num);

    while (num != 0)
    {

        printf("\nEnter the patient name : ");
        scanf(" %[^\n]", p1.name);
        printf("Enter the patient id : ");
        scanf("%d", &p1.id);
        printf("Enter the patient age : ");
        scanf("%d", &p1.age);
        printf("Enter the patient contact number : ");
        scanf("%d", &p1.conNumber);
        printf("Enter the patient gender :");
        scanf("%s", p1.gender);
        fprintf(patientFile, "\n%s %d %d %d %s", p1.name, p1.id, p1.age, p1.conNumber, p1.gender);
        printf("\nPatient added successfully.\n");
        num--;
    }
    fclose(patientFile);
}

void displayAllPatients()
{

    FILE *patientFile;
    patientFile = fopen("data/patients.txt", "r");
    if (patientFile == NULL)
    {
        printf("Error! not like that file.\n");
        exit(1);
    }

    Patient p1;
    printf("\n-........... All the Patient List......................\n");
    while (fscanf(patientFile, "%s %d %d %d %s", p1.name, &p1.id, &p1.age, &p1.conNumber, p1.gender) != EOF)
    {

        printf("Name: %s\n", p1.name);
        printf("ID: %d\n", p1.id);
        printf("Age: %d\n", p1.age);
        printf("Contact: %d\n", p1.conNumber);
        printf("Gender: %s\n", p1.gender);
    }
    fclose(patientFile);
}

void searchPatient()
{
    FILE *patientFile;
    patientFile = fopen("data/patients.txt", "r");
    if (patientFile == NULL)
    {
        printf("Error! not like that file.\n");
        exit(1);
    }
    Patient p1;
    int id;
    printf("Enter the patient ID : ");
    scanf("%d", &id);

    while (fscanf(patientFile, "%s %d %d %d %s", p1.name, &p1.id, &p1.age, &p1.conNumber, p1.gender) != EOF)
    {
        if (id == p1.id)
        {
            printf("\nPatient Found !!\n");
            printf("Name: %s\n", p1.name);
            printf("ID: %d\n", p1.id);
            printf("Age: %d\n", p1.age);
            printf("Contact: %d\n", p1.conNumber);
            printf("Gender: %s\n", p1.gender);
            break;
        }
        printf("No patient with ID %d\n", id);
        break;
    }
    fclose(patientFile);
}