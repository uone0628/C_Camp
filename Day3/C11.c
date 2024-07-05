/*
# C11. 별 찍기 함수 만들기 3


파라미터로 문자 하나와 숫자 두 개를 넘겨주면 한 줄에 첫 번째 숫자만큼 빈칸을 출력한 후, 바로 이어서 두 번째 숫자만큼 넘겨받은 문자를 화면에 출력하는 함수를 만들어라. 

그리고 사용자로부터 모양(문자 하나) 과 높이, 여백을 입력받은 후, 이 함수를 사용해서 입력한 크기만큼의 여백과 높이를 갖는 우직각 삼각형을 입력한 문자모양으로 화면에 출력시켜라. 

함수 원형은 다음과 같다.


```
void PrintCharWithBlank(int blanks, int size, char ch);
파라미터) blanks : 빈칸의 개수, size : 출력할 문자의 개수, ch : 출력할 문자 
리턴 값) 없음
수행내용) blanks 숫자만큼 빈칸 출력, size 개수만큼 ch 문자 출력 후 개행 
```

실행 예)

```
사용할 문자? ^
높이와 여백의 크기? 5 2
      ^
     ^^
    ^^^
   ^^^^
  ^^^^^
```

```
사용할 문자? %
높이와 여백의 크기? -1 -1
잘못 입력하셨습니다.
```
*/
#include <stdio.h>

void PrintCharWithBlank(int blanks, int size, char ch);

int main(void) {
  char ch;
  int height, blank;
  
  printf("사용할 문자? ");
  scanf("%c", &ch);
  printf("높이와 여백의 크기? ");
  scanf("%d %d", &height, &blank);

  if(height < 1 || blank < 0) {
    printf("잘못 입력하셨습니다.\n");
  } else {
    PrintCharWithBlank(blank, height, ch);
  }
  
  return 0;
}

void PrintCharWithBlank(int blanks, int size, char ch) {
  int i, j;

  for(i = 0; i < size; i++) {
    for(j = 0; j < blanks; j++) {
      printf(" ");
    }
    for(j = 0; j < size - i - 1; j++) {
      printf(" ");
    }
    for(j = 0; j < i + 1; j++) {
      printf("%c", ch);
    }
    printf("\n");
  }
}