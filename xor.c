/* xor.c */


#include <stdio.h>
#include <string.h>


void printstring(char *label, char *text) {
    printf("%s = ", label);
    for (int i = 0; text[i] != '\0'; i++) {
        printf("'%c' (0x%02x) ", text[i], (unsigned char)text[i]);
    }
    printf("\n");
}


int main()
{ 
    char cleartext[100];
    char key[100];
    char ciphertext[100];
    char newcleartext[100];

    printf("Insert the message: ");
    scanf(" %99s", cleartext);

     printf("Insert the key: ");
    scanf(" %99s", key);


    printstring("Cleartext", cleartext);
    printstring("Key", key);
    
    for (int i = 0; cleartext[i] != '\0'; i++) {
        ciphertext[i] = cleartext[i] ^ key[i % strlen(key)]; // XOR operation to encrypt
        // Using modulo to repeat the key if it's shorter than the cleartext 
    }
    ciphertext[strlen(cleartext)] = '\0';
    
    printstring("Ciphertext", ciphertext);

    for(int i = 0; ciphertext[i] != '\0'; i++){
        newcleartext[i] = ciphertext[i] ^ key[i % strlen(key)]; // XOR operation to decrypt
        // Using modulo to repeat the key if it's shorter than the ciphertext
    }

     newcleartext[strlen(ciphertext)] = '\0';
    

    printstring("New Cleartext", newcleartext);

    return 0;

    
}



