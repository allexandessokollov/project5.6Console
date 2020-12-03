//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>




int countAnswer(int arr[], int firstNeg, int secondNeg);
int secondNeg(int arr[], int arrSize);
int firstNeg(int arr[], int arrSize);
void fillArrKeyboard(int arr[], int arrSize);
void fillArrRandomly(int arr[], int arrSize);


int const maxArraySize = 14;

int coloseApp()
{
    int forClosing = 1;
    while (forClosing == 1)
    {
        printf("Enter 0 to close\n");
        scanf("%d", &forClosing);
    }

    return forClosing;
}

int main(int argc, char* argv[])
{


    int arrSize, fNeg, sNeg, answer, toFillArr;

    printf("Enter array size\n");
    scanf("%d", &arrSize);

    while(arrSize < 0 || arrSize > maxArraySize)
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


    fNeg = firstNeg(arr, arrSize);
    sNeg = secondNeg(arr, arrSize);


    if((sNeg - fNeg) <= 1)
    {
        
        printf("\n\nthere is no elements between\nrestart application\n\n");
        int forClosing = coloseApp();

        if(forClosing == 0)
        {
            return 0;
        }
    }
    else
    {
        answer = countAnswer(arr, fNeg, sNeg);
        printf("answer is: %d\n\n", answer);
    }





    
    int forClosing = coloseApp();
    return 0;
}







int firstNeg(int arr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] < 0)
        {
            return i;
        }
    }

    return -1;
}

int secondNeg(int arr[], int arrSize)
{

    bool isFirst = false;

    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] < 0 && isFirst == false)
        {
            isFirst = true;
        }
        else if(arr[i] < 0 && isFirst)
        {
            return i;
        }
    }

    return -1;    //TODO: Add your source code here
}

int countAnswer(int arr[], int firstNeg, int secondNeg)
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
        arr[i] = random(20) - 10;
    }
}
//-------------------------------------------------------------------
 