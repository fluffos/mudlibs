#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("bandicoot");
    set_short("Bandicoot");
    set_long("   El bandicoot parece como una rata pero con la corpulencia "
    "de un gato. Es gris y esta moteado con una serie de anillos de color "
    "marron que recorren su cuerpo, tiene un hozico largo y de su mandibula "
    "sobresalen unos afilados dientes, incluso con la boca cerrada. "
    "Se dedica a rebuscar entre las hojas caidas que cubren el suelo. "
    "\n");
    set_random_stats(2,5);
    set_move_after(3,1);
    set_str(10);
    set_max_hp(20);
    load_chat(100,
       ({
        1,":escarba entre a hojarasca olisqueandolo todo.",
        1,":mastica algo pequenyo y crujiente.",
        1,":te mira con desconfianza.",
        1,":se rasca con vigor.",
       }));
    load_a_chat(100,
      ({
       1,":bufa.",
    }));
      1,":grunye.",
    set_level(6+random(6));
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







