#ifndef MAT_H
#define MAT_H

#define V 10


void C(int graph[V][V]);

int isReachable(int G[V][V], int i, int j);
void B(int G[V][V]);

int (*A())[V];

int max(int x, int y);
int knapSack(int item_weights[], int item_values[], char item_names[], char selected_items[]);
int my_knapSack();

#endif // MAT_H
