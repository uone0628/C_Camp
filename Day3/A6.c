/*
# A6. 10명 중 누가 비만인가? (함수 버전)

10명의 신장(cm단위)과 체중(kg단위)를 입력받은 후, 이들 중 몇 번째 사람들이 비만인지를 AskBiman() 함수를 통해 판정하여 출력하라. 

그리고 도합 몇 명이 비만인지 출력하라.

단, 비만여부는 다음 비만도 수치가 25이상인 경우에 "비만"으로 판단한다.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 

이 때, 신장은 미터 단위로 환산해야 함을 유의하라. 

```
int AskBiman(int height, int weight);
파라미터) height : 신장(cm), weight : 체중(kg) 리턴 값) 없음
수행내용) 비만도 계산 후 판정결과 리턴
리턴값) 비만아님 0, 비만임1
```


변수는 다음과 같이 사용하라. 
```
int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
int bmilevel[10]; // 10명의 비만도 등급(0~4)
int count; // 비만인 사람의 숫자
int i;  // 반복문을 위한 변수  
```
실행 예)

```
1번째 사람의 신장과 체중? 165 56
2번째 사람의 신장과 체중? 176 90
3번째 사람의 신장과 체중? 187 60
4번째 사람의 신장과 체중? 155 47
5번째 사람의 신장과 체중? 170 75
6번째 사람의 신장과 체중? 173 80
7번째 사람의 신장과 체중? 165 50
8번째 사람의 신장과 체중? 182 73
9번째 사람의 신장과 체중? 158 48
10번째 사람의 신장과 체중? 170 66
2번째 사람은 비만
5번째 사람은 비만
6번째 사람은 비만

총 3명의 사람이 비만
```
*/
#include <stdio.h>

int AskBiman(int height, int weight);

int main(void) {
	int height[10], weight[10]; // 10명의 신장(cm), 체중(kg)
	int bmilevel[10]; // 10명의 비만도 등급(0~4)
	int count = 0; // 비만인 사람의 숫자
	int i;  // 반복문을 위한 변수  

	for(i = 0; i < 10; i++) {
		printf("%d번째 사람의 신장과 체중? ", i + 1);
		scanf("%d %d", &height[i], &weight[i]);

		bmilevel[i] = AskBiman(height[i], weight[i]);
	}

	for(i = 0; i < 10; i++) {
		if(bmilevel[i] == 1) {
			printf("%d번째 사람은 비만\n", i + 1);
			count++;
		}
	}

	printf("\n총 %d명의 사람이 비만", count);
	
	return 0;
}

int AskBiman(int height, int weight) {
	float bmi;
	int level;

	bmi = weight / (height * height * 0.01 * 0.01);

	if(bmi >= 25) {
		level = 1;
	} else {
		level = 0;
	}

	return level;
}