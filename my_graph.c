#include <stdio.h>
#include "my_mat.h"
#include <string.h>

#define V 10



int main() {
    char str[3]; 
    int indicator = 1;
    int (*graph)[V];
    while (indicator){
        scanf("%s", str); 
    
        if (strcmp(str, "A") == 0) {
            graph = A();
        } 
        
        else if (strcmp(str, "B") == 0) { // להשלמה
            B(graph);
        } 
        
        else if (strcmp(str, "C") == 0) { // להשלמה
            C(graph); 
            
        } else if (strcmp(str, "D") == 0 || strcmp(str, "EOF") == 0) {  // להשלמה
            indicator = 0;
        }

    }
}    
