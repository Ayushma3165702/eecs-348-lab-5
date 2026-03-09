#include <stdio.h>

int main() {

    char *months[12] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };

    float sales[12] = {
        23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,
        72400.31,56210.89,67230.84,68233.12,80950.34,95225.22
    };

    printf("Monthly Sales Report\n");
    printf("-------------------------\n");

    for(int i=0;i<12;i++){
        printf("%-10s $%.2f\n",months[i],sales[i]);
    }

    float min=sales[0];
    float max=sales[0];
    float sum=0;
    int minIndex=0;
    int maxIndex=0;

    for(int i=0;i<12;i++){

        sum+=sales[i];

        if(sales[i]<min){
            min=sales[i];
            minIndex=i;
        }

        if(sales[i]>max){
            max=sales[i];
            maxIndex=i;
        }

    }

    printf("\nSales Summary\n");
    printf("-------------------------\n");

    printf("Minimum Sales: %s $%.2f\n",months[minIndex],min);
    printf("Maximum Sales: %s $%.2f\n",months[maxIndex],max);
    printf("Average Sales: $%.2f\n",sum/12);

    printf("\nSix-Month Moving Average\n");
    printf("-------------------------\n");

    for(int i=0;i<=6;i++){

        float avg=0;

        for(int j=i;j<i+6;j++){
            avg+=sales[j];
        }

        avg/=6;

        printf("%s - %s : $%.2f\n",months[i],months[i+5],avg);
    }

    printf("\nSales Highest to Lowest\n");
    printf("-------------------------\n");

    float tempSales[12];
    char *tempMonths[12];

    for(int i=0;i<12;i++){
        tempSales[i]=sales[i];
        tempMonths[i]=months[i];
    }

    for(int i=0;i<11;i++){
        for(int j=i+1;j<12;j++){

            if(tempSales[j]>tempSales[i]){

                float t=tempSales[i];
                tempSales[i]=tempSales[j];
                tempSales[j]=t;

                char *m=tempMonths[i];
                tempMonths[i]=tempMonths[j];
                tempMonths[j]=m;

            }

        }
    }

    for(int i=0;i<12;i++){
        printf("%-10s $%.2f\n",tempMonths[i],tempSales[i]);
    }

    return 0;
}
