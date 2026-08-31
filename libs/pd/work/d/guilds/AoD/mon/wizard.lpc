#include <std.h>
inherit MONSTER;
void create()
{
 ::create();
 set_name("Satanic Wizard");
 set_level(60);
 set_short("%^BOLD%^%^BLACK%^Sat%^RESET%^%^CYAN%^an%^BOLD%^%^BLACK%^ic Wi%^RESET%^%^CYAN%^za%^BOLD%^%^BLACK%^rd%^RESET%^");
 set_long("%^BOLD%^%^BLACK%^This wizard stands 6 foot tall, he holds a human skull in one hand "
"%^BOLD%^%^BLACK%^and a vial of blood in the other, if you wish to buy healing or magical items "
"%^BOLD%^%^BLACK%^ask him.");
 set_race("sacrom");
 set_body_type("human");
 set_gender("male");
 set_id( ({ "wizard", "satanic wizard" }) );
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
The sign reads:
-----------------------------------------
 [ A vial of blood ]
     A magical blend of blood, blood drained from dead members
     is given to the others to heal. ( 20 gold pieces )
     You can <buy '#' blood> to buy a specific number of blood vials..
[ Human Skull ]
   A Skull left over from a great battle, filled with magical power.
   you can <Buy '#' skull> to buy a specific number of skulls.
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
 if (str!="soul" && str!="blood" && str!="soul" && str!="blood")
   {
    if(sscanf(str, "%d %s", numba, str) != 2) {
      this_object()->force_me("say I dont have that for sale.");
      return 1;
    }
   }
 switch(str)
 {
 case "skull":
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
      write("The Satanic Wizard hands you "+(string)numba+" skulls.");
      say("The Satanic Wizard hands "+this_player()->query_cap_name()+"
"+(string)numba+" skulls.");
      while(numba--)
        new("/d/guilds/AoD/obj/stone")->move(this_player());
      return 1;
    }
    this_player()->add_money("gold", -30);
    write("The Satanic Wizard hands you a skull.");
    say("The Satanic Wizard hands "+this_player()->query_cap_name()+" a skull.");
  new("/d/guilds/AoD/obj/stone")->move(this_player());
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
      write("The Satanic Wizard hands you "+(string)numba+" vials of blood.");
      say("The Satanic Wizard hands "+this_player()->query_cap_name()+"
"+(string)numba+" vials of blood.");
        while(numba > 0) {
          oil = new("/d/guilds/AoD/obj/oil");
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
    write("The Satanic Wizard hands you a vial of blood.");
    say("The Satanic Wizard hands "+this_player()->query_cap_name()+" a vial of blood.");
    new("/d/guilds/AoD/obj/oil")->move(this_player());
    return 1;
}
}
