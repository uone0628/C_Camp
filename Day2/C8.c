/*
# C8. 별 찍기 (8각도형 2)

> _**반드시 코드 상단에 생각을 정리한 후, 코딩하도록 하라. 정리된 생각도 평가함!_

짝수 값의 길이를 입력받은 후, 아래 그림과 같이 속이 비어 있는 8각 모양의 도형을 화면에 출력하라.


실행 예

```
길이(짝수)를 입력하시오 > 2
 ##
#  #
#  #
 ##
```
```
길이(짝수)를 입력하시오 > 4   
   ####
  ##  ##
 ##    ##
##      ##
##      ##
##      ##
##      ##
 ##    ##
  ##  ##
   ####

```
*/
#include <stdio.h>

int main(void) {
  int length;
  int i, j;

  printf("길이(짝수)를 입력하시오 > ");
  scanf("%d", &length);

  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      printf(" ");
    }
    for (j = 0; j < length / 2; j++) {
      printf("#");
    }
    for (j = 0; j < i * 2; j++) {
      printf(" ");
    }
    for (j = 0; j < length / 2; j++) {
      printf("#");
    }
    printf("\n");
  }

  for (i = 0; i < length; i++) {
    for (j = 0; j < length / 2; j++) {
      printf("#");
    }
    for (j = 0; j < length * 2 - 2; j++) {
      printf(" ");
    }
    for (j = 0; j < length / 2; j++) {
      printf("#");
    }
    printf("\n");
  }

  for (i = 1; i < length; i++) {
    for (j = 0; j < i; j++) {
      printf(" ");
    }
    for (j = 0; j < length / 2; j++) {
      printf("#");
    }
    for (j = 0; j < length * 2 - i * 2 - 2; j++) {
      printf(" ");
    }
    for (j = 0; j < length / 2; j++) {
      printf("#");
    }
    printf("\n");
  }
	
  return 0;
}