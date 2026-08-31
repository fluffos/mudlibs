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

 [ A magical stone ] 
     The stone found deep in the Sindarii ocean has been found to
     emits a green light that carrys mana that is absorbed by the
     user to regain mana power. ( 30 gold peices )
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
 if (str!="oil" && str!="healing oil")
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
  write("Vincent hands you a vial of healing oil.");
  say("Vincent hands "+this_player()->query_cap_name()+" a vial of healing oil.");
  new("/std/obj/oil")->move(this_player());
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
