#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    float marks;
};

// Function declarations (no average marks now)
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchByID(struct Student students[], int count, int id);

int main() {
    struct Student students[100];
    int count = 0;
    int choice, searchID;

    while (1) {
        printf("\n---Student Management System---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n"); // Removed average option
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &searchID);
                searchByID(students, count, searchID);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addStudent(struct Student students[], int *count) {
    struct Student *s = &students[*count];

    printf("Enter Student ID: ");
    scanf("%d", &s->id);

    getchar(); // clear newline from buffer
    printf("Enter Student Name: ");
    fgets(s->name, 100, stdin);
    s->name[strcspn(s->name, "\n")] = 0; // remove newline

    printf("Enter Marks: ");
    scanf("%f", &s->marks);

    (*count)++;
}

void displayStudents(struct Student students[], int count) {
    printf("\n---Students List---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Marks: %.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}

void searchByID(struct Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found! Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}