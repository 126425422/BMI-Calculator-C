#include <stdio.h>

int main() {
    float weight, height, bmi;

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Enter your height (m): ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    printf("\nYour BMI is: %.2f\n", bmi);

    if (bmi < 18.5)
        printf("Category: Underweight\n");
    else if (bmi < 25)
        printf("Category: Normal weight\n");
    else if (bmi < 30)
        printf("Category: Overweight\n");
    else
        printf("Category: Obesity\n");

    return 0;
}
