//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int findSequenceSumm(int arr[], int firstNeg, int secondNeg);
int findNegNumberIndex(int arr[], int startIndex, int arrSize);
void fillArrKeyboard(int arr[], int arrSize);
void fillArrRandomly(int arr[], int arrSize);


int const MAX_ARRAY_SIZE = 14;

int main()
{
    int arrSize, fNeg, sNeg, answer, toFillArr;

    printf("Enter array size\n");
    scanf("%d", &arrSize);

    while(arrSize < 0 || arrSize > MAX_ARRAY_SIZE)
    {
        printf("Size of array should be more than 0 and less than 14\n");
        scanf("%d", &arrSize);
    }

    int *arr = new int[arrSize];
    
    printf("\nTo fill array using keybord press 1\nTo fill array randomly press 2\n");

    scanf("%d", &toFillArr);


    randomize();
    switch(toFillArr)
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


    fNeg = findNegNumberIndex(arr, 0, arrSize);;
    sNeg = findNegNumberIndex(arr, fNeg + 1, arrSize);

    if((sNeg - fNeg) <= 1)
    {
        printf("\n\nthere is no elements between\nrestart application\n\n");

        puts("\n\n\nPress any key ... ");
        getch();
        getch();

        return 0;
    }
    else
    {
        answer = findSequenceSumm(arr, fNeg, sNeg);

        printf("answer is: %d\n\n", answer);
    }


    puts("\n\n\nPress any key ... ");
    getch();
    getch();

    return 0;
}


int findNegNumberIndex(int arr[], int startIndex, int arrSize)
{
    int ifWasntFind = -1;

    for(int i = startIndex; i < arrSize; i++)
    {
        if(arr[i] < 0)
            return i;
    }

    return  ifWasntFind;
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
    const int toRandom = 20,
    toRandomCorrection = -5;
    for(int i = 0; i < arrSize; i++)
    {
        arr[i] = random(toRandom) + toRandomCorrection;
    }
}
//-------------------------------------------------------------------
 