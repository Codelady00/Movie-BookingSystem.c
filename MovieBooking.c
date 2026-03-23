#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structures
struct Movie {
    char name[50];
    float price;
};

struct Ticket {
    char userName[50];
    char date[20];
    char time[20];
    char movieName[50];
    int numTickets;
    float total;
};

struct Node {
    struct Ticket ticket;
    struct Node* next;
};

typedef struct Node* Stack;

// Stack functions
void push(Stack* s, struct Ticket t) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ticket = t;
    newNode->next = *s;
    *s = newNode;
}

struct Ticket pop(Stack* s) {
    if (*s == NULL) {
        struct Ticket empty = {0};
        return empty;
    }
    struct Ticket t = (*s)->ticket;
    struct Node* temp = *s;
    *s = (*s)->next;
    free(temp);
    return t;
}

// Validation functions
int isValidDate(char* date) {
    if (strlen(date) != 10) return 0;
    if (date[2] != '/' || date[5] != '/') return 0;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(date[i])) return 0;
    }
    return 1;
}

int isValidTime(char* time) {
    if (strlen(time) != 5) return 0;
    if (time[2] != ':') return 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        if (!isdigit(time[i])) return 0;
    }
    return 1;
}

int main() {
    // Initialize movies
    struct Movie movies[3] = {
        {"Frozen", 100.0},
        {"Dhurandar - The Revenge", 120.0},
        {"Gudiya Patole", 150.0}
    };

    Stack bookings = NULL;

    char userName[50];
    printf("Welcome to the Movie Booking System!\n");
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    // Remove trailing newline
    size_t len = strlen(userName);
    if (len > 0 && userName[len - 1] == '\n') {
        userName[len - 1] = '\0';
    }

    printf("Please select a movie:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s - Rs.%.2f\n", i + 1, movies[i].name, movies[i].price);
    }
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return 1;
    }

    char date[20], time[20];
    printf("Enter date (dd/mm/yyyy): ");
    fgets(date, sizeof(date), stdin);
    len = strlen(date);
    if (len > 0 && date[len - 1] == '\n') {
        date[len - 1] = '\0';
    }
    if (!isValidDate(date)) {
        printf("Invalid date format! Use dd/mm/yyyy\n");
        return 1;
    }

    printf("Enter time (hh:mm): ");
    fgets(time, sizeof(time), stdin);
    len = strlen(time);
    if (len > 0 && time[len - 1] == '\n') {
        time[len - 1] = '\0';
    }
    if (!isValidTime(time)) {
        printf("Invalid time format! Use hh:mm\n");
        return 1;
    }

    printf("Enter the number of tickets: ");
    int tickets;
    scanf("%d", &tickets);

    if (tickets <= 0) {
        printf("Invalid number of tickets! Must be at least 1.\n");
        return 1;
    }

    // Create ticket
    struct Ticket t;
    strcpy(t.userName, userName);
    strcpy(t.date, date);
    strcpy(t.time, time);
    strcpy(t.movieName, movies[choice - 1].name);
    t.numTickets = tickets;
    t.total = movies[choice - 1].price * tickets;

    // Push to stack
    push(&bookings, t);

    // Save to file
    FILE* f = fopen("bookings.txt", "a");
    if (f != NULL) {
        fprintf(f, "%s,%s,%s,%s,%d,%.2f\n", t.userName, t.date, t.time, t.movieName, t.numTickets, t.total);
        fclose(f);
    }

    // Display ticket
    printf("\n====================\n");
    printf("       TICKET       \n");
    printf("====================\n");
    printf("Name: %s\n", t.userName);
    printf("Date: %s\n", t.date);
    printf("Time: %s\n", t.time);
    printf("Movie: %s\n", t.movieName);
    printf("Tickets: %d\n", t.numTickets);
    printf("Total: Rs.%.2f\n", t.total);
    printf("====================\n");

    return 0;
}