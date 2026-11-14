/*
* NIGHTFALL FINANCE DEPARTMENT
*  rosie.c
*  This file is a short demonstration for the use of money.
*  Rosie sells roses for exactly the price of 15 copper coins,
*  if the player doesn't have them, she charges 2 copper coins
*  exchangement rate.
*  For further details see:
*   /d/archwiz/common/finance/cbteller.c
*   /std/shop.c
*   /doc/std/money
*  Or ask the Archwizard of Finance.
*
*  THU:16.10.92  Orcgrimm
*/

#include <properties.h>
#include <money.h>
#include <moving.h>

inherit "/std/npc";
inherit MONEY_LIB;

#define ROSE "/d/archwiz/common/finance/exm/rose"
/*-------------------------------------------------------------------------*/
create () {
  object obj;
  if (::create()) return;
  SetName("Rosie");
  SetLong("This is Rosie, the flower girl. She sells very beautiful roses, "+
          "one rose costs exactly 15 copper coins.\n");
  SetRace("human");
  SetGender(GENDER_FEMALE);
  SetWimpy(QueryMaxHP()/2);
  SetGoChance(20);
  SetMsgIn  ( ({ "arrives", "hushes in" }) );
  SetMsgOut ( ({ "leaves", "hushes out" }) );
  SetMMsgIn ( ({ "plops in", "is here" })  );
  SetMMsgOut( ({ "fades away", "left" })   );
  SetGoChance(0);
}
/*-------------------------------------------------------------------------*/
init() {
  ::init();
  add_action("buy","buy");
}
/*-------------------------------------------------------------------------*/
give_rose() {
  object obj;
  obj=clone_object(ROSE);
  obj->move(this_player(),M_GIVE);
  write("Rosie gives you a wonderful rose.\n");
  say(this_player()->QueryName()+" buys a rose.\n",this_player());
}
/*-------------------------------------------------------------------------*/
buy(str) {
  mixed *m;
  int i;
  if (!str || str!="rose") return 0;
  
  /*  we want to check if the player has EXACTLY 15 copper coins, so we
   *  query his money-array:
   */
  m=QueryMoney(this_player());
  if (!m || !sizeof(m)) {
    /* oh, the player does not owe a single coin! */
    notify_fail("You have no money at all!\n");
    return 0;
  }
  
  /*  lets check if he has the copper coins  */
  if ((i=member(m, N_COPPER))>=0)
    /* ok, he has coppers, but how much? */
    if (m[i+1]>=15) { 
      /* ok, the player has the specified amount, subtract directly */
      AdjustMoney(this_player(),-15,N_COPPER);
      give_rose();
      return 1;
    }

  write("\"You do not have exactly 15 copper coins, so I charge the value of "+
        "2 coppers for exchangement.\", she says.\n");
  
  /*  now test if the player has the amount of 15 (rose) + 2 (charge) MU */
  if (QuerySomeonesValue(this_player())<17) {
    write("You do not have enough money.\n");
    return 1;
  }
  
  /*  and now we let him pay.
   *  PayValue2() is just the same like PayValue(), but returns two strings:
   *  how much did you pay and how much did you get back.
   */
  m=PayValue2(this_player(),17);
  write("You pay "+m[0]+
       ( m[1] ? " and receive "+m[1] : "") +".\n");
  give_rose();
  return 1;
}
/*-------------------------------------------------------------------------*/

  
