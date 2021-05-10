#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
/*#include <unistd.h>		// For VSC */
#include <ctype.h>

#define EXIT_SYSTEM	   	   	   "Q"  /* Code to exit system */
#define SYSTEM_SHUTDOWN			3	/* Time delay before clearing screen to shutdown system */
#define REENTER_INPUT			2	/* Time delay before clearing screen to show same menu again */
#define PAYMENT_TO_MAINMENU		5	/* Time delay between showing payment done message and returning to Main Menu */
#define CANCEL_TO_MAINMENU		5	/* Time delay between showing payment cancel message and returning to Main Menu */
#define CONTINUE_TO_MAINMENU	2	/* Time delay between showing continue with order message and returning to Main Menu */

float total_cost = 0.00;	/* Total amount to paid by customer for his placed orders */

/* For Mac PCs */
void cls()
{
    int x = 0;
    while(x!=100)
    {
        printf("\n");
        x++;
    }
}

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

int countdown(int start_count)
{    
	int i;
	for(i=start_count; i>-1; i--)
	{
		if(i == 0)
        {
			delay(200);		// For Quincy
/*	  	  	  sleep(0.2);	  // For VSC */
            break;
        }		
		else if(i == start_count)
		{
			delay(500);
/*	  	  	  sleep(0.5);	  // For VSC */
			printf("%d", i);
/*	  	  	  printf("%d\n", i);// For VSC */
			delay(1000);
/*	  	  	  sleep(1);	  	  // For VSC  */	
		}
		else
		{
			printf("%d", i);
/*	  	  	  printf("%d\n", i);// For VSC  */
			delay(1000);
/*	  	  	  sleep(1);	  	  // For VSC  */
		}
	}
    return 0;
}

char display_main_menu (char exit_code[])
{
    int loop = 1;
    char choice1[] = "1";
    char choice2[] = "2";
	char choice3[] = "3";
	char choice4[] = "4";
	char choice5[] = "5";
    char choice_quit[] = "q";  
    char choice[200],prompt;
    while (loop == 1)
    {
        cls();
        printf("\n --------------------------------------------------- \n");
        printf("|             McKay Fast Food Drive Thru            |\n");
        printf("|              Takeaway Ordering System             |\n");
        printf(" --------------------------------------------------- \n");
        printf("Welcome to our drive through takeway ordering system!\n\n");
        printf("1) Promotions\n");
        printf("2) Combo Sets\n");
		printf("3) Kids' Meals\n");
		printf("4) A la Carte\n");
		printf("5) Drinks Only\n");
        printf("\nPlease select one of the above:- \n");
        scanf("%s",choice);	   
        if (strcmp(choice, choice1) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice2) == 0)
        {
            loop = 0;
        }
		else if (strcmp(choice, choice3) == 0)
        {
            loop = 0;
        }
		else if (strcmp(choice, choice4) == 0)
        {
            loop = 0;
        }
		else if (strcmp(choice, choice5) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, exit_code) == 0)
        {
            printf("\nSystem will auto shutdown in %d seconds. Thank you and have a nice day. ", SYSTEM_SHUTDOWN);
			countdown(SYSTEM_SHUTDOWN);
            cls();
            loop = 0;
        }
        else if (strcmp(choice, choice_quit) == 0)
        {
            printf("\nSystem will auto shutdown in %d seconds. Thank you and have a nice day. ", SYSTEM_SHUTDOWN);
			countdown(SYSTEM_SHUTDOWN);
            cls();
            loop = 0;
        }
        else
        {
            prompt = getchar();
            printf("Invalid choice. Please choose between 1 to 5.\nEnter any key to try again.");
            prompt = getchar();		
            loop = 1;
            fflush(stdin);
            continue;
        }
    }
    return *choice;
}


char display_promo_menu()
{
    int loop = 1;
    char choice1[] = "1";
    char choice2[] = "2";
    char choice3[] = "3";
    char choice4[] = "4";
    char choice5[] = "5";
    char choice6[] = "6";
    char choice[200], prompt;
    while (loop == 1)
    {
        cls();
        printf("\n~~~~~~~   Promotions   ~~~~~~~\n");
        printf("1) Buddy Chicken Burger Combo --------------> $9.00\n");
        printf("2) Buddy Fish Burger Combo -----------------> $10.00\n");
        printf("3) Buddy Chicken Fish Burger Combo ---------> $10.00\n");
        printf("4) Family-of-4 Chicken Burger Combo --------> $18.00\n");
        printf("5) Family-of-4 Fish Burger Combo -----------> $20.00\n");
        printf("6) Family-of-4 Chicken Fish Burger Combo ---> $19.00\n");
        printf ("\nPlease select one of the above:- \n");
        scanf("%s",choice);
        if (strcmp(choice, choice1) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice2) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice3) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice4) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice5) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice6) == 0)
        {
            loop = 0;
        }
        else
        {
            prompt = getchar();
            printf("Invalid choice. Please choose between 1 to 6.\nEnter any key to try again.");
            prompt = getchar();		
            loop = 1;
            fflush(stdin);
            continue;
        } 
    }
    return *choice;
}

