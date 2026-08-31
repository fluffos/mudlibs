#include <std.h>
inherit MONSTER;
void create()
{
    ::create();
    set_name("shengar");
    set_short("%^BOLD%^%^BLACK%^Shengar, the Magician");
    set_long("Shengar was once a powerful magician but he was struck down by a "
      "rival.  He now works in this shop selling magical orbs and other "
      "wonders, waiting for a chance to get revenge.");
    set_level(30);
    set_body_type("human");
    set_gender("male");
    set_id( ({ "shengar", "owner", "magician" }) );
}

void init()
{
    ::init();
    add_action("fBuy", "buy");
    add_action("fRead", "read");
}
int fRead(string str)
{
    if (!str || str!="sign")
	return notify_fail("Read what?\n");
    say (this_player()->query_cap_name()+" reads over the sign.");
    write("The sign reads:
-----------------------------------------
 [ Fire ] ( 30 gold pieces )
     A ball of blue fire. It is used to heal members from damage.
 [ Acid ] ( 20 gold pieces )
     An acid orb. It is used to restore a member's mp.
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
 if (str!="acid" && str!="fire" && str != "orb" && str != "orbs" && 
   str != "scrolls" && str != "scroll")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "acid":
 case "acid":
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
      write("Shengar hands you "+(string)numba+" acid orbs.");
      say("Shengar hands "+this_player()->query_cap_name()+" "+(string)numba+" acid orbs.");
      while(numba--)
        new("/d/guilds/forsaken/obj/acidorb")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -20);
    write("Shengar hands you an acid orb.");
    say("Shengar hands "+this_player()->query_cap_name()+" an acid orb.");
    new("/d/guilds/forsaken/obj/acidorb")->move(this_player());
    return 1;
  break;
 case "fire":
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
      write("Shengar hands you "+(string)numba+" blue flames.");
      say("Shengar hands "+this_player()->query_cap_name()+" "+(string)numba+" blue flames.");
        while(numba > 0) {
          oil = new("/d/guilds/forsaken/obj/healfire");
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
    write("Shengar hands you a ball of blue fire.");
    say("Shengar hands "+this_player()->query_cap_name()+" a ball of blue fire.");
    new("/d/guilds/forsaken/obj/healfire")->move(this_player());
    return 1;
break;
 //case "orbs":
// case "orb":
  //  if(this_player()->query_money("gold") < 20 ) {
    //  this_object()->force_me("say You don't have that much //money!");
  //    return 1;
    //}
//    if(numba) {
  //    if(numba < 1 || numba > 1000) return 0;
    //  if(this_player()->query_money("gold") < 20*numba ) {
      //  this_object()->force_me("say You don't have that much //money!");
  //      return 1;
    //  }
      //this_player()->add_money("gold", -20*numba);
//      write("Shengar hands you "+(string)numba+" orbs.");
  //    say("Shengar hands "+this_player()->query_cap_name()+" //"+(string)numba+" orbs.");
  //    while(numba--)
    //    new("/d/guilds/forsaken/orb")->move(this_player());
      //return 1;
//    }
  //  this_player()->add_money("gold", -20);
    //write("Shengar hands you some orbs.");
//    say("Shengar hands "+this_player()->query_cap_name()+" an //orb.");
  //  new("/d/guilds/forsaken/orb")->move(this_player());
    //return 1;
//  break;
 case "scroll":
 case "scrolls":
    if(this_player()->query_money("gold") < 30 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }

}
}
