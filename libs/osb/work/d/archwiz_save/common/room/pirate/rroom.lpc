/*  -*- LPC -*-  */
#include "path.h"
#include <money.h>
#include <moving.h>
#include <combat.h>
#include <magic.h>

inherit "/std/room";

int count;

string r(int i)
{
  if (i<1||i>4) return 0;
  return ({
   "You see a vision of a distant room. A voice speaks: '...I really need "+
   "you to rescue the holy grail, Doctor j.........'. The vision fades. "+
   "Waiting for the answer ...\n",
   "You see a vision of a distant land. You recognize it. It's Britannia! "+
   "You look straight into Lord Britishs throneroom. He speaks: '.... "+
   "Only an a.......... may save our land from this terrible fate. Will "+
   "you be the one? ...'. The vision fades.\n"+
   "You feel the presence of someone who waits for the correct answer. ",
   "You see a vision of a distant city. You recognize it. Its Skarabrae! "+
   "You look straight into the adventurers guild. An elf says: '...I hope "+
   "you will be the one, who will kill this evil wizard m.........'. "+
   "The vision fades. The Unseen is waiting for the answer.\n",
   "meaning of life and so on ... ?\n"})[i-1]; /* Pepel sighs deeply on 2.5.95 */
}

int reduce_money(int amount) {
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
  write(sprintf("You pay %d copper coins.\n",amount));
  return 1;
}

int pay(string str) {
  if (!str) return (int) notify_fail("Pay with what?\n") && 0;
  if ((str=="money") && (count<3) && (count != -1)) {
    if (!reduce_money(8888))
      return 0;
    write("You buy the answer to this riddle, but you can't unterstand it, "
"because the words are too softly spoken.\n");
    say(this_player()->QueryName()+" buys the answer for a riddle.\n");
    count++;
    return 1;
  }
  notify_fail("What do you want to pay with?\n");
  return 0;
}

look_mirror() {
  write("You can see the Nightfall City shop. You see:\n"+
  (CITY("shop"))->GetIntDesc());
  return "";
}

int go_north() {
  count=-1;
  if (!this_player()) return 0;
  this_player()->move(CITY("shop"),M_GO,"into the mirror");
  return 1;
}

int enter(string str) {
  if (str!="mirror") return 0;
  go_north();
}

int listen() {
  switch (count) {
    case -1:
    case  4: write("Not now. Come back later...\n");break;
    case  0: write(r(1));break;
    case  1: write(r(2));break;
    case  2: write(r(3));break;
    case  3: write(r(4));break;
    }
  return 1;
}

correct() {
  count++;
  write("\nRight!, a voice booms out. Go on like that.\n");
  say("\nRight!, a voice booms out.\n");
}

int answer(string str) {
  object ob;
  if (!str) return (int) notify_fail(
    "Answer what?\n") && 0;
  if (!this_player()) return 0;
  switch (count) {
    case 0: if (str=="jones") 
	      correct();
	      break;
    case 1: if (str=="avatar")
              correct();
	      break;
    case 2: if (str=="mangar")
              correct();
	      break;
    case 3: if (str=="42") {
	      count++;
	      write("\nRight!, You solved all riddles. Your reward will follow... "
"Great, you fulfilled this small quest!\n");
	      say("\nRight!!!\n");
              ob=clone_object("/std/weapon");
	      ob->SetShort("a morningstar");
	      ob->SetLong(
"A large spiked ball of steel connected to a stick by a chain.\n");
	      ob->SetWC(17);
	      ob->SetNumberHands(2);
	      ob->SetValue(5000);
	      ob->SetWeight(20000);
	      ob->SetWeaponType(WT_CLUB);
	      ob->SetDamType(DT_BLUDGEON);
	      ob->SetIds(({"weapon","morningstar"}));
	      ob->SetAds(({"spiked","large","a"}));
	      ob->move(this_object(),M_DROP);
              ob=clone_object("/std/thing");
	      ob->SetShort("a small golden cube");
	      ob->SetLong(
"This cube is the proof that you solved the 4 riddles.\n");
	      ob->SetValue(0);
	      ob->SetWeight(200);
	      ob->SetAds(({"small","golden"}));
	      ob->SetIds(({"cube"}));
	      ob->move(this_object(),M_DROP);
              write("Look around.\n"); }
	      break;
	default: write("Wrong!\n");
    }
    return 1;
}

create() {
  ::create();
  SetIntShort("riddle room");
  SetIntLong(
"You're in the magic riddle room. To the north is a magic mirror. "
"In the mirror you see the Nightfall City shop. On the wall is a sign.\n");
  AddDetail("sign","Something is written on it.\n");
  AddReadMsg("sign",
"'listen' to all riddles and 'answer'.\n"
"Or 'pay money' and you will pay 8888 copper coins for the right "
"answer. "
"This possibility is only given for the first 3 riddles.\n");
  AddDetail(({"room","magic room","riddle room","magic riddle room"}),
QueryIntLong());
  AddDetail(({"floor","ground","walls","wall","ceiling"}),
"You see nothing special.\n");
  AddDetail(({"magic mirror","mirror","nightfall city shop",
  "city shop","shop"}),#'look_mirror);
  SetTPort(TPORT_NO);
  AddRoomCmd("pay",#'pay);
  AddRoomCmd("answer",#'answer);
  AddRoomCmd("listen",#'listen);
  AddExit("north",#'go_north);
  AddExit("enter",#'enter);
  HideExit("north",1);
  HideExit("enter",1);
  reset();
}

reset() {
  ::reset();
  count=0;
}
