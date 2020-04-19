
void main(void)

{
  FILE *flag;
  FILE *flag_00;
  FILE *flag_01;
  FILE *flag_02;
  long in_FS_OFFSET;
  char lowercase_o;
  int i;
  int j;
  int k;
  char array [4];
  char local_34;
  char local_33;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  flag = fopen("flag.txt","r");
  flag_00 = fopen("mystery.png","a");
  flag_01 = fopen("mystery2.png","a");
  flag_02 = fopen("mystery3.png","a");
  if (flag == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  if (flag_00 == (FILE *)0x0) {
    puts("mystery.png is missing, please run this on the server");
  }
  fread(array,0x1a,1,flag);
  fputc((int)array[1],flag_02);
  fputc((int)(char)(array[0] + '\x15'),flag_01);
  fputc((int)array[2],flag_02);
  lowercase_o = array[3];
  fputc((int)local_33,flag_02);
  fputc((int)local_34,flag_00);
  i = 6;
  while (i < 10) {
    lowercase_o = lowercase_o + '\x01';
    fputc((int)array[i],flag_00);
    i = i + 1;
  }
  fputc((int)lowercase_o,flag_01);
  j = 10;
  while (j < 0xf) {
    fputc((int)array[j],flag_02);
    j = j + 1;
  }
  k = 0xf;
  while (k < 0x1a) {
    fputc((int)array[k],flag_00);
    k = k + 1;
  }
  fclose(flag_00);
  fclose(flag);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


