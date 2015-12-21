#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int numCases;
    int numCycles;
    int height;
    int n;
    int i, j;

    scanf("%d", &numCases);
    
    for (i = 0; i < numCases; i++)
    {
        height = 1;
        scanf("%d", &numCycles);
        
        n = numCycles;
        if (numCycles % 2 != 0)
            n = numCycles + 1;
                
        for (j = 1; j <= n/2; j++)
        {
            height = 2 * height + 1;
        }
        
        if (numCycles % 2 != 0)
            height--;
        
        printf("%d\n", height);       
    }
    return 0;
}