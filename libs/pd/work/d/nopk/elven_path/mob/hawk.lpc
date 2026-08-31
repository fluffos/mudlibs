#include <std.h>
 
inherit MONSTER;
int ran;
void init() {
  ::init();
  add_action("asd","asd");
}
 
void create() {
    ::create();
  set_name("hawk");
  set_id( ({"hawk"}) );
  set_short("a hawk (flying)");
  set_long(
          "A very large hawk. It flys around the forest in search of food."
  );
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
  set_gender("male");
  set_class("fighter");
  set_spell_chance(25);
  set_spells( ({"asd"}) );
  set_alignment(35);
  set_body_type("fowl");
  set_race("hawk");
  set_emotes(9, ({"The hawk screeches loudly.",
    "The hawk swoops in after a rodent."}),0);
  add_action("asd", "asd");
}
 
int asd() {
 if(this_player()->is_player()) {
 message("info","What?",this_player());
 return 1;
  }
if(!query_current_attacker()) return 1;
  else {
 message("info", "The hawk swoops at you and hits!",query_current_attacker());
 message("info","The hawk swoops at "+query_current_attacker()->query_cap_name()+"and hits!",environment(this_object()), query_current_attacker());
 query_current_attacker()->add_sp(-(5));
 query_current_attacker()->add_hp(-25);
  }
 return 1;
  }
