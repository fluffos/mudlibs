#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A strangely dressed ogre");
  set("long", @ENDLONG
Frankie is a medium sized ogre, quite large to a 'normal' humanoid.  
He is wearing a purple felt hat that rests on long pierced ears.  A pink, 
furry coat covers his frame, and offsetting bright yellow and red polka-dot
trousers.
ENDLONG
  );
  set_alignment(100);
  set_name("frankie");
  set("id", ({
    "ogre",
    "frankie",
  }));
  wear(ARMOR(fhat), "hat");
  credit(100 + random(300) );
  set("damage", ({ 15, 40 }) );
  set("armor_class", 5);
  set("attack_strength", 14);
  set("race", "ogre");
  set("attrib1", "freaky");  set("attrib2", "medium sized");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7);
  set("chat_chance", 5);
  set("chat_output", ({
    "Frankie stares at your legs and drools.\n",
    "Frankie admires his pants.\n",
    "Frankie takes his felt hat off and brushes some dust off of it.\n",
    "Frankie says: \"Am I not the most handsome ogre you have ever seen?\"\n",
    "The ogre puts his arm around you and says: \"What are doing tommorrow night?\"\n", 
}) );
  set("att_chat_output", ({
      "The ogre says: \"You brute, you brute, you vicious brute!\"\n",
      "Frankie screams: \"RAPE!!!!!!\"\n",
      "Frankie says: \"I will never go out with you now!\"\n",
      "Frankie kicks you in the GROIN!\n",
}) );
  set("forgetful", 1);
}
