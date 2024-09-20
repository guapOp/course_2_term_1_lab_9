#ifndef LAB_9_RPC_CORE_H
#define LAB_9_RPC_CORE_H

#include <string>
#include <iostream>

using namespace std;
using std::byte;


class Wallet {
private:
    string privateKey;
    double balance;
protected:
    string address;
public:
    Wallet(const string& privateKey, const string& address, double initialBalance);
    
    double getBalance() const;
    
    string getAddress() const;
    
    void receiveFunds(double amount);
    
    virtual void sendFunds(double amount, Wallet& recipient) = 0;
    
    friend void transferFunds(Wallet& sender, Wallet& recipient, double amount);
};

class BitcoinWallet : public Wallet {
public:
    BitcoinWallet(const string& privateKey, const string& address, double initialBalance);
    
    void sendFunds(double amount, Wallet& recipient) override;
};

class EthereumWallet : public Wallet {
public:
    EthereumWallet(const string& privateKey, const string& address, double initialBalance);
    
    void sendFunds(double amount, Wallet& recipient) override;
};

void transferFunds(Wallet& sender, Wallet& recipient, double amount);

#endif
