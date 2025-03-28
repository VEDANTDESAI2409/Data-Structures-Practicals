#include <stdio.h>

int n = 5;
int arr[10]; // Increased size to prevent overflow during insertion
void print() {
 printf("Array elements:\n");
 for (int i = 0; i < n; i++) {
 printf("%d: %d\n", i, arr[i]);
 }
}
void insert() {
 int j, d, i;
 printf("Enter index to insert (0-%d): ", n);
 scanf("%d", &j);
 if (j < 0 || j > n) {
 printf("Invalid index!\n");
 return;
 }
 printf("Enter number to insert: ");
 scanf("%d", &d);
 for (i = n; i > j; i--) {
arr[i] = arr[i - 1];
 }
 arr[j] = d;
 n++;
 print();
}
void delete() {
 int j, i;
 printf("Enter index to delete (0-%d): ", n - 1);
 scanf("%d", &j);
 if (j < 0 || j >= n) {
 printf("Invalid index!\n");
 return;
 }
 for (i = j; i < n - 1; i++) {
 arr[i] = arr[i + 1];
 }
 n--;
 print();
}
void search() {
 int d, i, found = 0;
 printf("Enter element to search: ");
 scanf("%d", &d);
 for (i = 0; i < n; i++) {
 if (arr[i] == d) {
 printf("Element found at index %d\n", i);
 found = 1;
break;
 }
 }
 if (!found) {
 printf("Element not found!\n");
 }
}
int main() {
 int ch, m = 1;
 printf("Enter %d elements:\n", n);
 for (int i = 0; i < n; i++) {
 printf("Element %d: ", i);
 scanf("%d", &arr[i]);
 }

 while (m) {
 printf("\nChoose an operation:\n");
 printf("1) Print\n2) Insert\n3) Delete\n4) Search\n");
 printf("Enter choice: ");
 scanf("%d", &ch);

 switch (ch) {
 case 1: print(); break;
 case 2: insert(); break;
 case 3: delete(); break;
 case 4: search(); break;
 default: printf("Invalid choice!\n"); break;
 }printf("Enter 1 to continue, 0 to exit: ");
 scanf("%d", &m);
 }
 return 0;
}
