#include <std.h>
 
inherit MONSTER;
void init() {
  ::init();
  add_action("asd","asd");
}
 
void create() {
    ::create();
    set_name("hawk");
  set_id( ({"hawk","screeching hawk"}) );
 set_short("Screeching hawk (flying)");
    set_long(
 "This is a very big hawk. He flys around the woods day in and day out in "
 "search of food. He looks rather mean and quite deadly. "
 );
set_level(9);
set_gender("male");
set_class("fighter");
set_spell_chance(25);
set_spells( ({"asd"}) );
set_alignment(35);
set_body_type("fowl");
set_race("hawk");
set_emotes(9, ({"The hawk screeches loudly.",
"The hawk flys in giant circles up in the sky."}),0);
add_action("asd", "asd");
}
 
int asd() {
 if(this_player()->is_player()) {
 message("info","What?",this_player());
 return 1;
  }
if(!query_current_attacker()) return 1;
  else {
 message("info", "The hawk divebombs you and hits!",query_current_attacker());
 message("info","The hawk divebombs "+query_current_attacker()->query_cap_name()+"and hits!",environment(this_object()), query_current_attacker());
 query_current_attacker()->add_sp(-(20));
 query_current_attacker()->add_hp(-25);
  }
 return 1;
  }
