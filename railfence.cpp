#  include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    char encrypted[100] = "";
    int depth;
    printf("-------------Rail Fence - Encryption---------\n\n");
    printf("Enter Plain Text: ");
    scanf("%s", str);
    printf("Enter Depth: ");
    scanf("%d", &depth);
    int len = strlen(str);
    char rails[depth][len];
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < len; j++) {
            rails[i][j] = '\0';
        }
    }
    int dir = 1;
    int row = 0;
    for (int i = 0; i < len; i++) {
        rails[row][i] = str[i];
        row += dir;
        if (row == depth - 1 || row == 0) {
            dir *= -1;
        }
    }
    printf("Rail Fence Pattern:\n");
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < len; j++) {
            if (rails[i][j] == '\0') {
                printf(" ");
            } else {
                printf("%c", rails[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nCipher Text: ");
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < len; j++) {
            if (rails[i][j] != '\0') {
                encrypted[strlen(encrypted)] = rails[i][j];
                printf("%c", rails[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}









