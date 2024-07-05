/*
# B6. 5명의 점수 만들어 분석하기 (함수 버전)

학생 5명의 국어, 영어, 수학 점수를 50~100 사이의 점수를 임의로 만들어 저장한 후에, 다음 항목들을 계산하여 출력하라. 

1) 각 과목별 총점과 평균 점수

2) 각 학생별 총점과 평균점수, 평균에 따른 등급


등급은 다음과 같은 기준으로 결정하라.  

평균 90이상 : A

평균 80이상 ~ 90미만 : B 

평균 70이상 ~ 80미만 : C 

평균 60이상 ~ 70미만 : D 

평균 60미만 : F

다음과 같은 함수를 만들어 사용하라.
```
int classsum(int s[5][3], int classnum);
파라미터 : 점수배열(s)과 과목번호(0,1,2) 
리턴값 : 해당 과목의 총점
```

```
int studentsum(int s[5][3], int studentnum);
파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
리턴값 : 해당 학생의 총점
```

```
char studentgrade(int s[5][3], int studentnum);
파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
리턴값 : 해당 학생의 등급 ('A','B','C','D','F')
```

변수는 다음과 같이 사용하라. 

```
int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
char classname[3][20]={"국어","영어","수학"};
int sum_student[5]; // 학생별 총점
float average_student[5];  // 학생별 평균
char grade[5]; // 학생별 등급 
int sum_class[3]; // 과목별 총점
float average_class[3]; // 과목별 평균
int i, j;  // 반복문을 위한 변수 
```

**이 문제는 테스트 케이스가 없습니다! 밑의 출력 예시를 참고해서 출력하세요!**

실행 예)

```
5명의 학생 점수가 생성되었습니다.
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
#include <stdlib.h>
#include <time.h>

int classsum(int s[5][3], int classnum);
// 파라미터 : 점수배열(s)과 과목번호(0,1,2) 
// 리턴값 : 해당 과목의 총점
int studentsum(int s[5][3], int studentnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 총점
char studentgrade(int s[5][3], int studentnum);
// 파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
// 리턴값 : 해당 학생의 등급 ('A','B','C','D','F')

int main(void) {
  int jumsu[5][3]; // 5명의 3과목 점수를 저장하고 있는 2차원 배열 
  char classname[3][20]={"국어","영어","수학"};
  int sum_student[5]; // 학생별 총점
  float average_student[5];  // 학생별 평균
  char grade[5]; // 학생별 등급 
  int sum_class[3]; // 과목별 총점
  float average_class[3]; // 과목별 평균
  int i, j;  // 반복문을 위한 변수 

  srand(time(0));

  printf("5명의 학생 점수가 생성되었습니다.\n");
  
  for(i = 0; i < 5; i++) {
    printf("%d번 학생 : ", i+1);
    jumsu[i][0] = rand()%51+50;
    jumsu[i][1] = rand()%51+50;
    jumsu[i][2] = rand()%51+50;
    printf("국어 %d, 영어 %d, 수학 %d\n",jumsu[i][0], jumsu[i][1], jumsu[i][2]);
  }

  printf("1) 각 과목별 총점과 평균점수\n");
  for(i = 0; i < 3; i++) {
    sum_class[i] = classsum(jumsu, i);
    average_class[i] = sum_class[i] / 5.0;
    printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i], sum_class[i], average_class[i]);
  }

  printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
  for(i = 0; i < 5; i++) {
    sum_student[i] = studentsum(jumsu, i);
    average_student[i] = sum_student[i] / 3.0;
    grade[i] = studentgrade(jumsu, i);
    printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1, sum_student[i], average_student[i], grade[i]);
  }

  return 0;
}

int classsum(int s[5][3], int classnum){
  int sum = 0;
  for(int i = 0; i < 5; i++) {
    sum += s[i][classnum];
  }
  return sum;
}

int studentsum(int s[5][3], int classnum){
  int sum = 0;
  for(int i = 0; i < 3; i++) {
    sum += s[classnum][i];
  }
  return sum;
}

char studentgrade(int s[5][3], int classnum){
  float average = studentsum(s, classnum) / 3.0;
  if(average >= 90) return 'A';
  else if(average >= 80) return 'B';
  else if(average >= 70) return 'C';
  else if(average >= 60) return 'D';
  else return 'F';
}