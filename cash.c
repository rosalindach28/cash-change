// use fewest number of coins for change
// using greedy approach
//largest-to-smallest in value

#include <stdio.h>

// first line of all other functions
int get_cents(void);
int calculate_quarters(int change);
int calculate_dimes(int change);
int calculate_nickels(int change);
int calculate_pennies(int change);

int main(void)
{
    int total; // total amount of coins
    int coins = get_cents(); // grabs user input
   // printf("%d\n", coins);
    int q = calculate_quarters(coins); 
    int remainder = (coins - 25*q); // calculates dimes using the amount left
    int d = calculate_dimes(remainder);
    remainder = remainder - (10*d); // amount remaining is updated
    int n = calculate_nickels(remainder);
    remainder = remainder - (5*n); // amount remaining is updated
    int p = calculate_pennies(remainder);
    
    printf("Quarters: %d\n", q);
    printf("Dimes: %d\n", d);
    printf("Nickels: %d\n", n);
    printf("Pennies: %d\n", p);
    printf("Total amount of coins: %d\n", q+d+n+p);
}

/*
-- Note for above (remainder var)
after the number of one type of coin is determined, the amount owed needs to be updated each time
by subtracting the amount calculated from the total amount
for example if the total amount is 99, first the quarters are calculated
3 quarters can be used = 75 so when calculating for dimes
the amount owed needs to be updated to 99-75 = 24 
so total amount - 25* number of quarters that are used
and so on for each type of coin until the amount remaining is zero
*/

int get_cents(void)
{
    int cents;
    int integer_read = 0;
    do
    {
        printf("Enter number of cents: ");
        integer_read = scanf("%d", &cents); // store input value in variable
        while(integer_read != 1) // input read is not an integer
        {
           printf("Not a number, try again. \n");
           scanf("%*[^\n]"); // read and empty buffer so strings do not cause infinite loop
           printf("Enter number of cents: "); // prompt user for valid input
           integer_read = scanf("%d", &cents);
        } 
    }
    while (cents < 0); // input validation
    return cents;
}
int calculate_quarters(int change) // variable change is parameter
{
    int quarters; // number of quarters
    if(change < 25)
    {
        quarters = 0;
    }
    else if (change == 25)
    {
        quarters = 1;
    }
    else
    {
        quarters = change/25;
    }
    return quarters;
}

int calculate_dimes(int change)
{
    int dimes; // number of dimes
    if(change < 10)
    {
        dimes = 0;
    }
    else if (change == 10)
    {
        dimes = 1;
    }
    else
    {
        dimes = change/10;
    }
    return dimes;  
}

int calculate_nickels(int change)
{
    int nickels; // number of nickels
    if(change < 5)
    {
        nickels = 0;
    }
    else if (change == 5)
    {
        nickels = 1;
    }
    else
    {
        nickels = change/5;
    }
    return nickels;
    
}
int calculate_pennies(int change)
{
    int pennies; // number of pennies
    if (change < 1)
    {
        pennies = 0;
    }
    else if (change < 5) 
    {
        pennies = 0;
        while(pennies < change) // penny amount increases if change is between 1-4
        {
            pennies++;
        }
    }
    return pennies;   
}