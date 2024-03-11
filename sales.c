#include <stdio.h>



void sales_report(float sales[], char *months[]) { // function for generating the sales report.
    printf("Monthly sales report for 2022:\n"); // starts it exactly like the sample output.
    printf("Month          Sales\n");
    for (int i = 0; i < 12; i++) { // iterates through the months 1 by 1 in order to print both the month and the sales side by side.
        printf("%-15s $%.2f\n", months[i], sales[i]); // prints it and sorts it using the -15s and sets it to only use two decimal points, as dollars do.
    }
}

void sales_summary(float sales[], char *months[]) { // function to generate the sales summary.
    float min_sales = sales[0]; // we start these float variables at the first value, and then it will switch if it every finds a new min or max respectively.
    float max_sales = sales[0];
    float total_sales = 0; // starts a total sales counter to add up then divide for the average.

    for (int i = 0; i < 12; i++) { // iterate again through the months, and then if the next sales is less than the current minimum, we switch it to the current minimum. 
        if (sales[i] < min_sales) { // 
            min_sales = sales[i];
        }
        if (sales[i] > max_sales) { // same thing as minimum, iterate and switch if bigger than current max.
            max_sales = sales[i];
        }
        total_sales += sales[i]; // add up the sales.
    }

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[12 - 1]); // prints out the summary like in the sample.
    printf("Average sales: $%.2f\n", total_sales / 12);
}

void moving_average(float sales[], char *months[]) { // function for the 6 month average.
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < 12 - 5; i++) { // we want to iterate through as long as there are 6 months to go off of, so at month 7 it will cut off and not keep going.
        float sum = 0; // set a sum for adding up.
        for (int j = i; j < i + 6; j++) { // iterating through the 6 months each time that will be averaged.
            sum += sales[j]; // add the sales up for each of the 6 months.
        }
        printf("%-15s - %-15s $%.2f\n", months[i], months[i + 5], sum / 6); // print the moving average, sorting the data columns.
    }
}

void sales_report_sorted(float sales[], char *months[]) { // function for the sales report from highest to lowest.
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month          Sales\n");

    float temp_sales[12]; // 
    char *temp_months[12];

    for (int i = 0; i < 12; i++) { // iterate through and set our variables to the equivalent of the sales and months variables.
        temp_sales[i] = sales[i];
        temp_months[i] = months[i];
    }

    for (int i = 0; i < 12 - 1; i++) { // these loops will iterate through and sort our temp months and sales to the respective corresponding order. 
        for (int j = 0; j < 12 - i - 1; j++) {
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

    for (int i = 0; i < 12; i++) { // prints each one in order.
        printf("%-15s $%.2f\n", temp_months[i], temp_sales[i]);
    }
}

int main() {
    float sales[12]; 
    char *months[12] = {"January", "February", "March", "April", "May", "June", // sets the months 
                             "July", "August", "September", "October", "November", "December"};

    // Read sales data from input file
    FILE *file = fopen("input.txt", "r"); // i had to research how to do this, found help on stack overflow. i originally just hardcoded the values in to test and worked on this last.

    for (int i = 0; i < 12; i++) {
        fscanf(file, "%f", &sales[i]);
    }

    fclose(file);

    sales_report(sales, months);
    sales_summary(sales, months); // these actually put our real data into all of our functions and therefore prints out the results.
    moving_average(sales, months);
    sales_report_sorted(sales, months);

    return 0;
}