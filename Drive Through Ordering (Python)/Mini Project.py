import time
import datetime

EXIT_SYSTEM = "Q"           # Code to exit system
SYSTEM_SHUTDOWN = 3         # Time delay before clearing screen to shutdown system
REENTER_INPUT = 2           # Time delay before clearing screen to show same menu again
PAYMENT_TO_MAINMENU = 5     # Time delay between showing payment done message and returning to Main Menu
CANCEL_TO_MAINMENU = 5      # Time delay between showing payment cancel message and returning to Main Menu
CONTINUE_TO_MAINMENU = 2    # Time delay between showing continue with order message and returning to Main Menu
total_cost = 0              # Total amount to be paid by customer for his placed orders

def cls(): 
    print ("\n" * 100)      # Displays 100 empty new lines to clear screen

def display_main_menu(exit_code):
    loop = True    
    while (loop == True):
        cls()        
        print(" --------------------------------------------------- ")
        print("|             McKay Fast Food Drive Thru            |")
        print("|              Takeaway Ordering System             |")
        print(" --------------------------------------------------- ")
        print("Welcome to our drive through takeway ordering system!")
        print("1) Promotions")
        print("2) Combo Sets")
        print("3) Kids' Meals")
        print("4) A la Carte")
        print("5) Drinks Only")        
        choice = input("Please select one of the above:- ").upper()
        if (choice == "1") or (choice == "2") or (choice == "3") or (choice == "4") or (choice == "5"):
            loop = False
        elif(choice == exit_code):      # Staff uses this hidden choice to exit the system
            print(f"\nSystem will auto shutdown in {SYSTEM_SHUTDOWN} seconds. Thank you and have a nice day. ", end = "")
            countdown(SYSTEM_SHUTDOWN)                       
            cls()
            loop = False            
        else:            
            print("Invalid choice. Please choose between 1 to 5.\n")            
            choice = 0
            time.sleep(REENTER_INPUT)
    return choice

def display_promo_menu():    
    loop = True
    while (loop == True):
        cls()
        print("\n~~~~~~~~~~~~~~~~~~   Promotions   ~~~~~~~~~~~~~~~~~~")
        print("1) Buddy Chicken Burger Combo --------------> $9.00")
        print("2) Buddy Fish Burger Combo -----------------> $10.00")
        print("3) Buddy Chicken Fish Burger Combo ---------> $10.00")
        print("4) Family-of-4 Chicken Burger Combo --------> $18.00")
        print("5) Family-of-4 Fish Burger Combo -----------> $20.00")
        print("6) Family-of-4 Chicken Fish Burger Combo ---> $19.00")
        choice = input("Please select one of the above:- ")
        if (choice == "1") or (choice == "2") or (choice == "3") or (choice == "4") or (choice == "5") or (choice == "6"):
            loop = False
        else:
            print("Invalid choice. Please choose between 1 to 6.\n")
            time.sleep(REENTER_INPUT)   # Delay the system to allow user to have enough time to read the error message
    return choice

def display_combo_menu():    
    loop = True
    while (loop == True):   
        cls()
        print("\n~~~~~~~~~~~~~   Combo Sets   ~~~~~~~~~~~~")
        print("1) Chicken Burger Combo ----------> $5.00")
        print("2) Double Chicken Burger Combo ---> $7.00")
        print("3) Fish Burger Combo -------------> $5.50")
        print("4) Double Fish Burger Combo ------> $7.50")
        print("5) Beef Burger Combo -------------> $6.00")
        print("6) Double Beef Burger Combo ------> $8.00")
        choice = input("Please select one of the above:- ")
        if (choice == "1") or (choice == "2") or (choice == "3") or (choice == "4") or (choice == "5") or (choice == "6"):
            loop = False
        else:
            print("Invalid choice. Please choose between 1 to 6.\n")
            time.sleep(REENTER_INPUT)   # Delay the system to allow user to have enough time to read the error message
    return choice

def display_kids_menu():    
    loop = True
    while (loop == True):
        cls()
        print("\n~~~~~~~~~~~   Kids' Meals   ~~~~~~~~~~")
        print("1) Chicken Nuggets 4pc Meal ---> $4.00")
        print("2) Fish Nuggets 4pc Meal ------> $4.20")
        print("3) Cheese Burger Meal ---------> $3.50")        
        choice = input("Please select one of the above:- ")
        if (choice == "1") or (choice == "2") or (choice == "3"):
            loop = False
        else:
            print("Invalid choice. Please choose between 1 to 3.\n")
            time.sleep(REENTER_INPUT)   # Delay the system to allow user to have enough time to read the error message
    return choice

