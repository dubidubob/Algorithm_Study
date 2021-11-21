//알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char word[100];    // 크기가 N인 char형 배열을 선언
	int alpa[26];

	for (int i = 0; i < (sizeof(alpa) / sizeof(int)); i++) {//!해당 자료형 크기로 나눠야함
		alpa[i] = -1;
	}

	printf("\n문자열을 입력하세요: ");//! 이거 뺄 것(문제 입력 조건에 없었기 때문
	scanf("%s", word);

	for (int i = 0; word[i]; i++) {
		if (alpa[((int)word[i] - 97)] == -1)
			alpa[((int)word[i] - 97)] = i;
	}

	for (int i = 0; i < (sizeof(alpa) / sizeof(int)); i++) {
		printf("%d ", alpa[i]);
	}


	return 0;
}
