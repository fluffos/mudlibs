// Written by Chronos 8-28-95.
// Replaced the old money system, which aggrevated me.
// Now 1 coin = The coin!
#include <mudlib.h>

int coins;

varargs
int credit(int amt, int flag) {
  if (userp(this_player()) && !flag) {
   log_file("MONEY_XFER", "["+ctime(time())+"] "+TPN+
 " credited "+amt+" coins to "+this_object()->query("cap_name")+".\n" ) ;
  }
  coins += amt;
  return coins ;
}

int debit(int cost) {
  if ((coins - cost) < 0) return 0;
  else {
    coins -= cost;
  return 1;
  }
}

int query_coins();

int query_coins() {
  return coins ;
}

int query_coins_in_bank() {
  if (!userp(this_object())) return -1;
  return this_object()->query("bank_balance");
}
