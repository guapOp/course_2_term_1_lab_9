#include "RPC_core.h"
#include "iostream"

using namespace std;


Wallet::Wallet(const string &privateKey, const string &address, double initialBalance) :
    privateKey(privateKey), address(address), balance(initialBalance)
{}

double Wallet::getBalance() const { return balance; }
string Wallet::getAddress() const { return address; }

void Wallet::receiveFunds(double amount) {
    balance += amount;
}

BitcoinWallet::BitcoinWallet(const string& privateKey, const string& address, double initialBalance)
        : Wallet(privateKey, address, initialBalance) {}

void BitcoinWallet::sendFunds(double amount, Wallet& recipient) {
    if (amount <= getBalance()) {
        transferFunds(*this, recipient, amount);
        cout << "send " << amount << " BTC to " << recipient.getAddress() << endl;
    } else {
        cout << "low balance" << endl;
    }
}


EthereumWallet::EthereumWallet(const string& privateKey, const string& address, double initialBalance)
        : Wallet(privateKey, address, initialBalance) {}

void EthereumWallet::sendFunds(double amount, Wallet& recipient) {
    if (amount <= getBalance()) {
        transferFunds(*this, recipient, amount);
        cout << "send " << amount << " ETH to " << recipient.getAddress() << endl;
    } else {
        cout << "low balance" << endl;
    }
}


void transferFunds(Wallet& sender, Wallet& recipient, double amount) {
    sender.balance -= amount;
    recipient.receiveFunds(amount);
}
