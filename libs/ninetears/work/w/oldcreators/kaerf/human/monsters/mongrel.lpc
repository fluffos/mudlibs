#include "path.h"
inherit "/obj/monster";
string *colors = ({"negro y marron","de un sucio amarillo","negro","marron y gris","blanco y negro"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("chucho");
    set_short("Chucho");
    add_alias("perro");
    set_main_plural("perros");
    add_plural("chuchos");
    set_long("  Un perro de aspecto sarnoso, agacha la cabeza y mueve el rabo segun te acercas. "
    "Es "+colors[i]+" en donde le queda pelo, "
    "una oreja esta rasgada, y parece sufrir alguna enfermedad en los huesos por la forma renqueante "
    "de moverse, por su mirada dirias que le harias un favor matandole. "
    "\n");

    set_random_stats(2,5);
    set_str(5+i);
    load_chat(100,
       ({
        1,":ladra!.",
        1,":aulla.",
      1,":gime.",
      1,":se rasca.",
        1,":se lame una herida.",
        1,":levanta una pata y se mea en tu pierna.",
       }));
    load_a_chat(100,
      ({
       1,"rechina los dientes!",
       1,":grunye!",
    }));
    set_wimpy(50);
    set_level(1+random(3)+i);
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






