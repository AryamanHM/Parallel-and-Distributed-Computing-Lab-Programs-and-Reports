#include<stdio.h> 
#include<omp.h>

void main()
{
int a[]={1,2,3,4,5};
int cube=0;
 int i;
#pragma omp parallel for lastprivate(cube) 
for(i=0;i<5;i++){
cube = a[i]*a[i]*a[i]; printf("%d\n",cube);
}
printf("\n%d: cube is the max.",cube);
}

