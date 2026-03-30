#include <stdio.h>
#include <string.h>

struct car {
    int id;
    char name[20];
    float rent;
    int status; // 0 = Available, 1 = Rented
};

struct car c[100];
int count = 0;

// Add Car
void addCar() {
    printf("\nEnter Car ID: ");
    scanf("%d", &c[count].id);

    printf("Enter Car Name: ");
    scanf("%s", c[count].name);

    printf("Enter Rent per Day: ");
    scanf("%f", &c[count].rent);

    c[count].status = 0; // Available
    count++;

    printf("\nCar Added Successfully!\n");
}

// View Cars
void viewCars() {
    if(count == 0) {
        printf("\nNo Cars Available!\n");
        return;
    }

    printf("\n--- Car List ---\n");
    for(int i = 0; i < count; i++) {
        printf("\nID: %d", c[i].id);
        printf("\nName: %s", c[i].name);
        printf("\nRent per Day: %.2f", c[i].rent);

        if(c[i].status == 0)
            printf("\nStatus: Available\n");
        else
            printf("\nStatus: Rented\n");
    }
}

// Rent Car
void rentCar() {
    int id, days, found = 0;
    printf("\nEnter Car ID to Rent: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(c[i].id == id) {
            found = 1;

            if(c[i].status == 1) {
                printf("\nCar is already rented!\n");
                return;
            }

            printf("Enter number of days: ");
            scanf("%d", &days);

            float total = days * c[i].rent;
            c[i].status = 1;

            printf("\nCar Rented Successfully!\n");
            printf("Total Rent = %.2f\n", total);
            return;
        }
    }

    if(!found)
        printf("\nCar Not Found!\n");
}

// Return Car
void returnCar() {
    int id, found = 0;
    printf("\nEnter Car ID to Return: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(c[i].id == id) {
            found = 1;

            if(c[i].status == 0) {
                printf("\nCar is already available!\n");
                return;
            }

            c[i].status = 0;
            printf("\nCar Returned Successfully!\n");
            return;
        }
    }

    if(!found)
        printf("\nCar Not Found!\n");
}

// Main Menu
int main() {
    int choice;

    while(1) {
        printf("\n===== Car Rental System =====\n");
        printf("1. Add Car\n");
        printf("2. View Cars\n");
        printf("3. Rent Car\n");
        printf("4. Return Car\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addCar(); break;
            case 2: viewCars(); break;
            case 3: rentCar(); break;
            case 4: returnCar(); break;
            case 5: printf("\nExiting...\n"); return 0;
            default: printf("\nInvalid Choice!\n");
        }
    }
}