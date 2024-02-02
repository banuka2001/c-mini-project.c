#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// define the constant values
#define MaximumDays 31
#define MaxEntries 2


// Define global variables
int dayOfMonth;
float balance, totalExpenses, monthlyIncome, totalIncome ;
char answer1;
int targetDay;
char answer3;

// Define our own data type, which is Expense
typedef struct {
    int dayOfMonth;
    char category[30];
    float amount;
} Expense;

// 2D Array of our own data type
Expense expenses[MaximumDays][MaxEntries];

// Function call at top
float Income();
void monthlyReport();
void investmentPlans();
void checkExpenses();
void enterExpenses();
void ReturnOrExit();
void checkElectricityBill();

// Switch case to let user decide what to do
int main() {
    int choice;
    do {

        system("cls");
        printf("\n\t\t***************************************\n");
        printf("\t\t***** Finance Management System *******\n");
        printf("\t\t***************************************\n\n");


        printf("\t1. Enter Expenses\n\n");
        printf("\t2. Check Current Bill for Units\n\n");
        printf("\t3. Check Water Bill for Units\n\n");
        printf("\t4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterExpenses();
                break;
            case 2:
                checkElectricityBill();
                break;
            case 3:
                
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
    printf("\n\t\t -------- Monthly Report -------- \n");
    printf(" Total income = %.2f \n Total expenses = %.2f \n Remaining balance = %.2f \n", totalIncome, totalExpenses, balance);

    investmentPlans();
    
}

        
// Enter the monthly income

float Income() {
    float monthlyIncome;
    printf("\nEnter monthly income: Rs.");
    scanf("%f", &monthlyIncome);
    return monthlyIncome;
}

// Enter Expenses

void enterExpenses() {
    // set totaExpenses and totalIncome 0 at first
    totalExpenses = 0;
    totalIncome = 0;

    // Execute the Income() function
    float monthlyIncome = Income();

    while (1) {
        system("cls");
        printf("\n\t---- Enter your expenses (Day / Expense Category / Amount) ----\n\n");
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

        printf("\nEnter Expense Category: \n");
        printf("\t Food  |  Pets  |  Groceries  |  Transport  |  Health\n");
        scanf("%s", expenses[dayOfMonth - 1][Entries].category);


        printf("Enter amount: Rs.");
        scanf("%f", &expenses[dayOfMonth - 1][Entries].amount);

        totalExpenses += expenses[dayOfMonth - 1][Entries].amount;
       
        LOOP:
        printf("\nDo you want to add another expense? (Y/N)");
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

    checkExpenses();
    
    
}


// check the expenses for specific day

void checkExpenses() {
    char answer1;
    int targetDay;

    do { 
        
        system("cls");
        printf("\n\tDo you want to check expenses for a specific day? (y/n): ");
        scanf(" %c", &answer1);

        if (answer1 == 'y' || answer1 == 'Y') {
            printf("Enter the day: ");
            scanf("%d", &targetDay);

            // Check if the date is in between 1 - 31
            if (targetDay < 1 || targetDay > 31) {
                printf("Invalid date. Please enter date between 1 - 31.\n");
            } else {
                int entriesFound = 0;
                printf("Expenses for the day %d:\n", targetDay);

                // Loop to run through the 2D array's second bracket
                for (int i = 0; i < MaxEntries; i++) {
                    // Check if an entry exists for the specified day
                    if (expenses[targetDay - 1][i].dayOfMonth == targetDay) {
                        entriesFound = 1;
                        printf("Expense Category: %s, Amount: %.2f\n", expenses[targetDay - 1][i].category, expenses[targetDay - 1][i].amount);
                    }
                }

                // Check if no entries were found
                if (!entriesFound) {
                    printf("No entries for the day %d. \n", targetDay);
                }
                
            }
        }
    } while (answer1 == 'y' || answer1 == 'Y');

    if (answer1 == 'n' || answer1 == 'N') {
        monthlyReport();
    }
}



// Electricity Bill Calculater

void checkElectricityBill() { 

 printf("Electricity Tariff Revision\n");

    printf("----------------------------------------------------------------------------------\n");
    printf("Block\t\t\tEnergy Charge (Rs. /kWh)\tFixed Charge (Rs. /Month)\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Consumption 0 - 60 kWh per month\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Block 1 : 0 - 30 kWh\t8.00\t\t\t\t120.00\n");
    printf("Block 2 : 31 - 60 kWh\t10.00\t\t\t\t240.00\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Consumption above 60 kWh per month\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Block 1 : 0 - 60 kWh\t16.00\t\t\t\tN/A\n");
    printf("Block 2 : 61 - 90 kWh\t16.00\t\t\t\t360.00\n");
    printf("Block 3 : 91 - 120 kWh\t50.00\t\t\t\t960.00\n");
    printf("Block 4 : 121 - 180 kWh\t50.00\t\t\t\t960.00\n");
    printf("Block 5 : Above 180 kWh\t75.00\t\t\t\t1500.00\n");
    printf("----------------------------------------------------------------------------------\n");

    const int charge0_30 = 8;   // Rs/kWh
    const int charge31_60 = 10;   // Rs/kWh

    const int charge0_60 = 16;   // Rs/kWh
    const int charge61_91 = 16;   // Rs/kWh
    const int charge91_120 = 50;   // Rs/kWh
    const int charge121_180 = 50;   // Rs/kWh
    const int chargeAbove180 = 75;   // Rs/kWh

    const int fixed0_30 = 120;   // Rs/Month
    const int fixed31_60 = 240;   // Rs/Month

    const int fixed0_60 = 0;   // Rs/Month
    const int fixed61_90 = 360;   // Rs/Month
    const int fixed91_120 = 960;   // Rs/Month
    const int fixed121_180 = 960;   // Rs/Month
    const int fixedAbove180 = 1500;   // Rs/Month

    printf("\nElectricity Bill Calculator\n");

    int previousReading, currentReading, totalUnits, totalAmount;
    char calculateAnother;

    do {
        do {
            printf("\nEnter Your Previous Meter Reading (Integer) : ");
            scanf("%d", &previousReading);

            printf("\n(Note: Current reading should be greater than previous reading.)\n");
            printf("Enter Your Current Meter Reading (Integer) : ");
            scanf("%d", &currentReading);

        // Check if current reading is greater than previous reading
        } while (currentReading < previousReading);

        totalUnits = currentReading - previousReading;

        printf("Total Units : %d\n", totalUnits);

        if (totalUnits > 0 && totalUnits <= 60) {
            printf("Consumption 0 - 60 kWh per month\n");

            if (totalUnits <= 30) {
                totalAmount = (totalUnits * charge0_30) + fixed0_30;
            } else {
                totalAmount = (30 * charge0_30) + ((totalUnits - 30) * charge31_60) + fixed31_60;
            }

        } else if (totalUnits > 60 && totalUnits <= 180) {
            printf("Consumption above 60 kWh per month\n");
            if (totalUnits <= 60) {
                totalAmount = (totalUnits * charge0_60) + fixed0_60;
            } else if (totalUnits <= 90) {
                totalAmount = (60 * charge0_60) + ((totalUnits - 60) * charge61_91) + fixed61_90;
            } else if (totalUnits <= 120) {
                totalAmount = (60 * charge0_60) + (30 * charge61_91) + ((totalUnits - 90) * charge91_120) + fixed91_120;
            } else if (totalUnits <= 180) {
                totalAmount = (60 * charge0_60) + (30 * charge61_91) + (30 * charge91_120) + ((totalUnits - 120) * charge121_180) +  fixed121_180;
            }
        } else if (totalUnits > 180) {
            printf("Consumption above 180 kWh per month\n");
            totalAmount = (totalUnits * chargeAbove180) + fixedAbove180;
        }
        printf("----------------------------------------------------------------------------------\n");
        printf("\nTotal Amount: Rs. %d/=\n", totalAmount);
        printf("----------------------------------------------------------------------------------\n");
        do {
            printf("\nDo you want to calculate another bill? (Y/N): ");
            scanf(" %c", &calculateAnother);

            if (calculateAnother != 'Y' && calculateAnother != 'y' && calculateAnother != 'N' && calculateAnother != 'n') {
                printf("Invalid input. Please enter either Y or N.\n");
            }

        } while (calculateAnother != 'Y' && calculateAnother != 'y' && calculateAnother != 'N' && calculateAnother != 'n');

    } while (calculateAnother == 'Y' || calculateAnother == 'y');

    printf("\nThank you for using the Electricity Bill Calculator!\n");
    ReturnOrExit();

}   


// Code for return to the menu or exit the code


void ReturnOrExit() {
    char Choice;
    do {
        printf("\nDo you want to return to the main menu? (Y/N): ");
        scanf(" %c", &Choice);

        Choice = toupper(Choice); 

        if (Choice == 'Y') {
            main(); 
            break; 
        } else if (Choice == 'N') {
            printf("\nThank you for using the Financial Management System!\n");
            exit(0); // Exit the program
        } else {
            printf("Invalid choice. Please enter 'Y' for Yes, or 'N' for No.\n");
        }
    } while (Choice != 'Y' && Choice != 'N');
}



// Investment Plans

void investmentPlans() {
   
    int bank ,fd_period ,fd_year;
    char answer3;
    float fd_amount ,interest_rate ,interest ,total_interest;
    printf("\n\tDo you want any Financial Investment advice for your Remaining Balance..? (Y/N)  ");
    scanf("%s",&answer3);



    if(answer3=='n' || answer3=='N')
        {
        printf("\n\t\t\t\t\t--*|\t THANK YOU.!\t|*--\n");
            ReturnOrExit();
        }
    else if(answer3=='y' || answer3=='Y')
    { if(balance>=5000){ //if the balance<5000 we can't open a FD.
         LOOP:
        while(1){
        printf("\n\t\t\t\t\tPlease select a Bank for Transactions. \n");
        printf("\n\t\t\t\t\t|\tPeople's Bank - 1\t|\n");
        printf("\t\t\t\t\t|\tBank of Ceylon - 2\t|\n");
        printf("\n\t\t\tEnter Bank Code : ");
        scanf("%d",&bank);
            if(bank>2 || bank<1){
              printf("\n\t\t\t\t* Invalid input. Please enter 1 or 2. *\n");
              continue;
            }
            switch(bank){
                case 1: //People's Bank
                    printf("\t\t\t\t\t\tPEOPLE'S BANK\n");
                    while(1){
                        printf("\n\tYour Remaining Balance is %.2f\n",balance);
                        printf("\tPlease enter the amount you wish to deposit (Minimum deposit Rs. 5,000/-) : Rs. ");
                        scanf("%f",&fd_amount);
                        if(fd_amount>balance || fd_amount<5000){
                            printf("\n\t* Please enter amount between Rs. 5000.00 /- and Rs. %.2f /- *\n",balance);
                           continue;}
                        while(1){
                            printf("\n\t\t\t\t\tPlease select the deposit period \n");
                            printf("\n\t\t\t\t\t|\t01 year deposit - 1\t|\n");
                            printf("\t\t\t\t\t|\t02 year deposit - 2\t|\n");
                            printf("\t\t\t\t\t|\t05 year deposit - 3\t|\n");
                            printf("\n\t\t\tEnter Deposit Code : ");
                            scanf("%d",&fd_period);
                                if(fd_period>3 || fd_period<1){
                                    printf("\n\t\t\t\t* Invalid input. *");
                                continue;}
                                    switch(fd_period){
                                    case 1:
                                        printf("\n\t\tInterest rate is \t= 8.00 %% \n");
                                        interest_rate=8.00/100;
                                        fd_year=1;
                                        break;
                                    case 2:
                                        printf("\n\t\tInterest rate is \t= 9.00 %% \n");
                                        interest_rate=9.00/100;
                                        fd_year=2;
                                        break;
                                    case 3:
                                        printf("\n\t\tInterest rate is \t= 10.50 %% \n");
                                        interest_rate=10.50/100;
                                        fd_year=5;
                                        break;
                                    }
                        break;}

                    break;}

                    break;

                case 2:
                    if(balance>=10000){ //if the balance < 10000 we can't open FD in BOC.
                    printf("\t\t\t\t\t\tBANK OF CEYLON\n"); //Bank of Ceylon.
                    while(1){
                        printf("\n\tYour Remaining Balance is %.2f /-\n",balance);
                        printf("\tPlease enter the amount you wish to deposit (Minimum deposit Rs. 10,000/-) : Rs. ");
                        scanf("%f",&fd_amount);
                        if(fd_amount>balance || fd_amount<10000){
                            printf("\n\t* Please enter amount between Rs. 10000.00 /- and Rs. %.2f/- *\n",balance);
                           continue;}
                        while(1){
                            printf("\n\t\t\t\t\tPlease select the deposit period \n");
                            printf("\n\t\t\t\t\t|\t01 year deposit - 1\t|\n");
                            printf("\t\t\t\t\t|\t02 year deposit - 2\t|\n");
                            printf("\t\t\t\t\t|\t05 year deposit - 3\t|\n");
                            printf("\n\t\t\tEnter Deposit Code : ");
                            scanf("%d",&fd_period);
                                if(fd_period>3 || fd_period<1){
                                    printf("\n\t\t\t\t* Invalid input. *");
                                continue;}
                                    switch(fd_period){
                                    case 1:
                                        printf("\n\t\tInterest rate is \t= 8.00 %% \n");
                                        interest_rate=8.00/100;
                                        fd_year=1;
                                        break;
                                    case 2:
                                        printf("\n\t\tInterest rate is \t= 8.50 %% \n");
                                        interest_rate=8.50/100;
                                        fd_year=2;
                                        break;
                                    case 3:
                                        printf("\n\t\tInterest rate is \t= 9.50 %% \n");
                                        interest_rate=9.50/100;
                                        fd_year=5;
                                        break;
                                    }
                        break;}

                    break;}
                    break;
                    }else
                    printf("\n\t\t** You don't have enough balance to go for a INVESTMENT PLAN in BOC Bank. **\n"); goto LOOP;
                }

        break; }

    interest=fd_amount*interest_rate;
    printf("\t\tThe Annual Interest you get for a deposit of Rs. %.2f /- is \t= Rs. %.2f /-\n",fd_amount ,interest);
        total_interest=fd_year*interest;
    printf("\t\tTotal Interest after %d year/years \t\t\t\t\t= Rs. %.2f /-\n\n",fd_year ,total_interest);
    printf("\n\t\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");
    ReturnOrExit();

    }
    } else {
        printf("\n\t\t** You don't have enough balance to go for an INVESTMENT PLAN. **\n");
        printf("\n\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");
        ReturnOrExit();
    }
}



   