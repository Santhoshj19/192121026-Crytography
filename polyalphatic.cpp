#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char msg[100]; 
    char key[100]; 
    int msgLen, keyLen, i, j;
    printf("Enter the plain text (letters and digits): ");
    scanf("%s", msg);
    printf("Enter the key: ");
    scanf("%s", key);
    msgLen = strlen(msg);
    keyLen = strlen(key);
    char newKey[msgLen], encryptedMsg[msgLen];
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';
    for (i = 0; i < msgLen; ++i) {
        if (isalpha(msg[i])) {
            encryptedMsg[i] = ((toupper(msg[i]) + toupper(newKey[i])) % 26) + 'A';
        } else if (isdigit(msg[i])) {
            encryptedMsg[i] = ((msg[i] - '0' + newKey[i]) % 10) + '0';
        } else {
            encryptedMsg[i] = msg[i]; 
        }
    }
    encryptedMsg[i] = '\0';
    printf("Original Message: %s\n", msg);
    printf("Key: %s\n", key);
    printf("New Generated Key: %s\n", newKey);
    printf("Encrypted Message: %s\n", encryptedMsg);
    return 0;
}
