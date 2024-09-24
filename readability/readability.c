#include <cs50.h>
#include <stdio.h>
#include <string.h>

int punc(char x);

int main(void){

    string sen = get_string("Text: ");

    int length = strlen(sen);

    int l = length; //number of letters
    int s = 0; //number of sentences
    int w = 0; //number of words

    for(int i = 0; i < length; i++){

        {
            l -= 1;
            s += 1;
            w += 1;
        }

        else if (sen[i] == ' ')
            w += 1;

    }

    int index = 0.0588 * (l / w * 100) - 0.296 * (s / w * 100) - 15.8;



    //printf("%s\n", sen);
    printf("%i\n%i\n%i\n", l,s,w);


}

punc(char x){
    if (X == '.' || x == '!' || X == '?')
        return 1;

    else if (x == ',')
        return 2;

    else
        return 0;
}
