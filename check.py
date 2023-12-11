def check_type_existing(object_in_the_wallet,wallet):
    print("Type name ?")
    input_type = input('')

    check_input_type = input_type in object_in_the_wallet

    if check_input_type:
        print(f"This type existing in wallet: {wallet}")
    else:
        print("This type is not in the wallet")