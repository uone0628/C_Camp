/*
# C10. 별 찍기 함수 만들기 2 

파라미터로 문자 하나와 숫자 하나를 넘겨주면 이 숫자만큼 넘겨받은 문자를 화면에 출력하는 함수를 만들어라. 

그리고 사용자로부터 문자 하나와 10개의 숫자를 입력받은 후, 이 함수를 사용해서 10줄에 걸쳐서 그 숫자만큼의 문자를 화면에 출력 시켜라. 

함수 원형은 다음과 같다.

```
void PrintChar(int size, char ch);
파라미터) size : 출력할 문자의 갯수, ch : 출력할 문자 리턴 값 
리턴값)없음
수행내용) size 개수만큼 ch 문자 출력 후 개행 
```

실행 예)

```
사용할 문자? $
숫자 10개? 1 2 3 4 5 6 7 8 9 10
$
$$
$$$
$$$$
$$$$$
$$$$$$
$$$$$$$
$$$$$$$$
$$$$$$$$$
$$$$$$$$$$
```
*/
#include <stdio.h>

void PrintChar(int size, char ch);

int main(void) {
  char ch;
  int num[10];
  int i;

  printf("사용할 문자? ");
  scanf("%c", &ch);

  printf("숫자 10개? ");
  for(i = 0; i < 10; i++) {
    scanf("%d", &num[i]);
  }

  for(i = 0; i < 10; i++) {
      PrintChar(num[i], ch);
  }

  return 0;
}

void PrintChar(int size, char ch) {
  int i;

  for(i = 0; i < size; i++) {
    printf("%c", ch);
  }
  printf("\n");
}