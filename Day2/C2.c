/*
# C2. 별 찍기 (우직각 삼각형)

높이와 여백을 정하는 숫자 두 개를 입력받은 후에 이 숫자만큼의 높이와 왼쪽 여백을 갖는 우직각 삼각형을 '*' 문자로 화면에 출력하라. 

예를 들어 10을 입력하면 첫 줄에는 1개, 2번째 줄에는 2개, 3번째 줄에는 3 개, .. 10번째 줄에는 10개의 '*' 을 왼쪽 여백을 가진 우측 정렬된 모습으로 출력하는 것이다.

변수는 다음과 같이 사용하라. 
```
int height; // 입력받은 높이
int blank; // 입력받은 여백 크기
int i, j; // 반복문 사용을 위한 변수 
```
실행 예)

```
height? 4
blank? 2
     *
    **
   ***
  ****
```
*/
#include <stdio.h>

int main(void) {
  int height; // 입력받은 높이
  int blank; // 입력받은 여백 크기
  int i, j; // 반복문 사용을 위한 변수

  printf("height? ");
  scanf("%d", &height);
  printf("blank? ");
  scanf("%d", &blank);

  for(i = 0; i < height; i++) {
    for(j = 0; j < blank; j++) {
      printf(" ");
    }
    for(j = 0; j < height - i - 1; j++) {
      printf(" ");
    }
    for(j = 0; j < i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}