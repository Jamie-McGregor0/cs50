#include <stdio.h>
#include <cs50.h>
int main(void){

    int h;
    do{
        h = get_int("Height: ");
    }while(h < 1);

    int w = 2 * h + 2;

    for(int i = 0; i < h; i ++){

        int s = (w / 2 - 2 - i); //space in one side

        for(int j = 0; j < w; j ++){

            if ((j >= s && j < w/2 - 1) || (j > w/2 && j < w - s))
                printf("#");

            else if(j < w - s)
                printf(" ");
        }
        printf("\n");
    }


}
