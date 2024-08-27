#include <stdio.h>
#include <cs50.h>

length(int s)

int main(void){

    int sum = 0;
    int x;
    int n = get_long("Number: ");

    for(int i = 0; i < n; i ++;){

        sum  = sum + n % 10;
        n = n / 10;
        x = n % 10 * 2;
        n = n / 10;
        sum = sum + x / 10 + x % 10;


    }







}

length(int s){
    int length = 1;
    while(s / 10 > 0){
        s = s / 10;
        length ++;
    }

return length;
}
