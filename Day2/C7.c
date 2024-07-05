/*
# C7. 별 찍기 (8각도형)

길이를 입력받은 후, 아래 그림과 같은 8각 모양의 도형을 화면에 출력하라.

실행 예
```
길이를 입력하시오 > 5
    #####
   #######
  #########
 ###########
#############
#############
#############
#############
#############
 ###########
  #########
   #######
    #####
```
```
길이를 입력하시오 > 2
 ##
####
####
 ## 
```
*/
#include <stdio.h>

int main(void) {
  int length;
  int i, j;
  
  printf("길이를 입력하시오 > ");
  scanf("%d", &length);

  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      printf(" ");
    }
    for (j = 0; j < length + 2 * i; j++) {
      printf("#");
    }
    printf("\n");
  }
  
  for (i = 0; i < length; i++) {
    for (j = 0; j < length * 3 - 2; j++) {
      printf("#");
    }
    printf("\n");
  }

  for (i = 1; i < length; i++) {
    for (j = 0; j < i; j++) {
      printf(" ");
    }
    for (j = 0; j < length * 3 - 2 * i - 2; j++) {
      printf("#");
    }
    printf("\n");
  }
  
  return 0;
}