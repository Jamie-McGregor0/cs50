#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int punc(char x);

int main(void){

    string sen = get_string("Text: ");

    int length = strlen(sen);

    float l = length; //number of letters
    float s = 0; //number of sentences
    float w = 0; //number of words

    for(int i = 0; i < length; i++){

        if (punc(sen[i]) == 1){ // "!"
            l ++;
            s ++;
            w ++;
        }

        else if (punc(sen[i]) == 2){ // ','
            l --;
            w ++;
        }

        else if (punc(sen[i]) == 3){ // '\''
            l --;
            w ++;
        }
        else if (punc(sen[i]) == 4){ // ' '

            if (punc(sen[i-1]) == 1 || punc(sen[i-1]) == 2) // "! "
                l --;

            else{ // "A B"
                l --;
                w ++;
            }

        }

    }

    float index = 0.0588 * (l / w * 100) - 0.296 * (s / w * 100) - 15.8;

    //printf("%f\n%f\n%f\n", l,s,w);

    if (index >= 16)
        printf("Grade 16+\n");

    else if (index < 1)
        printf("Before Grade 1\n");

    else
        printf("Grade %i\n", (int)round(index));


}

int punc(char x){
    if (x == '.' || x == '!' || x == '?')
        return 1;

    else if (x == ',')
        return 2;

    else if (x == '\'')
        return 3;

    else if (x == ' ')
        return 4;

    else
        return 0;
}
