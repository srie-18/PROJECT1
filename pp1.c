#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 2

struct Item {
    int id;
    char name[100];
    int quantity;
    float price;
};
void addItem(struct Item items[], int *count);
void viewInventory(struct Item items[], int count);
void searchItem(struct Item items[], int count);
void updateItem(struct Item items[], int count);
void deleteItem(struct Item items[], int *count);
void calculateTotalValue(struct Item items[], int count);

int main() {
    struct Item items[MAX_ITEMS];
    int count = 0, choice;

    while(1){
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem(items, &count);
                break;
            case 2:
                viewInventory(items, count);
                break;
            case 3:
                searchItem(items, count);
                break;
            case 4:
                updateItem(items, count);
                break;
            case 5:
                deleteItem(items, &count);
                break;
            case 6:
                calculateTotalValue(items, count);
                break;
            case 7:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        //scanf("%d",&choice);
    }
  }

void addItem(struct Item items[], int *count) {
    if (MAX_ITEMS <= *count) {
        printf("Inventory is full.Cannot add");
        return;
    }
    printf("Enter item ID: ");
    scanf("%d", &items[*count].id);
    printf("Enter item name: ");
    scanf(" %[^\n]%*c", items[*count].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*count].price);
    (*count)++;
    printf("Item added successfully.\n");
}

void viewInventory(struct Item items[], int count) {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d  %s %d %.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

void searchItem(struct Item items[], int count) {
    int id, found = 0;
    printf("Enter item ID in digits to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("Item found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found in the inventory.\n");
    }
}

void updateItem(struct Item items[], int count) {
    int id, update = 0;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]%*c", items[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Item updated successfully.\n");
            update = 1;
            break;
        }
    }
    if (!update) {
        printf("Item not updated.\n");
    }
}

void deleteItem(struct Item items[], int *count) {
    int a, deleted = 0;
    printf("Enter item ID to delete: ");
    scanf("%d", &a);
    for (int i = 0; i < *count; i++) {
        if (items[i].id == a) {
            for (int j = i; j < *count - 1; j++) {
                items[j] = items[j + 1];
            }
            (*count)--;
            printf("Item deleted successfully.\n");
            deleted = 1;
            break;
        }
    }
    if (!deleted) {
        printf("Item deleted successfully.\n");
    }
}

void calculateTotalValue(struct Item items[], int count) {
    float totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += items[i].quantity * items[i].price;
    }
    printf("Total Inventory Value: %.2f\n", totalValue);
}


