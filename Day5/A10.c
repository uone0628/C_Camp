/*
# A10. 비만인 사람 숫자 알아내기 (구조체 버전)

다음 구조체를 사용하여 데이터 파일(data.txt)로부터 5명의 신장(cm단위)과
체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라.

단, 비만여부는 다음 비만도 수치가 25이상인 경우에 "비만"으로 판단한다.비만도
수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 비만도계산기능을 수행하는
함수를 작성하여 사용할 것.

```
struct bmi_struct{
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_index; // 0 비만아님,1 비만
};
```

```
float evalbmi(int h, int w);
// h : 신장(cm 단위)
// w : 체중(kg 단위)
// 리턴값 : 비만도
// 수행내용 : 파라미터로 받은 신장, 체중을 가지고 비만도를 계산하여 리턴
```

data.txt 내용
```
176 80
182 99
168 54
170 45
167 60
```

실행 예:
```
5명의 정보를 읽었습니다.
비만인 사람은 2명입니다.
```
*/
#include <stdio.h>

struct bmi_struct {
  int height, weight; // 키(cm), 몸무게(kg)
  float bmi;          // 비만도
  int bmi_index;      // 0 비만아님,1 비만
};

float evalbmi(int h, int w);

int main(void) {
  struct bmi_struct person[5]; // 5명의 비만도 구조체 배열

  FILE *f;
  f = fopen("data.txt", "r");
  int count = 0; // 비만인 사람

  for (int i = 0; i < 5; i++) {
    fscanf(f, "%d %d", &person[i].height, &person[i].weight);
    person[i].bmi = evalbmi(person[i].height, person[i].weight);
    if (person[i].bmi >= 25)
      person[i].bmi_index = 1;
    else
      person[i].bmi_index = 0;
  }

  printf("5명의 정보를 읽었습니다.\n");

  for (int i = 0; i < 5; i++) {
    if (person[i].bmi_index == 1)
      count++;
  }

  fclose(f);

  printf("비만인 사람은 %d명입니다.\n", count);

  return 0;
}

float evalbmi(int h, int w) {
  float bmi;
  bmi = w / ((h / 100.0) * (h / 100.0));
  return bmi;
}