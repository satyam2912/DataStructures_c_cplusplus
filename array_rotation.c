#include <stdio.h>
#include <stdlib.h>
int main()
{
int n,i,j=0,m, first,*a;
printf("Enter no of array elements:\n");
scanf("%d" ,&n);
a = (int*)malloc(n*sizeof(int));
printf("Enter no of array rotation:\n");
scanf("%d" ,&m);
printf("Enter array elements:\n");
for (i=0 ; i <n ; i++){
scanf("%d" , &a[i]);
}
while(j<m){
    first=a[0];
        for (i=0 ; i<n ;i++)
            {
                a[i]=a[i+1];
            }
    a[n-1] = first;
    j++;
}
for(i=0 ; i <n ; i++)
{
    printf("%d " , a[i]);
}
free(a);
   return 0;
}