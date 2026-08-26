#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
::create();
  set("short", "John Miller, School Principle");
  set("long", @ENDLONG
Mr. Miller has a cruel face, he appears to be the principle from your
nightmares.  He is dressed in a plaid suit, and carries a splintered
ruler.
ENDLONG
  );
  set_alignment(-500);
set_name("the evil principle");
  set("id", ({
    "principle",
    "john",
    "miller",
     
    
    
  }));
set("damage", ({ 15, 60 }) );
credit(700);
set("armor_class", 10);
arm(WEAPONS(ruler), "ruler");
set("attack_strength", 18);
  set("race", "dwarf");
set("attrib1", "tall"); set("attrib2", "thin");
set("gender", "male");
set("weapon_name", "splintered ruler");

  set_verbs( ({
    "thrash",
    "smack",
}));
  set_verbs2( ({
    "thrashes",
    "smacks",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
"Mr. Miller reads over some disciplinary files.\n"
"The principle admires his ruler and grins evilly.\n",
"John says: 'You know, one day I am gonna be mayor of Rithik.\n",
"John says: 'Don't you think Mrs. Krauss is hot?  I do!\n",
    
   
  }) );
  set("forgetful", 1);
set("post_wield_func", "special_on");
}

int special_on() {
  write(@ENDLONG
The splintered ruler fills your heart with evil, you feel punishment is due
the world.
ENDLONG
 );
return 1;
}

int weapon_hit(int damage) {
  object victim;


  int cost;
  cost = random(damage) + 7;
  victim = environment()->query_current_attacker();
  if (random(100) < 20) {
  message("combat",
 
     victim->query("cap_name") + " now knows the power of punishment!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
"You feel smited with the power of the mighty ruler!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
"John laughs as he punishes the one who challenges his authority.\n");
    return 0;
  }
}
