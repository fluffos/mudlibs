#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Hans, the Animal Handler");
  enable_commands();
  set("long", @ENDLONG
Hans wears cover-alls that are covered with all sorts of differently 
colored materials.  He carries a pitchfork that he wields with pride.  
He has a stern face that never smiles.
ENDLONG
  );
  set_alignment(100);
  set_name("hans");
  set("id", ({
    "hans",
    "handler",
    "animal handler",
  }));
  
  credit(100 + random(300) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 3);

  arm(WEAPONS(fork), "fork");
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "blonde");  set("attrib2", "muscular");
  set("gender", "male");
  set("weapon_name", "wicked pitchfork");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(9);
  set("chat_chance", 4);
  set("chat_output", ({
    "Hans drones: 'For beings of the Netherealm, there excrement has some 
shocking simmilarities to the Prime plane.'\n",
    "Hans gets a guitly look on his face and a strange smell fills the area.\n",
    "Hans picks up some hay and tosses it into an undefined pile.\n",
  }) );
  set("forgetful", 1);
 call_out("wander", 50);
}
int wander()
{
        int x;
        command("get all");
        x = random(13);
        switch(x)
        {
           case 1:
                {
                command("south");
                break;
                }
           case 2:
                {
                command("west");
                break;
                }
           case 3:
                {
                command("north");
                break;
                }
           case 4:
                {
                command("east");
                break;
                }
            case 5:
                {
                command("swear");
                break;
                }
        
               case 10:
               {
               command("enter");
               break;
               }
               case 11:
               {
               command("spit");
               break;
               }
              default:
              {
              command("get all"); 
              break ;
               }
         }
        call_out("wander", 40);
        return 0;
}
int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 20;
  victim = environment()->query_current_attacker();
  if (random(100) < 20) {
  message("combat",
  "You gore " +
        victim->query("cap_name") + "horribly with his wicked pitchfork!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You are gored horribly by Hans' wicked pitchfork!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 query("cap_name") +"Is gored horribly by Hans the Animal handler!\n");
}
}

