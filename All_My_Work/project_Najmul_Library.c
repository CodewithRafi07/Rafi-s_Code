#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define FILENAME "library.dat"

// Structure to represent a book
struct Book {
    int id;
    char title[50];
    char author[50];
};

// Function prototypes
void addBook(struct Book books[], int *count);
void displayBooks(struct Book books[], int count);
void searchBook(struct Book books[], int count);
void deleteBook(struct Book books[], int *count);
void saveToFile(struct Book books[], int count);
void loadFromFile(struct Book books[], int *count);

int main() {
    struct Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    // Load existing books from file
    loadFromFile(books, &count);

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                displayBooks(books, count);
                break;
            case 3:
                searchBook(books, count);
                break;
            case 4:
                deleteBook(books, &count);
                break;
            case 5:
                saveToFile(books, count);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar(); // Clear newline

    // Check for duplicate ID
    for (int i = 0; i < *count; i++) {
        if (books[i].id == newBook.id) {
            printf("Book ID already exists!\n");
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    books[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books in the library!\n");
        return;
    }

    printf("\nBook List:\n");
    printf("ID\tTitle\t\tAuthor\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\n", books[i].id, books[i].title, books[i].author);
    }
}

void searchBook(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Book Found:\n");
            printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
            return;
        }
    }
    printf("Book not found!\n");
}

void deleteBook(struct Book books[], int *count) {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1]; // Shift books to fill gap
            }
            (*count)--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found!\n");
}

void saveToFile(struct Book books[], int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file); // Write book count
    fwrite(books, sizeof(struct Book), count, file); // Write books
    fclose(file);
    printf("Books saved to file.\n");
}

void loadFromFile(struct Book books[], int *count) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("No existing library data found.\n");
        return;
    }

    fread(count, sizeof(int), 1, file); // Read book count
    fread(books, sizeof(struct Book), *count, file); // Read books
    fclose(file);
    printf("Loaded %d books from file.\n", *count);
}