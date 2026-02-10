#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    int left, right;
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline
    str[strcspn(str, "\n")] = '\0';

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {

        // Optional: skip non-alphanumeric characters
        while (!isalnum(str[left]) && left < right)
            left++;
        while (!isalnum(str[right]) && left < right)
            right--;

        // Optional: ignore case
        if (tolower(str[left]) != tolower(str[right])) {
            isPalindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (isPalindrome)
        printf("The string IS a palindrome.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}
