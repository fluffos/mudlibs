// Based on Patrick :p

#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create() {
   ::create();
   set_property("passive", 1);
   set_name("Allisah");
   set_level(50);
   set_short("Allisah the Healer");
   set_long("Allisah is the newly appointed healer of Rhondale. Though she is young, she knows her craft well.");
   set_race("human");
   set_gender("female");
   set_id( ({ "allisah", "owner" }) );
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
 [ A vial of healing oil ]
     A magical blend of different oils from plants and herbs mixed
     togeather to make a healing oil. ( 20 gold pieces )
     You can <buy '#' oil> to buy a specific number of oils.
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
    this_object()->force_me("say I do not sell stones here, that is Jorca's job. His shop is across the road.");
    return 1;
  }
  if(str=="oil") {
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't enough money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Allisah hands you a vial of healing oil.");
    say("Allisah hands "+this_player()->query_cap_name()+" a vial of healing oil.");
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
  write("Allisah hands you "+(string)numba+" vials of healing oil.");
  say("Allisah hands "+this_player()->query_cap_name()+" "+(string)numba+" vials of healing oil.");
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
