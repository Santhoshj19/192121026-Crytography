#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTLEFT(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

void compute_sha1(const char *input, size_t input_len, uint32_t hash[5]) {
   
}

int main() {
    char message[1024];
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    uint32_t hash[5];
    size_t message_len = strlen(message);

    compute_sha1(message, message_len, hash);

    printf("Message: %s\n", message);
    printf("SHA-1 Hash: ");
    for (int i = 0; i < 5; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}
