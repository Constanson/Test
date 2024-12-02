#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define FILENAME "inventory.txt"

typedef struct {
    char model[50];
    int quantity;
} InventoryItem;

InventoryItem inventory[MAX_ITEMS];
int itemCount = 0;

void displayInventory() {
    if (itemCount == 0) {
        printf("The inventory is empty.\n");
        return;
    }
    printf("Current inventory list:\n");
    printf("No.\tModel\t\tQuantity\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\n", i + 1, inventory[i].model, inventory[i].quantity);
    }
}

void addInventory() {
    if (itemCount >= MAX_ITEMS) {
        printf("The inventory is full.You cannot add more items.\n");
        return;
    }
    InventoryItem newItem;
    printf("Enter item model: ");
    scanf("%s", newItem.model);
    printf("Enter quantity to add: ");
    scanf("%d", &newItem.quantity);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].model, newItem.model) == 0) {
            inventory[i].quantity += newItem.quantity;
            printf("The item already exists. Updated the quantity.\n");
            return;
        }
    }

    inventory[itemCount++] = newItem;
    printf("Item added.\n");
}


void removeInventory() {
    if (itemCount == 0) {
        printf("The inventory is empty.Failed to remove.\n");
        return;
    }
    char model[50];
    int quantity;

    printf("Enter item model to remove: ");
    scanf("%s", model);
    printf("Enter quantity to remove: ");
    scanf("%d", &quantity);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].model, model) == 0) {
            if (inventory[i].quantity < quantity) {
                printf("Not enough items. Failed to remove.\n");
                return;
            }
            inventory[i].quantity -= quantity;
            printf("Item removed.\n");

            if (inventory[i].quantity == 0) {
                for (int j = i; j < itemCount - 1; j++) {
                    inventory[j] = inventory[j + 1];
                }
                itemCount--;
            }
            return;
        }
    }
    printf("Item not found.\n");
}

void loadInventory() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) {
        printf("No existing inventory data found.\n");
        return;
    }
    itemCount = 0;
    while (fscanf(file, "%s %d", inventory[itemCount].model, &inventory[itemCount].quantity) != EOF) {
        itemCount++;
    }
    fclose(file);
    printf("Inventory data loaded successfully.\n");
}

void saveInventory() {
    FILE* file = fopen(FILENAME, "w");
    if (!file) {
        printf("Failed to save inventory data.\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%s %d\n", inventory[i].model, inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory data saved successfully.\n");
}

void menu() {
    int choice;
    do {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Display inventory\n");
        printf("2. Add to inventory\n");
        printf("3. Remove from inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayInventory();
                break;
            case 2:
                addInventory();
                break;
            case 3:
                removeInventory();
                break;
            case 4:
                saveInventory();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    loadInventory();
    menu();
    return 0;
}