#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create()
{
    ::create();
    set_name("jack, the disgruntled storekeeper");
    set_level(90);
    set_short("Jack, the disgruntled storekeeper");
    set_long("Jack is slowly turning out healing potions for you sick travelers. He
 dosent seem to be too happy about it either.");
 set_race("human");
 set_body_type("human");
 set_gender("male");
 set_class("fighter");
 set_subclass("warrior");
 set_spell_chance(45);
 set_spells(({"slash"}));
 set_id( ({ "jack", "storekeeper", "monster" }) );

 new("/d/freepk/purgatory/weap/repper")->move(this_object());
force_me("wield sword");
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
 [ A monkey's paw ]
     A strange thing brought in from the rangers in the 
     forest, they claim it has healing potiential.
     ( 35 gold pieces )
     You can <buy '#' paw> to buy a specific number of oils.
-----------------------------------------");
 return 1;
}

int fBuy(string str) {
  int numba;
  object oil;
  if(!str) {
    write("Buy what?\n");
    return 1;
  }
  if(str=="head" || str=="heads" || str=="shrunken heads") {
    this_object()->force_me("say I no longer sell shrunken heads here, "
"they disgust me. Try the store across the street.");
    return 1;
  }
  if(str=="paw" || str=="monkey's paw" || str=="paws") {
    if(this_player()->query_money("gold") < 35 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -35);
    write("Jack tosses you a monkey's paw.");
    say("Jack throws something disgusting at "+this_player()->query_cap_name()+"
.");
    new("/d/freepk/purgatory/item/paw")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "paw" && str !="monkey's paws" && str !="paws" && str !="monkies paw
") {
    write("Buy what?\n");
    return 1;
  }
  if(numba < 1) {
    this_object()->force_me("say How do you plan on doing that?");
    return 1;
  }
  if(numba > 1000) {
    this_object()->force_me("say I dont have that many right now!");
    return 1;
  }
  if(this_player()->query_money("gold") < 35*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -35*numba);
  write("Jack tosses "+(string)numba+" paws in your face, happy to be rid of them.");
  say("Jack tosses "+this_player()->query_cap_name()+" "+(string)numba+" monkey's paws.");
  while(numba > 0) {
    oil = new("/d/freepk/purgatory/item/paw");
    if(numba >= 15)
      oil->set_uses(15);
    else
      oil->set_uses(numba);
    numba -= 15;
    oil->move(this_player());
  } 
  return 1;
}