char display_combo_menu()
{
    int loop = 1;
    char choice1[] = "1";
    char choice2[] = "2";
    char choice3[] = "3";
    char choice4[] = "4";
    char choice5[] = "5";
    char choice6[] = "6";
    char choice[200], prompt;
    while (loop == 1)
    {
        cls();
        printf("\n~~~~~   Combo Sets   ~~~~~\n");
        printf("1) Chicken Burger Combo ----------> $5.00\n");
        printf("2) Double Chicken Burger Combo ---> $7.00\n");
        printf("3) Fish Burger Combo -------------> $5.50\n");
        printf("4) Double Fish Burger Combo ------> $7.50\n");
        printf("5) Beef Burger Combo -------------> $6.00\n");
        printf("6) Double Beef Burger Combo ------> $8.00\n");
        printf ("\nPlease select one of the above:- \n");
        scanf("%s",choice);
        if (strcmp(choice, choice1) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice2) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice3) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice4) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice5) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice6) == 0)
        {
            loop = 0;
        }
        else
        {
            prompt = getchar();
            printf("Invalid choice. Please choose between 1 to 6.\nEnter any key to try again.");
            prompt = getchar();		
            loop = 1;
            fflush(stdin);
            continue;
        } 
    }
    return *choice;
}

char display_kids_menu()
{
    int loop = 1;
    char choice1[] = "1";
    char choice2[] = "2";
    char choice3[] = "3";    
    char choice[200], prompt;
    while (loop == 1)
    {
        cls();
        printf("\n~~~~~   Kids' Meals   ~~~~~\n");
        printf("1) Chicken Nuggets 4pc Meal ---> $4.00\n");
        printf("2) Chicken Nuggets 4pc Meal ---> $4.20\n");
        printf("3) Chicken Nuggets 4pc Meal ---> $3.50\n");        
        printf ("\nPlease select one of the above:- \n");
        scanf("%s",choice);
        if (strcmp(choice, choice1) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice2) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice3) == 0)
        {
            loop = 0;
        }        
        else
        {
            prompt = getchar();
            printf("Invalid choice. Please choose between 1 to 3.\nEnter any key to try again.");
            prompt = getchar();		
            loop = 1;
            fflush(stdin);
            continue;
        } 
    }
    return *choice;
}

char display_alacarte_menu()
{
    int loop = 1;
    char choice1[] = "1";
    char choice2[] = "2";
    char choice3[] = "3";
    char choice4[] = "4";
    char choice5[] = "5";
    char choice6[] = "6";
    char choice[200], prompt;
    while (loop == 1)
    {
        cls();
        printf("\n~~~~~   A la Carte   ~~~~~\n");
        printf("1) Chicken Burger ----------> $3.00\n");
        printf("2) Double Chicken Burger ---> $4.00\n");
        printf("3) Fish Burger -------------> $3.20\n");
        printf("4) Double Fish Burger ------> $4.20\n");
        printf("5) Beef Burger -------------> $3.50\n");
        printf("6) Double Beef Burger ------> $4.50\n");
        printf ("\nPlease select one of the above:- \n");
        scanf("%s",choice);
        if (strcmp(choice, choice1) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice2) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice3) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice4) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice5) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice6) == 0)
        {
            loop = 0;
        }
        else
        {
            prompt = getchar();
            printf("Invalid choice. Please choose between 1 to 6.\nEnter any key to try again.");
            prompt = getchar();		
            loop = 1;
            fflush(stdin);
            continue;
        } 
    }
    return *choice;
}

