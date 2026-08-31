#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("big mama juju");
 set_short("Big Mama Juju");
 set_long("Big Mama Juju, she is a faerie that has come to make this island her home. "
           "She creates ancient faerie dust and sphere for use by the local people.");
 set_race("faerie");
 set_level(45);
 set_body_type("faerie");
 set_gender("female");
 set_id( ({ "big mama juju", "owner", "magician", "mama", "mama juju", "juju" }) );
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
 [ %^BOLD%^%^BLUE%^D%^WHITE%^us%^BLUE%^t%^RESET%^ ]
     Dust. It is used to restore hp. ( 20 gold pieces )

 [ %^BOLD%^%^BLUE%^S%^RED%^p%^WHITE%^he%^RED%^r%^BLUE%^e%^RESET%^ ]
     Sphere. It is used to restore mp ( 30 gold pieces )

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
 if (str!="dust" && str!="sphere")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "dust":
 case "dusts":
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
      write("Big Mama Juju hands you "+(string)numba+" dusts.");
      say("Rand hands "+this_player()->query_cap_name()+" "+(string)numba+"
dusts.");
      while(numba > 0) {
        oil = new("/wizards/loki/Island/item/dust");
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
    write("Big Mama Juju hands you a dust.");
    say("Big Mama Juju hands "+this_player()->query_cap_name()+" a dust.");
    new("/wizards/loki/Island/items/dust")->move(this_player());
    return 1;
  break;
 case "sphere":
 case "spheres":
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
      write("Big Mama Juju hands you "+(string)numba+" spheres.");
      say("Big Mama Juju hands "+this_player()->query_cap_name()+" "+(string)numba+"
spheres.");
      while(numba--)
        new("/wizards/loki/Island/item/sphere")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("Big Mama Juju hands you an sphere.");
    say("Big Mama Juju hands "+this_player()->query_cap_name()+" an sphere.");
    new("/d/guilds/illuminati/obj/angreal")->move(this_player());
    return 1;
break;
}
}
