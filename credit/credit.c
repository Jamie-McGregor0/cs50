#include <stdio.h>
#include <cs50.h>

int length(int s);

int main(void){

    int sum = 0;
    int x;
    int n = get_long("Number: ");
    int l = length(n);

    for(int i = 0; i < l / 2; i ++){

        sum  = sum + n % 10;
        n = n / 10;
        x = n % 10 * 2;
        n = n / 10;
        sum = sum + x / 10 + x % 10;

    }

    if(sum % 10 == 0){

        if(l == 13 || l == 16)
            printf("VISA\n");

        else if(l == 15)
            printf("AMEX\n");

        else
            printf("MASTERCARD\n");

    }

    else
        printf("INVALID\n");

}

int length(int s){
    int length = 1;
    while(s / 10 > 0){
        s = s / 10;
        length ++;
    }

return length;
}
