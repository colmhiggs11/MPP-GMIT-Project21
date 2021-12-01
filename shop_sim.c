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
	
	fp =fopen("stock.csv","r");
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

int main(void)
{	

	struct Shop shop =  createAndStockShop();
	printShop(shop);
	
	
	return 0;
}