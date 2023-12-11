#include <stdio.h>
#include <string.h>

float amount = 500;
char object_in_the_wallet[50][20]; // Assuming a maximum of 50 objects of 20 characters each
int wallet_count = 0;
int action = 0;

void display_menu() {
    printf("1. View all things on the wallet\n");
    printf("2. Deposit something on the wallet\n");
    printf("3. Withdrawal\n");
    printf("4. Quantity's type\n");
    printf("5. Check if one type existing\n");

    printf("Enter your action: ");
    scanf("%d", &action);
}

void view_wallet() {
    for (int i = 0; i < wallet_count; i++) {
        printf("%s\n", object_in_the_wallet[i]);
    }
}

void deposit_money() {
    printf("What's type of something you want to add:\n");
    printf("1. Money\n");
    printf("2. Others\n");
    int user_choice;
    scanf("%d", &user_choice);

    int check = 0;
    for (int i = 0; i < wallet_count; i++) {
        if (strcmp(object_in_the_wallet[i], "Money") == 0) {
            check = 1;
            break;
        }
    }

    if (user_choice == 1) {
        printf("How much money you want to add:\n");
        float to_add;
        scanf("%f", &to_add);

        if (!check && to_add > 0) {
            amount += to_add;
            sprintf(object_in_the_wallet[wallet_count], "Money: %.2f", amount);
            wallet_count++;
            printf("Adding money on your wallet\n");
        } else if (check && to_add > 0) {
            float current_amount;
            sscanf(object_in_the_wallet[0], "Money: %f", &current_amount);
            current_amount += to_add;
            sprintf(object_in_the_wallet[0], "Money: %.2f", current_amount);
            printf("Total money on your wallet is updating\n");
        } else {
            printf("Add a correct value\n");
        }
    } else {
        printf("Type name:\n");
        char type_name[20];
        scanf("%s", type_name);
        printf("How much?\n");
        float value;
        scanf("%f", &value);

        sprintf(object_in_the_wallet[wallet_count], "%s: %.2f", type_name, value);
        wallet_count++;
        printf("Your %s adding to the wallet\n", type_name);
    }
}

void withdraw_money() {
    printf("Taking:\n");
    printf("1. Money\n");
    printf("2. Others\n");
    int user_choice_take;
    scanf("%d", &user_choice_take);

    if (user_choice_take == 1) {
        float to_take;
        printf("Enter money value you want taking:\n");
        scanf("%f", &to_take);

        int check = 0;
        float current_amount = 0;

        for (int i = 0; i < wallet_count; i++) {
            if (strcmp(object_in_the_wallet[i], "Money") == 0) {
                sscanf(object_in_the_wallet[i], "Money: %f", &current_amount);
                check = 1;
                break;
            }
        }

        if (check && to_take > 0) {
            if (current_amount >= to_take) {
                current_amount -= to_take;
                sprintf(object_in_the_wallet[0], "Money: %.2f", current_amount);
                printf("Your withdrawal %.2f has been successfully completed\n", to_take);
            } else {
                printf("Insufficient funds\n");
            }
        } else if (to_take < 0) {
            printf("You can't take a negative value\n");
        } else {
            printf("You don't have money in your wallet\n");
        }
    } else if (user_choice_take == 2) {
        char type_name[20];
        printf("Type name:\n");
        scanf("%s", type_name);

        int found = 0;
        for (int i = 0; i < wallet_count; i++) {
            if (strstr(object_in_the_wallet[i], type_name) != NULL) {
                found = 1;
                for (int j = i; j < wallet_count - 1; j++) {
                    strcpy(object_in_the_wallet[j], object_in_the_wallet[j + 1]);
                }
                wallet_count--;
                break;
            }
        }

        if (found) {
            printf("Object removed from the wallet\n");
        } else {
            printf("Object doesn't exist in the wallet\n");
        }
    } else {
        printf("Invalid choice\n");
    }
}

void check_type() {
    char input_type[20];
    printf("What's quantity type you want to know?\n");
    scanf("%s", input_type);

    int found = 0;
    for (int i = 0; i < wallet_count; i++) {
        if (strstr(object_in_the_wallet[i], input_type) != NULL) {
            found = 1;
            printf("This type content: %s\n", object_in_the_wallet[i]);
            break;
        }
    }

    if (!found) {
        printf("Type not found\n");
    }
}

void check_type_existing() {
    char input_type[20];
    printf("Type name?\n");
    scanf("%s", input_type);

    int found = 0;
    for (int i = 0; i < wallet_count; i++) {
        if (strstr(object_in_the_wallet[i], input_type) != NULL) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("This type existing in wallet\n");
    } else {
        printf("This type is not in the wallet\n");
    }
}

