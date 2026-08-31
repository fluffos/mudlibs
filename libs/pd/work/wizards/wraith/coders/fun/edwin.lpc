#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("edwin");
 set_short("Edwin, the Alchemist");
 set_long("He sits in his corner, enchanting scrolls and creating orbs.");
 set_race("Sackralr");
 set_body_type("human");
 set_gender("male");
 set_id( ({ "edwin", "owner" }) );
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
 say (this_player()->query_cap_name()+" reads the sign.");
 write("The sign reads:
-----------------------------------------
 [ A magic orb ]
     A magic orb that will help regenerate magick.
     ( 20 gold pieces )
     You can <buy '#' orb> to buy a specific number of orbs.
 [ An Arcane Scroll ]
      Enchanted with the Arcane magiks of the sorcerers,
      this scroll can be used to mend the wounds of battle.
      ( 30 gold pieces )
     You can <buy '#' scroll> to buy a specific number of scrolls.
-----------------------------------------");
 return 1;
}
int fBuy(string str) {
  int numba;
  object oil;
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="orbs" && str!="scroll" && str!="orb" && str!="scrolls")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "scrolls":
 case "scroll":
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 30*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -30*numba);
      write("Edwin hands you "+(string)numba+" scrolls.");
      say("Edwin hands "+this_player()->query_cap_name()+"
"+(string)numba+" scrolls.");
      while(numba--)
        new("/d/guilds/acheron/scroll")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Edwin hands you some scrolls.");
    say("Edwin hands "+this_player()->query_cap_name()+" some scrolls.");
    new("/d/guilds/acheron/scroll")->move(this_player());
    return 1;
  break;
 case "orb":
 case "orbs":
    if(this_player()->query_money("gold") < 20 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    if(numba) {
      if(numba < 1 || numba > 1000) return 0;
      if(this_player()->query_money("gold") < 20*numba ) {
        this_object()->force_me("say You don't have that much money!");
        return 1;
      }
      this_player()->add_money("gold", -20*numba);
      write("Edwin hands you "+(string)numba+" orbs.");
      say("Edwin hands "+this_player()->query_cap_name()+"
"+(string)numba+" orbs.");
        while(numba > 0) {
          oil = new("/d/guilds/acheron/orb");
          if(numba >= 15)
            oil->set_uses(15);
          else

            oil->set_uses(numba);
          numba -= 15;
          oil->move(this_player());
        }
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Edwin hands you an orb.");
    say("Edwin hands "+this_player()->query_cap_name()+" an orb.");
    new("/d/guilds/acheron/orb")->move(this_player());
    return 1;
}
}
