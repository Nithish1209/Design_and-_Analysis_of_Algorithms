#include<stdio.h>
int main(){
int i,j,n;
printf("Enter the size of array : ");
scanf("%d",&n);
int a[n];
printf("Enter the array elements");
for(i=0; i<n; i++)
{
scanf("%d",&a[i]);

}

int min =a[0];
int max=a[0];
for(j=0; j<n; j++)
{
	 if(min>a[j])
	 {
	 	 min=a[j];
	 }
	 
	 if(max<a[j])
	 {
	 	 max=a[j];
	 }
	 
	 
}

printf("The max ele : %d",max);
printf("\n The min ele : %d",min);


}
