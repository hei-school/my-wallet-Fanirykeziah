import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class WalletManager {
    ArrayList<Object> wallet = new ArrayList<>();
    HashMap<String , String> objectInTheWallet = new HashMap<>();

    double amount = 500;

    public void displayMenu(){
        Scanner scanner = new Scanner(System.in);
        int action;

        System.out.println("1. View all things on the wallet");
        System.out.println("2. Deposit something on the wallet");
        System.out.println("3. Withdrawal");
        System.out.println("4. Quantity's type");
        System.out.println("5. Check if one type existing ");

        System.out.println("Enter your action : ");
        action = scanner.nextInt();

        switch (action) {
            case 1 -> System.out.println(wallet);
            case 2 -> depositSomething();
            case 3 -> withdrawal();
            case 4 -> quantity();
            case 5 -> checking();
        }
    }

    private void depositSomething(){
        Scanner scannerType = new Scanner(System.in);
        System.out.println("What's type of something you want to add :");
        System.out.println("1 . Money");
        System.out.println("2 . Others");
        Scanner scannerChoice = new Scanner(System.in);
        int choice = scannerChoice.nextInt();
        boolean check = wallet.contains(objectInTheWallet.get("Money"));

        if( choice == 1){
            Scanner scanner = new Scanner(System.in);
            System.out.println("How much money you want to add :");
            double toAdd = scanner.nextDouble();
            if( !check && toAdd > 0 ){
                amount += toAdd;
                objectInTheWallet.put("Money" , String.valueOf(amount));
                wallet.add(objectInTheWallet);
                System.out.println("Total money on your wallet is updating to"+ wallet);
            }
            else if(check && toAdd > 0){
                double amount = Double.parseDouble(objectInTheWallet.get("Money"));
                amount += toAdd;
                objectInTheWallet.put("Money" , String.valueOf(amount));
                wallet.add(objectInTheWallet);
                System.out.println("Total money on your wallet is updating to"+ wallet);
            }
            else {
                System.out.println("Add a correct value");
            }
        }

        else {
            System.out.println("Type name :");
            String type = scannerType.nextLine();
            Scanner scannerValue = new Scanner(System.in);
            System.out.println("How much ? :");
            int value = scannerValue.nextInt();

            objectInTheWallet.put(type , String.valueOf(value));
            wallet.add(objectInTheWallet);

            System.out.println("Your" + type + "adding to the wallet");
            System.out.println("Your wallet actually" + wallet);
        }
    }

    private void withdrawal(){
        Scanner scannerType = new Scanner(System.in);
        System.out.println("Taking :");
        System.out.println("1 . Money");
        System.out.println("2 . Others");
        Scanner scannerChoice = new Scanner(System.in);
        int choice = scannerChoice.nextInt();

        if( choice == 1 ){
            Scanner scanner = new Scanner(System.in);
            System.out.println("Enter money value you want taking : ");
            double toTake = scanner.nextDouble();
            boolean check = wallet.contains(objectInTheWallet.get("Money"));
            double amount = Double.parseDouble(objectInTheWallet.get("Money"));

            if( check && toTake > 0){
                amount -= toTake;
                System.out.println("Your withdrawal " + toTake + "Ariary has been successfully completed");
                System.out.println("Your current money is : " + wallet);
            }
            else {
                System.out.println("You don't have enough balance to make this withdrawal / You can't take a negative value");
            }
        }

        else if(choice == 2){
            System.out.println("Type name :");
            String type = scannerType.nextLine();

            if (wallet.contains(objectInTheWallet.get(type))) {
                wallet.remove(objectInTheWallet.get(type));
                System.out.println("Wallet actually : " + wallet);
            }
            else
                System.out.println("Object doesn't exist in the wallet");
        }

        else {
            System.out.println("Invalid choice");
        }
    }

    private void quantity(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("What's quantity type you want to know ?");
        String value = objectInTheWallet.get(scanner.nextLine());

        if( value != null){
            System.out.println("This type content :" + value);
        }
        System.out.println("Type not found");
    }

    private void checking(){
        System.out.println("Type name ?");
        Scanner scanner = new Scanner(System.in);

        boolean check = wallet.contains(objectInTheWallet.get(scanner.nextLine()));

        if(check){
            System.out.println("This type existing in wallet:" + wallet);
        }
        else {
            System.out.println("This type is not in the wallet");
        }
    }
}
