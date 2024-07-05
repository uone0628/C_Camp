/*
# D1. 5명의 점수 채점하고 등급매기기

다음과 같이 5명의 학생들에게 10문제의 답을 입력받아, 이를 채점하여 등급을 매기는 작업을 하는 프로그램을 작성하라.

학생별로 10개씩의 답안을 입력받은 후에, 각 등급별 학생 이름과 인원수를 출력하라.

단, 10문제의 정답은 미리 코드에 제시된 그대로 사용하라.

등급은 다음과 같이 결정한다.

1st  : 9~10문제 맞춘 경우

2nd  : 7~8문제 맞춘 경우

Fail : 6문제 이하로 맞춘 경우

변수는 제시된 것을 사용하되, 부득이한 경우 용도를 명시하고 추가해도 좋다.

반드시 코드창에 정리된 생각을 입력한 후에 코딩할 것.

변수는 다음과 같이 사용하라.
```
int i,j; // 반복문을 위한 변수
int jumsu[3]={0};  // 점수 계산용 변수
int count;  // 인원수 계산용 변수
char names[5][20]={"James", "David", "Simon", "Peter", "Jason"}; // 학생 이름
int sheet[5][10];  // 학생별 답안내용
int answer[10]={1,2,3,4,1,2,3,4,3,2}; // 정답순서
int grade[5] ={0};  // 학생별 등급
```

```
Enter James's sheet >>  1 2 3 4 1 2 3 4 3 2
Enter David's sheet >>  2 3 1 4 1 2 3 4 3 2
Enter Simon's sheet >>  1 2 3 4 1 1 2 1 1 1
Enter Peter's sheet >>  1 2 3 4 1 2 3 4 4 2
Enter Jason's sheet >>  1 2 2 3 1 3 3 2 3 3

Grade result
1st : James Peter (2)
2nd : David (1)
Fail : Simon Jason (2)
```
*/
#include<stdio.h>

int main(void){
  int i,j; // 반복문을 위한 변수
  int jumsu[5]={0};  // 점수 계산용 변수
  int count;  // 인원수 계산용 변수
  char names[5][20]={"James", "David", "Simon", "Peter", "Jason"}; // 학생 이름
  int sheet[5][10];  // 학생별 답안내용
  int answer[10]={1,2,3,4,1,2,3,4,3,2}; // 정답순서
  int grade[5] ={0};  // 학생별 등급

  for(i=0; i<5; i++) {
    printf("Enter %s's sheet >> ", names[i]);
    for(j=0;j<10;j++) {
      scanf("%d", &sheet[i][j]);
    }
  }

  for(i=0; i<5; i++) {
    for(j=0; j<10; j++) {
      if(sheet[i][j] == answer[j]) {
        jumsu[i]++;
      }
    }
  }

  for(i=0; i<5; i++) {
    if(jumsu[i] >= 9) {
      grade[i]=1;
    } else if(jumsu[i] >= 7) {
      grade[i]=2;
    } else {
      grade[i]=3;
    }
  }

  printf("\nGrade result\n");

  printf("1st : ");
  count = 0;
  for(i=0; i<5; i++) {
    if(grade[i] == 1) {
      printf("%s ", names[i]);
      count++;
    }
  }
  printf("(%d)\n", count);

  printf("2nd : ");
  count = 0;
  for(i=0; i<5; i++) {
    if(grade[i] == 2) {
      printf("%s ", names[i]);
      count++;
    }
  } 
  printf("(%d)\n", count);

  printf("Fail : ");
  count = 0;
  for(i=0; i<5; i++) {
    if(grade[i] == 3) {
      printf("%s ", names[i]);
      count++;
    }
  }
  printf("(%d)\n", count);

  return 0; 
}