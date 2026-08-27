#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("foca");
    set_short("Foca");
    set_long("   Una gran foca, simplemente esta tumbada sin hacer nada "
    "en particular. Es de un negro profundo y, tal vez por el mucho tiempo "
    "que se pasa en el mar, huele realmente mal. \n");
    set_gender(2);
    set_random_stats(12,5);
    set_move_after(30,10);
    set_max_hp(20);
   set_al(-250);
    load_chat(100,
       ({
        1,":gira sobre si misma.",
        1,":se lanza arena sobre su cuerpo.",
        1,":te mira cautelosa.",
        1,":jadea.",
//    1,":arfs loudly.",
        1,":se rasca lentamente."
       }));
    load_a_chat(100,
      ({
       1,":te muestra los dientes.",
       1,":lanza una garra."
    }));
    set_level(6+random(12));
   set_gender(0);

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




