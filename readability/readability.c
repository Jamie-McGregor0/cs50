#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){

    string sen = get_string("Text: ");

    int length = strlen(sen);



    printf("%s\n", sen);
    printf("%i\n", length);


}
