#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
const uint32_t K[] = {
    0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
};
const uint32_t IV[] = {
    0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
};
void md5_transform(uint32_t state[4], const uint8_t block[64]) {
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t m[16];
    for (int i = 0; i < 16; i++) {
        m[i] = block[i * 4] | (block[i * 4 + 1] << 8) | (block[i * 4 + 2] << 16) | (block[i * 4 + 3] << 24);
    }
    for (int i = 0; i < 16; i++) {
        uint32_t f = F(b, c, d);
        uint32_t g = i;
        uint32_t temp = d;
        d = c;
        c = b;
        b = b + LEFT_ROTATE((a + f + K[0] + m[g]), 7);
        a = temp;
    }
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}
void md5_hash(const uint8_t *message, size_t message_len, uint8_t hash[16]) {
    uint32_t state[4];
    memcpy(state, IV, sizeof(IV));
    for (size_t i = 0; i < message_len; i += 64) {
        md5_transform(state, message + i);
    }
    for (int i = 0; i < 4; i++) {
        hash[i * 4] = state[i] & 0xFF;
        hash[i * 4 + 1] = (state[i] >> 8) & 0xFF;
        hash[i * 4 + 2] = (state[i] >> 16) & 0xFF;
        hash[i * 4 + 3] = (state[i] >> 24) & 0xFF;
    }
}
int main() {
    char message[1024]; 
    uint8_t hash[16];
    printf("Enter the message to hash: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    md5_hash((uint8_t *)message, strlen(message), hash);
    printf("MD5 Hash: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
