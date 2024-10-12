#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string key = argv[argc - 1];

    if(strlen(key) != 26 || argc != 2)
        return 1;

    for(int i = 0; i < strlen(key); i++){

        if(isalpha(key[i]) == 0){
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    int check[strlen(alphabet)] = {};

    for(int i = 0; i < strlen(key); i++){
        for(int j = 0; j < strlen(alphabet); j++){

            if(key[i] == alphabet[j])
                check[j] += 1;
        }
    }

    for(int i = 0; i < strlen(alphabet); i++){
        if(check[i] > 1)
            return 1;
    }


    string plain = get_string("plaintext: ");
    char cipher[strlen(plain)];
    strcpy(cipher, plain);

    for(int i = 0; i < strlen(plain); i++){

        for(int j = 0; j < strlen(alphabet); j++){

            if(isalpha(plain[i])){
                if(tolower(plain[i]) == tolower(alphabet[j])){
                    if(islower(plain[i]))
                        cipher[i] = tolower(key[j]);
                    else
                        cipher[i] = toupper(key[j]);
                }
            }
        }
    }

    printf("ciphertext: %s\n", cipher);

}
