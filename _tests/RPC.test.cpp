#include <gtest/gtest.h>
#include "../RPC_core.h"

TEST(ETHTest, Send) {
    EthereumWallet ethSender("123", "0xAb5801a7D398351b8bE11C439e05C5B3259aec9B", 100.0);
    EthereumWallet ethRecipient("321", "0x4B0897b0513fdc7C541B6d9D7E929C4e5364D2dB", 50.0);

    ethSender.sendFunds(30.0, ethRecipient);

    EXPECT_DOUBLE_EQ(ethSender.getBalance(), 70.0);
    EXPECT_DOUBLE_EQ(ethRecipient.getBalance(), 80.0);

}

TEST(BTCTest, Send) {
    BitcoinWallet btcSender("456", "1FmAb2Mci2aqwMe3CswQRtctPaiaH8a79r", 100.0);
    BitcoinWallet btcRecipient("654", "bc1qhdxmpx76v73c3xxhk2fu095y862lxkjswjdzrl", 50.0);

    btcSender.sendFunds(20.0, btcRecipient);

    EXPECT_DOUBLE_EQ(btcSender.getBalance(), 80.0);
    EXPECT_DOUBLE_EQ(btcRecipient.getBalance(), 70.0);
}
