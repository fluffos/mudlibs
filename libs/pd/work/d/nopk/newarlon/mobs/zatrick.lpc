#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create()
{
    ::create();
    set_name("zatrick");
    set_level(30);
    set_short("Zatrick, the Healery Storeowner");
    set_long("Zatrick is a tall human, hard at work over cauldrons, and bossing around his apprentice, Pelgadiss.");
    set_race("human");
    set_gender("male");
    set_id( ({ "zatrick", "storeowner" }) );
    set_body_type("human");
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
           --Items For Sale--
-----------------------------------------
 [ A vial of healing oil ]
     A magical blend of different oils from plants and herbs mixed
     togeather to make a healing oil. ( 20 gold pieces )
     You can <buy '#' oil> to buy a specific number of oils.
 
 [ A magical stone ] 
     The stone found deep in the Sindarii ocean has been found to
     emits a green light that carrys mana that is absorbed by the
     user to regain mana power. ( 30 gold peices )
     You can <buy '#' stones> to buy a specific number of stones.
-----------------------------------------");
 return 1;
}

int fBuy(string str) {
  int numba, enc, maxenc, over;
  object oil;

  enc = this_player()->query_internal_encumbrance();
  maxenc = this_player()->query_max_internal_encumbrance();

  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="oil") {
    if(enc + 2 > maxenc) {
      this_object()->force_me("say You can't hold another oil!");
      return 1;
    }
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Zatrick hands you a vial of healing oil.");
    say("Zatrick hands "+this_player()->query_cap_name()+" a vial of healing
oil.");
    new("/std/obj/oil")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    return notify_fail("Buy what?\n");
  }
  if(str != "oil") {
    return notify_fail("Buy what?\n");
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
    return 1;
  }
  if(this_player()->query_money("gold") < 20*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -20*numba);
  write("Zatrick hands you "+(string)numba+" vials of healing oil.");
  say("Zatrick hands "+this_player()->query_cap_name()+" "+(string)numba+"
vials of healing oil.");

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
