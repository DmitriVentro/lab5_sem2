#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> /* prototype exit() */
#include <string.h>
#include <iostream>
#define ROWS 
#define COLS 75
void file_open(void);
FILE* file_in;
char ch, arr_str[ROWS][COLS];
int j, i, count = 0;

int main(int agrc, char* argv[]) {
	setlocale(LC_ALL, "");
	file_open();
	for (j = 0; j < ROWS; ++j) {
		for (i = 0; (ch = getc(file_in)) != '\n' && (ch != EOF); ++i) {
			arr_str[j][i] = ch; // ���������� ������
		} //����� ����������� for
		if (ch == EOF) {
			puts("��������� ����� �����, �����.");
			fprintf(stdout, "count is: %i \n", count);
			break;
		} // ����� if
		else {
			arr_str[j][i] = '\0';
			++count;
		} // ����� else

	} // ����� �������� for
	fclose(file_in);
	/* ����� ������� �� ������� */
	fprintf(stdout, "�� ����� ������� %i �����, ������� ����� ���:\n", count);
	puts(""); // ������� ������
	for (j = 0; j < count; ++j) {
		fprintf(stdout, "%s\n", arr_str[j]);
	}
	puts(""); // ������� ������
	puts("��������� ���������.");
	exit(EXIT_SUCCESS);
}

void file_open(void) {
	if ((file_in = fopen("D:\\who\\tickets_info.txt","r")) == NULL) {
		fprintf(stdout, "%s\n", "�� ���� ������ ���� ��� ������");
		exit(EXIT_FAILURE);
	}
}

/*
����� �� �������:
�� ����� ������� 7 �����, ������� ����� ���:

I am a human 1
I am a 2 human`s 2
I am a 3 human 3
Nmjh## ___ 987 ht!
5555555555555555
66666666666666
77777777777777

��������� ���������.
*/