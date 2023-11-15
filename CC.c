#include <stdio.h>
#include <ctype.h>

void encrypt(char* message, int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch - 65 + key) % 26) + 65;
        }
        message[i] = ch;
    }
}

void decrypt(char* message, int key) {
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch - 65 - key + 26) % 26) + 65;
        }
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    gets(message);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}