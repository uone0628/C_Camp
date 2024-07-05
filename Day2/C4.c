/*
# C4. 별 찍기 (A 모양)

단, A의 수평한 선은 전체 줄 갯수의 중간 쯤의 줄에서 표시하면 된다.

예를 들어

3줄 - 2번째 줄이 중간 줄
7줄 - 4번째 줄이 중간 줄
10줄 - 6번째 줄이 중간 줄

```
size? > 3
  *
 ***
*   *
```

```
size? > 7
      *
     * *
    *   *
   *******
  *       *
 *         *
*           *
```

```
size? > 10
         *
        * *
       *   *
      *     *
     *       *
    ***********
   *           *
  *             *
 *               *
*                 *
```
*/
#include <stdio.h>

int main(void) {
  int size;
  int i, j;

  printf("size? > ");
  scanf("%d", &size);

  int mid = size / 2 + 1;

	for(i = 0; i < size; i++) {
		for(j = 0; j < size - i - 1; j++) {
			printf(" ");
		}
		printf("*");
		if(i == mid - 1) {
			for(j = 0; j < 2 * i - 1; j++) {
				printf("*");
			}
			printf("*\n");
		} else if(i != 0) {
			for(j = 0; j < 2 * i - 1; j++) {
				printf(" ");
			}
			printf("*\n");
		}
		if(i == 0){
			printf("\n");
		} 

	}

  return 0;
}
