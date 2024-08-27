#include <stdio.h>
#include <cs50.h>

int length(long s);
int first(long n);
int second(long n);

int main(void){

    int sum = 0;
    int x;
    long n = get_long("Number: ");
    int l = length(n);
    int f = first(n);
    int s = second(n);

    for(int i = 0; i < l / 2; i ++){

        sum  = sum + n % 10;
        n = n / 10;
        x = n % 10 * 2;
        n = n / 10;
        sum = sum + x / 10 + x % 10;

    }

    if(sum % 10 == 0){

        if((l == 13 || l == 16) && f == 4)
            printf("VISA\n");

        else if(l == 15 && f == 3 && (s == 4 || s == 7))
            printf("AMEX\n");

        else if(f == 5 && s <= 5)
            printf("MASTERCARD\n");

        else
            printf("INVALID\n");

    }

    else
        printf("INVALID\n");

}

int length(long n){
    int length = 1;
    while(n / 10 > 0){
        n = n / 10;
        length ++;
    }

return length;
}

int first(long n){
    while(n / 10 > 0)
        n = n / 10;

    return n;
}

int second(long n){
    while(n / 100 > 0)
        n = n / 10;

    return n;
}
