#include <stdio.h>
#include <string.h>

char str[50], pat[20], rep[20], res[50];
int c = 0, m = 0, i = 0, j = 0, k, flag = 0;

void stringmatch() {
    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    res[j] = rep[k];
                }
                i = 0;
                c = m;
            }
        } else {
            res[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    res[j] = '\0';
}

int main() {
    printf("Enter the main string:");
    fgets(str, sizeof(str), stdin);
    printf("\nEnter the pat string:");
    fgets(pat, sizeof(pat), stdin);
    printf("\nEnter the replace string:");
    fgets(rep, sizeof(rep), stdin);

    // Removing newline characters from inputs
    str[strcspn(str, "\n")] = '\0';
    pat[strcspn(pat, "\n")] = '\0';
    rep[strcspn(rep, "\n")] = '\0';

    printf("\nThe string before pattern match is:\n %s\n", str);
    stringmatch();
    if (flag == 1)
        printf("\nThe string after pattern match and replace is:\n %s\n", res);
    else
        printf("\nPattern string is not found\n");

    return 0;
}
