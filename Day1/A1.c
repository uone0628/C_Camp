/*
# A1. 키와 몸무게로 비만도(BMI) 계산 

신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만도(BMI)를 계산하여 출력하라.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 

이 때, 신장은 미터 단위로 환산해야 함을 유의하라.


변수는 다음과 같이 사용하라. 
```
int height, weight; // 신장(cm), 체중(kg) 
float bmi; // 비만도 수치 
```

# 힌트)

실수형 변수의 경우 타입을 %f로 한다. 그리고 소수점 이하 자릿수를 1자리로 맞춰 출력할 경우 %.1f 처럼 점 뒤에 숫자 1을 넣어준다.

```
float fnum;
scanf("%f", &fnum);
printf("%.1f", fnum); 
```
*/

#include <stdio.h>

int main(void) {
  int height, weight; // 신장(cm), 체중(kg)
  float bmi;          // 비만도 수치

  printf("height? ");
  scanf("%d", &height);
  printf("weight? ");
  scanf("%d", &weight);
  bmi = weight / (height * height * 0.0001);
  printf("Your bmi is %.1f\n", bmi);

  return 0;
}