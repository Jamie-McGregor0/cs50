#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    string key = "bcdefghijklmnopqrstuvwxyza";

    string plain = get_string("plaintext: ");

    string cipher[strlen(plain)];

    strcpy(cipher, plain);

    for(int i = 0; i < strlen(plain); i++){

        for(int j = 0; j < strlen(alphabet); j++){

            if(isalpha(plain[i])){
                if(tolower(plain[i]) == tolower(alphabet[j])){
                    cipher[i] = key[j];
                }
            }
        }

    }


    printf("ciphertext: %s\n", cipher);



}
