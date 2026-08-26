#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Gembralli, the wicked Ring Master");
  enable_commands();
  set("long", @ENDLONG
Gembralli is middle aged and maintains a constant scowl
when not performing.  A thin moustache covers his upper
lip.  You sense that gembralli is quite powerful, and
should be avoided at all cost.
ENDLONG
  );
  set_alignment(100);
  set_name("gembralli");
  set("id", ({
    "gembralli",
    "ring master",
    "master",
  }));
  arm(WEAPONS(jwhip), "whip");
  set("agressive", 1);
  set("damage", ({ 100, 300 }) );
  set("armor_class", 42);
  set("attack_strength", 42);
  set("race", "human");
  set("attrib1", "black haired");  set("attrib2", "dark eyed");
  set("gender", "male");
  set_skill("defense", 42, "dexterity");
  set_skill("attack", 42, "strength");
  set_level(42);
  set("forgetful", 1);
  set("att_chat_output", ({ 
     "Gembralli screams: \"You will die for your mistake!\"\n",
     "Gembralli laughs at you.\n",
     "The wicked Ring Master says: \"Your combat skills are appauling.\"\n",
     "Gembralli's eyes glow for a moment.\n",
}) );
}
