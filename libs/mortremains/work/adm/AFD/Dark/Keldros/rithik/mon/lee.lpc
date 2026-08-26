#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Lee, the School Janitor");
  enable_commands();
  set("long", @ENDLONG
Lee is an elderly dwarf that looks very tired.  He has an anger in his 
face that tells you he is not the playfull type.
ENDLONG
  );
  set_alignment(-100);
  set_name("lee");
  set("id", ({
    "janitor",
    "lee",
    "_dad_",
  }));
  credit(180 );
  set("damage", ({ 18, 25 }) );
  set("armor_class", 9);

  arm(WEAPONS(mop), "mop");
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "hard-working");
  set("gender", "male");
  set("weapon_name", "mop");
  set_verbs( ({
    "bash at",
    "jab",
}));
  set_verbs2( ({
    "bashes at",
    "jab",
}));
  set_skill("defense", 5, "dexterity");
  set_skill("attack", 10, "strength");
  set_level(6);
  set("chat_chance", 3);
  set("chat_output", ({
    "Lee says: \"With 5 grown adults in this school, only I can keep the place clean!\"\n",
    "Lee says: \"Clean, clean, clean.\"\n",
    "Lee says: \"Get outta my school!\"\n",
    "The janitor mops up an invisible stain on the floor.\n",
    "Lee complains: \"Work, work, work, I am the only one who does any work 
around here.\"\n",
   
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
            case 6:
               {
               command("mr.ades");
               break;
               }
               case 7:
               {
               command("mrs.racine");
               break;
               }
               case 8:
               {
               command("mr.lyman");
               break;
               }
               case 9:
               {
               command("say No way am I going into Mrs. Krauss' classroom again!");
               break;
               }
               case 10:
               {
               command("seduce lee");
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