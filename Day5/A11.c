/*
# A11. 비만 판정하기 (동적 메모리 할당 버전)

비만 판정 함수버전에서 키와 몸무게 데이터를 입력받아 비만도 데이터를 완성하여 출력하라.

제작할 함수는 다음과 같다. 이 중에서 add_bmi()는 이미 제공됨.

사용하는 구조체는 다음과 같다.

```
struct bmi_struct{
    int height, weight; // 키(cm), 몸무게(kg)
    float bmi; // 비만도
    int bmi_index; // 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};
```

```
struct bmi_struct* add_bmi();
// 파라미터 : 없음
// 리턴값 : 메모리 할당받아 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 포인터
```

```
void eval_bmi(struct bmi_struct* p);
// 파라미터 : 비만도 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장
```

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 

이 때, 신장은 **미터 단위로 환산**해야 함을 유의 하라. 

비만도 수치에 따른 비만도 판정 

1. 18.5 미만 : 저체중 

2. 18.5 ~ 23 미만 : 정상체중 

3. 23~25미만 : 과체중 

4. 25이상 : 비만 

단, main에서는 다음과 같이 구조체 포인터만을 사용하고, add_bmi()를 통해 메모리가 할당되도록 해야 한다.

**main() 코드는 이미 제공되니 수정하지 말 것!**

실행 예)

```
키와 몸무게를 입력하시오 >  177 77
키: 177 몸무게: 77 비만도: 24.6 판정결과 : 과체중
```

```
키와 몸무게를 입력하시오 >  165 45
키: 165 몸무게: 45 비만도: 16.5 판정결과 : 저체중
```

```
키와 몸무게를 입력하시오 >  179 73
키: 179 몸무게: 73 비만도: 22.8 판정결과 : 정상
```

```
키와 몸무게를 입력하시오 >  190 126
키: 190 몸무게: 126 비만도: 34.9 판정결과 : 비만
```


*/
#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
  int height, weight; // 키(cm), 몸무게(kg)
  float bmi; // 비만도
  int bmi_index; // 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

struct bmi_struct* add_bmi();
// 파라미터 : 없음
// 리턴값 : 메모리 할당받아 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 포인터

void eval_bmi(struct bmi_struct* p);
// 파라미터 : 비만도 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장

int main(void) {
	struct bmi_struct* one;
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};

	one = add_bmi();

	printf("키: %d ", one->height);
	printf("몸무게: %d ", one->weight);
	printf("비만도: %.1f ", one->bmi);    
    printf("판정결과 : %s\n", bmi_string[one->bmi_index-1]);
	return 0;
}

struct bmi_struct* add_bmi(){
  struct bmi_struct* p = (struct bmi_struct*)malloc(sizeof(struct bmi_struct));
  printf("키와 몸무게를 입력하시오 > ");
  scanf("%d %d", &(p->height), &(p->weight));
  eval_bmi(p);
  return p;
}

void eval_bmi(struct bmi_struct* p){
  p->bmi = p->weight / ((p->height * 0.01) * (p->height * 0.01));
  if(p->bmi < 18.5) p->bmi_index = 1;
  else if(p->bmi < 23) p->bmi_index = 2;
  else if(p->bmi < 25) p->bmi_index = 3;
  else p->bmi_index = 4;
}
