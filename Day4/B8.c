/*
# B8. 국영수 점수 분석하기 (파일 버전) 

데이타 파일로부터 학생 5명의 국어, 영어, 수학 점수를 입력받아 다음 항목들을 계산하여 출력하라. 

1) 각 과목별 총점과 평균 점수
2) 각 학생별 총점과 평균점수, 평균에 따른 등급


등급은 다음과 같은 기준으로 결정하라.  

평균 90이상 : A

평균 80이상 ~ 90미만 : B 

평균 70이상 ~ 80미만 : C 

평균 60이상 ~ 70미만 : D 

평균 60미만 : F

```
void evalClass(int s[5][3], int i, int* s, float* a);
// 파라미터 : 점수배열(j)과 과목번호(i=0,1,2), 총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a)
// 리턴값 : 없음
// 수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균을 계산해 저장함

void evalStudent(int s[5][3], int i, int* s, float* a, char* g);
// 파라미터 : 점수배열(j)과 학생번호(i=0,1,2,3,4),총점을 저장할 포인터변수(s), 평균을 저장할 포인터변수(a), 등급을 저장할 포인터변수(g='A','B','C','D','F') 
// 리턴값 : 없음
// 수행내용 : 점수배열과 과목번호를 받아서, 총점과 평균, 등급을 계산해 저장함
```


실행 예)

```
1번 학생 : 국어 85, 영어 95, 수학 75
2번 학생 : 국어 90, 영어 80, 수학 70
3번 학생 : 국어 65, 영어 85, 수학 75
4번 학생 : 국어 60, 영어 70, 수학 80
5번 학생 : 국어 60, 영어 50, 수학 60
1) 각 과목별 총점과 평균점수
국어 점수의 총점은 360 평균은 72.0
영어 점수의 총점은 380 평균은 76.0
수학 점수의 총점은 360 평균은 72.0
2) 각 학생별 총점과 평균점수, 평균에 따른 등급
1번 학생의 총점은 255 평균은 85.0(등급 B)
2번 학생의 총점은 240 평균은 80.0(등급 B)
3번 학생의 총점은 225 평균은 75.0(등급 C)
4번 학생의 총점은 210 평균은 70.0(등급 C)
5번 학생의 총점은 170 평균은 56.7(등급 F)
```
*/
#include <stdio.h>

void evalClass(int j[5][3], int i, int* s, float* a);
void evalStudent(int j[5][3], int i, int* s, float* a, char* g);

int main(void) {
	int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
	char classname[3][20]={"국어","영어","수학"};
	int sum; //총점저장용
	float avg;  // 평균저장용 
	char grade; // 등급저장용 
	int i, j;  // 반복문을 위한 변수
	FILE *data;
	
	//이곳에 코드를 작성하세요!
	data = fopen("data.txt", "r");
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 3; j++) {
			fscanf(data, "%d", &jumsu[i][j]);
		}
	}
	
	for(i=0;i<5;i++){
		printf("%d번 학생 : ",i+1);
		for(j=0;j<3;j++){
			printf("%s %d", classname[j], jumsu[i][j]);
			if(j<2) printf(", ");
			else printf("\n");
		}
	}
	
	printf("1) 각 과목별 총점과 평균점수\n");
	for(i=0;i<3;i++){
		evalClass(jumsu, i, &sum, &avg);
		printf("%s 점수의 총점은 %d 평균은 %.1f\n",classname[i],sum,avg);
	}

	printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
	for(i=0;i<5;i++){
		evalStudent(jumsu, i, &sum, &avg, &grade);
		printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n",i+1,sum,avg,grade);
	}
  
  fclose(data);
	return 0;
}

void evalClass(int j[5][3], int i, int *s, float *a) {
	int sum = 0;
	for (int k = 0; k < 5; k++) {
		sum += j[k][i];
	}
	*s = sum;
	*a = (float)sum / 5.0;
}

void evalStudent(int j[5][3], int i, int *s, float *a, char *g) {
	int sum = 0;
	for (int k = 0; k < 3; k++) {
		sum += j[i][k];
	}
	*s = sum;
	*a = (float)sum / 3.0;

	if (*a >= 90)
		*g = 'A';
	else if (*a >= 80)
		*g = 'B';
	else if (*a >= 70)
		*g = 'C';
	else if (*a >= 60)
		*g = 'D';
	else
		*g = 'F';
}