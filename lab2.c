#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 10
void prims(int w[MAX_VERTICES][MAX_VERTICES], int n) {
int i, j, s, k = 0;
int min, sum = 0;
int u = 0, v = 0;
int flag = 0;
int sol[MAX_VERTICES] = {0};
printf("Enter the source vertex: ");
scanf("%d", &s);
sol[s] = 1;
k = 1;
while (k <= n - 1) {
min = INT_MAX;
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (sol[i] == 1 && sol[j] == 0) {
if (i != j && min > w[i][j]) {
min = w[i][j];
u = i;
v = j;
}
}
}
}
sol[v] = 1;
sum = sum + min;
k++;
printf("%d->%d=%d\n", u, v, min);
}
for (i = 1; i <= n; i++) {
if (sol[i] == 0) {
flag = 1;
}
}
if (flag == 1) {
printf("No spanning tree\n");
} else {
printf("The cost of minimum spanning tree is %d\n", sum);
}
}
int main() {
int w[MAX_VERTICES][MAX_VERTICES];
int n, i, j;
printf("Enter the number of vertices: ");
scanf("%d", &n);
printf("Enter the weight of the graph:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &w[i][j]);
}
}
prims(w, n);
return 0;
}