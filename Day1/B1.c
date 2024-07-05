/*
# B1. 국영수 과목 점수 총점, 평균 계산하기    

국어, 영어, 수학 점수를 입력받아 이 점수의 총점과 평균을 계산하여 출력하라.

단, 총점 = 국어점수 + 영어점수 + 수학점수, 

평균 = 총점 / 3.0 으로 계산하라. 

변수는 다음과 같이 사용하라.
```
int kor, eng, math; // 국어점수, 영어점수, 수학점수 
int total; // 총점
float average; // 평균점수 
```
실행 예)  

```
Kor? 85
Eng? 95
Math? 80
total is 260,
average is 86.7.
```
*/

#include <stdio.h>

int main(void) {
  int kor, eng, math; // 국어점수, 영어점수, 수학점수 
  int total; // 총점
  float average; // 평균점수 

  printf("Kor? ");
  scanf("%d", &kor);
  printf("Eng? ");
  scanf("%d", &eng);
  printf("Math? ");
  scanf("%d", &math);
  total = kor + eng + math;
  average = total / 3.0;
  printf("total is %d, ", total);
  printf("average is %.1f. \n", average);
  
  return 0;
}