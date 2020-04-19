
undefined8 main(void)

{
  init_randomness();
  printf("Challenge: ");
  generate_challenge();
  putchar(10);
  fflush(stdout);
  puts("Setting alarm...");
  fflush(stdout);
  ualarm(200,0);
  printf("Solution? ");
  __isoc99_scanf(&DAT_00100efb,&guess);
  if (guess == result) {
    puts("Congrats! Here is the flag.txt!");
    system("/bin/cat flag.txt");
  }
  else {
    puts("Nope!");
  }
  return 0;
}



void init_randomness(void)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  srand((uint)tVar1);
  urandom = fopen("/dev/urandom","r");
  return;
}



void generate_challenge(void)

{
  result = gen_expr(4);
  return;
}



long gen_expr(uint param_1)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  
  if (param_1 == 0) {
    uVar1 = get_random();
    lVar2 = (long)(int)uVar1;
    printf("(%lld)",lVar2);
  }
  else {
    uVar3 = maybe_decrease(param_1);
    uVar4 = maybe_decrease(param_1);
    uVar5 = get_random_op();
    putchar(0x28);
    lVar2 = gen_expr((uint)uVar3);
    printf(" %c ",(ulong)(uint)(int)(char)uVar5);
    lVar6 = gen_expr((uint)uVar4);
    putchar(0x29);
    lVar2 = do_op((char)uVar5,lVar2,lVar6);
  }
  return lVar2;
}


ulong get_random_op(void)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_14 = 0x2a2d2b;
  iVar1 = rand();
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)*(byte *)((long)&local_14 + (ulong)(long)iVar1 % 3);
}


undefined8 get_random(void)

{
  long in_FS_OFFSET;
  undefined8 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  fread(&local_18,8,1,urandom);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_18;
}



ulong maybe_decrease(uint param_1)

{
  int iVar1;
  
  iVar1 = rand();
  if (0 < iVar1 % 0x32) {
    param_1 = param_1 - 1;
  }
  return (ulong)param_1;
}


long do_op(char param_1,long param_2,long param_3)

{
  if (param_1 == '+') {
    param_2 = param_3 + param_2;
  }
  else {
    if (param_1 == '-') {
      param_2 = param_2 - param_3;
    }
    else {
      if (param_1 != '*') {
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      param_2 = param_2 * param_3;
    }
  }
  return param_2;
}





