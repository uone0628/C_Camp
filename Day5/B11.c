/*
# B11. 국영수 점수 계산하기 (동적 메모리 할당 버전)

다음과 같은 구조체를 사용하여, 국어, 영어, 수학 점수를 입력받아 총점과 평균 점수, 등급을 계산하여 출력하라. 

단, 구조체 변수를 선언하지 말고, 구조체 포인터를 선언하여 동적으로 메모리를 할당받도록 하라.

```
struct jumsu_struct{
 int kor, eng, mat;
 int sum;
 float avg;
 char grade;
};
```

점수를 입력받는 과정은 다음 함수를 제작하여 수행하라.
```
struct jumsu_struct* get_score();
// 수행내용 : 점수 구조체를 동적메모리할당받고 학생의 국어, 영어, 수학 점수를 입력받아 구조체 포인터를 리턴함
```

총점과 평균, 등급 계산은 다음 함수를 제작하여 수행하라.
```
void eval_score(struct jumsu_struct* p);
// 파라미터 : 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 구조체 포인터를 받아 학생별 총점과 평균, 등급 계산하여 저장
```

등급은 다음과 같은 기준으로 결정하라. 

평균 90이상 : A 

평균 80이상 ~ 90미만 : B 

평균 70이상 ~ 80미만 : C 

평균 60이상 ~ 70미만 : D 

평균 60미만 : F 

실행 예)

```
국어 점수? > 85
영어 점수? > 95
수학 점수? > 75
학생의 총점은 255 평균은 85.0 (등급 B) 
```
*/
#include <stdio.h>
#include <stdlib.h>

struct jumsu_struct{
 int kor, eng, mat;
 int sum;
 float avg;
 char grade;
};

struct jumsu_struct* get_score();
void eval_score(struct jumsu_struct* p);

//제공된 코드, main() 수정 금지
int main(){
	struct jumsu_struct* score = get_score();
	eval_score(score);
	printf("학생의 총점은 %d 평균은 %.1f (등급 %c)\n",score->sum, score->avg, score->grade);
	return 0;
}

struct jumsu_struct* get_score() {
	struct jumsu_struct* score = (struct jumsu_struct*)malloc(sizeof(struct jumsu_struct));
	printf("국어 점수? > ");
	scanf("%d", &score->kor);
	printf("영어 점수? > ");
	scanf("%d", &score->eng);
	printf("수학 점수? > ");
	scanf("%d", &score->mat);
	return score;
}

void eval_score(struct jumsu_struct* p) {
	p->sum = p->kor + p->eng + p->mat;
	p->avg = p->sum / 3.0;
	if (p->avg >= 90) p->grade = 'A';
	else if (p->avg >= 80) p->grade = 'B';
	else if (p->avg >= 70) p->grade = 'C';
	else if (p->avg >= 60) p->grade = 'D';
	else p->grade = 'F';
}