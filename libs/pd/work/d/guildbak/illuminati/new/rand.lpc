#include <std.h>
inherit MONSTER;
void create()
{
    ::create();
    set_name("rand");
    set_short("%^BOLD%^%^WHITE%^Rand%^RESET%^");
    set_long("Rand Al'Thor, he creates the Heartstones and Angreal for use by the Illuminati. "
      "He radiates a very powerful magical aura, perhaps you shouldn't mess with him.");
    set_race("human");
    set_level(30);
    set_body_type("human");
    set_gender("male");
    set_id( ({ "rand", "owner", "magician" }) );
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
    write("%^RESET%^%^ORANGE%^The sign reads:
-----------------------------------------
 [ %^BOLD%^%^WHITE%^Heartstone%^RESET%^%^ORANGE%^ ]
     A heartstone. It is used to heal members from damage. 
                                        ( %^BOLD%^%^WHITE%^20 gold pieces%^RESET%^%^ORANGE%^ )

 [ %^BOLD%^%^WHITE%^Angreal%^RESET%^%^ORANGE%^ ]
     An angreal. It is used to restore a members mp. 
                                  ( %^BOLD%^%^WHITE%^30 gold pieces%^RESET%^%^ORANGE%^ )

-----------------------------------------");
 return 1;
}
int fBuy(string str) {
  object oil;
  int numba;
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="heartstone" && str!="angreal")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "heartstone":
 case "heartstones":
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
      write("Rand hands you "+(string)numba+" heartstones.");
      say("Rand hands "+this_player()->query_cap_name()+" "+(string)numba+"
heartstones.");
while (numba > 0) {
        oil = new("/d/guilds/illuminati/obj/heartstone");
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
    write("Rand hands you a heartstone.");
    say("Rand hands "+this_player()->query_cap_name()+" a heartstone.");
    new("/d/guilds/illuminati/obj/heartstone")->move(this_player());
    return 1;
  break;
 case "angreal":
 case "angreals":
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
      write("Rand hands you "+(string)numba+" angreals.");
      say("Rand hands "+this_player()->query_cap_name()+" "+(string)numba+"
angreals.");
      while(numba--)
        new("/d/guilds/illuminati/obj/angreal")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Rand hands you an angreal.");
    say("Rand hands "+this_player()->query_cap_name()+" an angreal.");
    new("/d/guilds/illuminati/obj/angreal")->move(this_player());
    return 1;
break;
}
}
