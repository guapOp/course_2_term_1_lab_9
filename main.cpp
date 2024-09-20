#include <iostream>
#include "RPC_core.h"

using namespace std;

int main() {

    // BTC
    BitcoinWallet MyWallet("d0;Bry-V<%4QAom", "1FmAb2Mci2aqwMe3CswQRtctPaiaH8a79r", 100.0);
    BitcoinWallet FriendWallet("|,>:@BU_KA(34TV", "bc1qhdxmpx76v73c3xxhk2fu095y862lxkjswjdzrl", 50.0);

    cout << "my BTC balance: " << MyWallet.getBalance() << " BTC" << endl;
    cout << "frient BTC balance: " << FriendWallet.getBalance() << " BTC" << endl;

    MyWallet.sendFunds(30.0, FriendWallet);

    cout << "after transfer:" << endl;
    cout << "my balance: " << MyWallet.getBalance() << " BTC" << endl;
    cout << "friend balance: " << FriendWallet.getBalance() << " BTC" << endl;



    // ETH
    EthereumWallet ETHMyWallet("@k<$nm.=ZoHG74o", "0xAb5801a7D398351b8bE11C439e05C5B3259aec9B", 10000.0);
    EthereumWallet ETHFriendWallet("ilq(Zc%BGHB#xG[", "0x4B0897b0513fdc7C541B6d9D7E929C4e5364D2dB", 10000.0);

    cout << "-----------------------------" << endl;

    cout << "my ETH balance: " << ETHMyWallet.getBalance() << " ETH" << endl;
    cout << "frient ETH balance: " << ETHFriendWallet.getBalance() << " ETH" << endl;

    ETHMyWallet.sendFunds(30.0, ETHFriendWallet);

    cout << "after transfer:" << endl;
    cout << "my balance: " << ETHMyWallet.getBalance() << " ETH" << endl;
    cout << "friend balance: " << ETHFriendWallet.getBalance() << " ETH" << endl;

    return 0;
}
