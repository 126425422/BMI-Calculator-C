#include <stdio.h>
#include <stdlib.h>

// Структура за съхранение на данни за човек
struct Person {
    char name[50];
    float weight;
    float height;
    float bmi;
    char category[30];
};

// Функция за изчисляване на BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Функция за определяне на категорията според BMI
void getCategory(float bmi, char category[]) {
    if (bmi < 18.5)
        sprintf(category, "Поднормено тегло");
    else if (bmi < 25)
        sprintf(category, "Нормално тегло");
    else if (bmi < 30)
        sprintf(category, "Наднормено тегло");
    else
        sprintf(category, "Затлъстяване");
}

// Главна функция
int main() {
    struct Person person;
    FILE *file;

    printf("Въведете име: ");
    scanf("%49s", person.name);

    printf("Въведете тегло (в килограми): ");
    scanf("%f", &person.weight);

    printf("Въведете ръст (в метри): ");
    scanf("%f", &person.height);

    person.bmi = calculateBMI(person.weight, person.height);
    getCategory(person.bmi, person.category);

    printf("\nРезултати за %s:\n", person.name);
    printf("BMI: %.2f\n", person.bmi);
    printf("Категория: %s\n", person.category);

    // Запис във файл
    file = fopen("bmi_results.txt", "a");
    if (file == NULL) {
        printf("Грешка при отваряне на файла!\n");
        return 1;
    }
    fprintf(file, "%s %.2f %.2f %.2f %s\n",
            person.name, person.weight, person.height, person.bmi, person.category);
    fclose(file);

    printf("\nДанните са записани във файла bmi_results.txt\n");

    // Прочитане на съдържанието на файла
    printf("\n--- Всички запазени резултати ---\n");
    file = fopen("bmi_results.txt", "r");
    if (file != NULL) {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    }

    return 0;
}
