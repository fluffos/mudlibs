// Based on Patrick :p

#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
    set_property("passive", 1);
    set_name("marlon");
    set_level(30);
    set_short("Marlon the Mystic");
    set_long("Marlon makes magical stones for anyone who wishes to buy them.");
    set_race("human");
    set_gender("male");
    set_id( ({ "marlon", "owner" }) );
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
     You can <buy '#' stone> to buy a specific number of stones.
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
    this_object()->force_me("say I do not sell oils here, that is Jarkun's job. His shop is out to the west.");
    return 1;
  }
  if(str=="stone") {
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't enough money!");
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Marlon hands you a magical stone.");
    say("Marlon hands "+this_player()->query_cap_name()+" a magical stone.");
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
  write("Marlon hands you "+(string)numba+" magical stones.");
  say("Marlon hands "+this_player()->query_cap_name()+" "+(string)numba+" magical stones.");
  while(numba--)
    new("/std/obj/stone")->move(this_player());
  return 1;
}
