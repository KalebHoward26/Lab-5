#include <stdio.h>

#define MONTHS 12

void generate_sales_report(float sales[], char *months[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
}

void generate_sales_summary(float sales[], char *months[]) {
    float min_sales = sales[0];
    float max_sales = sales[0];
    float total_sales = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min_sales) {
            min_sales = sales[i];
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
        }
        total_sales += sales[i];
    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[MONTHS - 1]);
    printf("Average sales: $%.2f\n", total_sales / MONTHS);
}

void generate_six_month_moving_average(float sales[], char *months[]) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < MONTHS - 5; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 5], sum / 6);
    }
}

void generate_sales_report_sorted(float sales[], char *months[]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");

    float temp_sales[MONTHS];
    char *temp_months[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        temp_sales[i] = sales[i];
        temp_months[i] = months[i];
    }

    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (temp_sales[j] < temp_sales[j + 1]) {
                float temp = temp_sales[j];
                temp_sales[j] = temp_sales[j + 1];
                temp_sales[j + 1] = temp;

                char *temp_month = temp_months[j];
                temp_months[j] = temp_months[j + 1];
                temp_months[j + 1] = temp_month;
            }
        }
    }

    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t$%.2f\n", temp_months[i], temp_sales[i]);
    }
}

int main() {
    float sales[MONTHS] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
                           72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June",
                             "July", "August", "September", "October", "November", "December"};

    generate_sales_report(sales, months);
    generate_sales_summary(sales, months);
    generate_six_month_moving_average(sales, months);
    generate_sales_report_sorted(sales, months);

    return 0;
}