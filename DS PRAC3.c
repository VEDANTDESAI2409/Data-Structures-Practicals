/*AIM : Implement a program for stack that performs following operations using array. 
(a) PUSH (b) POP (c) PEEP (d) CHANGE (e) DISPLAY*/

#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;
void push() {
 int val;
 if (top == MAX - 1) {
 printf("Stack Overflow!\n");
 return;
 }
 printf("Enter value to push: ");
 scanf("%d", &val);
 stack[++top] = val;
}
void pop() {
 if (top == -1) {
 printf("Stack Underflow!\n");
 return;
 }
 printf("Popped element: %d\n", stack[top--]);
}
void peep() {
 int pos;
 printf("Enter position from top (1 to %d): ", top + 1);
 scanf("%d", &pos);
 if (pos > top + 1 || pos <= 0) {
 printf("Invalid position!\n");
 return;
 }
 printf("Element at position %d: %d\n", pos, stack[top - pos + 1]);
}
void change() {
 int pos, val;
 printf("Enter position from top (1 to %d): ", top + 1);
 scanf("%d", &pos);
 if (pos > top + 1 || pos <= 0) {
 printf("Invalid position!\n");
 return;
 }
 printf("Enter new value: ");
 scanf("%d", &val);
 stack[top - pos + 1] = val;
}
void display() {
 if (top == -1) {
 printf("Stack is empty!\n");
 return;
 }
 printf("\nStack:\n");
 for (int i = top; i >= 0; i--) {

 printf("┌───────┐\n");
 printf("│ %3d │\n", stack[i]);
 if (i == 0) {
 printf("└───────┘\n"); // Bottom of the stack
 } else {
 printf("├───────┤\n"); // Connecting line
 }
 }
}
int main() {
 int choice, cont = 1;
 while (cont) {
 printf("\n1) PUSH\n2) POP\n3) PEEP\n4) CHANGE\n5) DISPLAY\nEnter your choice:");
 scanf("%d", &choice);
 switch (choice) {
 case 1: push(); break;
 case 2: pop(); break;
 case 3: peep(); break;
 case 4: change(); break;
 case 5: display(); break;
 default: printf("Invalid choice!\n");
 }
 printf("Enter 1 to continue, 0 to exit: ");
 scanf("%d", &cont);
 }
 return 0;
}
