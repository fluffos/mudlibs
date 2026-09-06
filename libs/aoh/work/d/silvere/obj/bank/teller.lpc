// the new and improved invisible bank teller for Silvere
// created:          Tune [27-Apr-1999]


#include <money.h>

inherit BANK_TELLER;


void create()
{
   ::create();
   
   SetShort("the transactions window");  // see below
   
   AddId( ({ "window", "counter" }) );
   
   AddAdjective( ({ "transaction", "banking", "bank" }) );
   
}

// as the Long is hard-coded into the bank teller obj, we have to
// overwrite it the hard way

varargs string QueryLong()
{
   return 
      "The capable clerks at the transactions counter can "
      "assist you in all of your financial matters, which "
      "include:\n"
      "  Accessing your funds:      WITHDRAW <amount> \n"
      "  Depositing cash:           DEPOSIT <amount> \n"
      "  Checking your balance:     BALANCE \n"
      "  Cancelling our services:   CLOSE ACCOUNT \n"
      "Please note that a small service fee is levied for certain "
      "transactions. \n";
}

varargs string InvShort()
{
  return ""; // this makes it invis in room, but you can look at it
}
