#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define block_size 512
#define name_length 8

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1],"r");
    if(card == NULL){
        printf("No FILE\n");
        return 2;
    }

    uint8_t buffer[block_size];
    FILE *current_file = NULL;
    int jpg_count = 0;
    char *img_name[name_length];

    while(fread(buffer, 1, 512, card) == block_size){
        for(int i = 0; i < block_size - 3; i ++){

            if(buffer[i] == 0xff && buffer[i+1] == 0xd8 && buffer[i+2] == 0xff && (buffer[i+3] & 0xf0) == 0xe0){

                if(current_file != NULL){
                    fclose(current_file);
                    current_file = NULL;
                }

                jpg_count ++;

                sprintf(img_name, "%03i.jpg", jpg_count);

                current_file = fopen(img_name, "w");
                fwrite(buffer + i, 1, block_size - i, current_file);

            }
        }

        if(current_file != NULL){
                fwrite(buffer, 1, block_size, current_file);
            }
    }

    if(current_file != NULL){
        fcolse(current_file);
    }

    fclose(card);

}
