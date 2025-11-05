#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция за изчисляване на BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Функция за тълкуване на резултата
const char* interpretBMI(float bmi) {
    if (bmi < 18.5)
        return "Поднормено тегло";
    else if (bmi < 24.9)
        return "Нормално тегло";
    else if (bmi < 29.9)
        return "Наднормено тегло";
    else
        return "Затлъстяване";
}

// Функция за запис във файл (без съобщения при грешка)
void saveResultToFile(const char *name, float bmi, const char *category) {
    FILE *file = fopen("bmi_result.txt", "w");
    if (file == NULL) {
        return; // без грешка и без съобщение
    }

    fprintf(file, "Име: %s\n", name);
    fprintf(file, "BMI: %.2f\n", bmi);
    fprintf(file, "Категория: %s\n", category);
    fclose(file);
}

int main() {
    char name[50];
    float weight, height, bmi;

    printf("=== BMI (Body Mass Index) Калкулатор ===\n\n");

    printf("Въведете вашето име: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Въведете тегло (в килограми, напр. 70.5): ");
    scanf("%f", &weight);

    printf("Въведете височина (в метри, напр. 1.75): ");
    scanf("%f", &height);

    if (height <= 0 || weight <= 0) {
        printf("Грешка: Въведените стойности трябва да са положителни!\n");
        return 1;
    }

    bmi = calculateBMI(weight, height);
    const char *category = interpretBMI(bmi);

    printf("\n%s, вашият BMI е: %.2f\n", name, bmi);
    printf("Категория: %s\n", category);

    saveResultToFile(name, bmi, category); // запис без съобщения

    printf("\nБлагодаря, че използвахте BMI Калкулатора!\n");
    return 0;
}

