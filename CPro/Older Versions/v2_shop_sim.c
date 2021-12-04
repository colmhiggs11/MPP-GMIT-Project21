#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Product{
	char* name;
	double price;
};

struct ProductStock{
	struct Product product;
	int quantity;
};

struct Customer{
	char* name;
	double budget;
	struct ProductStock shoppingList[20];
	int index;
};

struct Shop {
	double cash;
	struct ProductStock stock[20];
	int index;

};

void printProduct(struct Product p)
{
	printf("Product Name: %s\nProduct Price: %.2f\n",p.name, p.price);
	printf("--------------------\n");
}

void printCustomer(struct Customer c)
{
	printf("Customer Name: %s\nCustomer Budget: %.2f\n",c.name, c.budget);
	printf("--------------------\n");
	for(int i=0; i<c.index; i++)
	{
		printProduct(c.shoppingList[i].product);
		printf("%s Orders %d of above Product\n", c.name,c.shoppingList[i].quantity);
		double cost = c.shoppingList[i].quantity* c.shoppingList[i].product.price;
		printf("The cost to %s will be €%.2f\n",c.name, cost);
	}
}

struct Shop createAndStockShop()
{
	struct Shop shop = {200};
	FILE * fp;
	char * line =NULL;
	size_t len =0;
	ssize_t read;
	
	fp =fopen("../stockc.csv","r");
	if(fp==NULL)
		exit(EXIT_FAILURE);
	
	// Need to add in the code to get to print the cash of the shop
	
	
	while ((read = getline(&line, &len, fp)) !=-1) {

		char* n = strtok(line,",");
		char* p = strtok(NULL,",");
		char* q = strtok(NULL,",");
		int quantity = atoi(q);
		double price = atof(p);
		char *name = malloc(sizeof(char) * 50);
		strcpy(name,n);
		struct Product product = {name,price};
		struct ProductStock stockItem = {product,quantity};
		shop.stock[shop.index++] = stockItem;
	

		 // printf("Name of Product %s Price %.2f Quantity %d\n",name,price,quantity);
	}
	return shop;
}

void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	for (int i=0; i<s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above\n\n",s.stock[i].quantity);
	}
}

void askName()
{
	fflush(stdin);
	printf("What is your name?\n");
	char name[10];
	fgets(name,10,stdin);
	printf("Glad to meet you, %s\n",name);
}

void clrscr()
{
    system("cls||clear");
}

int main(void)
{	

	//struct Shop shop =  createAndStockShop();
	//printShop(shop);
	
	
	
// https://stackoverflow.com/questions/42430351/simple-menu-in-c
// https://www.studytonight.com/c/programs/misc/menu-driven-program

	// int choice = -1;

	// while (choice != 0){
		
		// printf("\nOption 1: (1) ");
		// printf("\nOption 2: (2) ");
		// printf("\nOption 3: (3) ");
		// printf("\nEXIT: (0) ");

		// fflush(stdin);
		// printf("\nPlease choose an option ");
		// scanf("%d", &choice);


		// case 1:
			// if(input==1)
			// {
				// clrscr();
				// products();
			// }
		// if (choice == 1)
		// {
			// printf("The user pressed 1\n");
		// } else if (choice == 2){
			// printf("here we can do something else");
		// } else if (choice == 3){
			// askName();
		// }
	// }
	// printf("Buh bye");
    int choice, num, i;
    unsigned long int fact;
    while(1)
    {
		printf("\n######   Colms Shop in c   ######\n\n");
        printf("\t1. Option1 \n");
        printf("\t2. Option2\n");
        printf("\t3. Option3\n");
        printf("\t4. Exit the shop!\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
				clrscr();
                printf("OPTION 1\n");
                printf("Enter number:\n");
                scanf("%d", &num);
                fact = 1;
                for(i = 1; i <= num; i++)
                {
                    fact = fact*i;
                }
                printf("\n\nFactorial value of %d is = %lu\n\n\n",num,fact);
                break;
        
            case 2:
				clrscr();
                printf("OPTION 2\n");
                printf("Enter number:\n");
                scanf("%d", &num);
                if(num == 1)
                printf("\n1 is neither prime nor composite\n\n");
                    {
                        printf("\n%d is not a prime number\n\n", num);
                        break;
                    }
					break;
   
                
        
            case 3:
				clrscr();
                printf("OPTION 3\n");
                printf("Enter number:\n");
                scanf("%d", &num);
        
                if(num%2 == 0) // 0 is considered to be an even number
                    printf("\n\n%d is an Even number\n\n",num);
                else
                    printf("\n\n%d is an Odd number\n\n",num);
                break;
        
            case 4:
				clrscr();
                printf("\n\nExiting the shop , Thanks for shopping here, please come again!\n");
                exit(0);    // terminates the complete program execution
        }
    }
	return 0;
}