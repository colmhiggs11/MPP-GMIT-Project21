from dataclasses import dataclass, field
from typing import List
import csv

@dataclass
class Product:
    name: str
    price: float = 0.0
    
@dataclass
class ProductStock:
    product: Product
    quantity: int
    
@dataclass
class Shop:
    cash: float = 0.0
    stock: List[ProductStock] = field(default_factory=list)
    
@dataclass
class Customer:
    name: str = ""
    budget: float = 0.0
    shopping_list: List[ProductStock] = field(default_factory=list)
    
def create_and_stock_shop():
    s = Shop()
    
    ## ADD Null check here ##
    with open('../stockp.csv') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        first_row = next(csv_reader)
        s.cash = float(first_row[0])
        
        for row in csv_reader:
            p = Product(row[0], float(row[1]))
            ps = ProductStock(p, float(row[2]))
            s.stock.append(ps)
            # print(ps)
    return s
    
def read_customer(file_path):
    with open(file_path) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        first_row = next(csv_reader)
        c = Customer(first_row[0], float(first_row[1]))
        for row in csv_reader:
            name = row[0]
            quantity = float(row[1])
            p = Product(name)
            ps = ProductStock(p, quantity)
            c.shopping_list.append(ps)
        return c

def print_product(p):
    print(f'\nProduct name: {p.name} \nProduct Price: {p.price}')
    
def print_customer(c):
    print(f'Customer name: {c.name} \nCustomer Budget: {c.budget}')

    for item in c.shopping_list:
        print_product(item.product)
        
        print(f'{c.name} Orders {item.quantity} of above Product')
        cost = item.quantity * item.product.price
        print(f'The cost to {c.name} will be €{cost}')
        
def print_shop(s):
    print(f'Shop has {s.cash} in cash')
    for item in s.stock:
        print_product(item.product)
        print(f'The shop has {item.quantity} of the above')
        
        
# s = create_and_stock_shop()
# print_shop(s)
#c = read_customer("../Customer_b.csv")
#print_customer(c)


#Main function to run application
def main_menu():

# Menu display and choice inputs
    while True:
        display_menu()
        choice = input("Choice: ")

        if (choice=="1"):

            main_menu()
            
        if (choice=="2"):
             main_menu()
                   
        elif (choice=="3"):
            main_menu() 
            
        elif (choice=="4"):
            main_menu()
          
        elif (choice=="5"):
            main_menu()                
      
        elif (choice=="6"):  
            main_menu()
            
        elif (choice=="x"):
            print(f'Exiting')
            quit()
        
        else:
            main_menu()
            
            
def display_menu():
  print("\nMovies DB\n--------\n")
  print("MENU\n====")
  print("1 - View Films")
  print("2 - View Actors by Year of Birth & Gender")
  print("3 - View Studios")
  print("4 - Add New Country")
  print("5 - View Movie with Subtitles")
  print("6 - Add New MovieScript")
  print("x - Exit application")

if __name__  == "__main__":
    main_menu()  
  
