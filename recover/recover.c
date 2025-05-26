#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define block_size 512

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
    int i = 0;
    int jpg_count = 0;
    char img_name;

    while(fread(buffer, 1, 512, card) == block_size){
        for(int i = 0; i < block_size - 3; i ++){
            
            if(buffer[i] == 0xff && buffer[i+1] == 0xd8 && buffer[i+2] == 0xff && (buffer[i+3] & 0xf0) == 0xe0){
            if(jpg_count == 0){
                sprintf(img_name, "%03i.jpg", jpg_count);

                FILE *output_file = fopen(argv[1], "w");
                fwrite(buffer, 1, 1, output_file);
            }

            else{
                fclose(img);
            }




        }







        }
    }


}
