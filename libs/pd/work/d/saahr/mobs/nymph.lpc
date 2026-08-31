
#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("nymph");
  set_race("nymph");
  set_body_type("human");
  set_gender("female");
  set_id(({"nymph"}));
  set_short("nymph");
  set_long("She has a fair complexion and long flowing "+
    ({"blonde","brown","black","red"})[random(4)]+" hair. "
    "Her graceful body is covered by a knee-length dress.");

  set_class("wanderer");
  set_subclass("bard");
  set_level(40);

  set_skill("attack", 80);
  set_skill("melee", 80);
  set_skill("defense", 200);
  set_skill("euphony", 200);

  set_spells(({"sing song of blades", "sing song of winter"}));
  set_spell_chance(75);

  set_inventory( ([
    ARM+"nymphdress" : "wear dress",
  ]) );
}

