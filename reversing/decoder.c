#include <stdio.h>

int main(void)

{
  FILE *encoded_bmp;

  encoded_bmp = fopen("encoded.bmp","r");

  char current_char;
  fread(&current_char,1,1,encoded_bmp);
  int high = 2000;
  int low = 1;
  while (low < high) {
    fread(&current_char,1,1,encoded_bmp);
    low = low + 1;
  }
  int i = 0;
  while (i < 0x32) {
    int j = 7;
    char result = 0;
    while (j >= 0) {
      fread(&current_char,1,1,encoded_bmp);
      result = result | ((current_char & 1) << (7 - j));
      //printf("%x\n", ((current_char & 1) << (7 - j)));
      j = j - 1;
    }
    printf("%c", (result & 0xff) + 5);
    //printf("%d\n\n", (result & 0xff) + 5);
    //printf("%x\n", (result + 5));
    i = i + 1;
  }
  printf("\n");

  fclose(encoded_bmp);
}

