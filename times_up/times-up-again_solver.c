#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void init_randomness(void);
void generate_challenge(void);
long gen_expr(unsigned int param_1);
unsigned long maybe_decrease(unsigned int param_1);
long do_op(char param_1,long param_2,long param_3);
unsigned long get_random_op(void);
long long get_random(void);

long long result;
long long seed;
FILE * urandom;

int main(void)

{
  init_randomness();
  //printf("Challenge: ");
  ////printf("\n");
  generate_challenge();
  putchar(10);
  fflush(stdout);
  puts("Setting alarm...");
  fflush(stdout);
  ualarm(200,0);
  //printf("Solution? ");
  printf("%lli\n", result);	
  /*long long guess;
  scanf("%lli", &guess);
  if (guess == result) {
    puts("Congrats! Here is the flag.txt!");
    system("/bin/cat flag.txt");
  }
  else {
    puts("Nope!");
  }*/
  return 0;
}



void init_randomness(void)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)0x0);
  srand((unsigned 	)tVar1);
  urandom = fopen("/dev/urandom","r");
  return;
}



void generate_challenge(void)

{
  result = gen_expr(4);
  return;
}



long gen_expr(unsigned int param_1)

{
  long long uVar1;
  long lVar2;
  unsigned long uVar3;
  unsigned long uVar4;
  unsigned long uVar5;
  long lVar6;
  
  if (param_1 == 0) {
    uVar1 = get_random();
    lVar2 = (long)(int)uVar1;
    //printf("(%lld)",lVar2);
  }
  else {
    uVar3 = maybe_decrease(param_1);
    uVar4 = maybe_decrease(param_1);
    uVar5 = get_random_op();
    putchar(0x28);
   	//printf("\n");
    lVar2 = gen_expr((unsigned int)uVar3);
    //printf(" %c ",(unsigned long)(unsigned int)(int)(char)uVar5);
    lVar6 = gen_expr((unsigned int)uVar4);
    putchar(0x29);
    //printf("\n");
    lVar2 = do_op((char)uVar5,lVar2,lVar6);
  }
  return lVar2;
}


unsigned long get_random_op(void)

{
  int iVar1;
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  local_14 = 0x2a2d2b;
  iVar1 = rand();
  return (unsigned long)*(char *)((long)&local_14 + (unsigned long)(long)iVar1 % 3);
}


long long get_random(void)

{
  long long local_18;

  fread(&local_18,8,1,urandom);
  return local_18;
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