char display_drink_menu()
{
    int loop = 1;
    char choice1[] = "1";
    char choice2[] = "2";
    char choice3[] = "3";
    char choice4[] = "4";
    char choice5[] = "5";
    char choice6[] = "6";
    char choice[200], prompt;
    while (loop == 1)
    {
        cls();
        printf("\n~~~~~   Drinks Only   ~~~~~\n");
        printf("1) Coffee (Hot) ----------> $0.90\n");
        printf("2) Tea (Hot) -------------> $0.80\n");
        printf("3) Lemonade (Cold) -------> $1.00\n");
        printf("4) Orange Juice (Cold) ---> $1.00\n");
        printf("5) Coke (Cold) -----------> $1.20\n");
        printf("6) Root Beer (Cold) ------> $1.20\n");
        printf ("\nPlease select one of the above:- \n");
        scanf("%s",choice);
        if (strcmp(choice, choice1) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice2) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice3) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice4) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice5) == 0)
        {
            loop = 0;
        }
        else if (strcmp(choice, choice6) == 0)
        {
            loop = 0;
        }
        else
        {
            prompt = getchar();
            printf("Invalid choice. Please choose between 1 to 6.\nEnter any key to try again.");
            prompt = getchar();		
            loop = 1;
            fflush(stdin);
            continue;
        } 
    }
    return *choice;
}

char promo_item[][50] = {"Buddy Chicken Burger Combo","Buddy Fish Burger Combo","Buddy Chicken Fish Burger Combo","Family-of-4 Chicken Burger Combo","Family-of-4 Fish Burger Combo","Family-of-4 Chicken Fish Burger Combo"};
float promo_price[6] = {9,10,10,18,20,19};
char combo_item[][50] = {"Chicken Burger Combo","Double Chicken Burger Combo","Fish Burger Combo","Double Fish Burger Combo","Beef Burger Combo","Double Beef Burger Combo"};
float combo_price[6] = {5,7,5.5,7.5,6,8};
char kids_item[][50] = {"Chicken Nuggets 4pc Meal","Fish Nuggets 4pc Meal","Cheese Burger Meal"};
float kids_price[3] = {4,4.2,3.5};
char alacarte_item[][50] = {"Chicken Burger","Double Chicken Burger","Fish Fillet Burger","Double Fish Fillet Burger","Beef Burger","Double Beef Burger"};
float alacarte_price[6] = {3,4,3.2,4.2,3.5,4.5};
char drink_item[][50] = {"Coffee (Hot)","Tea (Hot)","Lemonade (Cold)","Orange Juice (Cold)","Coke (Cold)","Root Beer (Cold)"};
float drink_price[6] = {0.9,0.8,1,1,1.2,1.2};

float compute_promo(int item_choice, float cost)
{
	float price_item;
	char prompt;
	char ask_quantity [20];
	int quantity, i, length;
	int loop = 1;
	int pass = 1;
	FILE *receipt, *receipt_copy;
	receipt = fopen("receipt.txt","a");
	receipt_copy = fopen("receipt_copy.txt","a");
	
	while (loop == 1)
	{
		printf("Please enter quantity : ");
		scanf("%s",ask_quantity);
		length = strlen (ask_quantity);
		for (i=0;i<length; i++)
		{
			if (!isdigit(ask_quantity[i]))
			{
				prompt = getchar();
				printf("Invalid choice. Please enter desired quantity.\nEnter any key to try again.");
				prompt = getchar();		
				loop = 1;
				pass = 0;
				fflush(stdin);
				break;
			}
			else if (i == length - 1)
			{
				pass = 1;
				break;
			}
		}
		if (pass == 1)
		{
			quantity = atoi(ask_quantity);
			price_item = promo_price[item_choice - 1];	  // Obtain item price from promo_price array
			cost = quantity * price_item;
			fprintf(receipt,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(promo_item + item_choice - 1), price_item, cost);
			fclose(receipt);
			fprintf(receipt_copy,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(promo_item + item_choice - 1), price_item, cost);
			fclose(receipt_copy);
			total_cost = cost + total_cost;
			loop = 0;
			return total_cost;
		}
	}
}

