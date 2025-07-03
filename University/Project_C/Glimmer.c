#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_CART_ITEMS 50

// Structure for product
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Structure for cart item
typedef struct {
    int productId;
    int quantity;
} CartItem;

Product products[MAX_PRODUCTS];
int productCount = 0;

CartItem cart[MAX_CART_ITEMS];
int cartCount = 0;

// Function prototypes
void adminMenu();
void customerMenu();
void addProduct();
void viewProducts();
void customerViewProducts();
void addToCart();
void checkout();
Product* findProductById(int id);

int main() {
    int choice;

        // Add default products directly
        products[productCount++] = (Product){1, "Gold Necklace", 2999.99, 10};
        products[productCount++] = (Product){2, "Silver Ring", 499.50, 25};
        products[productCount++] = (Product){3, "Diamond Earrings", 5499.00, 5};
        products[productCount++] = (Product){4, "Platinum Bracelet", 3299.75, 7};
        products[productCount++] = (Product){5, "Pearl Pendant", 899.99, 12};

    while (1) {
        printf("\n===== Welcome to GLIMMER STORE =====\n");
        printf("1. Admin Panel\n");
        printf("2. Customer Panel\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                printf("Thank you for visiting GLIMMER!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// ADMIN

void adminMenu() {
    int choice;
    while (1) {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add Product\n");
        printf("2. View All Products\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product list is full!\n");
        return;
    }

    Product p;
    p.id = productCount + 1;
    printf("Enter product name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    products[productCount++] = p;
    printf("Product added successfully with ID: %d\n", p.id);
}

void viewProducts() {
    printf("\n--- Product List ---\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Stock");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-20s %-10.2f %-10d\n",
               products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// CUSTOMER

void customerMenu() {
    int choice;

    while (1) {
        printf("\n--- Customer Menu ---\n");
        printf("1. View Products\n");
        printf("2. Add to Cart\n");
        printf("3. Checkout\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerViewProducts();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                checkout(); 
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void customerViewProducts() {
    viewProducts();
}

void addToCart() {
    int id, qty, choice;

    while (1) {
        printf("Enter Product ID to add to cart: ");
        scanf("%d", &id);

        Product* p = findProductById(id);
        if (p == NULL) {
            printf("Product not found!\n");
        } else {
            printf("Enter quantity: ");
            scanf("%d", &qty);

            if (qty > p->quantity) {
                printf("Not enough stock!\n");
            } else {
                cart[cartCount].productId = id;
                cart[cartCount].quantity = qty;
                cartCount++;
                printf("Product added to cart!\n");
            }
        }

        printf("Do you want to add another product? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
    }
}


void checkout() {
    float total = 0;
    printf("\n--- Checkout ---\n");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Qty", "Price", "Total");

    for (int i = 0; i < cartCount; i++) {
        Product* p = findProductById(cart[i].productId);
        if (p != NULL && cart[i].quantity <= p->quantity) {
            float cost = p->price * cart[i].quantity;
            printf("%-5d %-20s %-10d %-10.2f %-10.2f\n", 
               p->id, p->name, cart[i].quantity, p->price, cost);
            total += cost;
            p->quantity -= cart[i].quantity;  // reduce stock
        }
    }

    printf("Total amount: %.2f\n", total);
    printf("Thank you for shopping with GLIMMER!\n");
    printf("Please Visit: www.glimmer.shop\n");
    printf("For any queries, Suggestions or Complaints\n");
    printf("Please Call: +880 160245-0000\n");
    exit(0);  // Close the program after checkout
}

Product* findProductById(int id) {
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}
