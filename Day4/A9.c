/*
# A9. 비만인 사람 숫자 알아내기2 (포인터 사용 함수 버전)

5명의 신장(cm단위)과 체중(kg단위)를 입력받아 이 중에서 비만인 사람의 숫자를 파악하여 출력하라.

**코드에서 main() 함수 내용은 수정금지!**

단, 신장과 체중의 입력은 AskHW() 함수를 통해 진행하라.

```
void AskHW(float* h, float *w);

// 파라미터 : 키(h)과 몸무게(w) 값을 저장할 변수의 포인터
// 리턴값 : 없음
// 수행내용 : 키(cm)과 몸무게(kg)을 화면에서 입력받아 h포인터에 미터(float)로 환산한 키, w포인터에 몸무게(float)값 을 저장 
```

실행 예:

```
1번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 176 80
2번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 182 99
3번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 168 54
4번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 170 45
5번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 167 60
비만인 사람은 2명입니다.
```
*/
#include <stdio.h>

void AskHW(float* h, float *w);

int main(void) {
	float height, weight, bmi;
	int count=0;
	for(int i=0;i<5;i++){
    printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. " ,i+1);
		AskHW(&height, &weight);
		bmi = weight / (height*height);
		if (bmi > 25) count++;
	}
	printf("비만인 사람은 %d명입니다.\n", count);
	return 0;
}

void AskHW(float* h, float *w){
	scanf("%f %f", h, w);
	*h = *h / 100;
}
