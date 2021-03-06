#include <stdio.h>
#include <limits.h>

//delete character in buffer memory
void clean() {
    while (getchar() != '\n');
}
// get valid size of array (return positive number)
int getValidSize(int min, int max, const char* error) {
    int inputNumber;
    int check;
    char inputChar;
    while (1) {
        check = scanf("%d%c", &inputNumber, &inputChar);
        if (check != 2 || inputChar != '\n') {
        	clean();
            printf("%s", error);
        } else if (inputNumber < min || inputNumber > max)
            printf("Please input number form %d to %d: ", min, max);
        else return inputNumber;
    }
}
// get valid element(return number)
long long int getValidElement(const char* error,int position) {
    long long int inputNumber;
    int check;
    char inputChar;
    while (1) {
        printf("Element[%d]=",position);
        check = scanf("%lld%c", &inputNumber, &inputChar);
        if (check != 2 || inputChar != '\n') {
        	clean();
            printf("%s", error);
        }
        else return inputNumber;
    }
}
void changeSize(int sizeArray,int **array)
{
    *array = realloc(*array, (sizeArray) * sizeof (long long int));
}
//user's input
void input(int *sizeArray,long long int *array)
{
    printf("Please enter size of array: ");
    *sizeArray=getValidSize(0,INT_MAX,"Invalid size of array!! Just enter integer: ");
    changeSize(sizeArray,&array);
    int i;
    for (i=0;i<*sizeArray;i++)
    {
        array[i]=getValidElement("Invalid element!! Just enter integer:\t",i);
    }
    for (i=0;i<*sizeArray;i++)
        printf("\n---%d----",array[i]);
}
//print array to screen
void output(int sizeArray,long long int *array)
{
    int i;
    printf("\n");
    for (i=0;i<sizeArray;i++){
        printf("%lld\t",array[i]);
    }
    printf("\n");
}
int main()
{
    int sizeArray;
    long long int *array;
    array=(long long int *)malloc(sizeof(long long int));
    input(&sizeArray,array);
    output(sizeArray,array);
    return 0;
}

