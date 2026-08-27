#include "path.h"
inherit "/obj/monster";
string *colors = ({"larga en espiral","azulada","con pintas rosas","ancha en espiral",
                    "verde y gris","blanquecina"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("cangrejo hermitanyo");
    set_short("Cangrejo hermitanyo");
    add_alias("cangrejo");
    set_main_plural("cangrejos");
    set_long("  Un gran cangrejo hermitanyo con una concha "+colors[i]+". "
    "Se arrastra por la arena lentamente dedicado a sus asuntos. "
    "\n");

    set_random_stats(2,5);
    set_dex(5+i);
   set_gender(0);
    load_chat(10,
       ({
        1,":escarba por los alrededores.",
        1,":apunta su pinza hacia ti.",
        1,":se entretiene con algo que ha encontrado entre la arena.",
       }));
    load_a_chat(100,
      ({
       1,":abre y cierra una pinza!",
       1,":te escupe una baba verdosa.",
    }));
    set_wimpy(10);
    set_level(3+random(3)+i);
    set_move_after(3,3);
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






