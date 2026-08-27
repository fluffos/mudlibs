#include "path.h"
inherit "/obj/monster";
string *colors = ({"gordo","pardo","negro","dorado","a pintas","blanco"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("gato salvaje");
    set_short("Gato salvaje");
    add_alias("gato");
    set_main_plural("gatos salvajes");
    add_plural("gatos");
    set_long("  Un gato "+colors[i]+" de aspecto resistente. "
    "Aunque se le ve fuerte su vida no debe ser muy facil, se le ven "
    "algunas heridas y desgarrones en su piel. "
    "\n");

    set_random_stats(2,5);
    set_str(5+i);
    load_chat(10,
       ({
        1,":maulla!.",
        1,":ronronea.",
        1,":se estira con pereza.",
        1,":se dedica a su higiene personal.",
       }));
    load_a_chat(100,
      ({
       1,":te ensenya las garras!",
       1,":bufa enojado.",
    }));
    set_wimpy(10);
    set_level(3+random(3)+i);
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
    "punch"   :({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"muerde a","rasga a","aranya a",})[three]+" "+DN+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n",
                 "Golpeas "+DN+".\n",
                  AN+" "+({"te muerde","te rasga","te aranya",})[three]+" en "+({"el brazo","la mano","la pierna","el cuello","el pecho",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c






