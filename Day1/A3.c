/*
A3. 5명 중 비만은 몇 명인가?
5명의 신장(cm단위)과 체중(kg단위)를 입력받은 후, 비만이 몇 명인지 출력하라.

비만도(BMI) 25 이상일 때, 비만으로 판정한다.

비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다.

이 때, 신장은 미터 단위로 환산해야 함을 유의하라.

변수는 다음과 같이 사용하라.

int height, weight; // 신장(cm), 체중(kg) 
float bmi; // 비만도 수치
int people; // 비만인 사람의 수

실행 예)
1번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 176 80
2번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 182 99
3번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 168 54
4번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 170 45
5번째 사람의 신장(cm)과 체중(kg)을 입력하시오. 167 60
비만인 사람은 총 2명입니다.
*/
#include <stdio.h>

int main(void) {
	int height, weight; // 신장(cm), 체중(kg)
	float bmi; // 비만도 수치
	int people = 0; // 비만인 사람의 수
	int i;

	for(i=1; i<=5; i++) {
		printf("%d번째 사람의 신장(cm)과 체중(kg)을 입력하시오. ", i);
		scanf("%d %d", &height, &weight);
		bmi = weight / (height * height * 0.0001);
		if(bmi >= 25) {
			people++;
		}
	}

	printf("비만인 사람은 총 %d명입니다.", people);
	
	return 0;
}