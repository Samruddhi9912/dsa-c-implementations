#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[100];
    int i, j, n, m, found = 0;

    printf("Enter the main string: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    for(i = 0; i <= n - m; i++) {
        for(j = 0; j < m; j++) {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m) {
            printf("Pattern found at position %d\n", i);
            found = 1;
        }
    }

    if(!found)
        printf("Pattern not found");

    return 0;
}