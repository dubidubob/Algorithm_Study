//���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. ������ ���ĺ��� ���ؼ�, �ܾ ���ԵǾ� �ִ� ��쿡�� ó�� �����ϴ� ��ġ��, ���ԵǾ� ���� ���� ��쿡�� -1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	char word[100];    // ũ�Ⱑ N�� char�� �迭�� ����
	int alpa[26];

	for (int i = 0; i < (sizeof(alpa) / sizeof(int)); i++) {//!�ش� �ڷ��� ũ��� ��������
		alpa[i] = -1;
	}

	printf("\n���ڿ��� �Է��ϼ���: ");//! �̰� �� ��(���� �Է� ���ǿ� ������ ����
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
