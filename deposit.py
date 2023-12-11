def deposit(object_in_the_wallet,wallet):
    print("What's type of something you want to add :")
    print("1. Money")
    print("2. Others")
    user_choice = int(input())

    check = "Money" in object_in_the_wallet

    if user_choice == 1:
        print("How much money you want to add :")
        to_add = float(input())

        if not check and to_add > 0:
            global amount
            amount += to_add
            object_in_the_wallet["Money"] = str(amount)
            print(f"Adding money on your wallet: {wallet}")
        elif check and to_add > 0:
            current_amount = float(object_in_the_wallet["Money"])
            current_amount += to_add
            object_in_the_wallet["Money"] = str(current_amount)
            print(f"Total money on your wallet is updating to: {wallet}")
        else:
            print("Add a correct value")
    else:
        print("Type name :")
        type_name = input()
        print("How much ? :")
        value = float(input())

        object_in_the_wallet[type_name] = str(value)
        wallet.append(object_in_the_wallet.copy())

        print(f"Your {type_name} adding to the wallet")
        print(f"Your wallet actually: {wallet}")
