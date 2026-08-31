#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create()
{
    ::create();
    set_name("Dorf, the manic spellcaster");
    set_level(90);
    set_short("Dorf, the manic spellcaster");
    set_long("Dorf is a small human, about 4 foot tall and thin as a rail. He has this strange creepy look in his eyes as he looks around.");
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_class("clergy");
    set_subclass("druid");
    set_spell_chance(45);
    set_spells(({"icestorm", "thornwrack"}));
    set_id( ({ "dorf", "spellcaster", "monster" }) );

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
 [ A shrunken head ]
     The shrunken head of some unfortunate
     traveler that got lost in the forest.
     The natives claim that it has magicial
     potiential.
     ( 39 gold pieces )
     You can <buy '#' head> to buy a specific number of heads.
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
  if(str=="paw" || str=="paws" || str=="monkies paws") {
    this_object()->force_me("say I no longer sell monkey paws here, "
"they disgust me. Try the store across the street.");
    return 1;
  }
  if(str=="head" || str=="shrunken head" || str=="heads" || str=="shrunken heads") {
    if(this_player()->query_money("gold") < 39 ) {
      this_object()->force_me("say You don't have that much money!");
      return 1;
    }
    this_player()->add_money("gold", -39);
    write("Dorf flings a shrunken head in your general direction.");
    say("Something flies through the air at "+this_player()->query_cap_name()+".");
    new("/d/freepk/purgatory/item/head")->move(this_player());
    return 1;
  }
  if(sscanf(str, "%d %s", numba, str) != 2) {
    write("Buy what?\n");
    return 1;
  }
  if(str != "head" && str !="shrunken heads" && str !="heads" && str !="shrunken
 heads") {
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
  if(this_player()->query_money("gold") < 39*numba ) {
    this_object()->force_me("say You don't have that much money!");
    return 1;
  }
  this_player()->add_money("gold", -39*numba);
  write("Dorf tosses "+(string)numba+" shrunken heads in your general direction, laughing as he watches you try to catch them all.");
  say("Dorf throws "+(string)numba+" shrunken heads at "+this_player()->query_cap_name()+".");
  while(numba--) {
    oil = new("/d/freepk/purgatory/item/head");
    if (oil->move(this_player())) oil->move(environment());
  } 
  return 1;
}

