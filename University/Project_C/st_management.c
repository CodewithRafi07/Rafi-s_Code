#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define TEXT_FILE "students.txt"
#define BINARY_FILE "students.dat"

// Structure to represent a student
struct Student {
    int id;
    char name[50];
    float grade;
};

// Function prototypes
void addStudentText(struct Student students[], int *count);
void addStudentBinary(struct Student students[], int *count);
void displayStudentsText();
void displayStudentsBinary();
void searchStudentText();
void searchStudentBinary();
void updateStudentGradeText();
void updateStudentGradeBinary();
void deleteStudentText(int *count);
void deleteStudentBinary(int *count);
void loadStudentsText(struct Student students[], int *count);
void loadStudentsBinary(struct Student students[], int *count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // Load existing students from files
    loadStudentsText(students, &count);
    // Alternatively, use loadStudentsBinary(students, &count);

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student (Text File)\n");
        printf("2. Add Student (Binary File)\n");
        printf("3. Display All Students (Text File)\n");
        printf("4. Display All Students (Binary File)\n");
        printf("5. Search Student (Text File)\n");
        printf("6. Search Student (Binary File)\n");
        printf("7. Update Student Grade (Text File)\n");
        printf("8. Update Student Grade (Binary File)\n");
        printf("9. Delete Student (Text File)\n");
        printf("10. Delete Student (Binary File)\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                addStudentText(students, &count);
                break;
            case 2:
                addStudentBinary(students, &count);
                break;
            case 3:
                displayStudentsText();
                break;
            case 4:
                displayStudentsBinary();
                break;
            case 5:
                searchStudentText();
                break;
            case 6:
                searchStudentBinary();
                break;
            case 7:
                updateStudentGradeText();
                break;
            case 8:
                updateStudentGradeBinary();
                break;
            case 9:
                deleteStudentText(&count);
                break;
            case 10:
                deleteStudentBinary(&count);
                break;
            case 11:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Add a student to text file (append mode)
void addStudentText(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    struct Student newStudent;
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    getchar();

    // Check for duplicate ID
    for (int i = 0; i < *count; i++) {
        if (students[i].id == newStudent.id) {
            printf("Student ID already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    printf("Enter Student Grade: ");
    scanf("%f", &newStudent.grade);

    // Append to text file
    FILE *file = fopen(TEXT_FILE, "a");
    if (file == NULL) {
        printf("Error opening text file!\n");
        return;
    }
    fprintf(file, "%d %s %.2f\n", newStudent.id, newStudent.name, newStudent.grade);
    fclose(file);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added to text file successfully!\n");
}

// Add a student to binary file (append mode)
void addStudentBinary(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    struct Student newStudent;
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    getchar();

    // Check for duplicate ID
    for (int i = 0; i < *count; i++) {
        if (students[i].id == newStudent.id) {
            printf("Student ID already exists!\n");
            return;
        }
    }

    printf("Enter Student Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;

    printf("Enter Student Grade: ");
    scanf("%f", &newStudent.grade);

    // Append to binary file
    FILE *file = fopen(BINARY_FILE, "ab");
    if (file == NULL) {
        printf("Error opening binary file!\n");
        return;
    }
    fwrite(&newStudent, sizeof(struct Student), 1, file);
    fclose(file);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added to binary file successfully!\n");
}

// Display students from text file
void displayStudentsText() {
    FILE *file = fopen(TEXT_FILE, "r");
    if (file == NULL) {
        printf("No student data found in text file!\n");
        return;
    }

    struct Student student;
    printf("\nStudent List (Text File):\n");
    printf("ID\tName\t\tGrade\n");
    while (fscanf(file, "%d %[^\n] %f\n", &student.id, student.name, &student.grade) != EOF) {
        printf("%d\t%s\t\t%.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

// Display students from binary file
void displayStudentsBinary() {
    FILE *file = fopen(BINARY_FILE, "rb");
    if (file == NULL) {
        printf("No student data found in binary file!\n");
        return;
    }

    struct Student student;
    printf("\nStudent List (Binary File):\n");
    printf("ID\tName\t\tGrade\n");
    while (fread(&student, sizeof(struct Student), 1, file)) {
        printf("%d\t%s\t\t%.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

// Search student in text file
void searchStudentText() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    FILE *file = fopen(TEXT_FILE, "r");
    if (file == NULL) {
        printf("Error opening text file!\n");
        return;
    }

    struct Student student;
    while (fscanf(file, "%d %[^\n] %f\n", &student.id, student.name, &student.grade) != EOF) {
        if (student.id == id) {
            printf("Student Found: ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            fclose(file);
            return;
        }
    }
    printf("Student not found!\n");
    fclose(file);
}

// Search student in binary file
void searchStudentBinary() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    FILE *file = fopen(BINARY_FILE, "rb");
    if (file == NULL) {
        printf("Error opening binary file!\n");
        return;
    }

    struct Student student;
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.id == id) {
            printf("Student Found: ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            fclose(file);
            return;
        }
    }
    printf("Student not found!\n");
    fclose(file);
}

// Update student grade in text file
void updateStudentGradeText() {
    int id;
    float newGrade;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    printf("Enter new grade: ");
    scanf("%f", &newGrade);

    FILE *file = fopen(TEXT_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL) {
        printf("Error opening files!\n");
        return;
    }

    struct Student student;
    int found = 0;
    while (fscanf(file, "%d %[^\n] %f\n", &student.id, student.name, &student.grade) != EOF) {
        if (student.id == id) {
            student.grade = newGrade;
            found = 1;
        }
        fprintf(temp, "%d %s %.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove(TEXT_FILE);
        rename("temp.txt", TEXT_FILE);
        printf("Grade updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("Student not found!\n");
    }
}

// Update student grade in binary file
void updateStudentGradeBinary() {
    int id;
    float newGrade;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    printf("Enter new grade: ");
    scanf("%f", &newGrade);

    FILE *file = fopen(BINARY_FILE, "r+b");
    if (file == NULL) {
        printf("Error opening binary file!\n");
        return;
    }

    struct Student student;
    int found = 0;
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.id == id) {
            student.grade = newGrade;
            fseek(file, -sizeof(struct Student), SEEK_CUR); // Move back to start of record
            fwrite(&student, sizeof(struct Student), 1, file);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        printf("Grade updated successfully!\n");
    } else {
        printf("Student not found!\n");
    }
}

// Delete student from text file
void deleteStudentText(int *count) {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(TEXT_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL) {
        printf("Error opening files!\n");
        return;
    }

    struct Student student;
    int found = 0;
    while (fscanf(file, "%d %[^\n] %f\n", &student.id, student.name, &student.grade) != EOF) {
        if (student.id != id) {
            fprintf(temp, "%d %s %.2f\n", student.id, student.name, student.grade);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove(TEXT_FILE);
        rename("temp.txt", TEXT_FILE);
        (*count)--;
        printf("Student deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Student not found!\n");
    }
}

// Delete student from binary file
void deleteStudentBinary(int *count) {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    FILE *file = fopen(BINARY_FILE, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (file == NULL || temp == NULL) {
        printf("Error opening files!\n");
        return;
    }

    struct Student student;
    int found = 0;
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.id != id) {
            fwrite(&student, sizeof(struct Student), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove(BINARY_FILE);
        rename("temp.dat", BINARY_FILE);
        (*count)--;
        printf("Student deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Student not found!\n");
    }
}

// Load students from text file
void loadStudentsText(struct Student students[], int *count) {
    FILE *file = fopen(TEXT_FILE, "r");
    if (file == NULL) {
        printf("No existing text file data found.\n");
        return;
    }

    *count = 0;
    while (fscanf(file, "%d %[^\n] %f\n", &students[*count].id, students[*count].name, &students[*count].grade) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Loaded %d students from text file.\n", *count);
}

// Load students from binary file
void loadStudentsBinary(struct Student students[], int *count) {
    FILE *file = fopen(BINARY_FILE, "rb");
    if (file == NULL) {
        printf("No existing binary file data found.\n");
        return;
    }

    *count = 0;
    while (fread(&students[*count], sizeof(struct Student), 1, file)) {
        (*count)++;
    }
    fclose(file);
    printf("Loaded %d students from binary file.\n", *count);
}