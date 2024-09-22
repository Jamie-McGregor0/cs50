#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){

    int numb[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char chr[] = "abcdefghijklmnopqrstuvwxyz";

    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");

    int length1 = strlen(s1);
    int length2 = strlen(s2);

    char x1[length1];
    char x2[length2];

    strcpy(x1, s1);

    int sum1 = 0;
    int sum2 = 0;

    for(int i = 0; i < length1; i++){

        for(int j = 0; j < 26; j++){

            if(x1[i] == chr[j])
                sum1 += numb[j];

        }
    }

    for(int i = 0; i < length2; i++){

        for(int j = 0; j < 26; j++){

            if(x1[i] == chr[j])
                sum2 += numb[j];

        }
    }

    if(sum1 == sum2)
        printf("Tie!\n");

    else if(sum1 > sum2)
        printf("Player 1 wins!\n");

    else
        printf("Player 2 wins!\n");


}
