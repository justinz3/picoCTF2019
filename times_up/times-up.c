
undefined8 main(void)

{
  init_randomness();
  printf("Challenge: ");
  generate_challenge();
  putchar(10);
  fflush(stdout);
  puts("Setting alarm...");
  fflush(stdout);
  ualarm(5000,0);
  printf("Solution? ");
  __isoc99_scanf(&DAT_00100e68,&guess);
  if (guess == result) {
    puts("Congrats! Here is the flag!");
    system("/bin/cat flag.txt");
  }
  else {
    puts("Nope!");
  }
  return 0;
}





void init_randomness(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  time_t tVar4;
  
  tVar4 = time((time_t *)0x0);
  srand((uint)tVar4);
  iVar1 = rand();
  iVar2 = rand();
  iVar3 = rand();
  seed = (long)(iVar3 + iVar1 * iVar2);
  return;
}




void generate_challenge(void)

{
  result = gen_expr(4);
  return;
}




long gen_expr(uint param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  if (param_1 == 0) {
    lVar1 = get_random();
    lVar1 = (long)(int)lVar1;
    printf("(%lld)",lVar1);
  }
  else {
    uVar2 = maybe_decrease(param_1);
    uVar3 = maybe_decrease(param_1);
    uVar4 = get_random_op();
    putchar(0x28);
    lVar1 = gen_expr((uint)uVar2);
    printf(" %c ",(ulong)(uint)(int)(char)uVar4);
    lVar5 = gen_expr((uint)uVar3);
    putchar(0x29);
    lVar1 = do_op((char)uVar4,lVar1,lVar5);
  }
  return lVar1;
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
    if (param_1 != '-') {
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    param_2 = param_2 - param_3;
  }
  return param_2;
}




ulong get_random_op(void)

{
  long lVar1;
  long in_FS_OFFSET;
  undefined2 local_13;
  undefined local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_13 = 0x2d2b;
  local_11 = 0;
  lVar1 = get_random();
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)*(byte *)((long)&local_13 + (ulong)((uint)lVar1 & 1));
}




long get_random(void)

{
  int iVar1;
  
  iVar1 = rand();
  seed = seed * iVar1;
  iVar1 = rand();
  seed = (seed + iVar1) * 0x539;
  iVar1 = rand();
  seed = seed + iVar1;
  iVar1 = rand();
  return seed * iVar1;
}




