#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("temugin");
 set_short("Temugin");
 set_long("A short dragon-like creature bows deep before you, waiting "
                 "to complete your order. To see what there is to buy <read sign>.");
 set_race("half-dragon");
 set_body_type("pegataur");
 set_gender("neuter");
 set_id( ({ "temguin", "owner" }) );
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
 [ A crystal shard ]
     A sliver of a dragons heart, said to have magical 
     properities.
     ( 30 gold pieces )
     You can <buy '#' shard> to buy a specific number of shards.
 [ A dragons scale ]
      The colorful scale of an odd type of hidden dragon. Healing
      energies have been seen and felt in its presence.
      ( 20 gold pieces )
     You can <buy '#' scale> to buy a specific number of scaless.
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
 if (str!="scale" && str!="scales" && str!="shard" && str!="shards")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "shard":
 case "shards":
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
      write("Temguin hands you "+(string)numba+" shards.");
      say("Temguin hands "+this_player()->query_cap_name()+"
"+(string)numba+" shards.");
      while(numba--)
        new("/d/guilds/dw/shard")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Temguin hands you a shard.");
    say("Temguin hands "+this_player()->query_cap_name()+" a shard.");
    new("/d/guilds/dw/shard")->move(this_player());
    return 1;
  break;
 case "scale":
 case "scales":
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
      write("Temguin hands you "+(string)numba+" scales.");
      say("Temguin hands "+this_player()->query_cap_name()+"
"+(string)numba+" scales.");
        while(numba > 0) {
          oil = new("/d/guilds/dw/scale");
          if(numba >= 15)
            oil->set_uses(15);
          else
            oil->set_uses(numba);
          numba -= 15;
          oil->move(this_player());
        }
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Temguin hands you a scale.");
    say("Temguin hands "+this_player()->query_cap_name()+" a scale.");
    new("/d/guilds/dw/scale")->move(this_player());
    return 1;
}
}
