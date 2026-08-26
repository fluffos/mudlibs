// The standard bank.
// Written from scratch, amazingly enough.  :o
// Chronos, 8-28-95.

#include <mudlib.h>

#define MINIMUM_BALANCE 2000

inherit ROOM;
 
void create() {
  seteuid(getuid());
  set( "light", 1 );
  set( "short", "The bank.");
  set( "long", @ENDLONG
You're standing in the bank.
You can: open account, deposit, withdraw, balance.
ENDLONG
  );
  ::create();
}

void init() {
  add_action("balance", "balance");
  add_action("withdraw", "withdraw");
  add_action("deposit", "deposit");
  add_action("open_account", "open");
}

int open_account(string str) {
  if (!str) return 0;
  if (str != "account") return 0;
  if (TP->query("bank_balance")) {
    write("You already have an account.\n");
    return 1;
  }
  if (TP->query_coins() < MINIMUM_BALANCE) {
  write("The minimum balance at this bank is "+MINIMUM_BALANCE +
   " coins.\nYour account can never go below this amount.\n");
    return 1;
  }
  TP->debit(MINIMUM_BALANCE);
  TP->add("bank_balance", MINIMUM_BALANCE);
  write("You deposit " + MINIMUM_BALANCE + 
         " coins, thus opening your account.\n");
  return 1;
}

int withdraw(mixed str) {
  int coins;
  if (stringp(str)) {
    if (sscanf(str, "%d coins", coins) != 1) {
      write("Usage: withdraw <number> [coins]\n");
      return 1;
    }
  }
  if (intp(str)) {
    coins = str ;
  }
  if (TP->query("bank_balance")<coins) {
    write("You don't have that much money in your account.\n");
    return 1;
  }
  if ((int)TP->query("bank_balance") - coins < MINIMUM_BALANCE) {
    write("That withdrawal would put you below your minimum balance requirement.\n");
    return 1;
  }
  TP->credit(coins);
  TP->add("bank_balance", -coins);
  write("You withdraw " + coins + " coins from your account.\n");
  return 1;
}

int deposit(mixed str) {
  int coins;
  if (stringp(str)) {
    if (sscanf(str, "%d coins", coins) != 1) {
      write("Usage: deposit <number> [coins]\n");
      return 1;
    }
  }
  if (intp(str)) {
    coins = str ;
  }
  if (!coins) {
    write("Usage: deposit <number> [coins]\n");
    return 1;
  }
  if (!TP->query("bank_balance")) {
    write("You don't have an account here.\n");
    return 1;
  }
  if (TP->query_coins() < coins) {
    write("You don't have that many coins.\n");
    return 1;
  }
  TP->add("bank_balance", coins);
  TP->debit(coins);
  write("You deposit "+coins+" coins in the bank.\n");
  return 1;
}

int balance() {
  write("Your balance is currently " + TP->query("bank_balance") +
     " coins.\n");
  return 1;
}
