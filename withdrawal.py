def withdraw(object_in_the_wallet,wallet):
    print("Taking :")
    print("1. Money")
    print("2. Others")
    user_choice_take = int(input('Enter your choice: '))

    if user_choice_take == 1:
        to_take = float(input('Enter money value you want taking : '))
        check = "Money" in object_in_the_wallet
        current_amount = float(object_in_the_wallet.get("Money", 0))

        if check and to_take > 0:
            if current_amount >= to_take:
                current_amount -= to_take
                object_in_the_wallet["Money"] = str(current_amount)
                print(f"Your withdrawal {to_take} has been successfully completed")
                print(f"Your current money is : {wallet}")
            else:
                print("Insufficient funds")
        elif to_take < 0:
            print("You can't take a negative value")
        else:
            print("You don't have money in your wallet")
    elif user_choice_take == 2:
        type_name = input('Type name: ').strip()

        if type_name in object_in_the_wallet:
            wallet.remove(object_in_the_wallet)
            print(f"Wallet actually : {wallet}")
        else:
            print("Object doesn't exist in the wallet")
    else:
        print("Invalid choice")