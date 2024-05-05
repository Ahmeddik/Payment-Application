#include "terminal.h"
#include <stdio.h>



EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {

    printf("Enter transaction date (DD/MM/YYYY): ");
    if (scanf("%10s", termData->transactionDate) != 1) {
        printf("Error reading input\n");
        return INTERNAL_SERVER_ERROR;
    }
    if (strlen(termData->transactionDate) != 10) {
        return WRONG_DATE;
    }
    return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData) {
    // Extracting MM/YY from the card expiration date
    int cardMonth, cardYear, transMonth, transYear;
    sscanf(cardData->cardExpirationDate, "%d/%d", &cardMonth, &cardYear);
    sscanf(termData->transactionDate, "%d/%d", &transMonth, &transYear);

    // Checking if card is expired
    if (cardYear < transYear || (cardYear == transYear && cardMonth < transMonth)) {
        return EXPIRED_CARD;
    }
    return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
    printf("Enter transaction amount: ");
    scanf("%f", &termData->transAmount);
    getchar(); // Consume newline character from input buffer

    if (termData->transAmount <= 0) {
        return INVALID_AMOUNT;
    }
    return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
    if (termData->transAmount > termData->maxTransAmount) {
        return EXCEED_MAX_AMOUNT;
    }
    return TERMINAL_OK;
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount) {
    if (maxAmount <= 0) {
        return INVALID_MAX_AMOUNT;
    }
    termData->maxTransAmount = maxAmount;
    return TERMINAL_OK;
}

/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/

//the test cases

void getTransactionDateTc(void)
{
    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: getTransactionDate\n");
    printf("\nTest Case 1:\n");

    printf("Input Data: 15/04/2024\n");
    printf("Expected Result: TERMINAL_OK\n");
    ST_terminalData_t termData;
    EN_terminalError_t result1 = getTransactionDate(&termData);
    printf("Actual Result: %s\n", (result1 == WRONG_DATE) ? "WRONG_DATE" : "TERMINAL_OK");
    if (result1 == TERMINAL_OK)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
    printf("\n");



    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: getTransactionDate\n");
    printf("\nTest Case 2:\n");

    printf("Input Data: 15-04-2024\n");
    printf("Expected Result: WRONG_DATE\n");
    ST_terminalData_t termData2;
    EN_terminalError_t result2 = getTransactionDate(&termData2);
    printf("Actual Result: %s\n", (result2 == WRONG_DATE) ? "WRONG_DATE" : "TERMINAL_OK");
    if (result2 == WRONG_DATE)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
    printf("\n");
}

/*----------------------------------------------------------------------------------*/

void isCardExpiredTc(void)
{

    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: isCardExpired\n");
    printf("\nTest Case 1:\n");

    printf("Input Data: 04/02/2024\n");
    printf("Expected Result: TERMINAL_OK\n");
    ST_cardData_t cardData = { "aala adel mohamed ali", "8989374615436851", "06/25" };
    ST_terminalData_t termData = { 100,1000,0 };
    printf("entre transction date : ");
    gets(termData.transactionDate);
    EN_terminalError_t result3 = isCardExpired(&cardData, &termData);
    printf("Actual Result: %s\n", (result3 == EXPIRED_CARD) ? "EXPIRED_CARD" : "TERMINAL_OK");
    if (result3 == TERMINAL_OK)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
    printf("\n");


    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: isCardExpired\n");
    printf("\nTest Case 2:\n");

    printf("Input Data: 04/02/2026\n");
    printf("Expected Result: TERMINAL_OK\n");
    ST_cardData_t cardData2 = { "aala adel mohamed ali", "8989374615436851", "06/25" };
    ST_terminalData_t termData2 = { 100,1000,0 };
    printf("entre transction date : ");
    gets(termData2.transactionDate);
    EN_terminalError_t result4 = isCardExpired(&cardData2, &termData2);
    printf("Actual Result: %s\n", (result4 == EXPIRED_CARD) ? "EXPIRED_CARD" : "TERMINAL_OK");
    if (result4 == EXPIRED_CARD)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
    printf("\n");

}

/*----------------------------------------------------------------------------------*/

