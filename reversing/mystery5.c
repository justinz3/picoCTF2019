
undefined8 main(void)

{
  size_t sVar1;
  undefined4 local_4c;
  undefined local_48 [52];
  int local_14;
  FILE *local_10;
  
  flag = local_48;
  local_4c = 0;
  flag_index = &local_4c;
  local_10 = fopen("flag.txt","r");
  if (local_10 == (FILE *)0x0) {
    puts("No flag found, please make sure this is run on the server");
  }
  sVar1 = fread(flag,0x32,1,local_10);
  local_14 = (int)sVar1;
  if (local_14 < 1) {
    puts("Invalid Flag");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  fclose(local_10);
  encodeAll();
  return 0;
}


/* WARNING: Could not reconcile some variable overlaps */

void encodeAll(void)

{
  ulong local_48;
  undefined8 local_40;
  undefined4 local_38;
  ulong local_28;
  undefined8 local_20;
  undefined4 local_18;
  char local_9;
  
  local_28 = 0x635f31306d657449;
  local_20 = 0x706d622e70;
  local_18 = 0;
  local_48 = 0x622e31306d657449;
  local_40 = 0x706d;
  local_38 = 0;
  local_9 = '5';
  while ('0' < local_9) {
    local_48._0_6_ = CONCAT15(local_9,(undefined5)local_48);
    local_48 = local_48 & 0xffff000000000000 | (ulong)(uint6)local_48;
    local_28._0_6_ = CONCAT15(local_9,(undefined5)local_28);
    local_28 = local_28 & 0xffff000000000000 | (ulong)(uint6)local_28;
    encodeDataInFile((char *)&local_48,(char *)&local_28);
    local_9 = local_9 + -1;
  }
  return;
}



void encodeDataInFile(char *param_1,char *param_2)

{
  size_t sVar1;
  ulong uVar2;
  byte local_2e;
  char local_2d;
  int high;
  FILE *encoded;
  FILE *original;
  int local_18;
  int j;
  int i;
  int local_c;
  
  original = fopen(param_1,"r");
  encoded = fopen(param_2,"a");
  if (original != (FILE *)0x0) {
    sVar1 = fread(&local_2e,1,1,original);
    local_c = (int)sVar1;
    high = 0x7e3;
    i = 0;
    while (i < high) {
      fputc((int)(char)local_2e,encoded);
      sVar1 = fread(&local_2e,1,1,original);
      local_c = (int)sVar1;
      i = i + 1;
    }
    j = 0;
    while (j < 0x32) {
      if (j % 5 == 0) {
        local_18 = 0;
        while (local_18 < 8) {
          uVar2 = codedChar(local_18,*(byte *)(*flag_index + flag),local_2e);
          local_2d = (char)uVar2;
          fputc((int)local_2d,encoded);
          fread(&local_2e,1,1,original);
          local_18 = local_18 + 1;
        }
        *flag_index = *flag_index + 1;
      }
      else {
        fputc((int)(char)local_2e,encoded);
        fread(&local_2e,1,1,original);
      }
      j = j + 1;
    }
    while (local_c == 1) {
      fputc((int)(char)local_2e,encoded);
      sVar1 = fread(&local_2e,1,1,original);
      local_c = (int)sVar1;
    }
    fclose(encoded);
    fclose(original);
    return;
  }
  puts("No output found, please run this on the server");
                    /* WARNING: Subroutine does not return */
  exit(0);
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



