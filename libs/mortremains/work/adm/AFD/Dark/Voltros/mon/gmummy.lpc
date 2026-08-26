#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "greater mummy");
  enable_commands();
  set("long", @ENDLONG
This mummy is wrapped in dark bandages, and is wearing a tattered
cleric robe and pontiff.  A unholy symbol hangs from it's neck.  It's
eyes are sunken into his head, and what skin you can see is gray.
ENDLONG
  );
  set_alignment(-50);
  set_name("greater mummy");
  set("id", ({
    "mummy",
    "greater mummy",
  }));
  credit(150);
  set("damage", ({ 17, 47 }) );
        clone_object("/d/Dark/Voltros/obj/symbol")->move(this_object());
  set("armor_class", 9);
  set("hit_points", 140);
  set("attack_strength", 10);
  set("gender", "male");
  set("agressive", 1);
		set("undead", 12);
  set("race", "undead");
  set("attrib2", "smelly");  set("attrib1", "heidous");
  set("weapon_name", "hands");
  set_verbs( ({
    "swing at",
}));
  set_skill("defense", 11, "dexterity");
  set_skill("attack", 11, "strength");
  set_level(11);

}