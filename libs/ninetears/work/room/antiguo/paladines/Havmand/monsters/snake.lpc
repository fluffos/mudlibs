#include "path.h"
inherit "/obj/monster";
string *colors = ({"marron","negra con pintas blancas","gris plateada","verde brillante","roja y negra","amarilla"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("serpiente");
    set_short("serpiente");
    set_long("  Una serpiente "+colors[i]+" se arrastra sin molestar "
    "a nadie, se mueve despacio como si no tuviera prisa. "
    "Tal vez necesite un empujoncito? "
    "\n");
    set_gender(2);
    set_random_stats(2,5);
    set_dex(10+i);
    load_chat(10,
       ({
        1,":sisea.",
        1,":examina el aire con su lengua.",
        1,":se enrosca.",
       }));
    load_a_chat(100,
      ({
       1,":escupe veneno en tu direccion.",
       1,":muestra los colmillos.",
    }));
//   set_gender(0);
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









