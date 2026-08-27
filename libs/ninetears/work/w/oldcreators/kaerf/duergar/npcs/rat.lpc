#include "path.h"
inherit "/obj/monster";
string *colors = ({"huesuda","sarnosa","negra","gorda","albina","maloliente"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("rata");
    set_short("rata");
    set_long("  Una astuta rata "+colors[i]+" . "
    "Con gatos y perros acosandola, la vida de una rata es brutal,peligrosa y corta. "
    "Y tu aun podrias acortarla mas, no?. "
    "\n");

    set_random_stats(2,5);
    load_chat(10,
       ({
        1,":chilla",
        1,":se lame.",
       }));
    load_a_chat(100,
      ({
       1,":te mordisquea!",
       1,":se restriega en ti.",
    }));
    set_level(i-3);
}
//This is supposed to be code for modifying the unarmed combat
//of various creatures.  I am Talon; however, so not even the gods
//know how this will turn out...

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack () {

  int two,three,four,five;
  two=random(2);
  three=random(3);
  four=random(4);
  five=random(5);

  return ([
    "punch"   :({ AN+" "+({"muerde","aranya","desgarra",})[three]+" "+DN+" el "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te aranya","te desgarra",})[three]+" en el "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"muerde","aranya","desgarra",})[three]+" "+DN+" en el "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te aranya","te desgarra",})[three]+" en el "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"muerde","aranya","desgarra",})[three]+" "+DN+" en el  "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te aranya","te desgarra",})[three]+" en el "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"muerde","aranya","desgarra",})[three]+" "+DN+" en el  "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te aranya","te desgarra",})[three]+" en el "+({"brazo","punyo","muslo","rostro","pecho",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c







