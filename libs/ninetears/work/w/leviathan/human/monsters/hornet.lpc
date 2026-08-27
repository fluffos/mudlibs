#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("avispa");
    set_short("Avispa");
    add_alias("insecto");
    set_main_plural("avispas");
    set_gender(2);
    set_long(" Es un insecto negro y naranja,  tan grande como tu mano "
    "resulta algo mas que molesto, y da la impresion de ponerse a la "
    "ofensiva a la menor provocacion.\n");
    set_random_stats(2,5);
    set_dex(20);
    load_chat(100,
       ({
        1,":zumba en tu oido... BzZzZzz.",
        1,":se posa en tu nariz.",
       }));
    load_a_chat(100,
      ({
       1,":Zigs , zags, y ataca!",
    }));
    set_level(1+random(3));
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
     "punch"   :({ AN+" "+({"pica a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "golpeas a "+DN+".\n",
                  AN+" "+({"te pica","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"pica a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te pica","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"pica a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas "+DN+".\n",
                  AN+" "+({"te pica","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"pica a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas "+DN+".\n",
                  AN+" "+({"te pica","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c



