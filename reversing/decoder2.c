#include <stdio.h>

int main(void)

{
  FILE *encoded_bmp;

  encoded_bmp = fopen("encoded2.bmp","r");

  char current_char;
  int high = 723;
  int low = 0;
  while (low < high) {
    fread(&current_char,1,1,encoded_bmp);
    low = low + 1;
  }
  int i = 0;
  while (i < 100) {
  	//printf("i:%d\n", i);
  	//printf("i%2:%d\n", i % 2);
  	if(i % 2 == 0) {
  		//printf("yay?\n");
		int j = 7;
		char result = 0;
		while (j >= 0) {
		  fread(&current_char,1,1,encoded_bmp);
		  result = result | ((current_char & 1) << (7 - j));
		  //printf("%x\n", ((current_char & 1) << (7 - j)));
		  j = j - 1;
		}
		printf("%c", (result));
		//printf("%d\n\n", (result & 0xff) + 5);
		//printf("%x\n", (result));
    } 
    else {
    	fread(&current_char,1,1,encoded_bmp);
    }
    i = i + 1;
  }
  printf("\n");

  fclose(encoded_bmp);
}

