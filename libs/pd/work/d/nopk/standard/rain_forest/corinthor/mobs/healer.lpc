// Based on Patrick :p

#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create() {
   ::create();
     set_property("passive", 1);
     set_name("Mori'nen");
     set_level(5);
     set_short("Master Mori'nen");
     set_long("Mori'nen is the aged Master of Healers in Corinthor. He is the most learned in both magical and herbal healing, and an expert at making regenerative potions.");
     set_race("elf");
     set_body_type("human");
     set_gender("male");
     set_id( ({ "elf", "mori'nen", "morinen", "owner" }) );
}
void init() {
   ::init();
     add_action("fBuy", "buy");
     add_action("fRead", "read");
}
int fRead(string str) {
    if (!str || str!="sign")
       return notify_fail("Read what?\n");
    say(this_player()->query_cap_name()+" reads over the sign.");
    write("The sign reads:
-----------------------------------------
 [ A vial of healing oil ]
     A magical blend of different oils from plants and herbs mixed
     together to make a healing oil. ( 20 gold pieces )
     You should <buy '#' oil> to buy a specific number of oils.
-----------------------------------------");
 return 1;
}
int fBuy(string str) {
  int numba;
  object oil;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="stone" || str=="magical stone") {
    this_object()->force_me("say I apologise, but I do not sell stones here.");
    return 1;
  }
  if(str=="oil") {
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't enough money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write(this_object()->query_cap_name()+" hands you a vial of healing oil.");
    say(this_object()->query_cap_name()+" hands "+this_player()->query_cap_name()+" a vial of healing oil.");
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
  if(this_player()->query_money("gold") < 20*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -20*numba);
  write(this_object()->query_cap_name()+" hands you "+(string)numba+" vials of healing oil.");
  say(this_object()->query_cap_name()+" hands "+this_player()->query_cap_name()+" "+(string)numba+" vials of healing oil.");
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
