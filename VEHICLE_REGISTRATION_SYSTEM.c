#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define FILENAME "records.txt"

typedef struct {
    int id;
    char owner[50];
    char make[50];
    int year;
} Vehicle;

Vehicle records[MAX_RECORDS];
int recordCount = 0;

void loadRecords();
void saveRecords();
void clearInputBuffer();
void addRecord();
void displayAllRecords();
void searchRecord();
void updateRecord();
void deleteRecord();
void displayMenu();

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void loadRecords() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return; 
    }

    recordCount = 0;
    while (recordCount < MAX_RECORDS &&
           fscanf(file, "%d\n%[^\n]\n%[^\n]\n%d\n", 
                  &records[recordCount].id, 
                  records[recordCount].owner, 
                  records[recordCount].make, 
                  &records[recordCount].year) == 4) {
        recordCount++;
    }

    fclose(file);
}

void saveRecords() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("\nError: Could not save data to file.\n");
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d\n%s\n%s\n%d\n", 
                records[i].id, 
                records[i].owner, 
                records[i].make, 
                records[i].year);
    }

    fclose(file);
}

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("\nError: Record limit reached.\n");
        return;
    }

    printf("\n--- Add New Vehicle Record ---\n");
    printf("Enter Registration ID (Integer): ");
    scanf("%d", &records[recordCount].id); clearInputBuffer();
    printf("Enter Owner Name: ");
    scanf("%[^\n]", records[recordCount].owner); clearInputBuffer();
    printf("Enter Vehicle Make: ");
    scanf("%[^\n]", records[recordCount].make); clearInputBuffer();
    printf("Enter Year of Registration: ");
    scanf("%d", &records[recordCount].year); clearInputBuffer();
    
    recordCount++;
    printf("\nRecord added successfully.\n");
}

void displayAllRecords() {
    if (recordCount == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--- Vehicle Registration Records (%d) ---\n", recordCount);
    printf("ID\tOwner\tMake\tYear\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t%s\t%d\n", 
               records[i].id, 
               records[i].owner, 
               records[i].make, 
               records[i].year);
    }
    printf("----------------------------------------\n");
}

void searchRecord() {
    int searchId;
    printf("\nEnter ID to search: ");
    if (scanf("%d", &searchId) != 1) { clearInputBuffer(); printf("\nInvalid input.\n"); return; } clearInputBuffer();

    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nOwner: %s\nMake: %s\nYear: %d\n", 
                   records[i].id, 
                   records[i].owner, 
                   records[i].make, 
                   records[i].year);
            return;
        }
    }
    printf("\nRecord with ID %d not found.\n", searchId);
}

void updateRecord() {
    int searchId;
    printf("\nEnter ID of the record to update: ");
    if (scanf("%d", &searchId) != 1) { clearInputBuffer(); printf("\nInvalid input.\n"); return; } clearInputBuffer();

    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == searchId) {
            printf("\nRecord Found. Enter NEW data (including new ID if desired):\n");
            
            printf("Enter NEW Registration ID (Integer): ");
            scanf("%d", &records[i].id); clearInputBuffer();
            printf("Enter NEW Owner Name: ");
            scanf("%[^\n]", records[i].owner); clearInputBuffer();
            printf("Enter NEW Vehicle Make: ");
            scanf("%[^\n]", records[i].make); clearInputBuffer();
            printf("Enter NEW Year of Registration: ");
            scanf("%d", &records[i].year); clearInputBuffer();

            printf("\nRecord updated successfully.\n");
            return;
        }
    }
    printf("\nRecord with ID %d not found.\n", searchId);
}

void deleteRecord() {
    int deleteId, foundIndex = -1;
    printf("\nEnter ID of the record to delete: ");
    if (scanf("%d", &deleteId) != 1) { clearInputBuffer(); printf("\nInvalid input.\n"); return; } clearInputBuffer();

    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == deleteId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < recordCount - 1; i++) {
            records[i] = records[i + 1]; 
        }
        
        recordCount--;
        printf("\nRecord with ID %d deleted successfully.\n", deleteId);
    } else {
        printf("\nRecord with ID %d not found.\n", deleteId);
    }
}

void displayMenu() {
    printf("\n\n--- VEHICLE REGISTRATION SYSTEM ---\n");
    printf("1. Add New Record\n");
    printf("2. Display All Records\n");
    printf("3. Search Record by ID\n");
    printf("4. Update Record by ID\n");
    printf("5. Delete Record by ID\n");
    printf("6. Save & Exit\n");
    printf("Enter your choice: ");
}

int main() {
    loadRecords(); 
    
    int choice;
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) { clearInputBuffer(); choice = 0; } else { clearInputBuffer(); }

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayAllRecords(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: 
                saveRecords(); 
                printf("\nData saved. Exiting Program. Goodbye!\n"); 
                break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return EXIT_SUCCESS;
}