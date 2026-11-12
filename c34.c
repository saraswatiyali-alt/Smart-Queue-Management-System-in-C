
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int token = 100;

void generateToken() {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }

    token++;
    queue[++rear] = token;

    printf("\nYour token number is: %d\n", token);
    printf("Please wait for your turn.\n");
}

void callNext() {
    if (front > rear) {
        printf("\nNo customers waiting!\n");
        return;
    }

    printf("\nNow serving token: %d\n", queue[front]);
    front++;
}

void displayQueue() {
    if (front > rear) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nWaiting Tokens:\n");

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\nPeople waiting: %d\n", rear - front + 1);
}

void searchToken() {
    int search, found = 0;

    printf("\nEnter token number: ");
    scanf("%d", &search);

    for (int i = front; i <= rear; i++) {
        if (queue[i] == search) {
            printf("Token %d is waiting.\n", search);
            printf("Position in queue: %d\n", i - front + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Token not found in waiting queue.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== SMART QUEUE SYSTEM =====\n");
        printf("1. Generate Token\n");
        printf("2. Call Next Customer\n");
        printf("3. Display Waiting Queue\n");
        printf("4. Search Token\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateToken();
                break;

            case 2:
                callNext();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                searchToken();
                break;

            case 5:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