float compute_combo(int item_choice, float cost)
{
	float price_item;
	char prompt;
	char ask_quantity [20];
	int quantity, i, length;
	int loop = 1;
	int pass = 1;
	FILE *receipt, *receipt_copy;
	receipt = fopen("receipt.txt","a");
	receipt_copy = fopen("receipt_copy.txt","a");
	
	while (loop == 1)
	{
		printf("Please enter quantity : ");
		scanf("%s",ask_quantity);
		length = strlen (ask_quantity);
		for (i=0;i<length; i++)
		{
			if (!isdigit(ask_quantity[i]))
			{
				prompt = getchar();
				printf("Invalid choice. Please enter desired quantity.\nEnter any key to try again.");
				prompt = getchar();		
				loop = 1;
				pass = 0;
				fflush(stdin);
				break;
			}
			else if (i == length - 1)
			{
				pass = 1;
				break;
			}
		}
		if (pass == 1)
		{
			quantity = atoi(ask_quantity);
			price_item = combo_price[item_choice - 1];	  // Obtain item price from promo_price array
			cost = quantity * price_item;
			fprintf(receipt,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(combo_item + item_choice - 1), price_item, cost);
			fclose(receipt);
			fprintf(receipt_copy,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(combo_item + item_choice - 1), price_item, cost);
			fclose(receipt_copy);
			total_cost = cost + total_cost;
			return total_cost;	  
		}
	}
}

float compute_kids(int item_choice, float cost)
{
	float price_item;
	char prompt;
	char ask_quantity [20];
	int quantity, i, length;
	int loop = 1;
	int pass = 1;	 
	FILE *receipt, *receipt_copy;
	receipt = fopen("receipt.txt","a");
	receipt_copy = fopen("receipt_copy.txt","a");

	while (loop == 1)
	{
		printf("Please enter quantity : ");
		scanf("%s",ask_quantity);
		length = strlen (ask_quantity);
		for (i=0;i<length; i++)
		{
			if (!isdigit(ask_quantity[i]))
			{
				prompt = getchar();
				printf("Invalid choice. Please enter desired quantity.\nEnter any key to try again.");
				prompt = getchar();		
				loop = 1;
				pass = 0;
				fflush(stdin);
				break;
			}
			else if (i == length - 1)
			{
				pass = 1;
				break;
			}
		}
		if (pass == 1)
		{
			quantity = atoi(ask_quantity);
			price_item = kids_price[item_choice - 1];	 // Obtain item price from promo_price array
			cost = quantity * price_item;
			fprintf(receipt,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(kids_item + item_choice - 1), price_item, cost);
			fclose(receipt);
			fprintf(receipt_copy,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(kids_item + item_choice - 1), price_item, cost);
			fclose(receipt_copy);
			total_cost = cost + total_cost;
			return total_cost;	
		}
	}  
}

float compute_alacarte(int item_choice, float cost)
{
	float price_item;
	char prompt;
	char ask_quantity [20];
	int quantity, i, length;
	int loop = 1;
	int pass = 1; 
	FILE *receipt, *receipt_copy;
	receipt = fopen("receipt.txt","a");
	receipt_copy = fopen("receipt_copy.txt","a");

	while (loop == 1)
	{
		printf("Please enter quantity : ");
		scanf("%s",ask_quantity);
		length = strlen (ask_quantity);
		for (i=0;i<length; i++)
		{
			if (!isdigit(ask_quantity[i]))
			{
				prompt = getchar();
				printf("Invalid choice. Please enter desired quantity.\nEnter any key to try again.");
				prompt = getchar();		
				loop = 1;
				pass = 0;
				fflush(stdin);
				break;
			}
			else if (i == length - 1)
			{
				pass = 1;
				break;
			}
		}
		if (pass == 1)
		{
			quantity = atoi(ask_quantity);
			price_item = alacarte_price[item_choice - 1];	// Obtain item price from promo_price array
			cost = quantity * price_item;
			fprintf(receipt,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(alacarte_item + item_choice - 1), price_item, cost);
			fclose(receipt);
			fprintf(receipt_copy,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(alacarte_item + item_choice - 1), price_item, cost);
			fclose(receipt_copy);
			total_cost = cost + total_cost;
			return total_cost;	  
		}
	}
}

float compute_drink(int item_choice, float cost)
{
	float price_item;
	char prompt;
	char ask_quantity [20];
	int quantity, i, length;
	int loop = 1;
	int pass = 1; 
	FILE *receipt, *receipt_copy;
	receipt = fopen("receipt.txt","a");
	receipt_copy = fopen("receipt_copy.txt","a");

	while (loop == 1)
	{
		printf("Please enter quantity : ");
		scanf("%s",ask_quantity);
		length = strlen (ask_quantity);
		for (i=0;i<length; i++)
		{
			if (!isdigit(ask_quantity[i]))
			{
				prompt = getchar();
				printf("Invalid choice. Please enter desired quantity.\nEnter any key to try again.");
				prompt = getchar();		
				loop = 1;
				pass = 0;
				fflush(stdin);
				break;
			}
			else if (i == length - 1)
			{
				pass = 1;
				break;
			}
		}
		if (pass == 1)
		{
			quantity = atoi(ask_quantity);
			price_item = drink_price[item_choice - 1];	// Obtain item price from promo_price array
			cost = quantity * price_item;
			fprintf(receipt,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(drink_item + item_choice - 1), price_item, cost);
			fclose(receipt);
			fprintf(receipt_copy,"%d x %s (each selling at $%.2f) = $%.2f\n",quantity,(drink_item + item_choice - 1), price_item, cost);
			fclose(receipt_copy);
			total_cost = cost + total_cost;
			return total_cost;	  
		}
	}
}

