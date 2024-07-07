/*
# B13. 국영수 점수 파일 분석하기 (구조체 포인터 배열 버전)

**제공된 소스 main() 수정 금지**

데이터 파일로부터 학생들의 국어, 영어, 수학 점수를 입력받아 다음 항목들을 계산하여 출력하라. 

1) 각 과목별 총점과 평균 점수 

2) 각 학생별 총점과 평균점수, 평균에 따른 등급 
```
struct st_jumsu{
 int kor, eng, mat;
 int sum;
 float avg;
 char grade;
};
```

파일로부터 점수를 읽어와서 목록을 만들어내는 과정은 다음 함수를 통해 동적으로 메모리를 할당받아 진행하라.
```
int load_jumsu(struct jumsu_struct* p[], char* filename);
// 파라미터 : 점수목록을 저장할 구조체 포인터 배열, 데이터파일 이름
// 리턴값 : 만들어낸 점수 배열
// 수행내용 : 파일을 읽으면서 점수 구조체를 동적 메모리 할당을 통해 만들고 국어, 영어, 수학 점수를 입력받아 저장한 후, 만들어낸 점수목록의 개수를 리턴함
```

학생별 총점과 평균, 등급 계산은 다음 함수를 제작하여 사용하라.
```
void eval_score(struct jumsu_struct* p);
// 파라미터 : 학생의 점수 구조체 포인터
// 리턴값 : 없음
// 수행내용 : 구조체 포인터를 받아 학생별 총점과 평균, 등급 계산하여 저장
```

과목별 총점과 평균 계산은 다음 함수를 제작하여 사용하라.
```
void eval_class(struct jumsu_struct* p[], int sum[], float avg[]);
// 파라미터 : 점수목록(구조체 포인터 배열), 과목별 총점 배열, 과목별 평균 배열
// 리턴값 : 없음
// 수행내용 : 점수목록을 받아 3개의 과목별 총점과 평균을 계산하여 저장한다.
```

등급은 다음과 같은 기준으로 결정하라. 

평균 90이상 : A 
평균 80이상 ~ 90미만 : B 
평균 70이상 ~ 80미만 : C 
평균 60이상 ~ 70미만 : D 
평균 60미만 : F 

실행 예)
```
5명의 점수를 읽었습니다.
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

struct jumsu_struct{
    int kor, eng, mat;
    int sum;
    float avg;
    char grade;
};

int load_jumsu(struct jumsu_struct* p[], char* filename);
void eval_score(struct jumsu_struct* p);
void eval_class(struct jumsu_struct* p[], int sum[], float avg[]);

int main()
{
    struct jumsu_struct* jumsu[10]; 	// 최대 10명의 점수 저장용 포인터 배열 
    int count; // 점수 개수
    int classsum[3]; 			// 과목별 총점
    float classavg[3]; 			// 과목별 평균
    char classname[3][20]={"국어","영어","수학"};
    count = load_jumsu(jumsu, "data.txt");
    for(int i=0;i<count;i++)
        eval_score(jumsu[i]);
    eval_class(jumsu, classsum, classavg);
    printf("1) 각 과목별 총점과 평균점수\n");
    for(int i=0;i<3;i++)
        printf("%s 점수의 총점은 %d 평균은 %.1f\n", classname[i],classsum[i], classavg[i]);
    printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급\n");
    for(int i=0;i<5;i++)
        printf("%d번 학생의 총점은 %d 평균은 %.1f(등급 %c)\n", i+1,jumsu[i]->sum, jumsu[i]->avg,      jumsu[i]->grade);
    return 0;
}

int load_jumsu(struct jumsu_struct* p[], char* filename) {
    int count = 0;
    FILE* f;
    f = fopen(filename, "r");

    while(!feof(f)) {
        p[count] = (struct jumsu_struct*)malloc(sizeof(struct jumsu_struct));
        fscanf(f, "%d %d %d", &p[count]->kor, &p[count]->eng, &p[count]->mat);
        count++;
    }

    printf("%d명의 점수를 읽었습니다.\n", count);

    fclose(f);
    return count;
}

void eval_score(struct jumsu_struct* p) {
    p->sum = p->kor + p->eng + p->mat;
    p->avg = p->sum / 3.0;
    if(p->avg >= 90) p->grade = 'A';
    else if(p->avg >= 80) p->grade = 'B';
    else if(p->avg >= 70) p->grade = 'C';
    else if(p->avg >= 60) p->grade = 'D';
    else p->grade = 'F';
}

void eval_class(struct jumsu_struct* p[], int sum[], float avg[]) {
    for(int i = 0; i < 3; i++) {
        sum[i] = 0;
        avg[i] = 0;
    }
    for(int i = 0; i < 5; i++) {
        sum[0] += p[i]->kor;
        sum[1] += p[i]->eng;
        sum[2] += p[i]->mat;
    }
    for(int i = 0; i < 3; i++) {
        avg[i] = sum[i] / 5.0;
    }
}