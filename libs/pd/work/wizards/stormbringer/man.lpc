#include <std.h>
 
inherit MONSTER;
void init() {
  ::init();
  add_action("gas","gas");
}
 
void create() {
    ::create();
    set_name("old man");
  set_id( ({"man","old man"}) );
 set_short("An old man sitting on the pot");
    set_long(
 "This old man was just sitting here minding his own business "
 "when a nosy adventurer had to burst on in and disturb him. Now "
 "he's a little upset!"
 );
set_level(52);
set("aggressive", 500);
set_gender("male");
set_class("fighter");
set_spell_chance(99);
set_spells( ({"gas"}) );
set_alignment(0);
set_body_type("human");
set_race("human");
set_emotes(9, ({"The old man strains.",
"The old man mumbles something about trying to do his business."}),1);
add_action("gas", "gas");
}
 
int gas() {
 if(this_player()->is_player()) {
 message("info","What?",this_player());
 return 1;
  }
if(!query_current_attacker()) return 1;
  else {
 message("info", "The old man seems to levitate as he passes a gas that chokes you!",query_current_attacker());
 message("info","The old man passes a very loud and extremely unpleasant gas, choking
"+query_current_attacker()->query_cap_name()+"!",environment(this_object()), query_current_attacker());
 query_current_attacker()->add_sp(-(20));
 query_current_attacker()->add_hp(-45);
  }
 return 1;
  }
