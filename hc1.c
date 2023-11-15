#include <stdio.h>
#include <string.h>
#include <math.h>

int modInverse(int a, int m) {
    int m0 = m;
    int x0 = 0;
    int x1 = 1;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int main() {
    unsigned int a[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    unsigned int b[3][3];
    int i, j;

    printf("Enter the key (3x3 matrix):\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%u", &b[i][j]);
        }
    }

    unsigned int c[20], d[20];
    char msg[20];
    int determinant = 0, t = 0;

    printf("Enter plain text: ");
    scanf("%s", msg);

    for (i = 0; i < 3; i++) {
        c[i] = msg[i] - 65;
    }

    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) {
            t = t + (a[i][j] * c[j]);
        }
        d[i] = t % 26;
    }

    printf("\nEncrypted Cipher Text: ");
    for (i = 0; i < 3; i++) {
        printf("%c", d[i] + 65);
    }

    // Calculate the determinant of the key matrix
    int keyDet = b[0][0] * (b[1][1] * b[2][2] - b[2][1] * b[1][2]) -
                 b[0][1] * (b[1][0] * b[2][2] - b[2][0] * b[1][2]) +
                 b[0][2] * (b[1][0] * b[2][1] - b[2][0] * b[1][1]);

    // Ensure the determinant is not zero
    if (keyDet == 0) {
        printf("\nDecryption key is not valid (determinant is 0).\n");
        return 1;
    }

    // Calculate the modular multiplicative inverse of the determinant
    int keyDetInverse = modInverse(keyDet, 26);

    // Calculate the adjugate of the key matrix
    unsigned int keyAdj[3][3];
    keyAdj[0][0] = (b[1][1] * b[2][2] - b[2][1] * b[1][2]) % 26;
    keyAdj[0][1] = (b[0][2] * b[2][1] - b[2][2] * b[0][1]) % 26;
    keyAdj[0][2] = (b[0][1] * b[1][2] - b[1][1] * b[0][2]) % 26;
    keyAdj[1][0] = (b[1][2] * b[2][0] - b[2][2] * b[1][0]) % 26;
    keyAdj[1][1] = (b[0][0] * b[2][2] - b[2][0] * b[0][2]) % 26;
    keyAdj[1][2] = (b[0][2] * b[1][0] - b[1][2] * b[0][0]) % 26;
    keyAdj[2][0] = (b[1][0] * b[2][1] - b[2][0] * b[1][1]) % 26;
    keyAdj[2][1] = (b[0][1] * b[2][0] - b[2][1] * b[0][0]) % 26;
    keyAdj[2][2] = (b[0][0] * b[1][1] - b[1][0] * b[0][1]) % 26;

    // Calculate the inverse of the key matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            b[i][j] = (keyAdj[i][j] * keyDetInverse) % 26;
        }
    }

    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) {
            t = t + (b[i][j] * d[j]);
        }
        c[i] = t % 26;
    }

    printf("\nDecrypted Cipher Text: ");
    for (i = 0; i < 3; i++) {
        printf("%c", c[i] + 65);
    }

    return 0;
}
