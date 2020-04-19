#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void init_randomness(void);
void generate_challenge(void);
long gen_expr(unsigned int param_1);
unsigned long maybe_decrease(unsigned int param_1);
long do_op(char param_1,long param_2,long param_3);
unsigned long get_random_op(void);
long get_random(void);

long long result;
long long seed;

int main(void)

{
  init_randomness();
  generate_challenge();
  printf("%lli\n", result);
  
  /*long long guess;
  scanf("%lli", &guess);
  if(guess == result)
  	printf("YAY!\n");
  else
  	printf("BAD!\n");*/
  return 0;
}





void init_randomness(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  time_t tVar4;
  
  tVar4 = time((time_t *)0x0);
  srand((unsigned int)tVar4);
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




long gen_expr(unsigned int param_1)

{
  long lVar1;
  unsigned long uVar2;
  unsigned long uVar3;
  unsigned long uVar4;
  long lVar5;
  
  if (param_1 == 0) {
    lVar1 = get_random();
    lVar1 = (long)(int)lVar1;
    //printf("(%lld)",lVar1);
  }
  else {
    uVar2 = maybe_decrease(param_1);
    uVar3 = maybe_decrease(param_1);
    uVar4 = get_random_op();
    //putchar(0x28);
    lVar1 = gen_expr((unsigned int)uVar2);
    //printf(" %c ",(unsigned long)(unsigned int)(int)(char)uVar4);
    lVar5 = gen_expr((unsigned int)uVar3);
    //putchar(0x29);
    lVar1 = do_op((char)uVar4,lVar1,lVar5);
  }
  return lVar1;
}


unsigned long maybe_decrease(unsigned int param_1)

{
  int iVar1;
  
  iVar1 = rand();
  if (0 < iVar1 % 0x32) {
    param_1 = param_1 - 1;
  }
  return (unsigned long)param_1;
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




unsigned long get_random_op(void)

{
  long lVar1;
  long in_FS_OFFSET;
  long local_13;
  long local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_13 = 0x2d2b;
  local_11 = 0;
  lVar1 = get_random();

  return (unsigned long)*(char *)((long)&local_13 + (unsigned long)((unsigned int)lVar1 & 1));
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




