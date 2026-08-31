#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("A Giant Scorpion");
 set_level(60);
 set_short("A Giant Scorpion");
 set_long("This is a Giant Scorpion. Towering over 10 feet tall he looks
down at you in disgust.");
 set_race("scorpion");
 set_body_type("scorpion");
 set_gender("nueter");
 set_id( ({ "scorpion", "giant scorpion" }) );
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
 write("
The sign reads:
-----------------------------------------
 [ Scorpion's Blood ]
     Crushed from the small bodies of poisonious scorpions,
     their blood has been flitered and packaged for your use.
     You can <buy '#' blood> to buy a specific number of 
     purfied scorpions blood..
                                                       ( 20 gold pieces )
 [ Scorpion Crystal ]
   Mined from the Scorpion caves, these crystals are thought to 
   grant magical power.
   You can <Buy '#' crystal> to buy a specific number of crystals.
                                                       ( 30 gold pieces )
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
 if (str!="crystal" && str!="crystals" && str!="blood" && str!="bloods")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "crystal":
 case "crystals":
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
      write("The Giand Scorpion hands you "+(string)numba+" crystals.");
      say("The Giant Scorpion hands "+this_player()->query_cap_name()+" "+(string)numba+" crystals.");
      while(numba--)
        new("/d/guilds/scorpio/crystal")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("The Giand Scorpion hands you a crystal.");
    say("The Giant Scorpion hands "+this_player()->query_cap_name()+" a crystal.");
    new("/d/guilds/scorpio/crystal")->move(this_player());
    return 1;
  break;

 case "blood":
 case "vial":
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
      write("The Giant Scorpion hands you "+(string)numba+" packs of blood.");
      say("The Giant Scorpion hands "+this_player()->query_cap_name()+"
"+(string)numba+" packs of blood.");
        while(numba > 0) {
          oil = new("/d/guilds/scorpio/blood");
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
    write("The Giant Scorpion hands you a pack of blood.");
    say("The Giant Scorpion hands "+this_player()->query_cap_name()+" a pack of blood.");
    new("/d/guilds/scorpio/blood")->move(this_player());
    return 1;
}
}
