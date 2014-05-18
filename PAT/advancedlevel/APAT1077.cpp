#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    char s1[260], s2[260];
    getchar();
    gets(s1);
    int end1 = (int)strlen(s1);
    int end2 = 0;
    int max = end1;
    
    while (-- n) {
        gets(s2);
        end2 = (int)strlen(s2);
        int i = end1 - 1, j = end2 - 1;
        while (i >= 0 && i >= 0 && end1 - i <= max && end2 - j <= max && s1[i] == s2[j]) {
            i --;
            j --;
        }
        max = end1 - i -1;
    }
    
    if (max == 0)
        printf("nai\n");
    else
        printf("%s\n", s1 + end1 - max);
    
    return 0;
}
