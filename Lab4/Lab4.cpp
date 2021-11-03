#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void cleaning(char* text, int len) { // Чистим text от нулей после прохождения strtok()
	for (int i = 0; i < len; ++i)
		if (text[i] == 0)
			text[i] = ' ';
}
char* writting(char* token, int len) { // Записываем в указатель слово, которое сравниваем (необходимо чтобы избежать бага)
	char* word = (char*)calloc(len + 1, sizeof(char));
	for (int i = 0; i < len; i++)
		word[i] = token[i];
	word[len] = '\0';
	token = NULL;
	return word;
}
int main()
{
	char text[] = "Lorem ipsum dolor sit amet consectetur adipiscing elit Ut placerat libero Lorem ipsum dolor"; // Само преждложения в котором будем искать уникальные слова
	printf("TEXT:\n%s\n", text);
	int len = strlen(text); // Длина текста
	char* uniqueWords = (char*)calloc(len + 1, sizeof(char)); // Строка в которую будем записывать уникальные слова
	int count = 0; // Счётчик пробелов = слов
	for (int i = 0; i < len; i++)
		if (text[i] == ' ')
			++count;
	char *word = NULL, *token = NULL;
	for (int i = 0, wordCount = 0; i < count; i++, wordCount = 0)
	{
		for (int mem, j = 0; j != i + 1; j++) { // Берём слово, которое будем сравнивать
			if (j == 0)
				token = strtok(text, " ");
			else
				token = strtok(NULL, " ");
		}
		word = writting(token, strlen(token));
		cleaning(text, len);
		for (char* pch = strtok(text, " "); pch != NULL && wordCount < 2; pch = strtok(NULL, " ")) // Сравниваем word с текстом(pch)
			if (strcmp(pch, word) == 0)
				++wordCount;
		if (wordCount < 2) { // Если слово больше одного раза встречается(оно встречается с самим собой), значит не уникальное
			strcat(uniqueWords, word);
			strcat(uniqueWords, " ");
		}
		free(word);
		cleaning(text, len);
	}
	printf("RESULT:\n%s", uniqueWords);
	printf("\n\n");
	free(uniqueWords);
	return 0;
}
