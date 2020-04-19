
int main(void)

{
  long lVar1;
  size_t sVar2;
  undefined4 local_18;
  int local_14;
  FILE *flag_file;
  
  flag_file = fopen("flag.txt","r");
  if (flag_file == (FILE *)0x0) {
    fwrite("./flag.txt not found\n",1,0x15,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  flag_size = 0;
  fseek(flag_file,0,2);
  lVar1 = ftell(flag_file);
  flag_size = (int)lVar1;
  fseek(flag_file,0,0);
  if (0xfffe < flag_size) {
    fwrite("Error, file bigger that 65535\n",1,0x1e,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  flag = malloc((long)flag_size);
  sVar2 = fread(flag,1,(long)flag_size,flag_file);
  local_14 = (int)sVar2;
  if (local_14 < 1) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  local_18 = 0;
  flag_index = &local_18;
  output = fopen("output","w");
  buffChar = 0;
  remain = 7;
  fclose(flag_file);
  encode();
  fclose(output);
  fwrite("I\'m Done, check ./output\n",1,0x19,stderr);
  return 0;
}




void encode(void)

{
  char bVar1;
  int iVar2;
  long long uVar3;
  unsigned long uVar4;
  int local_10;
  char local_9;
  
  while( true ) {
    if (flag_size <= *flag_index) {
      while (remain != 7) {
        save(0);
      }
      return;
    }
    bVar1 = *(char *)(*flag_index + flag);
    uVar3 = isValid(bVar1);
    if ((char)uVar3 != '\x01') break;
    uVar4 = lower(bVar1);
    local_9 = (char)uVar4;
    if (local_9 == ' ') {
      local_9 = '{';
    }
    local_10 = *(int *)(matrix + (long)((int)local_9 + -0x61) * 8 + 4);
    iVar2 = local_10 + *(int *)(matrix + (long)((int)local_9 + -0x61) * 8);
    while (local_10 < iVar2) {
      uVar4 = getValue(local_10);
      save((char)uVar4);
      local_10 = local_10 + 1;
    }
    *flag_index = *flag_index + 1;
  }
  fwrite("Error, I don\'t know why I crashed\n",1,0x22,stderr);
                    /* WARNING: Subroutine does not return */
  exit(1);
}





long long isValid(char param_1)

{
  long long uVar1;
  
  if ((param_1 < 'a') || ('z' < param_1)) {
    if ((param_1 < 'A') || ('Z' < param_1)) {
      if (param_1 == ' ') {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}




unsigned long getValue(int param_1)

{
  char bVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (param_1 < 0) {
    iVar2 = param_1 + 7;
  }
  bVar1 = (char)(param_1 >> 0x37);
  return (unsigned long)((int)(unsigned int)(char)secret[iVar2 >> 3] >>
                 (7 - (((char)param_1 + (bVar1 >> 5) & 7) - (bVar1 >> 5)) & 0x1f) & 1);
}




void save(char param_1)

{
  buffChar = buffChar | param_1;
  if (remain == 0) {
    remain = 7;
    fputc((int)(char)buffChar,output);
    buffChar = '\0';
  }
  else {
    buffChar = buffChar * '\x02';
    remain = remain + -1;
  }
  return;
}



unsigned long lower(char param_1)

{
  unsigned long uVar1;
  
  if (((char)param_1 < 'A') || ('Z' < (char)param_1)) {
    uVar1 = (unsigned long)param_1;
  }
  else {
    uVar1 = (unsigned long)((unsigned int)param_1 + 0x20);
  }
  return uVar1;
}



