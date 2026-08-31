#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("zelgadiss");
 set_short("Zelgadiss, the magician");
 set_long("He is busy taking stones he gets from his friend John on "
          "the pier of Arlon and storing mana in these stones.");
 set_race("human");
 set_gender("male");
 set_id( ({ "zelgadiss", "owner", "magician" }) );
}
void init()
{
 ::init();
 add_action("fBuy", "buy");
 add_action("fRead", "read");
}
 set_heart_beat(10);
int fRead(string str)
{
 if (!str || str!="sign")
   return notify_fail("Read what?\n");
 say (this_player()->query_cap_name()+" reads over the sign.");
 write("The sign reads:
-----------------------------------------
 [ A magical stone ] 
     The stone found deep in the Sindarii ocean has been found to
     emits a green light that carrys mana that is absorbed by the
     user to regain mana power. ( 30 gold peices )
-----------------------------------------");
 return 1;
}
int fBuy(string str) {
  int numba;
  if(!str) {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
  }
  if(str=="stone" || str=="magical stone") {
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Zelgadiss hands you a magical stone.");
    say ("Zelgadiss hands "+this_player()->query_cap_name()+" a magical stone.");
    new("/std/obj/stone")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
  }
  if(str != "stones" && str != "magical stones") {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(this_player()->query_money("gold") <30*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -30*numba);
  write("Zelgadiss hands you "+(string)numba+" magical stones.");
  say("Zelgadiss hands "+this_player()->query_cap_name()+" "+(string)numba+" magical stones.");
  while(numba--)
    new("/std/obj/stone")->move(this_player());
  return 1;
}
