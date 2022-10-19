	#include<stdio.h>
int main()
{
	int i,n,key,flag=0,arr[10],c=0;
	printf("Enter the limit: \n");
	c++;
	scanf("%d",&n);
	c++;
	
	printf("Enter the elements \n");
	c++;
	
	for(i=0;i<n;i++)
		{
		c++;
		 scanf("%d",&arr[i]);
		}
		c++;
	
	printf("\n enter the search element\n");
	c++;
	scanf("%d",&key);
	c++;
	
	for(i=0;i<n;i++)
	 {
	 c++;
	  if(arr[i]==key)
		{
		c++;
		 flag=1;
		 break;
		 c++;
		}
			
	 }
	 c++;
	 if(flag==1)
	    {
	    c++;
	    printf("\n The element %d is found at %d",key,i+1);
	    c++;
	    }
	 else
	 {
	  c++;
	   printf("\n Element not found");
	   c++;
	   }
	   
	   printf("\n space complexity=%d \n",20+(4*n));
	   c++;
	printf("Time complexity=%d\n",c);
	
}
