#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int numIterations;
    char s[100001];
    int i, j;
    char *p;
    char *q;
    int numDeletions;
    
    scanf("%d", &numIterations);
    
    for(i = 0; i < numIterations; i++){
        
        scanf("%s", s);
        numDeletions = 0;
        p = s;
        q = s + 1;
        
        while(*q != '\0'){
            if (*q == *p)
                numDeletions++;
            else
                p = q;
            q++;
        }
        
        printf("%d\n", numDeletions);
    }
    
    return 0;
}
