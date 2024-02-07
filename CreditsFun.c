//CreditsFun.c by Steven Conyers
Created: 3/15/2021
Updated: 2/7/2024 */

#include <stdio.h>

//Prototypes
void printHeading       (void);
int getCreditsRegister	(void);
int getCreditsCompleted	(void);
float getTuitionRate	(int);
void printTuitionCharge	(int, float);
char getAgain		(void);
void printFinal		(void);
//---------------------------------------------------------------------------------
//Globals
int count = 0;
float grandTuition = 0.0f;
//---------------------------------------------------------------------------------
int main(void)
{
//---------------------------------------------------------------------------------
//Local Variables
int creditsCompleted= 0;
int creditsRegister = 0;
float tuitionRate = 0.0f;
float tuitionCharge = 0.0f;
char again = 'y';
printHeading();
//---------------------------------------------------------------------------------
//Begin loop
while(again == 'y' || again == 'Y')
{
//---------------------------------------------------------------------------------
creditsCompleted = getCreditsCompleted();

creditsRegister = getCreditsRegister();
tuitionRate = getTuitionRate(creditsCompleted);

printTuitionCharge(creditsRegister, tuitionRate);

again = getAgain();
}
printFinal();
  
return 0;
}
//---------------------------------------------------------------------------------
//Heading
void printHeading(void)
{
	printf("Tuition Calculator by Steven Conyers\n");
}
//---------------------------------------------------------------------------------
//Input from user
int getCreditsCompleted(void)
{
	int localCreditsCompleted = 0;
	printf("\nHow many credits have you previously completed? ");
	scanf ("%d", &localCreditsCompleted);
  
	return localCreditsCompleted;
}
int getCreditsRegister(void)
{
	int localCreditsRegister = 0;
	printf("\nHow many credits are you registering for today? ");
	scanf("%d", &localCreditsRegister);
  
	return localCreditsRegister;
}
//---------------------------------------------------------------------------------
//Tuition Rate determination
float getTuitionRate(int creditsDone)
{
	float tuitionRate = 0.0f; //Local to this function only
	if (creditsDone < 91)
	{
		tuitionRate = 125.75f;
	}
		else if (creditsDone < 121)
		{
			tuitionRate = 175.75f;
		}
			else
			{
				tuitionRate = 250.25f;
			}
return tuitionRate;
}
//---------------------------------------------------------------------------------
//
void printTuitionCharge(int creditsRegister, float tuitionRate)
{
	float tuitionCharge = 0.0f;
	tuitionCharge = (float) creditsRegister * tuitionRate;
	grandTuition += tuitionCharge;	//global
	count++;						//global
	printf("\n\nTuition Charge: %.2f\n", tuitionCharge);
}	
//---------------------------------------------------------------------------------
//Prompt user to determine if loop should continue
char getAgain(void)
{
	char localAgain = '\0';
	printf("\nEnter Y to process another student: ");
	scanf(" %c", &localAgain); // end loop
	return localAgain;
} 
//---------------------------------------------------------------------------------
//Prints count and grand total
void printFinal(void)
{
	printf("Students processed: %d\n\n", count);
	printf("\nGrand Total of Tuition: $%.2f\n", grandTuition);
}
