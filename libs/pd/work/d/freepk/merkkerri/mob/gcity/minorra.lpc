#include <std.h>

inherit MONSTER;

void create()
{
 ::create();
set_name("minorra");
set_short("Minorra");
set_long("Minorra sells oils and different healing aids.");
set_race("gnoll");
set_gender("female");
set_id(({"minorra", "gnoll", "owner"}));
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
 write("Minorra hands you a vial of healing oil.");
say("Minorra hands "+this_player()->query_cap_name()+" a vial of healing
oil.");
  new("/std/obj/oil")->move(this_player());
  return 1;
  break;
    return 1;
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