void getTransactionAmountTc(void)
{
    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: getTransactionAmount\n");
    printf("\nTest Case 1:\n");

    printf("Input Data: 1000\n");
    printf("Expected Result: TERMINAL_OK\n");
    ST_terminalData_t termData;
    EN_terminalError_t result = getTransactionAmount(&termData);
    printf("Actual Result: %s\n", (result == INVALID_AMOUNT) ? "INVALID_AMOUNT" : "TERMINAL_OK");
    if (result == TERMINAL_OK)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
    printf("\n");



    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: isCardExpired\n");
    printf("\nTest Case 2:\n");

    printf("Input Data: -1000\n");
    printf("Expected Result: INVALID_AMOUNT\n");
    ST_terminalData_t termData2;
    EN_terminalError_t result2 = getTransactionAmount(&termData2);
    printf("Actual Result: %s\n", (result2 == INVALID_AMOUNT) ? "INVALID_AMOUNT" : "TERMINAL_OK");
    if (result2 == INVALID_AMOUNT)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }

    printf("\n");

}

/*----------------------------------------------------------------------------------*/

void isBelowMaxAmountTc(void)

{
    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: isBelowMaxAmount\n");
    printf("\nTest Case 1:\n");

    printf("Input Data: 1000 for max amount\n and 500 for transamount\n");
    printf("Expected Result: TERMINAL_OK\n");
    ST_terminalData_t termData;
    termData.maxTransAmount = 1000.0;
    termData.transAmount = 500.0;
    EN_terminalError_t result = isBelowMaxAmount(&termData);
    printf("Actual Result: %s\n", (result == TERMINAL_OK) ? "TERMINAL_OK" : "EXCEED_MAX_AMOUNT");
    if (result == TERMINAL_OK)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }


    printf("\nTester Name: Ahmed Seddik\n");
    printf("Function Name: isCardExpired\n");
    printf("\nTest Case 2:\n");

    printf("Input Data: 1000 for max amount\n and 2000 for transamount\n");
    printf("Expected Result: EXCEED_MAX_AMOUNT\n");
    ST_terminalData_t termData1;
    termData1.maxTransAmount = 1000.0;
    termData1.transAmount = 2000.0;
    EN_terminalError_t result1 = isBelowMaxAmount(&termData1);
    printf("Actual Result: %s\n", (result1 == TERMINAL_OK) ? "TERMINAL_OK" : "EXCEED_MAX_AMOUNT");
    if (result1 == EXCEED_MAX_AMOUNT)
    {
        printf("Result: Passed\n");
    }
    else
    {
        printf("Result: Failed\n");
    }
    printf("\n");


}

/*----------------------------------------------------------------------------------*/

void setMaxAmountTc()
{

    {
        printf("\nTester Name: Ahmed Seddik\n");
        printf("Function Name: setMaxAmount\n");
        printf("\nTest Case 1:\n");

        printf("Input Data: maxAmount = 1000.0\n");
        printf("Expected Result: TERMINAL_OK\n");

        ST_terminalData_t termData;
        termData.maxTransAmount = 0.0;
        EN_terminalError_t result1 = setMaxAmount(&termData, 1000.0);
        printf("Expected Result: TERMINAL_OK\n");
        printf("Actual Result: %s\n", (result1 == TERMINAL_OK) ? "TERMINAL_OK" : "INVALID_MAX_AMOUNT");
        if (result1 == TERMINAL_OK)
        {
            printf("Result: Passed\n");
        }
        else
        {
            printf("Result: Failed\n");
        }
        printf("\n");

    }


    {
        printf("\nTester Name: Ahmed Seddik\n");
        printf("Function Name: setMaxAmount\n");
        printf("\nTest Case 2:\n");

        printf("Input Data: maxAmount = 0.0\n");
        printf("Expected Result: INVALID_MAX_AMOUNT\n");
        ST_terminalData_t termData1;
        EN_terminalError_t result2 = setMaxAmount(&termData1, 0.0);
        printf("Actual Result: %s\n", (result2 == INVALID_MAX_AMOUNT) ? "INVALID_MAX_AMOUNT" : "TERMINAL_OK");
        if (result2 == INVALID_MAX_AMOUNT)
        {
            printf("Result: Passed\n");
        }
        else
        {
            printf("Result: Failed\n");
        }
        printf("\n");
    }
}
