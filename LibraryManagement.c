#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100      // macros for max entity
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 100

// Book structure
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int quantity;
} Book;

// Function for add book
void add_book(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    int id, quantity;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];
    printf("Enter Book ID: ");
    scanf("%d", &id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", title);
    printf("Enter Book Author: ");
    scanf(" %[^\n]", author);
    printf("Enter Book Quantity: ");
    scanf("%d", &quantity);

    books[*count].id = id;
    strcpy(books[*count].title, title);
    strcpy(books[*count].author, author);
    books[*count].quantity = quantity;

    (*count)++;
}

// Function for display all books
void display_books(Book books[], int count) {
    printf("\nList of Books:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s | Quantity: %d\n", books[i].id, books[i].title, books[i].author, books[i].quantity);
    }
}

// Function for search books 
void search_book_by_title(Book books[], int count) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter Book Title to Search: ");
    scanf(" %[^\n]", title);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book Found: ID: %d | Title: %s | Author: %s | Quantity: %d\n", books[i].id, books[i].title, books[i].author, books[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function for delete book 
void delete_book(Book books[], int *count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Book with ID %d deleted successfully.\n", id);
    } else {
        printf("Book with ID %d not found.\n", id);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add New Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &count);
                break;
            case 2:
                display_books(books, count);
                break;
            case 3:
                search_book_by_title(books, count);
                break;
            case 4:
                {
                    int id;
                    printf("Enter Book ID to Delete: ");
                    scanf("%d", &id);
                    delete_book(books, &count, id);
                }
                break;
            case 5:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Thank you ;)