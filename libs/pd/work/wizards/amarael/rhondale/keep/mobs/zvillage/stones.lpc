#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create() {
   ::create();
   set_property("passive", 1);
   set_name("Jorca");
   set_level(50);
   set_short("Jorca the Mystic");
   set_long("Jorca makes magical stones for anyone who wishes to buy them.");
   set_race("human");
   set_gender("male");
   set_id( ({ "jorca", "owner" }) );
}
void init() {
   ::init();
     add_action("fBuy", "buy");
     add_action("fRead", "read");
}

int fRead(string str) {

    if (!str || str!="sign")
       return notify_fail("Read what?\n");
    say (this_player()->query_cap_name()+" reads over the sign.");
    write("The sign reads:
-----------------------------------------
 [ A magical stone ]
     A magical stone used to replenish mana. ( 30 gold pieces )
     You can <buy '#' oil> to buy a specific number of oils.
-----------------------------------------");
 return 1;
}
int fBuy(string str) {
  int numba;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="oil") {
    this_object()->force_me("say I do not sell oils here, that is Allisah's job. Her shop is across the road.");
    return 1;
  }
  if(str=="stone") {
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't enough money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Jorca hands you a magical stone.");
    say("Jorca hands "+this_player()->query_cap_name()+" a magical stone.");
    new("/std/obj/stone")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "stone") {
    write("Buy what?\n");
    return 1;
  }

  if(this_player()->query_money("gold") < 30*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -30*numba);
  write("Jorca hands you "+(string)numba+" magical stones.");
  say("Jorca hands "+this_player()->query_cap_name()+" "+(string)numba+" magical stones.");
  while(numba--)
    new("/std/obj/stone")->move(this_player());
  return 1;
}
