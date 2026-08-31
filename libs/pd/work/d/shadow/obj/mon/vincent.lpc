#include <std.h>

inherit MONSTER;

void create()
{
 ::create();
 set_name("vincent");
 set_short("Vincent, the oil maker");
 set_long("He's hard at work making oils and different "
          "types of objects.");
 set_race("human");
 set_gender("male");
 set_id( ({ "vincent", "owner" }) );
}

void init()
{
 ::init();
 add_action("fBuy", "buy");
 add_action("fRead", "read");
// set_heart_beat(10);
}
int fRead(string str)
{
 if (!str || str!="sign")
   return notify_fail("Read what?\n");
 say (this_player()->query_cap_name()+" reads over the sign.");
 write("The sign reads:
-----------------------------------------
 [ A vial of healing oil ]
     A magical blend of different oils from plants and herbs mixed
     togeather to make a healing oil. ( 20 gold pieces )
-----------------------------------------");
 return 1;
}

int fBuy(string str) {
  int numba;
  int over, enc, maxenc;
  object oil;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="oil") {
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Vincent hands you a vial of healing oil.");
    say("Vincent hands "+this_player()->query_cap_name()+" a vial of healing oil.");
    new("/std/obj/oil")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "oil") {
    write("Buy what?\n");
    return 1;
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(numba > 1000) {
    this_object()->force_me("say I dont have that many right now!");
    return 1;
  }
  // If they try to buy too many...

  over = enc + ((numba / 15) * 2) - maxenc;
  if(over > 0) {
    numba = numba - ((over * 15)/2);
    numba -= numba % 15;
    if(numba == 0) {
      this_object()->force_me("say You can't hold any more oils!");
      return 1;
    }
    this_object()->force_me("say I'd say you could only hold "+numba+" more
oils.");
  }
  if(this_player()->query_money("gold") < 20*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -20*numba);
  write("Vincent hands you "+(string)numba+" vials of healing oil.");

  say("Vincent hands "+this_player()->query_cap_name()+" "+(string)numba+" vials of healing oil.");
  while(numba > 0) {
    oil = new("/std/obj/oil");
    if(numba >= 15)
      oil->set_uses(15);
    else
      oil->set_uses(numba);
    numba -= 15;
    oil->move(this_player());
  } 
  return 1;
}
