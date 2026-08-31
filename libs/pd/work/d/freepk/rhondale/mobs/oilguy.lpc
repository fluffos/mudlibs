// Based on Patrick :p

#include <std.h>
#include <daemons.h>
inherit MONSTER;
void create() {
   ::create();
   set_property("passive", 1);
   set_name("jarkun");
   set_level(30);
   set_short("Jarkun the Healer");
   set_long("Jarkun is busy making money selling his oils.");
   set_race("human");
   set_gender("male");
   set_id( ({ "jarkun", "owner" }) );
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
  if(!str) {
    write("Buy what?\n");
    return 1;
  }

  if(str=="stone" || str=="magical stone") {
    this_object()->force_me("say I do not sell stones here, that is Marlon's job. His shop is out to the south.");
    return 1;
  }
  if(str=="oil") {
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't enough money!");
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Jarkun hands you a vial of healing oil.");
    say("Jarkun hands "+this_player()->query_cap_name()+" a vial of healing oil.");
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
  if(this_player()->query_money("gold") < 20*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -20*numba);
  write("Jarkun hands you "+(string)numba+" vials of healing oil.");
  say("Jarkun hands "+this_player()->query_cap_name()+" "+(string)numba+" vials of healing oil.");
  while(numba--)
    new("/std/obj/oil")->move(this_player());
  return 1;
}
