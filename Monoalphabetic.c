#include <stdio.h>
#include <string.h>
const char* PLAINTEXT_ALPHABET = "abcdefghijklmnopqrstuvwxyz";
const char* CIPHERTEXT_ALPHABET = "zyxwvutsrqponmlkjihgfedcba";

char* encrypt(char* plaintext, char* key) {
  char* ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    int plaintext_index = PLAINTEXT_ALPHABET[i] - 'a';
    ciphertext[i] = CIPHERTEXT_ALPHABET[plaintext_index];
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

char* decrypt(char* ciphertext, char* key) {
  char* plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    int ciphertext_index = CIPHERTEXT_ALPHABET[i] - 'a';
    plaintext[i] = PLAINTEXT_ALPHABET[ciphertext_index];
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

int main() {
  char plaintext[100];
  printf("Enter the plaintext message to encrypt: ");
  scanf("%s", plaintext);

  char key[26];
  printf("Enter the encryption key: ");
  scanf("%s", key);

  char* ciphertext = encrypt(plaintext, key);

  printf("The encrypted message is: %s\n", ciphertext);

  char* decrypted_plaintext = decrypt(ciphertext, key);

  printf("The decrypted message is: %s\n", decrypted_plaintext);

  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}
