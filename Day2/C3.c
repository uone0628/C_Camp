/*
# C3. 별 찍기 (이등변 삼각형)  

숫자를 하나 입력받은 후에 이 숫자만큼의 높이를 갖는 이등변삼각형을 '*' 문자로 화면에 출력하라. 

예를 들어 10을 입력하면 첫 줄에는 1개, 2번째 줄에는 3개, 3번째 줄에는 5개, ..., 10번째 줄에는 19개의 '*' 을 가운데 정렬한 모습으로 출력하는 것이다.


변수는 다음과 같이 사용하라. 
```
int height; // 입력받은 높이
int i, j; // 반복문 사용을 위한 변수 
```
```
height? 4
   *
  ***
 *****
*******
```
*/
#include <stdio.h>

int main(void) {
  int height; // 입력받은 정사각형 한 변의 길이 
  int i, j; // 반복문 사용을 위한 변수 

  printf("height? ");
  scanf("%d", &height);

  for(i = 0; i < height; i++) {
    for(j = 0; j < height - i - 1; j++) {
      printf(" ");
    }
    for(j = 0; j < i * 2 + 1; j++) {
      printf("*");
    }
    printf("\n");
  }
 
  return 0;
}