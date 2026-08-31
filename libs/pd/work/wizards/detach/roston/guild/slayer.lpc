#include <std.h>

inherit MONSTER;

void create()
{
 ::create();
 set_name("slayer");
 set_short("%^BOLD%^%^WHITE%^Slayer, the Dark Spirit");
 set_long("%^BOLD%^%^BLACK%^Slayer is a spirit that pleases the members "
          "of the D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^s%^WHITE%^o"
          "%^BLACK%^u%^WHITE%^l%^BLACK%^s, with healing products. He "
          "is holding up a sign with writing on it.");
 set_race("Demon");
 set_gender("male");
 set_id( ({ "slayer", "owner" }) );
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
%^BOLD%^%^WHITE%^ [ A soul ]
%^BOLD%^%^BLACK%^These souls are the souls of past members of the dark souls. 
                                       %^YELLOW%^ (15 gold pieces )

%^BLACK%^ [ A pile of Ashes] 
%^WHITE%^These ashes are from the burnt corpses of the fallen members
     of the dark soul clan. %^YELLOW%^(25 gold peices )%^RESET%^
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
 if (str!="soul" && str!="dark soul" && str!="ashes" && str!="black
ashes")
   {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
   }
 switch(str)
 {
  case "soul": case "dark soul":
  if (this_player()->query_money("gold") < 20)
   { this_object()->force_me("say You do not have 20 gold for the oil.");
     return 1;
   }
  this_player()->add_money("gold", -15);
  write("Slayer hands you %^BOLD%^%^BLACK%^A soul%^RESET%^.");
  say("Slayer hands "+this_player()->query_cap_name()+" a soul.");
  new("/wizards/detach/roston/guild/soul")->move(this_player());
  return 1;
  break;
  case "ashes": case "black ashes":
   if (this_player()->query_money("gold") < 25)
     { this_object()->force_me("say You do not have 30 gold for the
ashes.");
       return 1; }
   this_player()->add_money("gold", -25); 
   write("Slayer hands you %^BOLD%^%^WHITE%^A pile of ashes.");
   say ("Slayer hands "+this_player()->query_cap_name()+" a pile of
ashes.");
   new("/wizards/detach/roston/guild/ashes")->move(this_player());
   return 1;
   break;
 }
}

/* void heart_beat()
{
 if (random(50) > 25)
  {
 this_object()->force_me("say if you want to buy a soul type,
<buy soul>");

}
*/
