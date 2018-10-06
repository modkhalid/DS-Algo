
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int stack[100],top=-1,ch,element,size,count_push=0, count_pop=0;

	printf("Enter the size of Stack\n");
	scanf("%d", &size );

 while(true)
  {	
	printf("\nMenu\n");
	printf("1.Push an Element\n");
	printf("2.Pop an Element\n");
	printf("3.Display Current Stack\n");
	printf("4.Exit\n");

	scanf("%d",&ch );

	switch(ch)
	{
		case 1: if(top==(size-1))
		         printf("Overflow..!!");

		         else
		         {
		         	top++;
		         	printf("Enter the Element\n");
		         	scanf("%d", &stack[top]);
		         	count_push++;
		         }
		         break;

		case 2: if(top==-1)
		         printf("Underflow..!!");
		         else
		         {
		         	top--;
		         	count_pop++;
		         }
		         break;

		case 3: if(top==-1)
		        printf("UnderFlow..!!");

		        else
		        { 
		        	printf("Current Stack is:\n");

                   for(int i=top; i>=0; i--)
                   	printf("%d \n", stack[i]); 

                    printf("Number of push: %d \n", count_push);
                    printf("Number of pop: %d \n", count_pop);
		        }                  

		        break;
		case 4: exit(0);
		        break;

		default: printf("Wrong Choice\n");  
		        break;              
	}

  }
        return 0;
}