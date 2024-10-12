#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    string key = argv[argc - 1];

    if(strlen(key) != 26 || argc != 2)
        return 1;

    for(int i = 0; i < strlen(key); i++){

        if(isalpha(key[i]) == 0){
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    string plain = get_string("plaintext: ");

    for(int i = 0; i < strlen(plain); i++){

        for(int j = 0; j < 26; j++){

            if(isalpha(plain[i])){
                if(tolower(plain[i]) == tolower(key[j]))
                    plain[i] = key[j];
            }

        }

    }


    printf("ciphertext: %s\n%s\n", plain, key);



}
