#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("tutenkhamen");
 set_short("%^BOLD%^%^WHITE%^Tutenkhamen%^RESET%^");
 set_long("An ancient being, he looks to be centuries old.");
 set_race("human");
set_body_type("human");
 set_gender("male");
 set_id( ({ "tutenkhamen", "owner", "magician" }) );
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
 [ A soul ]
     A soul of a past memeber. It is used to heal members from
     damage ( 20 gold pieces )
     You can <buy '#' soul> to buy a specific number of souls.
 [ Ashes ]
     Ashes of a past memeber. It is used to restore a members
     mp ( 30 gold pieces )
     You can <buy '#' ashes> to buy a specific number of ashes.
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
 if (str!="ashes" && str!="soul" && str!="ashes" && str!="soul")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "ashes":
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
      write("Tutenkhamen hands you "+(string)numba+" ashes.");
      say("Tutenkhamen hands "+this_player()->query_cap_name()+" "+(string)numba+" ashes.");
      while(numba--)
        new("/d/guilds/darksoul/ashesobj")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Tutenkhamen hands you some ashes.");
    say("Tutenkhamen hands "+this_player()->query_cap_name()+" some ashes.");
    new("/d/guilds/darksoul/ashesobj")->move(this_player());
    return 1;
  break;
 case "soul":
 case "souls":
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
      write("Tutenkhamen hands you "+(string)numba+" souls.");
      say("Tutenkhamen hands "+this_player()->query_cap_name()+" "+(string)numba+" souls.");
        while(numba > 0) {
          oil = new("/d/guilds/darksoul/soul");
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
    write("Tutenkhamen hands you a soul.");
    say("Tutenkhamen hands "+this_player()->query_cap_name()+" a soul.");
    new("/d/guilds/darksoul/soul")->move(this_player());
    return 1;
}
}