int chkout_cont_proceed_cancel_error_check(char selection[])
{
	int choice;
	int loop = 1;
	while(loop == 1)
	{
		if(selection == "Checkout_Continue")
		{
			printf("Press 1 to checkout to see all of your order(s) or 2 to continue with your order :- ");
			scanf("%d", &choice);
		}
		else if(selection == "Proceed_Cancel")
		{
			printf("\nPress 1 to proceed to make payment or 2 to cancel your order :- \n");
			scanf("%d", &choice);
		}
		if(choice == 1)
        {
			loop = 0;
        }
		else if (choice == 2)
        {
			loop = 0;
        }
		else
        {
			printf("Invalid choice. Please choose between 1 and 2.");
        }	 	 	 
	}
	return choice;
}

float placed_orders(int choice, int item_choice, float cost)
{
	char con[1000];	// variable to read the contents from receipt.txt file
	char cont;
	int checkout_choice, proceed_choice;
	int loop = 1;
	//bool cancel_or_proceed = false;	 If this is True, it will be used to reset total_cost = 0 in the Main function
	time_t rawtime;
	struct tm *info;
	char buffer[80];	
	FILE *receipt, *receipt_copy;
	
	if (choice == 1)	// User selected Promotions Menu
	{
		switch (item_choice)
		{
			case 1 :			
			{
				total_cost = compute_promo(item_choice, cost);
				break;
			}
			case 2 :
			{
				total_cost = compute_promo(item_choice, cost);
				break;
			}
			case 3 :
			{
				total_cost = compute_promo(item_choice, cost);
				break;
			}
			case 4 :
			{
				total_cost = compute_promo(item_choice, cost);
				break;
			}
			case 5 :
			{
				total_cost = compute_promo(item_choice, cost);
				break;
			}
			case 6 :
			{
				total_cost = compute_promo(item_choice, cost);
				break;
			}
			default :
			{
				printf("Invalid choice. Please choose between 1 and 6.Press any key to continue.\n");
				cont = getchar();
				loop = 1; 	 	 
			}
		}
		
		//total_cost = checkout_to_cancel(total_cost, cancel_or_proceed
		// Prompts user to choose whether 1 to checkout to see all placed orders, or 2 to continue with his orders.
		checkout_choice = chkout_cont_proceed_cancel_error_check("Checkout_Continue");
		if(checkout_choice == 1)	// User chose to checkout to see all his placed orders
		{
			receipt = fopen("receipt.txt","r");
			while (fgets(con,1000,receipt) != NULL)	// reading text contents from receipt.txt file
			printf("%s",con);
			fclose(receipt);
			receipt = fopen("receipt.txt","w");	// Flush the receipt's contents for next customer's usage
			fclose(receipt);
			
            receipt_copy = fopen("receipt_copy.txt","a");
            printf("Please pay for the total amount of $%.2f",total_cost);
			fprintf(receipt_copy,"Please pay for the total amount of $%.2f",total_cost);		
            fclose(receipt_copy);
			
			proceed_choice = chkout_cont_proceed_cancel_error_check("Proceed_Cancel");
			if(proceed_choice == 1)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Completed on %s--------------\n\n", buffer);
				fclose(receipt_copy);                                
                printf("\nThank you for your payment on %s.\n\nYour receipt is ready for collection.\n\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer,PAYMENT_TO_MAINMENU);
				countdown(PAYMENT_TO_MAINMENU);
				total_cost = 0;
			}
			else if(proceed_choice == 2)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Cancelled on %s--------------\n\n", buffer);
				fclose(receipt_copy);                        
                printf("\nYou have chosen to cancel your order on %s.\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer, CANCEL_TO_MAINMENU);
                countdown(CANCEL_TO_MAINMENU);
				total_cost = 0;
			}
		}
		else if(checkout_choice == 2)
		{
			printf("\nYou have chosen to continue with other orders.\nThis system will auto return to Main Menu in %d seconds. ", CONTINUE_TO_MAINMENU);
            countdown(CONTINUE_TO_MAINMENU);
		}
	}
	else if (choice == 2)	// User selected Combo Sets Menu
	{
		switch (item_choice)
		{
			case 1 :			
			{
				total_cost = compute_combo(item_choice, cost);
				break;
			}
			case 2 :
			{
				total_cost = compute_combo(item_choice, cost);
				break;
			}
			case 3 :
			{
				total_cost = compute_combo(item_choice, cost);
				break;
			}
			case 4 :
			{
				total_cost = compute_combo(item_choice, cost);
				break;
			}
			case 5 :
			{
				total_cost = compute_combo(item_choice, cost);
				break;
			}
			case 6 :
			{
				total_cost = compute_combo(item_choice, cost);
				break;
			}
			default :
			{
				printf("Invalid choice. Please choose between 1 and 6.Press any key to continue.\n");
				cont = getchar();
				loop = 1;
			}
		}
		// Prompts user to choose whether 1 to checkout to see all placed orders, or 2 to continue with his orders.
		checkout_choice = chkout_cont_proceed_cancel_error_check("Checkout_Continue");
		if(checkout_choice == 1)	// User chose to checkout to see all his placed orders
		{
			receipt = fopen("receipt.txt","r");
			while (fgets(con,1000,receipt) != NULL)	// reading text contents from receipt.txt file
			printf("%s",con);
			fclose(receipt);
			receipt = fopen("receipt.txt","w");	// Flush the receipt's contents for next customer's usage
			fclose(receipt);
			
            receipt_copy = fopen("receipt_copy.txt","a");
            printf("Please pay for the total amount of $%.2f",total_cost);
			fprintf(receipt_copy,"Please pay for the total amount of $%.2f",total_cost);		
            fclose(receipt_copy);
			
			proceed_choice = chkout_cont_proceed_cancel_error_check("Proceed_Cancel");
			if(proceed_choice == 1)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Completed on %s--------------\n\n", buffer);
				fclose(receipt_copy);                                
                printf("\nThank you for your payment on %s.\n\nYour receipt is ready for collection.\n\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer,PAYMENT_TO_MAINMENU);
				countdown(PAYMENT_TO_MAINMENU);
				total_cost = 0;
			}
			else if(proceed_choice == 2)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Cancelled on %s--------------\n\n", buffer);
				fclose(receipt_copy);                        
                printf("\nYou have chosen to cancel your order on %s.\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer, CANCEL_TO_MAINMENU);
                countdown(CANCEL_TO_MAINMENU);
				total_cost = 0;
			}
		}
		else if(checkout_choice == 2)
		{
			printf("\nYou have chosen to continue with other orders.\nThis system will auto return to Main Menu in %d seconds. ", CONTINUE_TO_MAINMENU);
            countdown(CONTINUE_TO_MAINMENU);
		}
    }
	else if (choice == 3)	// User selected Kids Menu
	{
		switch (item_choice)
		{
			case 1 :			
			{
				total_cost = compute_kids(item_choice, cost);
				break;
			}
			case 2 :
			{
				total_cost = compute_kids(item_choice, cost);
				break;
			}
			case 3 :
			{
				total_cost = compute_kids(item_choice, cost);
				break;
			}	 	 	 
			default :
			{
				printf("Invalid choice. Please choose between 1 and 6.Press any key to continue.\n");
				cont = getchar();
				loop = 1;
			}
		}
		// Prompts user to choose whether 1 to checkout to see all placed orders, or 2 to continue with his orders.
		checkout_choice = chkout_cont_proceed_cancel_error_check("Checkout_Continue");
		if(checkout_choice == 1)	// User chose to checkout to see all his placed orders
		{
			receipt = fopen("receipt.txt","r");
			while (fgets(con,1000,receipt) != NULL)	// reading text contents from receipt.txt file
			printf("%s",con);
			fclose(receipt);
			receipt = fopen("receipt.txt","w");	// Flush the receipt's contents for next customer's usage
			fclose(receipt);
			
            receipt_copy = fopen("receipt_copy.txt","a");
            printf("Please pay for the total amount of $%.2f",total_cost);
			fprintf(receipt_copy,"Please pay for the total amount of $%.2f",total_cost);		
            fclose(receipt_copy);
			
			proceed_choice = chkout_cont_proceed_cancel_error_check("Proceed_Cancel");
			if(proceed_choice == 1)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Completed on %s--------------\n\n", buffer);
				fclose(receipt_copy);                                
                printf("\nThank you for your payment on %s.\n\nYour receipt is ready for collection.\n\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer,PAYMENT_TO_MAINMENU);
				countdown(PAYMENT_TO_MAINMENU);
				total_cost = 0;
			}
			else if(proceed_choice == 2)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Cancelled on %s--------------\n\n", buffer);
				fclose(receipt_copy);                        
                printf("\nYou have chosen to cancel your order on %s.\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer, CANCEL_TO_MAINMENU);
                countdown(CANCEL_TO_MAINMENU);
				total_cost = 0;
			}
		}
		else if(checkout_choice == 2)
		{
			printf("\nYou have chosen to continue with other orders.\nThis system will auto return to Main Menu in %d seconds. ", CONTINUE_TO_MAINMENU);
            countdown(CONTINUE_TO_MAINMENU);
		}
    }
	else if (choice == 4)	// User selected A la Carte Menu
	{
		switch (item_choice)
		{
			case 1 :			
			{
				total_cost = compute_alacarte(item_choice, cost);
				break;
			}
			case 2 :
			{
				total_cost = compute_alacarte(item_choice, cost);
				break;
			}
			case 3 :
			{
				total_cost = compute_alacarte(item_choice, cost);
				break;
			}
			case 4 :
			{
				total_cost = compute_alacarte(item_choice, cost);
				break;
			}
			case 5 :
			{
				total_cost = compute_alacarte(item_choice, cost);
				break;
			}
			case 6 :
			{
				total_cost = compute_alacarte(item_choice, cost);
				break;
			}
			default :
			{
				printf("Invalid choice. Please choose between 1 and 6.Press any key to continue.\n");
				cont = getchar();
				loop = 1;
			}
		}
		// Prompts user to choose whether 1 to checkout to see all placed orders, or 2 to continue with his orders.
		checkout_choice = chkout_cont_proceed_cancel_error_check("Checkout_Continue");
		if(checkout_choice == 1)	// User chose to checkout to see all his placed orders
		{
			receipt = fopen("receipt.txt","r");
			while (fgets(con,1000,receipt) != NULL)	// reading text contents from receipt.txt file
			printf("%s",con);
			fclose(receipt);
			receipt = fopen("receipt.txt","w");	// Flush the receipt's contents for next customer's usage
			fclose(receipt);
			
            receipt_copy = fopen("receipt_copy.txt","a");
            printf("Please pay for the total amount of $%.2f",total_cost);
			fprintf(receipt_copy,"Please pay for the total amount of $%.2f",total_cost);		
            fclose(receipt_copy);
			
			proceed_choice = chkout_cont_proceed_cancel_error_check("Proceed_Cancel");
			if(proceed_choice == 1)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Completed on %s--------------\n\n", buffer);
				fclose(receipt_copy);                                
                printf("\nThank you for your payment on %s.\n\nYour receipt is ready for collection.\n\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer,PAYMENT_TO_MAINMENU);
				countdown(PAYMENT_TO_MAINMENU);
				total_cost = 0;
			}
			else if(proceed_choice == 2)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Cancelled on %s--------------\n\n", buffer);
				fclose(receipt_copy);                        
                printf("\nYou have chosen to cancel your order on %s.\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer, CANCEL_TO_MAINMENU);
                countdown(CANCEL_TO_MAINMENU);
				total_cost = 0;
			}
		}
		else if(checkout_choice == 2)
		{
			printf("\nYou have chosen to continue with other orders.\nThis system will auto return to Main Menu in %d seconds. ", CONTINUE_TO_MAINMENU);
            countdown(CONTINUE_TO_MAINMENU);
		}
    }
	else if (choice == 5)	// User selected Drinks Only Menu
	{
		switch (item_choice)
		{
			case 1 :			
			{
				total_cost = compute_drink(item_choice, cost);
				break;
			}
			case 2 :
			{
				total_cost = compute_drink(item_choice, cost);
				break;
			}
			case 3 :
			{
				total_cost = compute_drink(item_choice, cost);
				break;
			}
			case 4 :
			{
				total_cost = compute_drink(item_choice, cost);
				break;
			}
			case 5 :
			{
				total_cost = compute_drink(item_choice, cost);
				break;
			}
			case 6 :
			{
				total_cost = compute_drink(item_choice, cost);
				break;
			}
			default :
			{
				printf("Invalid choice. Please choose between 1 and 6.Press any key to continue.\n");
				cont = getchar();
				loop = 1;
			}
		}
		// Prompts user to choose whether 1 to checkout to see all placed orders, or 2 to continue with his orders.
		checkout_choice = chkout_cont_proceed_cancel_error_check("Checkout_Continue");
		if(checkout_choice == 1)	// User chose to checkout to see all his placed orders
		{
			receipt = fopen("receipt.txt","r");
			while (fgets(con,1000,receipt) != NULL)	// reading text contents from receipt.txt file
			printf("%s",con);
			fclose(receipt);
			receipt = fopen("receipt.txt","w");	// Flush the receipt's contents for next customer's usage
			fclose(receipt);
			
            receipt_copy = fopen("receipt_copy.txt","a");
            printf("Please pay for the total amount of $%.2f",total_cost);
			fprintf(receipt_copy,"Please pay for the total amount of $%.2f",total_cost);		
            fclose(receipt_copy);
			
			proceed_choice = chkout_cont_proceed_cancel_error_check("Proceed_Cancel");
			if(proceed_choice == 1)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Completed on %s--------------\n\n", buffer);
				fclose(receipt_copy);                                
                printf("\nThank you for your payment on %s.\n\nYour receipt is ready for collection.\n\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer,PAYMENT_TO_MAINMENU);
				countdown(PAYMENT_TO_MAINMENU);
				total_cost = 0;
			}
			else if(proceed_choice == 2)
			{
				receipt_copy = fopen("receipt_copy.txt","a");
				time(&rawtime);
				info = localtime( &rawtime );
				strftime(buffer,80,"%A, %B the %dth, %Y at %H:%M:%S", info);
				fprintf(receipt_copy,"\n\n--------------Previous Order Cancelled on %s--------------\n\n", buffer);
				fclose(receipt_copy);                        
                printf("\nYou have chosen to cancel your order on %s.\nThis system will auto return to Main Menu in %d seconds.\nThank you for your patronage. ", buffer, CANCEL_TO_MAINMENU);
                countdown(CANCEL_TO_MAINMENU);
				total_cost = 0;
			}
		}
		else if(checkout_choice == 2)
		{
			printf("\nYou have chosen to continue with other orders.\nThis system will auto return to Main Menu in %d seconds. ", CONTINUE_TO_MAINMENU);
            countdown(CONTINUE_TO_MAINMENU);
		}
    }
	return total_cost;
}


