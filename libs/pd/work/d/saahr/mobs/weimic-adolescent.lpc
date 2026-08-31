
#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("young weimic");
  set_race("weimic");
  set_body_type("weimic");
  set_gender(({"male","female","female"})[random(3)]);
  set_id(({"weimic", "young weimic"}));
  set_short("young weimic");
  set_long("A nomad of the plains, this adolescent is out "
    "on the plains for one of "+query_possessive()+
    " first hunts alone. "+query_subjective()+" has darker "
    "colored fur than the adults but lighter than the smaller cubs.");

  set_class("fighter");
  set_subclass("warrior");
  set_level(35+random(3));

  set_spells(({"impale","throw spear"}));
  set_spell_chance(25);

  if (!random(2)) {
    set_inventory( ([
      WEP+"huntingspear" : "wield spear",
    ]) );
  }
}


