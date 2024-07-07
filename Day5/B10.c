/*
# B10. 국영수 점수 분석하기(구조체 버전)

다음과 같은 **구조체 배열**을 사용하여, 데이타 파일로부터 학생 5명의 국어, 영어, 수학 점수를 입력받아 다음 항목들을 계산하여 출력하라. 

1) 각 과목별 총점과 평균 점수 

2) 각 학생별 총점과 평균점수, 평균에 따른 등급  등급은 다음과 같은 기준으로 결정하라.  

```
struct jumsu_struct{
  int kor, eng, mat;
  int sum;
  float avg;
};
```
```
void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i);
// 파라미터 : 구조체 배열 
// int i : 0, 1, 2 (과목의 종류)
// 리턴값 : 없음
// 수행내용 : 구조체 배열를 받아 과목별 총점과 평균을 계산
```
```
void evalStudent(struct jumsu_struct *p);
// 파라미터 : 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 학생의 점수 구조체 포인터를 받아 총점과 평균, 등급 계산하여 저장
```

평균 90이상 : A 

평균 80이상 ~ 90미만 : B 

평균 70이상 ~ 80미만 : C 

평균 60이상 ~ 70미만 : D 

평균 60미만 : F  

data.txt 내용

```
85 95 75
90 80 70
65 85 75
60 70 80
60 50 60
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

struct jumsu_struct{
  int kor, eng, mat;
  int sum;
  float avg;
};

void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i);
void evalStudent(struct jumsu_struct *p);

int main(void) {
  struct jumsu_struct p[5];
  FILE *data;
  int i = 0;
  
  data = fopen("data.txt", "r");
  while(!feof(data)){
    fscanf(data, "%d %d %d", &p[i].kor, &p[i].eng, &p[i].mat);
    i++;
  }
  int sum[3];
  float avg[3];
  for(i = 0 ; i < 3 ; i++){
    sumClass(p, sum, avg, i);
  }

  //이곳에 코드 작성
  char grade;
  
  for(i = 0; i < 5; i++) {
    printf("%d번 학생 : 국어 %d, 영어 %d, 수학 %d\n", i+1, p[i].kor, p[i].eng, p[i].mat);
    
  }
  
  printf("1) 각 과목별 총점과 평균점수\n");
  printf("국어 점수의 총점은 %d 평균은 %.1f\n", sum[0], avg[0]);
  printf("영어 점수의 총점은 %d 평균은 %.1f\n", sum[1], avg[1]);
  printf("수학 점수의 총점은 %d 평균은 %.1f\n", sum[2], avg[2]);

  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for(i = 0; i < 5; i++) {
    evalStudent(&p[i]);
    if(p[i].avg >= 90) grade = 'A';
    else if(p[i].avg >= 80) grade = 'B';
    else if(p[i].avg >= 70) grade = 'C';
    else if(p[i].avg >= 60) grade = 'D';
    else grade = 'F';
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, p[i].sum, p[i].avg, grade);
  }
  
  
  return 0;
}

void sumClass(struct jumsu_struct p[], int* sum, float* avg, int i) {
  int j;
  sum[i] = 0;
  if(i == 0) {
    for(j = 0; j < 5; j++) {
      sum[i] += p[j].kor;
    }
  } else if(i == 1) {
    for(j = 0; j < 5; j++) {
      sum[i] += p[j].eng;
    }
  } else {
    for(j = 0; j < 5; j++) {
      sum[i] += p[j].mat;
    }
  }
  avg[i] = sum[i] / 5.0;
}

void evalStudent(struct jumsu_struct *p) {
  p->sum = p->kor + p->eng + p->mat;
  p->avg = p->sum / 3.0;
}