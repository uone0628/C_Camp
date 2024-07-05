/*
# A7. 비만인 사람 숫자 알아내기 (파일 버전)

데이터 파일로부터 5명의 신장(cm단위)과 체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라. 

단, 비만여부는 다음 비만도 수치가 25이상인 경우에 "비만"으로 판단한다.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 

비만도계산기능을 수행하는 함수를 작성하여 사용할 것.

```
float evalbmi(int h, int w);
// h : 신장(cm 단위)
// w : 체중(kg 단위)
// 리턴값 : 비만도
// 수행내용 : 파라미터로 받은 신장, 체중을 가지고 비만도를 계산하여 반환하라
```

실행 예:

```
5명의 데이터를 읽었습니다.
비만인 사람은 2명입니다.
```
*/
#include <stdio.h>

float evalbmi(int h, int w);

int main(void) {
	int height, weight;
	float bmi;
	int count=0;
	//이 곳에 코드를 작성하세요.
	FILE* file;
	file = fopen("data.txt", "r");
	for(int i=0; i<5; i++) {
		fscanf(file, "%d %d", &height, &weight);
		bmi = evalbmi(height, weight);
		if(bmi >= 25) {
			count++;
		}
	}
	printf("5명의 데이터를 읽었습니다.\n");
	printf("비만인 사람은 %d명입니다.\n", count);
	return 0;
}

float evalbmi(int h, int w) {
	float bmi;
	bmi = w / ((h/100.0) * (h/100.0));
	return bmi;
}
