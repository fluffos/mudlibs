#include <std.h>

inherit MONSTER;

void create()
{
 ::create();
 set_name("patrick");
 set_short("Patrick, the healer shop owner");
 set_long("He's hard at work making oils and different "
          "types of objects.");
 set_race("human");
 set_gender("male");
 set_id( ({ "patrick", "owner" }) );
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
int fBuy(string str)
{
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="oil" && str!="healing oil" && str!="stone" && str!="magical stone")
   {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
   }
 switch(str)
 {
  case "oil": case "healing oil":
  if (this_player()->query_money("gold") < 20)
   { this_object()->force_me("say You do not have 20 gold for the oil.");
     return 1;
   }
  this_player()->add_money("gold", -20);
  write("Patrick hands you a vial of healing oil.");
  say("Patrick hands "+this_player()->query_cap_name()+" a vial of healing oil.");
  new("/std/obj/oil")->move(this_player());
  return 1;
  break;
  case "stone": case "magical stone":
    this_object()->force_me("say I no longer sell stones here, my good friend in Arlon opened his own shop. If you need to purchase stones, goto him and buy them.");
    return 1;
   if (this_player()->query_money("gold") < 30)
     { this_object()->force_me("say You do not have 30 gold for the stone.");
       return 1; }
this_player()->add_money("gold", -30);
   write("Patrick hands you a magical stone.");
   say ("Patrick hands "+this_player()->query_cap_name()+" a magical stone.");
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
