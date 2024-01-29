#include <stdio.h>

// define the constant values
#define MaximumDays 31
#define MaxEntries 2

// Define global variables
int dayOfMonth;
float balance, totalExpenses, monthlyIncome, totalIncome;
char answer1;
int targetDay;

// Define our own data type, which is Expense
typedef struct {
    int dayOfMonth;
    char category[30];
    float amount;
} Expense;

// 2D Array of our own data type
Expense expenses[MaximumDays][MaxEntries];

// Function call at top
void monthlyReport();
void checkExpenses();
float Income();
void enterExpenses();

// Switch case to let user decide what to do
int main() {
    int choice;
    do {
        printf("\t***** Finance Management System *****\n");
        printf("1. Enter Expenses\n");
        printf("2. Check Current Bill for Units\n");
        printf("3. Check Water Bill for Units\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterExpenses();
                break;
            case 2:
                checkCurrentBill();
                break;
            case 3:
                // checkWaterBill();
                break;
            case 4:
                printf ("\n\tThank you for using the Financial Management System! \n\n\n");
                break;
            default:
                printf("\t\n\nInvalid choice. Please enter a number between 1 and 5.\n\n\n");
        }
    } while (choice != 4);

    return 0;
}

// Generate a monthly report
void monthlyReport() {
    printf("\t\tMonthly Report\n");
    printf(" Total income = %.2f \n Total expenses = %.2f \n Remaining balance = %.2f \n", totalIncome, totalExpenses, balance);
}

// check the expenses for specific day
void checkExpenses() {
    char answer1;
    int targetDay;

    do { 
        
        printf("\n\tDo you want to check expenses for a specific day? (y/n): ");
        scanf(" %c", &answer1);
        if (answer1 == 'y' || answer1 == 'Y') {
            printf("Enter the day: ");
            // store the day inside targetDay variable
            scanf("%d", &targetDay);
            // Check if the date is in between 1 - 31
            if (targetDay < 1 || targetDay > 31) {
                printf("Invalid date. Please enter date between 1 - 31.\n");
            } else {
                printf("Expenses for the day %d:\n", targetDay);
                    // loop to run 2D array's second bracket
                    // The second elements of the array accessed using this for loop.
                for (int i = 0; i < MaxEntries; i++) {
                    // The value in expense array that equals the inputted targetDay variable is accessed. 
                    if (expenses[targetDay - 1][i].dayOfMonth == targetDay) {
                        printf("Expense Category: %s, Amount: %.2f\n", expenses[targetDay - 1][i].category, expenses[targetDay - 1][i].amount);
                        if (i > MaxEntries)
                        {
                           printf("\nMaximum Entries per day have reached\n");
                        }
                        
                    }
                }
            }
        }
    } while (answer1 == 'y' || answer1 == 'Y');

    if (answer1 == 'n' || answer1 == 'N'); {
         printf ("\n\tThank you for using the Financial Management System! \n\n\n");
    }
       
        
}

// Enter the monthly income
float Income() {
    float monthlyIncome;
    printf("Enter monthly income: ");
    scanf("%f", &monthlyIncome);
    return monthlyIncome;
}

void enterExpenses() {
    // set totaExpenses and totalIncome 0 at first
    totalExpenses = 0;
    totalIncome = 0;

    // Execute the Income() function
    float monthlyIncome = Income();

    while (1) {
        printf("Enter your expenses (Day / Expense Category / Amount)\n");
        printf("Day of month: ");
        scanf("%d", &dayOfMonth);
        // Check if the date is in between 1 - 31
        if (dayOfMonth <= 0 || dayOfMonth > 31) {
            printf("Invalid day. Please enter a day between 1 and 31.\n");
            continue;
        }
        // introduce Entries variable and set the value to 0
        int Entries = 0;

        while (Entries < MaxEntries && expenses[dayOfMonth - 1][Entries].dayOfMonth != 0) {
            Entries++;
        }

        if (Entries >= MaxEntries) {
            printf("Maximum entries for the day %d reached.\n", dayOfMonth);
            break;
        }

        expenses[dayOfMonth - 1][Entries].dayOfMonth = dayOfMonth;

        printf("Enter Expense category: ");
        scanf("%29s", expenses[dayOfMonth - 1][Entries].category);

        printf("Enter amount: ");
        scanf("%f", &expenses[dayOfMonth - 1][Entries].amount);

        totalExpenses += expenses[dayOfMonth - 1][Entries].amount;
       
        LOOP:
        printf("Do you want to add another expense? (Y/N)");
        scanf(" %c", &answer1);
        if (answer1 == 'n' || answer1 == 'N') {
           
            break;
        }  else if (answer1 != 'y' && answer1 != 'Y') {
            printf("Invalid input. Please enter 'Y' or 'N'.\n");
           goto LOOP;
        }
      
    }

    totalIncome += monthlyIncome;
    balance = totalIncome - totalExpenses;

    monthlyReport();
    checkExpenses();
}

void checkCurrentBill() { 

  int previousReading, currentReading, totalUnits, Totalamount;
    int a,b,c,d,e,f;
    a=8;  // energy charge 0 - 60    Rs/kWh
    b=10; // energy charge 0 - 60    Rs/kWh
    c=16; // energy charge above 60  Rs/kWh
    d=16; // energy charge above 60  Rs/kWh
    e=50; // energy charge above 60  Rs/kWh
    f=75; // energy charge above 180 Rs/kWh

    printf("\n\tElectricity Bill Calculator\n\n");

    printf("Enter Your Previous Meter Reading : ");
    scanf("%d", &previousReading);

    printf("Enter Your Current Meter Reading : ");
    scanf("%d", &currentReading);

    totalUnits = currentReading - previousReading;

    printf("Total Units : %d\n", totalUnits);

    if (totalUnits > 0 && totalUnits <= 60){
        printf("Consumption 0 - 60 kWh per month\n");
        if(totalUnits <= 30){
            Totalamount = (totalUnits * a) + 120;
        } else if (totalUnits <= 60){
            Totalamount = (30 * a)/*0-30*/ + ((totalUnits - 30) * b) + 240;
        }
    } else if (totalUnits >= 61 && totalUnits <= 180){
        printf("Consumption above 60 kWh per month\n");
        if(totalUnits <= 60){
            Totalamount = (totalUnits * c) /*+ 120*/;
        } else if (totalUnits <= 90){
            Totalamount = (60 * c)/*0-60*/ + ((totalUnits - 60) * d) + 360;
        }
    } else {
        printf("\nConsumption above 180 kWh per month\n\n");
        Totalamount = (totalUnits * f) + 1500;
    }

    printf("Rs.%d\n\n", Totalamount);
    
 
} 
