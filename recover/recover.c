#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    if(argv[1] = ""){
        printf("No FILE\n");
        return 2;
    }

    FILE *card = fopen(argv[1],"r");

    uint8_t buffer[512];

    i == 0;

    while(fread(buffer, 1, 512, card) == 512){

        char img_name[512];
        if(buffer[i] == 0xff && buffer[i+1] == 0xd8 && buffer[i+2] == 0xff && (buffer[i+3] & 0xf0) == 0xe0){
            if(i == 0){

                sprintf(img_name[i], "%03i.jpg", i);
                FILE *card = fopen(argv[1], "w");
                fwrite(img, 1, 1, img0);
            }

            else{
                fclose(img);
            }





        }
    }


}
