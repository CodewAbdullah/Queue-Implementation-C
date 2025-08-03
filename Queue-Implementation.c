#include <stdio.h>
#define size 5
int queue[size];
int front = -1, rear = -1;

void inqueue(int num) {

    if (rear == size - 1) {

        printf("The queue is full.\n");
    }

    else {

        if (front == -1) {

            front = 0;
        }

        rear++;
        queue[rear] = num;
        printf("\n%d inqueued.\n", num);
    }
}

void dequeue() {

    if (front == -1 || front > rear) {

        printf("\nQueue is empty.\n");
    }

    else {

        printf("\n%d is dequeued.\n", queue[front]);
        front++;
    }

    if (front > rear) {
        front = rear = -1;
    }
}

void peek() {

    if (front == -1 || front > rear) {

        printf("\nThe queue is empty.\n");
    }

    else {

        printf("\nTop element: %d\n", queue[front]);
    }
}

void display() {

    if (front == -1 || front > rear) {

        printf("\nQueue is empty.\n");
    }

    else {

        printf("\nThe elements in the queue: ");

        for (int i = front; i <= rear; i++) {

            printf("%d ", queue[i]);
        }
    }
}

void count() {

    int count_elements = 0;

    if (front == -1 || front > rear) {

        printf("Queue is empty.\n");
    }

    else {

        for (int i = front; i <= rear; i++) {

            count_elements++;
        }

        printf("total elements: %d\n", count_elements);
    }
}

int main() {

    char exit = '\0';

    do {

        int choice = 0;
        int valid = 0;
        int valid1 = 0;
        int num = 0;

        printf("\n1. Inqueue.\n");
        printf("2. Dequeue.\n");
        printf("3. Peek.\n");
        printf("4. Display.\n");
        printf("5. Count elements.\n");
        printf("6. Exit.\n");

        do {

            valid = 0;
            printf("Choose an option: ");

            if (scanf("%d", &choice) != 1) {

                while(getchar() != '\n');
                printf("Invalid Input.\n");

                valid1 = 1;
            }

            else if (choice < 1 || choice > 6) {

                printf("Invalid Option, please choose an option between(1-6).\n");
            }

        }while (valid1 !=0 || choice < 1 || choice > 6);

        switch (choice) {

            case 1:

            do {

                valid = 0;
                printf("Enter your number to inqueue: ");
                if (scanf("%d", &num) != 1) {

                    while(getchar() != '\n');
                    printf("Invalid Input!!.\n");
                    valid = 1;
                }

            } while (valid != 0);

            inqueue(num);
            break;

            case 2:

            dequeue();
            break;

            case 3:

            peek();
            break;

            case 4:

            display();
            break;

            case 5:

            count();
            break;

            case 6:

            printf ("Do you want to exit the program?(Y/N): ");
            scanf(" %c", &exit);
            while (getchar() != '\n');
            break;

        }

    } while (exit != 'Y' && exit != 'y');

    printf("Exiting the program.\n");

    return 0;
}