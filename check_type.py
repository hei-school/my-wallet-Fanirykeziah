def check(object_in_the_wallet):
    print("What's quantity type you want to know ?")
    input_type = input('Enter the type: ')

    value = object_in_the_wallet.get(input_type)

    if value is not None:
        print(f"This type content: {value}")
    else:
        print("Type not found")