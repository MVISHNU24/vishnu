#include <stdio.h>
#include <stdlib.h>

int *generator,*data;
int generator_length,data_length,i;

int xor(int a,int b)
{
    if (a == b)
    {
        return 0;
    }
    return 1;
}

void CRC()
{
    int cur = 0;

    while (cur < data_length)
    {
        if (data[cur] == 0)
        {
            cur++;
            continue;
        }

        for ( i = 0; i < generator_length; i++)
        {
            data[cur+i] = xor(data[cur+i],generator[i]);
        }
    }
    
    for ( i = data_length; i < data_length+generator_length-1; i++)
    {
        printf(" %d ",data[i]);
    }
}

void main()
{
    
    printf("Enter the generator length and data length:\t");
    scanf("%d %d",&generator_length,&data_length);

    generator = (int *)malloc(sizeof(int)*generator_length);
    data = (int *)malloc(sizeof(int)*(data_length+generator_length-1));

    printf("Enter the generator:\t");
    for ( i = 0; i < generator_length; i++)
    {
        scanf("%d",&generator[i]);
    }

    printf("Enter the Data:\t");
    for ( i = 0; i < data_length; i++)
    {
        scanf("%d",&data[i]);
    }
    for ( i = data_length;i < data_length+generator_length-1;i++)
    {
        data[i] = 0;
    }
    
    CRC();

    free(generator);
    free(data);
}
