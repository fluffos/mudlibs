#include <std.h>

inherit MONSTER;

void create()
{
 ::create();
 set_name("goldar");
 set_short("Goldar, the high magician");
 set_long("He's hard at work studying the magic arts and different "
          "scrolls.");
 set_race("human");
 set_gender("male");
 set_id( ({ "goldar", "owner" }) );
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
 [ A magical stone ] 
     The stone found deep in the Sindarii ocean has been found to
     emits a green light that carrys mana that is absorbed by the
     user to regain mana power. ( 50 gold peices )

 [ A magical amulet ] 
     These amulets are imported from the high mage in Lodos, and
     can be used to help protect the wearer from damage while
     fighting. ( 800 gold peices )
-----------------------------------------");
 return 1;
}
int fBuy(string str)
{
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="amulet" && str!="magic amulet" && str!="stone" && str!="magical stone")
   {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
   }
 switch(str)
 {
  case "amulet": case "magic amulet":
  if (this_player()->query_money("gold") < 800)
   { this_object()->force_me("say You do not have 800 gold for an amulet.");
     return 1;
   }
  this_player()->add_money("gold", -800);
  write("Goldar hands you a magic amulet.");
  say("Goldar hands "+this_player()->query_cap_name()+" a magic amulet.");
  new("/d/lodos/obj/misc/amulet")->move(this_player());
  return 1;
  break;
  case "stone": case "magical stone":
   if (this_player()->query_money("gold") < 50)
     { this_object()->force_me("say You do not have 50 gold for the stone.");
       return 1; }
this_player()->add_money("gold", -50);
   write("Goldar hands you a magical stone.");
   say ("Goldar hands "+this_player()->query_cap_name()+" a magical stone.");
   new("/std/obj/stone")->move(this_player());
   return 1;
   break;
 }
}

/* void heart_beat()
{
 if (random(50) > 25)
  {
 this_object()->force_me("say if you want to buy some healing oil type,
<buy oil>");

}
*/
