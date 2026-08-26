// A cheapo security guard. Good for little more
// than eating donuts.

#include "macrosoft.h"

inherit MONSTER;

void create() {
    object badge;

    ::create();
    set("prevent_summon", 1);
    set("short", "Barbara the Office Manager");
    set("long", wrap(
	"This depraved soul was once a lowly officer worker, "+
	"like her subordinates, but has since devolved into "+
	"something much worse and far more terrifying and "+
	"desperate: middle management!"
      ) );
    set("id", ({ "barbara", "manager", "office manager" }) );
    set_name("barbara");
    set("gender", "female");
    set("attrib1", "fearsome");
    set("attrib2", "controlling");
    set("race", "troll");
    set("weapon_name", "claws");
    set("damage_type", "slashing");
    set("damage", ({ 3, 12 }) );
    set_verbs( ({ "swing at" }) );
    badge = clone_object(MS_OBJ("id_badge"));
    badge->set_color(3);
    wear(badge);
    set("natt", 2);
    set("stat", ([
      "strength" : 19,
      "dexterity" : 17
    ]) );
    set_skill("Unarmed", 2, "strength");
    credit(190+random(300));
    set("special", 4);
    set_level(8);
}

void heart_beat() {
    ::heart_beat();
    heal_up();
}

/* EOF */