def display_alacarte_menu():    
    loop = True
    while (loop == True):
        cls()
        print("\n~~~~~~~~~~   A la Carte   ~~~~~~~~~")
        print("1) Chicken Burger ----------> $3.00")
        print("2) Double Chicken Burger ---> $4.00")
        print("3) Fish Burger -------------> $3.20")
        print("4) Double Fish Burger ------> $4.20")
        print("5) Beef Burger -------------> $3.50")
        print("6) Double Beef Burger ------> $4.50")
        choice = input("Please select one of the above:- ")
        if (choice == "1") or (choice == "2") or (choice == "3") or (choice == "4") or (choice == "5") or (choice == "6"):
            loop = False
        else:
            print("Invalid choice. Please choose between 1 to 6.\n")
            time.sleep(REENTER_INPUT)   # Delay the system to allow user to have enough time to read the error message
    return choice

def display_drink_menu():    
    loop = True
    while (loop == True):
        cls()
        print("\n~~~~~~~~   Drinks only   ~~~~~~~~")
        print("1) Coffee (Hot) ----------> $0.90")
        print("2) Tea (Hot) -------------> $0.80")
        print("3) Lemonade (Cold) -------> $1.00")
        print("4) Orange Juice (Cold) ---> $1.00")
        print("5) Coke (Cold) -----------> $1.20")
        print("6) Root Beer (Cold) ------> $1.20")
        choice = input("Please select one of the above:- ")
        if (choice == "1") or (choice == "2") or (choice == "3") or (choice == "4") or (choice == "5") or (choice == "6"):
            loop = False        
        else:
            print("Invalid choice. Please choose between 1 to 6.\n")
            time.sleep(EENTER_INPUT)    # Delay the system to allow user to have enough time to read the error message
    return choice

def chkout_cont_proceed_cancel_error_check(selection):
    loop = True
    while (loop == True):
        if(selection == "Checkout_Continue"):
            choice = input("Press 1 to checkout to see all of your order(s) or 2 to continue with your order :- ")            
        elif(selection == "Proceed_Cancel"):
            choice = input("Press 1 to proceed to make payment or 2 to cancel your order :- ")            
        if (choice == "1") or (choice == "2"):
            loop = False        
        else:
            print("Invalid choice. Please choose between 1 and 2.")            
    return choice

def countdown(start_count):
    for i in range(start_count,-1,-1):
        if(i == 0):
            time.sleep(0.2)         # Pauses the system slightly to show the last countdown digit
            break
        elif(i == start_count):
            time.sleep(0.5)         # Pauses the system slightly longer before showing the first countdown digit
            print(str(i), end = "") # Displays the first countdown digit
            time.sleep(1)           # Pauses the system slightly longer before showing the second countdown digit
        else:
            print(str(i), end = "") # Displays the next countdown digit on the same line
            time.sleep(1)

