/*
#  A5. 비만 판정 (함수 버전)


10명의 신장(cm단위)과 체중(kg단위)를 입력받으면서 AskBiman() 함수를 통해 이들이 비만도를 출력하고 다음 기준에 따라 비만여부를 판정하여 출력하라.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 

이 때, 신장은 미터 단위로 환산해야 함을 유의 하라. 

비만도 수치에 따른 비만도 판정 

1. 18.5 미만 : 저체중
2. 18.5 ~ 23 미만 : 정상체중 

3. 23~25미만 : 과체중 

4. 25~30미만 : 경도비만 

5. 30이상 : 고도비만 

함수 원형은 다음과 같다.



```
int AskBiman(int height, int weight);
파라미터) height : 신장(cm), weight : 체중(kg) 리턴 값) 없음
수행내용) 비만도 계산 후 판정결과 리턴
리턴값) 저체중 0, 정상체중 1, 과체중 2, 경도비만 3, 고도비만 4
```

실행 예)

```
1번째 사람 신장과 체중? 176 80
경도비만
2번째 사람 신장과 체중? 182 99
경도비만
3번째 사람 신장과 체중? 168 54
정상
4번째 사람 신장과 체중? 170 45
저체중
5번째 사람 신장과 체중? 167 60
정상
6번째 사람 신장과 체중? 176 98
고도비만
7번째 사람 신장과 체중? 152 60
경도비만
8번째 사람 신장과 체중? 172 80
경도비만
9번째 사람 신장과 체중? 167 70
경도비만
10번째 사람 신장과 체중? 168 75
경도비만
```
*/
#include <stdio.h>

int AskBiman(int height, int weight);
void PrintResult(int biman);

int main(void) {
  int height[10], weight[10];
  float bmi[10];
  int grade;
  char bmistring[5][20] = {"저체중", "정상", "과체중", "경도비만", "고도비만"};

  for (int i = 0; i < 10; i++) {
    printf("%d번째 사람 신장과 체중? ", i + 1);
    scanf("%d %d", &height[i], &weight[i]);

    grade = AskBiman(height[i], weight[i]);
    printf("%s\n", bmistring[grade]);
  }
  return 0;
}

int AskBiman(int height, int weight) {
  int grade;
  float bmi;
  bmi = weight / (height * 0.01 * height * 0.01);
  if (bmi < 18.5)
    grade = 0;
  else if (bmi < 23)
    grade = 1;
  else if (bmi < 25)
    grade = 2;
  else if (bmi < 30)
    grade = 3;
  else
    grade = 4;

  return grade;
}