#include <stdio.h>

int count_char(char *str, char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (c >= 'a' && c <= 'z') { 
            if (str[i] == c || str[i] == c - 32) { 
                count++;
            }
        } else if (c >= 'A' && c <= 'Z') { 
            if (str[i] == c || str[i] == c + 32) 
                count++;
            }
        }
    }
    return count; 
}

int main() {
    char str[100]; 
    char c;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("Enter the character: ");
    scanf(" %c", &c); 

    int r = count_char(str, c);

    printf("The count of character '%c' in string \"%s\" is %d.\n", c, str, r);

    return 0;
}
