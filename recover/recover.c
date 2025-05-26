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
    i = 0;
    jpg_count = 0;
    char img_name;

    while(fread(buffer, 1, 512, card) == 512){


        if(buffer[i] == 0xff && buffer[i+1] == 0xd8 && buffer[i+2] == 0xff && (buffer[i+3] & 0xf0) == 0xe0){
            if(jpg_count == 0){
                sprintf(img_name, "%03i.jpg", jpg_count);
                FILE *card = fopen(argv[1], "w");
                fwrite(img, 1, 1, img0);
            }

            else{
                fclose(img);
            }





        }
    }


}
