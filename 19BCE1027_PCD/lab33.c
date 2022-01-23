#include<omp.h> #include<stdio.h> #define N 3
void main(){
int i;
float a[N],b[N],c[N],d[N],e[N]; for(i=0;i<N;i++)
{
a[i]=i*1.5;
b[i]=i+22.35;
}

#pragma omp sections
{
#pragma omp section for(i=0;i<N;i++){
c[i]=a[i]+b[i];
printf("\n addition of %0.2f + %0.2f = %0.2f ",a[i],b[i],c[i]);
}


#pragma omp section for(i=0;i<N;i++){
d[i]=a[i]*b[i];
printf("\n Multiplication of %0.2f and %0.2f = %0.2f
",a[i],b[i],d[i]);
}

#pragma omp section for(i=0;i<N;i++){
e[i]=a[i]-b[i];
printf("\nSubtraction of %0.2f and %0.2f = %0.2f
",a[i],b[i],e[i]);
}
}
}

