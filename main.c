#include <lib.h>
/*Условие ИЗ№1:
Создать структуру для хранения информации об HTML-теге: его имени, признаке «открывающий/закрывающий» и атрибутах тега.
 Составить с ее использованием программу, включающую в себя функцию, принимающую на вход текстовую строку с одним тегом.
 На выход функция должна возвращать указатель на инициализированную структуру.
*/



int main() {
    int64_t decNum = 98;
    printf("The arabian number is: %ld", decNum);
    if (decNum <= 0) {
        printf("Error number\nIt should be greater then zero\n");
        return 0;
    }
    size_t size = 0;
    char *answer = NULL;
    answer = getRomeNumber(decNum, answer, &size);
    printf("\nRome number is: ");
    printf("%s", answer);
    printf("\nsize: %lu\n", size);
    return 0;
}