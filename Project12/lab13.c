#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void task01();
void task02();
void task03();

int main() {
	setlocale(LC_CTYPE, "RUS");
	task03();
}

void task01() {
	char Snew[41] = "Hello, ";
	char Name[20];
	printf("Enter your name:\n");
	scanf("%s", Name);
	strcat(Snew, Name);
	for (int i = 0; Snew[i] != '\0'; i++) {
		Snew[i] = toupper(Snew[i]);
	}
	int exclaim_mark = 40 - strlen(Snew);
	for (int i = 0; i < exclaim_mark; i++) {
		strcat(Snew, "!");
	}
	printf("%s!\n", Snew);
}

void task02() {
	char Snew[20] = "Hello, ";
	char Name[20];
	printf("Enter your name:\n");
	scanf("%s", Name);
	strcat(Snew, Name);
	int length = strlen(Snew);
	int flag = 1;
	for (int i = length - 1; i >= 0; i--) {
		if ((Snew[i] != ' ') && (Snew[i] != ',')) {
			if (flag) {
				for (int j = length; j > i; j--) {
					Snew[j] = Snew[j - 1];
				}
				Snew[i] = '_';
				length++;
			}
			flag = 0;
		}
		else {
			flag = 1;
		}
	}

	printf("%s!\n", Snew);
}

void task03() {
	system("chcp 1251");
	setlocale(LC_ALL, "RUS");
	wchar_t str[100];
	int counter = 0;
	int start = 0;
	int end = strlen(str) - 1;
	printf("Enter a sentence:\n");
	fgetws(str, 100, stdin);
	while (str[start] != ' ' && str[start] != '\0') {
		start++;
	}
	while (str[end] != ' ') {
		end--;
	}
	for (int k = start; k<end; k++) {
		if (iswalpha(str[k]) ) {
			counter++;
		}
	}
	printf("%d", counter);
}
