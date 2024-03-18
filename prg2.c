#include <stdio.h>

char str[100], pat[20], rep[20], newstr[100];
int i = 0, j = 0, k, n = 0, exist = 0, l = 0;

void matchAndReplace();

int main() {
    printf("\nEnter the string:");
    fgets(str, sizeof(str), stdin);
    printf("\nEnter the pattern:");
    fgets(pat, sizeof(pat), stdin);
    printf("\nEnter the replacing pattern:");
    fgets(rep, sizeof(rep), stdin);
    matchAndReplace();
    return 0;
}

void matchAndReplace() {
    while (str[i] != '\0') {
        j = 0, k = i;
        while (str[k] == pat[j] && pat[j] != '\0') {
            k++;
            j++;
        }
        if (pat[j] == '\0') {
            exist = 1;
            for (l = 0; rep[l] != '\0'; l++)
                newstr[n++] = rep[l];
            i = k;
        } else
            newstr[n++] = str[i++];
    }
    if (!exist)
        printf("\nPattern does not exist");
    else {
        newstr[n] = '\0';
        printf("\nThe new string is:");
        puts(newstr);
    }
}
