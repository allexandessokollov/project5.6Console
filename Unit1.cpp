//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int const MAX_ARRAY_SIZE = 14;
int const MAX_RANDOM_VALUE = 15;
int const MIN_RANDOM_VALUE = -5;
int const FAILED_SEARCH = -1;

int findSequenceSumm(int arr[], int firstNeg, int secondNeg);
int findNegNumberIndex(int arr[], int startIndex, int arrSize);
void fillArrKeyboard(int arr[], int arrSize);
void fillArrRandomly(int arr[], int arrSize);




int main()
{
    int arrSize, fNeg, sNeg, answer, userChoice;

    do
    {
    printf("Enter array size\n"
    "Size of array should be more than 0 and less than %d\n", MAX_ARRAY_SIZE);

    scanf("%d", &arrSize);

    } while(arrSize < 0 || arrSize > MAX_ARRAY_SIZE);

    int *arr = new int[arrSize];

    printf("\nTo fill array using keybord press 1\nTo fill array randomly press 2\n");

    scanf("%d", &userChoice);


    switch(userChoice)
    {
    case 1:
        fillArrKeyboard(arr, arrSize);
        break;
    case 2:
        fillArrRandomly(arr, arrSize);
        break;
    }


    printf("\n\n");

    for(int i = 0; i < arrSize; i++)
    {
        printf(" %d | ", arr[i]);
    }
    printf("\n\n");


    fNeg = findNegNumberIndex(arr, 0, arrSize);

    if(fNeg == FAILED_SEARCH)
    {
        printf("\n\nthere is no negative numbers\nrestart application\n\n");
    }
    else
    {
        sNeg = findNegNumberIndex(arr, fNeg + 1, arrSize);

        if(sNeg == FAILED_SEARCH)
        {
        printf("\n\nthere is no second negative number\nrestart application\n\n");
        }
        else
        {
            if((sNeg - fNeg) <= 1)
            {
                printf("\n\nthere is no elements between\nrestart application\n\n");
            }
            else
            {
                answer = findSequenceSumm(arr, fNeg, sNeg);

                printf("answer is: %d\n\n", answer);
            }
        }
    }
    


    puts("\n\n\nPress any key ... ");
    getch();
    getch();

    delete []arr;

    return 0;
}


int findNegNumberIndex(int arr[], int startIndex, int arrSize)
{
    for(int i = startIndex; i < arrSize; i++)
    {
        if(arr[i] < 0)
            return i;
    }

    return  FAILED_SEARCH;
}

int findSequenceSumm(int arr[], int firstNeg, int secondNeg)
{
    int answer = 0;

    for(int i = firstNeg + 1; i < secondNeg; i++)
    {
        answer += arr[i];
    }

    return answer;
}

void fillArrKeyboard(int arr[], int arrSize)
{

    for(int i = 0; i < arrSize; i++)
    {
        printf("Enter element number %d \n", i);
        scanf("%d", &arr[i]);
    }

}

void fillArrRandomly(int arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        arr[i] = random(MAX_RANDOM_VALUE - MIN_RANDOM_VALUE) + MIN_RANDOM_VALUE;
    }
}
//-------------------------------------------------------------------
