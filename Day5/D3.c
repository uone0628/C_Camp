/*
# D3. 점수데이터 파일 분석하기 (구조체 버전)
# *구조체 사용*
다음과 같은 구조체를 사용해서 문제를 풀어나가면 된다. 
```

struct score_struct{
  char name[10]; // 이름 
  int jumsu[3];  // 점수 (C, Java, Python)
  int sum;  // 총점
  float avg;  //  평균 
};
```

```
data.txt

Kim 95 76 90
Park 76 90 79
Lee 87 80 92

Choi 85 96 87 
Oh 70 75 89
Wang 73 80 90

Yoon 85 93 75
Jeong 82 79 77

```

데이터파일(data.txt)로부터 이름, C, Java, Python 성적점수를 읽어들여 각 사람의 점수와 총점, 평균 및 각 교과목별 평균과 가장 높은 점수를 받은 사람의 이름, 점수를 출력하라.
* 주의사항- 파일에서 읽어올 때에 미리 횟수를 정하지 말 것. (최대 20개로 가정)- 파일을 읽는 fscanf()가 제대로 데이터를 읽었는지 확인해서 빈줄은 무시할 수 있도록 처리할 것. - 필요한 함수가 있으면 직접 만들어 사용할 것! 

실행결과 예시
```
8 records read.
Kim     95  76  90  261  87.0
Park    76  90  79  245  81.7
Lee     87  80  92  259  86.3
Choi    85  96  87  268  89.3
Oh      70  75  89  234  78.0
Wang    73  80  90  243  81.0
Yoon    85  93  75  253  84.3
Jeong   82  79  77  238  79.3
C - average : 81.6, Top : Kim (95)
Java - average : 83.6, Top : Choi (96)
Python - average : 84.9, Top : Lee(92)
```
*/
#include <stdio.h>

struct score_struct{
  char name[10]; // 이름 
  int jumsu[3];  // 점수 (C, Java, Python)
  int sum;  // 총점
  float avg;  //  평균 
};

int main(void) {
  struct score_struct p[20];
  FILE* f;
  int count = 0;
  
  f = fopen("data.txt", "r");
  
  while(!feof(f)) {
    if(fscanf(f, "%s %d %d %d", p[count].name, &p[count].jumsu[0], &p[count].jumsu[1], &p[count].jumsu[2]) == 4) {
      p[count].sum = p[count].jumsu[0] + p[count].jumsu[1] + p[count].jumsu[2];
      p[count].avg = p[count].sum / 3.0;
      count++;
    }
  }

  fclose(f);

  printf("%d records read.\n", count);

  for(int i = 0; i < count; i++) {
    printf("%-6s  %d  %d  %d  %d  %.1f\n", p[i].name, p[i].jumsu[0], p[i].jumsu[1], p[i].jumsu[2], p[i].sum, p[i].avg);
  }

  float c_avg = 0, java_avg = 0, python_avg = 0;
  int c_top = 0, java_top = 0, python_top = 0;

  for(int i = 0; i < count; i++) {
    c_avg += p[i].jumsu[0];
    if(p[i].jumsu[0] > p[c_top].jumsu[0]) {
      c_top = i;
    }
    java_avg += p[i].jumsu[1];
    if(p[i].jumsu[1] > p[java_top].jumsu[1]) {
      java_top = i;
    }
    python_avg += p[i].jumsu[2];
    if(p[i].jumsu[2] > p[python_top].jumsu[2]) {
      python_top = i;
    }
  }

  printf("C - average : %.1f, Top : %s (%d)\n", c_avg / (float)count, p[c_top].name, p[c_top].jumsu[0]);
  printf("Java - average : %.1f, Top : %s (%d)\n", java_avg / (float)count, p[java_top].name, p[java_top].jumsu[1]);
  printf("Python - average : %.1f, Top : %s (%d)\n", python_avg / (float)count, p[python_top].name, p[python_top].jumsu[2]);
  
  

  return 0;
}