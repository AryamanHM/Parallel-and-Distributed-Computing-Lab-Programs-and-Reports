#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <omp.h>
void main()
{
    int count = 0,c = 0, i, j = 0, k, space = 0;
    char str[100], p[50][100], str1[20], ptr1[50][100];
    char *ptr;
    printf("Enter the text file\n");
    //FILE * file = fopen("test.txt", "r"); 
    //fscanf(file, " %lf\n", &Data[i]); 
    //printf("%f\n", Data[i]); 
    //fclose(file);
    scanf(" %[^\n]s", str);
    int nthreads,tid;
    omp_set_num_threads(2);
    #pragma omp parallel private(tid)
    {
    	tid=omp_get_thread_num();
    for (i = 0;i<strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == ',' && str[i+1] == ' ')||(str[i] == '.'))
        {
            space++;
        }
    }
    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
    {
        if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
        {    
            p[i][k] = '\0';
            i++;
            k = 0;
        }        
        else
             p[i][k++] = str[j];
    }
 
    k = 0;
    for (i = 0;i <= space;i++)
    {
        for (j = 0;j <= space;j++)
        {
            if (i == j)
            {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;
 
                break;
            }
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
    for (i = 0;i < count;i++) 
    {
        for (j = 0;j <= space;j++)
        {
            if (strcmp(ptr1[i], p[j]) == 0)
                c++;
        }
        printf("%s -> %d times from thread=%d\n", ptr1[i], c,tid);
        c = 0;
        if(tid==0)
        {
        	nthreads=omp_get_num_threads();
        	printf("Number of threads=%d\n",nthreads);
		}
    }
}
}

