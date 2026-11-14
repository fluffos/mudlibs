#include "path.h"
#include <money.h>
#include <properties.h>
#include <rooms.h>

inherit "/std/room";

reduce_money(amount) {
  int res;

  res = MONEY_LIB->PayValue2(this_player(), amount, ({"copper"}));
  if(intp(res)) {
    switch(res) {
    case MONEY_NEGATIVE:
      notify_fail("You can't pay a negative amount of money!\n");
      break;
    case MONEY_NO_MONEY:
      notify_fail("You have no money.\n");
      break;
    case MONEY_NOT_ENOUGH:
      notify_fail("You have not enough money!\n");
      break;
    case MONEY_CANT_PAY:
      notify_fail(sprintf(
"You have not enough copper coins! You'll need %d of them!\n",amount));
      break;
    default:
      notify_fail(
"Sorry, an internal error occured. Please leave a bugreport!\n");
      log_file("rep/archwiz",
	       sprintf("\n--\n%s Pirates cave [%O]:\n"
"Error while trying to pay 8888 copper coins.\nMoneyMap: %s\n--\n",
		       ctime(time()),this_object(),
		       "/obj/lib/string"->
		       mixed_to_string(MONEY_LIB->QueryMoney(this_player()))));
    }
    return 0;
  }
  return 1;
}

int insert(string str) {
  int i, amnt;
  string currency;
  object ob;
  if (!this_player())
    return 0;
  if (!str)
    return (int) notify_fail("Insert how many coins?\n") && 0;
  if (sscanf(str,"%d %s",amnt,currency) == 2) {
    if(MONEY_DEMON->PresentMoney(currency,
				 MONEY_LIB->QueryMoney(this_player()))
       != "copper")
      return (int) notify_fail("Sorry, I only take copper coins!\n");
    if(amnt == 1000) {
      if (!reduce_money(1000))
	return 0;
      for (i=1;i<117;i+=1) write(i+". coin\n");
      write("Bored, you throw the remaining money in the air. "
"Magically it vanishes.\n");
      this_player()->SetFrog(0);
      write("You don't feel froggy anymore.\n");
      return 1;
    } else if (amnt==300) {
      if (!reduce_money(300))
	return 0;
      this_player()->Heal(random(10));
      write("You insert your coins and enter the cabin. "
"Water begins to flow. Soap follows. You feel very clean. "
"Gleaming, you leave the cabin.\n");
      this_player()->Set(P_SMELL,"Smells like after a bath.\n");
      if (!ob=present("stinkerx",this_player()))
	return 1;
      ob->remove();
      if (ob) destruct(ob);
      return 1;
    }
    return
      (int) notify_fail("I don't know which service you want to pay for.\n");
  }
  notify_fail("Insert how many copper coins?\n");
  return 0;
}

create() {
  ::create();
  SetIntShort("a stone hut");
  SetIntLong(
"You're in a small stone hut. A sign and a slot are on the wall. "
"A small washing cabin stands in a corner.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail("sign","One the sign a text is written:\n"
"  Hey man, you wanna be no longer a frog?\n"
"  Then insert 1000 copper coins at once, yeah!\n"
"  Hey man, you wanna be really clean?\n"
"  Then insert 300 copper coins at once, yeah!\n");
  AddRoomCmd("insert",#'insert);
  AddExit("north","./plane5");
  AddItem(PIROBJ("sunray"),REFRESH_REMOVE);
}