int main()
{
    char main_choice, item_choice_pro, item_choice_com;
    int now_item_choice_pro, now_main_choice;
    int loop = 1;
    float current_cost = 0;
	
	total_cost = 0;	   
	FILE *fp;
	fp = fopen("receipt.txt","w");
	fclose(fp);		/* Flush the receipt's contents to empty it when the system starts its first used for the day */
	fp = fopen("receipt_copy.txt","w");
	fclose(fp);		/* Flush the receipt copy's contents to empty it when the system starts its first used for the day */
    while(loop == 1)
    {
        main_choice = display_main_menu(EXIT_SYSTEM);
        if (main_choice == '1')
        {
            now_main_choice = main_choice - '0';
            item_choice_pro = display_promo_menu();
            now_item_choice_pro = item_choice_pro - '0';
            total_cost = placed_orders(now_main_choice,now_item_choice_pro,total_cost);	   	   	   
		}
        else if (main_choice == '2')
        {
            now_main_choice = main_choice - '0';
            item_choice_pro = display_combo_menu();
            now_item_choice_pro = item_choice_pro - '0';
            total_cost = placed_orders(now_main_choice,now_item_choice_pro,total_cost);
        }
		else if (main_choice == '3')
        {
            now_main_choice = main_choice - '0';
            item_choice_pro = display_kids_menu();
            now_item_choice_pro = item_choice_pro - '0';
            total_cost = placed_orders(now_main_choice,now_item_choice_pro,total_cost);	   	   	   
		}
		else if (main_choice == '4')
        {
            now_main_choice = main_choice - '0';
            item_choice_pro = display_alacarte_menu();
            now_item_choice_pro = item_choice_pro - '0';
            total_cost = placed_orders(now_main_choice,now_item_choice_pro,total_cost);	   	   	   
		}
		else if (main_choice == '5')
        {
            now_main_choice = main_choice - '0';
            item_choice_pro = display_drink_menu();
            now_item_choice_pro = item_choice_pro - '0';
            total_cost = placed_orders(now_main_choice,now_item_choice_pro,total_cost);	   	   	   
		}
		else if (main_choice == 'Q')			
			loop = 0;	// Exits system	   	   
		else if (main_choice == 'q')
			loop = 0;	// Exits system
    }
}

