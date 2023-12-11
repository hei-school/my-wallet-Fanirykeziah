from deposit import deposit;
from withdrawal import withdraw;
from check_type import check;
from check import check_type_existing;

amount = 500.0
object_in_the_wallet = {}
wallet = [object_in_the_wallet]
action = None

def main(action):
    if action == 1:
        print(wallet)
    elif action == 2:
        deposit(object_in_the_wallet,wallet)
    elif action == 3:
        withdrawal(object_in_the_wallet,wallet)
    elif action == 4:
        check(object_in_the_wallet)
    elif action == 5:
        check_type_existing(object_in_the_wallet,wallet)
    else:
        print("Invalid action")       

print("1. View all things on the wallet")
print("2. Deposit something on the wallet")
print("3. Withdrawal")
print("4. Quantity's type")
print("5. Check if one type existing")

action = input()
main(int(action))