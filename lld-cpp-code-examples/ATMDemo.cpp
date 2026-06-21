#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

using namespace std;

enum class ATMState { Idle, CardInserted, Authenticated };
enum class TransactionStatus { Success, Failed };

struct Card {
    string cardNumber;
};

struct Account {
    string accountNumber;
    double balance;
};

struct TransactionResult {
    TransactionStatus status;
    string message;
};

class BankService {
    unordered_map<string, string> pinByCard;
    unordered_map<string, Account> accountByCard;

public:
    void registerCard(const Card& card, const string& pin, const Account& account) {
        pinByCard[card.cardNumber] = pin;
        accountByCard[card.cardNumber] = account;
    }

    bool validatePin(const Card& card, const string& pin) {
        return pinByCard[card.cardNumber] == pin;
    }

    double getBalance(const Card& card) {
        return accountByCard[card.cardNumber].balance;
    }

    TransactionResult debit(const Card& card, double amount) {
        Account& account = accountByCard[card.cardNumber];
        if (account.balance < amount) {
            return TransactionResult{TransactionStatus::Failed, "Insufficient balance"};
        }
        account.balance -= amount;
        return TransactionResult{TransactionStatus::Success, "Debit successful"};
    }
};

class CashDispenser {
    double availableCash;

public:
    explicit CashDispenser(double availableCash) : availableCash(availableCash) {}

    bool canDispense(double amount) const {
        return availableCash >= amount;
    }

    void dispense(double amount) {
        if (!canDispense(amount)) {
            throw runtime_error("ATM has insufficient cash");
        }
        availableCash -= amount;
        cout << "Please collect cash: " << amount << endl;
    }
};

class ATM {
    ATMState state = ATMState::Idle;
    Card currentCard;
    BankService& bankService;
    CashDispenser& cashDispenser;

public:
    ATM(BankService& bankService, CashDispenser& cashDispenser)
        : bankService(bankService), cashDispenser(cashDispenser) {}

    void insertCard(const Card& card) {
        if (state != ATMState::Idle) {
            throw runtime_error("ATM is busy");
        }
        currentCard = card;
        state = ATMState::CardInserted;
    }

    bool authenticate(const string& pin) {
        if (state != ATMState::CardInserted) {
            throw runtime_error("Insert card first");
        }
        bool valid = bankService.validatePin(currentCard, pin);
        if (valid) state = ATMState::Authenticated;
        return valid;
    }

    double checkBalance() {
        ensureAuthenticated();
        return bankService.getBalance(currentCard);
    }

    TransactionResult withdraw(double amount) {
        ensureAuthenticated();
        if (!cashDispenser.canDispense(amount)) {
            return TransactionResult{TransactionStatus::Failed, "ATM has insufficient cash"};
        }

        TransactionResult result = bankService.debit(currentCard, amount);
        if (result.status == TransactionStatus::Success) {
            cashDispenser.dispense(amount);
        }
        return result;
    }

    void ejectCard() {
        currentCard = Card{};
        state = ATMState::Idle;
    }

private:
    void ensureAuthenticated() {
        if (state != ATMState::Authenticated) {
            throw runtime_error("Authenticate first");
        }
    }
};

int main() {
    BankService bank;
    Card card{"CARD-1"};
    bank.registerCard(card, "1234", Account{"ACC-1", 5000});

    CashDispenser dispenser(10000);
    ATM atm(bank, dispenser);

    atm.insertCard(card);
    cout << "PIN valid: " << boolalpha << atm.authenticate("1234") << endl;
    cout << "Balance: " << atm.checkBalance() << endl;

    TransactionResult result = atm.withdraw(1500);
    cout << result.message << endl;

    atm.ejectCard();
    return 0;
}
