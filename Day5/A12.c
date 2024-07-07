/*
# A12. 비만도 관리 프로그램 (구조체 포인터 배열 버전)

비만 판정 함수버전에서 키와 몸무게 데이터를 파일로부터 입력받아 비만도 데이터를 완성하여 출력하라.
제작할 함수는 다음과 같다. 

```
int load_bmi(struct bmi_struct* list[], char* filename);
// 파라미터 : 읽을 파일이름 
// 리턴값 : 만들어낸 구조체 데이터 세트의 갯수
// 수행내용 : 파일로부터 키와 몸무게의 데이터를 읽어 list 포인터 배열에 각각 
							메모리를 할당하여 키, 몸무게, 비만도, 비만도등급이 저장된 구조체 
							데이터가 연결되도록 한 후, 완성한 데이터 갯수를 리턴
```
```
void eval_bmi(struct bmi_struct* p);
// 파라미터 : 비만도 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 포인터로 키, 몸무게를 가지고 비만도, 비만도등급을 저장 
```
사용하는 구조체는 다음과 같다.
```
struct bmi_struct{
		int height, weight; // 키(cm), 몸무게(kg)
		float bmi; 		// 비만도
		int bmi_index; 	// 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};
```
비만도 수치 = 체중(kg) / (신장(m)의 제곱) 으로 계산한다. 
이 때, 신장은 미터 단위로 환산해야 함을 유의 하라. 
비만도 수치에 따른 비만도 판정 

1. 18.5 미만 : 저체중 
2. 18.5 ~ 23 미만 : 정상체중 
3. 23~25미만 : 과체중 
4. 25이상 : 비만 

단, main에서는 다음과 같이 구조체 포인터 배열만을 사용하고, load_bmi()를 통해 메모리를 할당받도록 한다.

data.txt 내용
```
165 56
176 90
187 60
155 47
170 75
173 80
165 50
182 73
158 48
170 66
```

실행 예)
```
10명의 데이터를 읽었습니다.
1번 분. 키: 165 몸무게: 56 비만도: 20.6 판정결과 : 정상
2번 분. 키: 176 몸무게: 90 비만도: 29.1 판정결과 : 비만
3번 분. 키: 187 몸무게: 60 비만도: 17.2 판정결과 : 저체중
4번 분. 키: 155 몸무게: 47 비만도: 19.6 판정결과 : 정상
5번 분. 키: 170 몸무게: 75 비만도: 26.0 판정결과 : 비만
6번 분. 키: 173 몸무게: 80 비만도: 26.7 판정결과 : 비만
7번 분. 키: 165 몸무게: 50 비만도: 18.4 판정결과 : 저체중
8번 분. 키: 182 몸무게: 73 비만도: 22.0 판정결과 : 정상
9번 분. 키: 158 몸무게: 48 비만도: 19.2 판정결과 : 정상
10번 분. 키: 170 몸무게: 66 비만도: 22.8 판정결과 : 정상 
```
*/
#include <stdio.h>
#include <stdlib.h>

struct bmi_struct{
    int height, weight; 		// 키(cm), 몸무게(kg)
    float bmi; 				// 비만도
    int bmi_index; 			// 1,2,3,4 --> 각각 저체중, 정상, 과체중, 비만
};

int load_bmi(struct bmi_struct* list[], char* filename);
void eval_bmi(struct bmi_struct* p);

int main(void) {
	struct bmi_struct* bmilist[50];  // 최대 50명의 비만도 데이터
	char bmi_string[4][20]={"저체중","정상","과체중","비만"};
	int count = load_bmi(bmilist, "data.txt");
	// 이곳에 코드 작성!	
	printf("10명의 데이터를 읽었습니다.\n");
	for(int i = 0; i < count; i++) {
		printf("%d번 분. 키: %d 몸무게: %d 비만도: %.1f 판정결과 : %s\n", i+1, bmilist[i]->height, bmilist[i]->weight, bmilist[i]->bmi, bmi_string[bmilist[i]->bmi_index - 1]);
	}
	return 0;
}

int load_bmi(struct bmi_struct* list[], char* filename) {
	FILE* f;
	f = fopen(filename, "r");
	int count = 0;

	while(!feof(f)) {
		list[count] = (struct bmi_struct*)malloc(sizeof(struct bmi_struct));
		fscanf(f, "%d %d", &(list[count]->height), &(list[count]->weight));
		eval_bmi(list[count]);
		count++;
	}
	fclose(f);
	return count;
}

void eval_bmi(struct bmi_struct* p) {
	p->bmi = p->weight / ((p->height * 0.01) * (p->height * 0.01));
	if(p->bmi < 18.5) p->bmi_index = 1;
	else if(p->bmi < 23) p->bmi_index = 2;
	else if(p->bmi < 25) p->bmi_index = 3;
	else p->bmi_index = 4;
}