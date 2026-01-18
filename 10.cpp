#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define MAX_LEN 1000
#define MAX_WORDS 100

void reverse_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        char temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

int main() {
    setlocale(LC_CTYPE, "Rus");
    char str[MAX_LEN];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    
    // Удаление символа новой строки, если он есть
    str[strcspn(str, "\n")] = 0;

    // 0) Вывод строки на экран
    printf("Введенная строка: %s\n", str);

    // Разделение строки на слова
    char *words[MAX_WORDS];
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL && count < MAX_WORDS) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // Подсчет количества слов, в которых количество символов кратно 5
    int count_div_5 = 0;
    for (int i = 0; i < count; i++) {
        if (strlen(words[i]) % 5 == 0) {
            count_div_5++;
        }
    }
    printf("Количество слов, длина которых кратна 5: %d\n", count_div_5);

    // Поиск слова с максимальным количеством вхождений введенной буквы
    char letter;
    printf("Введите букву для поиска: ");
    scanf(" %c", &letter);
    
    int max_count = 0;
    char *max_word = NULL;
    
    for (int i = 0; i < count; i++) {
        int current_count = 0;
        for (int j = 0; j < strlen(words[i]); j++) {
            if (tolower(words[i][j]) == tolower(letter)) {
                current_count++;
            }
        }
        if (current_count > max_count) {
            max_count = current_count;
            max_word = words[i];
        }
    }
    
    if (max_word != NULL) {
        printf("Слово с наибольшим количеством вхождений '%c': %s (%d раз)\n", letter, max_word, max_count);
    } else {
        printf("Слово с буквой '%c' не найдено.\n", letter);
    }

    // Ввод двух номеров слов и их замена
    int index1, index2;
    printf("Введите два номера слов для обмена (от 1 до %d): ", count);
    scanf("%d %d", &index1, &index2);
    
    if (index1 > 0 && index2 > 0 && index1 <= count && index2 <= count) {
        char *temp = words[index1 - 1];
        words[index1 - 1] = words[index2 - 1];
        words[index2 - 1] = temp;

        printf("Слова после обмена:\n");
        for (int i = 0; i < count; i++) {
            printf("%s ", words[i]);
        }
        printf("\n");
    } else {
        printf("Некорректные номера слов.\n");
    }

    // Сортировка слов по возрастанию
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    printf("Слова после сортировки:\n");
    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Переворот каждого слова в строке
    printf("Перевернутые слова:\n");
    for (int i = 0; i < count; i++) {
        reverse_word(words[i]);
        printf("%s ", words[i]);
    }
    
    printf("\n");

    return 0;
}

