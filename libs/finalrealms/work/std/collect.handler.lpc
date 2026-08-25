/* Collect.c, a different bank. It uses the bankhandler.
 * For use by hospitals and temples to let the players have a "raise account"
 * This is a ripoff of the bank.c. The difference is that players can't 
 * close and withdraw. Will change the actions too.. 
 * Baldrick.
 */

#include "/include/money.h"

/* this is a puzzle, if I have the define here it all works, but if the define 
   is in money.h i get a syntax error when I use it later on...
   Baldrick. (and Sojan)

#define BANK_HANDLER "/obj/handlers/bank-h"

   GRRRRRRRRRR, i put the define on the top of money.h and it all worked.
   Let's see if we break something else with this.
*/

inherit "/std/room";

nosave int bing;
string banker;

void set_percentage(int i)
  {
  //BANK_HANDLER->set_percentage(banker, i);
  return;
  }

void set_bank_name(string name)
  {
  banker = name;
  return;
}

void init() 
  {
  add_action("balance", "balance");
  add_action("create_account", "open");
  add_action("deposit", "deposit");
  ::init();
}

int balance() 
  {
  bing=BANK_HANDLER->handle_balance(banker);
  return bing;
}

int deposit(string str) 
  {
   bing=BANK_HANDLER->handle_deposit(banker, str);
  return bing;
}

int create_account() 
  {
  bing=BANK_HANDLER->handle_create_account(banker);
   return bing;
}
