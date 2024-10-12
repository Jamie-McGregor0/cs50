#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    string key = argv[argc - 1];

    for(int i = 0; i < strlen(key); i++){

        if(isalpha(key[i]) == 0)
            return 1;
    }


}
