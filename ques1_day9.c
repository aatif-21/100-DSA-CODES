#include <stdio.h>
#include <string.h>

int main() {
    char code[100];

    printf("Enter the code name: ");
    fgets(code, sizeof(code), stdin);

    // Remove newline character if present
    code[strcspn(code, "\n")] = '\0';

    int len = strlen(code);

    printf("Mirror format: ");
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", code[i]);
    }

    printf("\n");
    return 0;
}
