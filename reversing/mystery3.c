
undefined8 main(void)

{
  size_t sVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  byte current_char;
  char local_7d;
  int local_7c;
  int low;
  int i;
  int j;
  undefined4 local_6c;
  int high;
  int local_64;
  FILE *flag_file;
  FILE *original_bmp;
  FILE *encoded_bmp;
  char flag_array [56];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_6c = 0;
  flag_file = fopen("flag.txt","r");
  original_bmp = fopen("original.bmp","r");
  encoded_bmp = fopen("encoded.bmp","a");
  if (flag_file == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  if (original_bmp == (FILE *)0x0) {
    puts("original.bmp is missing, please run this on the server");
  }
  sVar1 = fread(&current_char,1,1,original_bmp);
  local_7c = (int)sVar1;
  high = 2000;
  low = 0;
  while (low < high) {
    fputc((int)(char)current_char,encoded_bmp);
    sVar1 = fread(&current_char,1,1,original_bmp);
    local_7c = (int)sVar1;
    low = low + 1;
  }
  sVar1 = fread(flag_array,0x32,1,flag_file);
  local_64 = (int)sVar1;
  if (local_64 < 1) {
    puts("flag is not 50 chars");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  i = 0;
  while (i < 0x32) {
    j = 0;
    while (j < 8) {
      uVar2 = codedChar(j,flag_array[i] - 5,current_char);
      local_7d = (char)uVar2;
      fputc((int)local_7d,encoded_bmp);
      fread(&current_char,1,1,original_bmp);
      j = j + 1;
    }
    i = i + 1;
  }
  
  // while it has bits, copy them over
  while (local_7c == 1) {
    fputc((int)(char)current_char,encoded_bmp);
    sVar1 = fread(&current_char,1,1,original_bmp);
    local_7c = (int)sVar1;
  }
  fclose(encoded_bmp);
  fclose(original_bmp);
  fclose(flag_file);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



ulong codedChar(int param_1,byte param_2,byte param_3)

{
  byte local_20;
  
  local_20 = param_2;
  if (param_1 != 0) {
    local_20 = (byte)((int)(char)param_2 >> ((byte)param_1 & 0x1f));
  }
  return (ulong)(param_3 & 0xfe | local_20 & 1);
}