def place_orders(price_file, choice, cost, exit_code):    
    code_f = open(price_file,"r")
    co = code_f.readlines()    
    for line in reversed(co) and co:          
        data = line.split(";")
        item_code = data[0]
        item_description = data[1]
        item_price = float(data[2])
        while(item_code == choice):
            ask_quantity = input("Please enter your desired quantity :- ")
            if ask_quantity.isdigit():  # Only non-negative integer numbers are allowed to be accepted as the desired quantity
                quantity = int(ask_quantity)
                cost = cost + (quantity * item_price)
                receipt = (f'{quantity} x {item_description} (each selling at ${item_price:0.2f}) = ${item_price * quantity:0.2f}\n')
                sum_receipt = open("receipt.txt","a")
                receipt_copy = open("receipt_copy.txt","a")
                total_receipt = "".join(receipt)
                sum_receipt.write(total_receipt)
                receipt_copy.write(total_receipt)
                sum_receipt.close()
                receipt_copy.close()            
                checkout_choice = chkout_cont_proceed_cancel_error_check("Checkout_Continue")
                cancel_or_proceed = False       # If this is True, it will be used to reset total_cost = 0 
                if(checkout_choice == "1"):
                    receipt = open("receipt.txt","r")                    
                    print ("\n" + receipt.read())        
                    receipt.close()        
                    open("receipt.txt","w").close()     # Flush the receipt's contents for next customer's usage
                    receipt_copy = open("receipt_copy.txt","a")
                    print(f'Please pay for the total amount of ${cost:0.2f}')
                    receipt_copy.write(f'\nPlease pay for the total amount of ${cost:0.2f}')
                    receipt_copy.close()                
                    proceed_choice = chkout_cont_proceed_cancel_error_check("Proceed_Cancel")
                    if(proceed_choice == "1"):                    
                        receipt_copy = open("receipt_copy.txt","a")
                        now = datetime.datetime.now()
                        receipt_copy.write("\n--------------Previous Order Completed on " + now.strftime('%d-%m-%Y %H:%M:%S') + "--------------\n")
                        receipt_copy.close()
                        print(f"\nThank you for your payment on {now.strftime('%A, %B the %dth, %Y at %H:%M:%S')}.\n\nYour receipt is ready for collection.\n\nThis system will auto return to Main Menu in {PAYMENT_TO_MAINMENU} seconds.\nThank you for your patronage. ", end = "")
                        countdown(PAYMENT_TO_MAINMENU)                        
                        cancel_or_proceed = True
                        main_choice = display_main_menu(exit_code)
                        break
                    else:
                        receipt_copy = open("receipt_copy.txt","a")
                        now = datetime.datetime.now()
                        receipt_copy.write("\n--------------Previous Order Cancelled on " + now.strftime('%d-%m-%Y %H:%M:%S') + "--------------\n")
                        receipt_copy.close()            
                        print(f"\nYou have chosen to cancel your order on {now.strftime('%A, %B the %dth, %Y at %H:%M:%S')}.\nThis system will auto return to Main Menu in {CANCEL_TO_MAINMENU} seconds.\nThank you for your patronage. ", end = "")
                        countdown(CANCEL_TO_MAINMENU)                        
                        cancel_or_proceed = True
                        main_choice = display_main_menu(exit_code)
                        break
                else:
                    print(f"\nYou have chosen to continue with other orders.\nThis system will auto return to Main Menu in {CONTINUE_TO_MAINMENU} seconds. ", end = "")
                    countdown(CONTINUE_TO_MAINMENU)                    
                    cancel_or_proceed = False
                    main_choice = display_main_menu(exit_code)
                    break
            else:
                print ("Invalid quantity. Please try again.")                
                continue
    return main_choice, cancel_or_proceed, cost

#################################   Main Program starts here  ####################################
open("receipt.txt","w").close()         # Flush the receipt's contents to empty it when the system starts its first used for the day
open("receipt_copy.txt","w").close()    # Flush the receipt copy's contents to empty it when the system starts its first used for the day
main_choice = display_main_menu(EXIT_SYSTEM)
while(main_choice != EXIT_SYSTEM):
    if(main_choice == "1"):
        promo_choice = display_promo_menu()
        main_choice, cancel_or_proceed, total_cost = place_orders("promo-code.txt", promo_choice, total_cost, EXIT_SYSTEM)
        if(cancel_or_proceed == True):
            total_cost = 0                       
    elif(main_choice == "2"):
        combo_choice = display_combo_menu()
        main_choice, cancel_or_proceed, total_cost = place_orders("combo-code.txt", combo_choice, total_cost, EXIT_SYSTEM)
        if(cancel_or_proceed == True):
            total_cost = 0                  
    elif(main_choice == "3"):
        kids_choice = display_kids_menu()
        main_choice, cancel_or_proceed, total_cost = place_orders("kids-code.txt", kids_choice, total_cost, EXIT_SYSTEM)
        if(cancel_or_proceed == True):
            total_cost = 0              
    elif(main_choice == "4"):
        alacarte_choice = display_alacarte_menu()
        main_choice, cancel_or_proceed, total_cost = place_orders("ala-code.txt", alacarte_choice, total_cost, EXIT_SYSTEM)
        if(cancel_or_proceed == True):
            total_cost = 0                  
    else:
        drink_choice = display_drink_menu()
        main_choice, cancel_or_proceed, total_cost = place_orders("drinks-code.txt", drink_choice, total_cost, EXIT_SYSTEM)
        if(cancel_or_proceed == True):
            total_cost = 0
