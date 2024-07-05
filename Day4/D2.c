/*
# D2. 점수데이터 파일 분석하기

데이터파일(data.txt)로부터 이름, C, Java, Python 성적점수를 읽어들여 각 사람의 점수와 총점, 평균 및 각 교과목별 평균과 가장 높은 점수를 받은 사람의 이름, 점수를 출력하라.

* 주의사항

- 파일에서 읽어올 때에 미리 횟수를 정하지 말 것. (최대 20개로 가정)

- 파일을 읽는 fscanf()가 제대로 데이터를 읽었는지 확인해서 빈줄은 무시할 수 있도록 처리할 것.
- 필요한 함수가 있으면 직접 만들어 사용할 것!


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

int main(void) {
	char pname[3][10]={"C", "Java", "Python"};
	char name[20][30]; // 이름 (최대 20명)
	int score[3][20]; // 3과목 점수 (최대 20명)
	int sum[20]; // 총점 (최대 20명)
	float avg[20]; // 평균 (최대 20명)
	
	int count=0;

	FILE *f;
	f = fopen("data.txt", "r");

	while(!feof(f)) {
		if(fscanf(f, "%s %d %d %d", name[count], &score[0][count], &score[1][count], &score[2][count]) == 4) {
			sum[count] = score[0][count] + score[1][count] + score[2][count];
			avg[count] = sum[count] / 3.0;
			count++;
		}
	}

	printf("%d records read.\n", count);
	for(int i = 0; i < count; i++) {
		printf("%-6s  %d  %d  %d  %d  %.1f\n", name[i], score[0][i], score[1][i], score[2][i], sum[i], avg[i]);
	}

	for(int i = 0; i < 3; i++) {
		int max = score[i][0];
		int max_index = 0;
		int csum = 0;
		float cavg = 0;
		
		for(int j = 0; j < count; j++) {
			if(score[i][j] > max) {
				max = score[i][j];
				max_index = j;
			}
			csum += score[i][j];
		}
		cavg = csum / (float)count;
		printf("%s - average : %.1f, Top : %s (%d)\n", pname[i], cavg, name[max_index], score[i][max_index]);
	}
	
  return 0;
}