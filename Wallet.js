const prompt = require("prompt-sync")();

let amount = 500;
let objectInTheWallet = {};
let wallet = [objectInTheWallet];
let action;

function displayMenu() {
  console.log("1. View all things on the wallet");
  console.log("2. Deposit something on the wallet");
  console.log("3. Withdrawal");
  console.log("4. Quantity's type");
  console.log("5. Check if one type existing");

  action = parseInt(prompt("Enter your action: "));
}

function viewWallet() {
  console.log(wallet);
}

function deposit() {
  console.log("What's type of something you want to add :");
  console.log("1. Money");
  console.log("2. Others");
  const userChoice = parseInt(prompt());

  const check = objectInTheWallet.hasOwnProperty("Money");

  if (userChoice === 1) {
    console.log("How much money you want to add :");
    let toAdd = parseFloat(prompt());

    if (!check && toAdd > 0) {
      amount += toAdd;
      objectInTheWallet["Money"] = amount.toString();
      console.log(`Adding money on your wallet: ${JSON.stringify(wallet)}`);
    } else if (check && toAdd > 0) {
      let amount = parseFloat(objectInTheWallet["Money"]);
      amount += toAdd;
      objectInTheWallet.Money = amount.toString();
      console.log(`Total money on your wallet is updating to: ${JSON.stringify(wallet)}`);
    } else {
      console.log("Add a correct value");
    }
  } else {
    console.log("Type name :");
    const type = prompt();
    console.log("How much ? :");
    const value = parseFloat(prompt());

    objectInTheWallet[type] = value.toString();
    wallet.push(objectInTheWallet);

    console.log(`Your ${type} adding to the wallet`);
    console.log(`Your wallet actually: ${JSON.stringify(wallet)}`);
  }
}

function withdraw() {
  console.log("Taking :");
  console.log("1 . Money");
  console.log("2 . Others");
  const userChoiceTake = parseInt(prompt('Enter your choice: '));

  if (userChoiceTake === 1) {
    const toTake = parseFloat(prompt('Enter money value you want taking : '));
    const check = wallet.includes(objectInTheWallet["Money"]);
    let amount = parseFloat(objectInTheWallet["Money"]);

    if (check && toTake > 0) {
      amount -= toTake;
      console.log(`Your withdrawal ${toTake} Ariary has been successfully completed`);
      console.log(`Your current money is : ${wallet}`);
    } else if (toTake < 0) {
      console.log("You can't take a negative value");
    } else {
      console.log("You don't have money in your wallet");
    }
  } else if (userChoiceTake === 2) {
    const type = prompt('Type name: ').trim();

    if (wallet.includes(objectInTheWallet[type])) {
      const index = wallet.indexOf(objectInTheWallet[type]);
      wallet.splice(index, 1);
      console.log(`Wallet actually : ${wallet}`);
    } else {
      console.log("Object doesn't exist in the wallet");
    }
  } else {
    console.log("Invalid choice");
  }
}

function checkType() {
  console.log("What's quantity type you want to know ?");
  const input = prompt('Enter the type: ');

  const value = objectInTheWallet[input];

  if (value !== undefined) {
    console.log(`This type content: ${value}`);
  } else {
    console.log("Type not found");
  }
}

function checkTypeExisting() {
  console.log("Type name ?");
  const inputType = prompt('');

  const checkInputType = wallet.includes(objectInTheWallet[inputType]);

  if (checkInputType) {
    console.log(`This type existing in wallet: ${wallet}`);
  } else {
    console.log("This type is not in the wallet");
  }
}

function handleAction() {
  switch (action) {
    case 1:
      viewWallet();
      break;
    case 2:
      deposit();
      break;
    case 3:
      withdraw();
      break;
    case 4:
      checkType();
      break;
    case 5:
      checkTypeExisting();
      break;
    default:
      console.log("Invalid action");
  }
}

displayMenu();
handleAction();
