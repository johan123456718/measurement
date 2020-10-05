#include <stdio.h>
#define MAX 10

void viewMeasurement(int array[], int nrOfMeasurement);
int enterMeasurement(int array[], int nrOfMeasurement);
void computeMeasurement(int array[], int nrOfMeasurement);
int maxValue(int array[], int nrOfMeasurement);
int minValue(int array[], int nrOfMeasurement);
float averageValue(int array[], int nrOfMeasurement);
void normalizeValue(int array[], int nrOfMeasurement);
int resetMeasurement(int array[], int nrOfMeasurement);

int main(void){
    char choice, tmp;
    int array[MAX] = {0};
    int nrOfMeasurement = 0;
    
    printf("---------------------------------\n");
    printf("v (View) - visar vilka mätvärden som finns lagrade\n");
    printf("e (Enter) - tillåter användaren att lägga till mätvärden\n");
    printf("c (Compute) - presenterar max, min, medelvärde och normaliserade mätvärden\n");
    printf("r (Reset) - raderar alla inmatade mätvärden\n");
    printf("q (Quit) - avslutar programmet");
    printf("\n---------------------------------\n");
    
    do{
        printf("\nVECRQ? ");
        scanf(" %c", &choice);

        switch(choice){
            case 'v':
                viewMeasurement(array, nrOfMeasurement);
            break;

            case 'e':
                nrOfMeasurement = enterMeasurement(array, nrOfMeasurement);
            break;
            
            case 'c':
                computeMeasurement(array, nrOfMeasurement);
            break;

            case 'r':
               nrOfMeasurement = resetMeasurement(array, nrOfMeasurement);
            break;

            case 'q':
            printf("QUIT\n");
            break;

            default: 
            printf("This option doesn't exist\n");
        }

    }while(choice != 'q');
}

void viewMeasurement(int array[], int nrOfMeasurement){
    printf("[");
     if(nrOfMeasurement == 0){
            printf(" NO MEASUREMENT ");
        }

    for(int i = 0; i < nrOfMeasurement; i++){
        printf("%d,", array[i]);
    }
    printf("]");
}

int enterMeasurement(int array[], int nrOfMeasurement){
    
    for(; nrOfMeasurement < MAX; nrOfMeasurement++){
        printf("Enter measurement #%d (or 0) ? ", nrOfMeasurement+1);
        scanf("%d", &array[nrOfMeasurement]);
        if(array[nrOfMeasurement] == 0){
            break;
        }
    }
    return nrOfMeasurement;
}

void computeMeasurement(int array[], int nrOfMeasurement){
    int max, min;
    float average;
    printf("Max value: %d\n", max = maxValue(array, nrOfMeasurement));
    printf("Min value: %d\n", min = minValue(array, nrOfMeasurement));
    printf("Average value: %.2f\n", average = averageValue(array, nrOfMeasurement));
    normalizeValue(array, nrOfMeasurement);
}

int maxValue(int array[], int nrOfMeasurement){
    int maxVal = array[0];

    for(int i = 0; i < nrOfMeasurement; i++){
        if(maxVal < array[i]){
            maxVal = array[i];
        }
    }
    return maxVal;
}

int minValue(int array[], int nrOfMeasurement){
    int minVal = array[0];

    for(int i = 0; i < nrOfMeasurement; i++){
        if(minVal > array[i]){
            minVal = array[i];
        }
    }
    return minVal;
}

float averageValue(int array[], int nrOfMeasurement){
    float sum = 0, averageVal;
    for(int i = 0; i < nrOfMeasurement; i++){
            sum += array[i];
            averageVal = sum / (nrOfMeasurement);
    }
    return averageVal;
}

void normalizeValue(int array[], int nrOfMeasurement){
    int tmpArray[MAX];
    printf("[");
    for(int i = 0; i < nrOfMeasurement; i++){
        tmpArray[i] = array[i];
        tmpArray[i] -= averageValue(array, nrOfMeasurement);
        printf("%d,", tmpArray[i]);
    }
    printf("]");
    printf("\n");
}

int resetMeasurement(int array[], int nrOfMeasurement){

    for(int i = 0; i < nrOfMeasurement; i++){
        array[i] = 0;
    }
    return nrOfMeasurement = 0;
}