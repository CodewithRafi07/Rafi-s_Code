#include <stdio.h>
#include <string.h>

#define MAX 10

struct Vault {
    char site[30];
    char password[30];
};

void encrypt(char *str) {
    for (int i = 0; str[i]; i++) str[i] += 3;
}

void decrypt(char *str) {
    for (int i = 0; str[i]; i++) str[i] -= 3;
}

int main() {
    struct Vault locker[MAX];
    int count = 0;
    char master[20];

    printf("Set your master key: ");
    scanf("%s", master);

    while (1) {
        int choice;
        printf("\n1. Add Password\n2. View Vault\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1 && count < MAX) {
            printf("Enter site name: ");
            scanf("%s", locker[count].site);
            printf("Enter password: ");
            scanf("%s", locker[count].password);
            encrypt(locker[count].password);
            count++;
        } else if (choice == 2) {
            char check[20];
            printf("Enter master key: ");
            scanf("%s", check);
            if (strcmp(check, master) == 0) {
                printf("\nSaved Passwords:\n");
                for (int i = 0; i < count; i++) {
                    printf("Site: %s, Password: ", locker[i].site);
                    decrypt(locker[i].password);
                    printf("%s\n", locker[i].password);
                    encrypt(locker[i].password); // Re-encrypt
                }
            } else {
                printf("Wrong master key!\n");
            }
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}
