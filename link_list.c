#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	node *link;
};
 int main()

{  int ch,a;

	while(1)
	{
		printf("1.Create a link list\n");
		printf("2.insert a node\n");
		printf("3.Display\n");
		printf("4.exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: struct node *start ;
			        start = (struct node*)malloc(sizeof(struct node));
			        start->link=NULL;
			        printf("enter data\n");
			        scanf("%d", &start->data);
              break;

            case 2: printf("1.at beg\n");
                    printf("2.at end\n");
                    scanf("%d", &a);

                   
                    	struct node *temp;
                    	temp=(struct node*)malloc(sizeof(struct node));
                    	printf("enter data\n");
                    	scanf("%d", &temp->data);

                    	if(a==1)
                    	{
                    	temp->link=start;
                    	start=temp;
                       }

                    else
                    {
                       start->link=temp;
                       temp->link=NULL;
                    }
                    break;

                    case 3: struct node *n;
                            n=start;
                            while(n->link!=NULL)
                           {
                             printf("%d", n->data);
                             n=n->link;
                           }
                           break;

              case 4: exit(0);
                     break;      
              
		}

	}
	return 0;
}