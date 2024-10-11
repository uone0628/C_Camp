#include <stdio.h>

int main(void) {
	int year, month, day = 1;
	int day_count = 0;  
	int d = 0; 
	int month_num[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("년도와 달을 입력해 주세요 : ");
	scanf("%d %d", &year, &month);

	for (int i = 1900; i < year; i++) {
		if (i % 4 == 0) {
			if (i % 400 == 0 || i % 100 != 0)
				day_count+=2;
			else if (i % 100 == 0)
				day_count++;
		}
		else {
			day_count++;
		}
	}

	if (year >= 1900 && month >= 1 && 12 >= month) {
		for (int i = 1; i <= month; i++) {
			switch (i) {
			case 2:
				if (year % 4 == 0) {
					if (year % 400 == 0 || year % 100 != 0) {
						d = 29;
						month_num[1] = 29;
					}
					else if (year % 100 == 0)
						d = 28;
				}
				else {
					d = 28;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				d = 30;
				break;
			default:
				d = 31;
				break;
			}
			if (i != month)
				day_count += d;
		}
		day_count += day;
		day = (day_count % 7);
	}
	else {
		printf("존재하지 않는 달입니다.");
		return 0;
	}

	printf("\n  Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");
	printf("-------------------------------------------\n");

	for (int i = 0; i < day; i++) {
		printf("      "); 
	}
	for (int i = 1; i <= month_num[month - 1]; i++) {
		if (day != 7) {
			printf(" %3d  ", i);
			day++;
		}
		else {
			printf("\n");
			day = 0;
			i--;
		}
	}
    printf("\n");

	return 0;
}