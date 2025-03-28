/*AIM : Write a program to implement Queue using arrays that performs following operations. 
(a) INSERT (b) DELETE (c) DISPLAY*/

#include <stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1;
void insert() {
 int val;
 if (rear == MAX - 1) {
 printf("Queue Overflow!\n");
 return;
 }
 printf("Enter value to insert: ");
 scanf("%d", &val);
 if (front == -1) front = 0;
 queue[++rear] = val;
}
void delete() {
 if (front == -1 || front > rear) {
 printf("Queue Underflow!\n");
 return;
 }
 printf("Deleted element: %d\n", queue[front++]);
 if (front > rear) front = rear = -1; // Reset queue if empty
}
void display() {
 if (front == -1) {
 printf("Queue is empty!\n");
 return;
 }
 printf("\nQueue: [");
 for (int i = front; i <= rear; i++) {
 printf(" %d ", queue[i]);
 if (i != rear) printf("|");
 }
 printf("]\n");
}
int main() {
 int choice, cont = 1;
 while (cont) {
 printf("\n1) ENQUEUE\n2) DEQUEUE\n3) DISPLAY\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1: insert(); break;
 case 2: delete(); break;
 case 3: display(); break;
 default: printf("Invalid choice!\n");
 }
 printf("Enter 1 to continue, 0 to exit: ");
 scanf("%d", &cont);
 }
 return 0;
}
