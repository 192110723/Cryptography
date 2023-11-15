#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char plaintext[], char key[]) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < plaintextLen; i++) {
        if (isalpha(plaintext[i])) {
            char shift = islower(key[j % keyLen]) ? key[j % keyLen] - 'a' : key[j % keyLen] - 'A';
            char base = islower(plaintext[i]) ? 'a' : 'A';
            plaintext[i] = (plaintext[i] - base + shift) % 26 + base;

            j++;
        }
    }
}
void vigenereDecrypt(char ciphertext[], char key[]) {
    int i, j;
    int ciphertextLen = strlen(ciphertext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < ciphertextLen; i++) {
        if (isalpha(ciphertext[i])) {
            char shift = islower(key[j % keyLen]) ? key[j % keyLen] - 'a' : key[j % keyLen] - 'A';
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            ciphertext[i] = (ciphertext[i] - base - shift + 26) % 26 + base;

            j++;
        }
    }
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    strtok(plaintext, "\n");
    strtok(key, "\n");

    vigenereEncrypt(plaintext, key);
    printf("Encrypted Text: %s\n", plaintext);

    vigenereDecrypt(plaintext, key);
    printf("Decrypted Text: %s\n", plaintext);

    return 0;
}
