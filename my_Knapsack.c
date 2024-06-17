#include <stdio.h>
#include "my_mat.h"

#define TOTAL_ITEMS 5

int my_knapSack() {
    int weights[TOTAL_ITEMS];
    int values[TOTAL_ITEMS];
    char item_names[TOTAL_ITEMS];
    char items[TOTAL_ITEMS]; 
    
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        char name;
        scanf(" %c %d %d", &name, &values[i], &weights[i]);
        item_names[i] = name; 
    }

    int max_value = knapSack(weights, values, item_names, items);

    printf("Maximum value: %d\r\n", max_value);
    printf("Selected items:");
    for (int i = 0; i < TOTAL_ITEMS; i++) {
        if (items[i] != '\0') { 
            printf(" %c", items[i]);
        }
    }
  
    return max_value;
}

int main() {
    my_knapSack();
    return 0;
}
