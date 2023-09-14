 #include <stdio.h>
#include <stdint.h>
uint64_t key = 0x133457799BBCDFF1; 
uint64_t plaintext = 0x0123456789ABCDEF;
int initial_permutation[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

uint32_t des_round(uint32_t data, uint32_t round_key) {
    uint32_t expanded_data = 0; 
    uint32_t substituted_data = expanded_data ^ round_key; 

    return substituted_data;
}

int main() {
    uint64_t permuted_data = 0;
    for (int i = 0; i < 64; i++) {
        int bit_pos = initial_permutation[i] - 1;
        uint64_t bit = (plaintext >> bit_pos) & 1;
        permuted_data |= (bit << (63 - i));
    }

   
    uint32_t left = permuted_data >> 32;
    uint32_t right = (uint32_t) permuted_data;

    uint32_t round_key = (uint32_t) (key >> 32); 
    uint32_t new_right = des_round(right, round_key);

   
    uint64_t ciphertext = ((uint64_t) left << 32) | new_right;

    printf("Plaintext: 0x%016llX\n", plaintext);
    printf("Ciphertext: 0x%016llX\n", ciphertext);

   return 0;
}
